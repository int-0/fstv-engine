#include "actor.h"
#include "player.h"
#include "scene.h"
#include "sdlutil.h"
#include "anim.h"

#ifndef PSP
#include "pc/config.h"
#else
#include "psp/config.h"
#endif

#define FPS_TICKS (SDL_GetTicks() - fps_counter)

int free_actor_slot(Scene *sc) {
  for (int i = 0; i < MAX_ACTORS; i++) {
    if (sc->live_actor[i] == DEAD) {
      return i;
    }
  }
  return -1;
}

int free_player_slot(Scene *sc) {
  for (int i = 0; i < MAX_PLAYERS; i++) {
    if (sc->live_player[i] == DEAD) {
      return i;
    }
  }
  return -1;
}

void add_actor(Scene *sc, Actor actor) {
  int i = free_actor_slot( sc );
  if (i >= 0) {
    sc->actors[i] = actor;
    sc->live_actor[i] = LIVE;
  }
}

void add_player(Scene *sc, Player player) {
  int i = free_player_slot( sc );
  if (i >= 0) {
    sc->players[i] = player;
    sc->live_player[i] = LIVE;
  }
}

void create_scene(Scene *sc, const char *filename) {
  sc->bg = load_image( filename );
  for (int i = 0; i < MAX_ACTORS; i++) {
    sc->live_actor[i] = DEAD;
  }
  for (int i = 0; i < MAX_PLAYERS; i++) {
    sc->live_player[i] = DEAD;
  }
}

void setup_scene(Context ct, Scene *sc) {
  sc->dest = ct.screen;
  
  /* BEGIN: create sample actor */
  SDL_Rect actor_offs;
  actor_offs.x = 100;
  actor_offs.y = 100;
  Anim actor_anim = create_anim( sc->bg, actor_offs, "toby_walk01.png" );
  add_frame_to( &actor_anim, "toby_walk02.png" );
  add_frame_to( &actor_anim, "toby_walk03.png" );
  add_frame_to( &actor_anim, "toby_walk04.png" );
  add_frame_to( &actor_anim, "toby_walk05.png" );
  add_frame_to( &actor_anim, "toby_walk06.png" );
  
  Actor toby;
  toby.actions[0] = actor_anim;
  toby.current_action = 0;
  toby.position = actor_offs;
  toby.dest = sc->dest;
  add_actor( sc, toby );
  /* END: create sample actor */

  /* BEGIN: create sample player */
  SDL_Rect player_offs;
  player_offs.x = 500;
  player_offs.y = 100;
  Anim player_head_left = create_anim( sc->bg, player_offs, 
				       "meca_head_left_01.png" );
  Anim player_weels_left = create_anim( sc->bg, player_offs,
					"meca_weels_left_01.png" );
  add_frame_to( &player_weels_left, "meca_weels_left_02.png" );
  add_frame_to( &player_weels_left, "meca_weels_left_03.png" );

  Player meca;
  meca.uactions[0] = player_head_left;
  meca.dactions[0] = player_weels_left;
  meca.xd_ofs = 0;
  meca.yd_ofs = 10;
  meca.current_uaction = 0;
  meca.current_daction = 0;
  meca.position = player_offs;
  meca.dest = sc -> dest;
  add_player( sc, meca );

  /* END: create sample player */
}

void draw_scene(Scene *sc) {
  /* Put background */
  SDL_BlitSurface( sc->bg, NULL, sc->dest, NULL);
  /* Put actors */
  for (int i = 0; i < MAX_ACTORS; i++) {
    if (sc->live_actor[i] == LIVE) {
      draw_actor( &sc->actors[i] );
    }
  }
  /* Put players */
  for (int i = 0; i < MAX_PLAYERS; i++) {
    if (sc->live_player[i] == LIVE) {
      draw_player( &sc->players[i] );
    }
  }
}

void update_scene(Scene *sc) {
  for (int i = 0; i < MAX_ACTORS; i++) {
    if (sc->live_actor[i] == LIVE) {
      update_actor( &sc->actors[i] );
    }
  }
  for (int i = 0; i < MAX_PLAYERS; i++) {
    if (sc->live_player[i] == LIVE) {
      update_player( &sc->players[i] );
    }
  }
}

void run_scene(Scene *sc) {

  int fps_counter;

  int quit = 0;
  SDL_Event event;

  while ( !quit ) {
    
    fps_counter = SDL_GetTicks();

    while ( SDL_PollEvent( &event ) ) {
      if ( event.type == SDL_QUIT ) {
	quit = -1;
      }
    }

    update_scene( sc );
    draw_scene( sc );
    
    SDL_Flip( sc->dest );

    if ( FPS_TICKS < 1000 / FRAMES_PER_SECOND ) {
      SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - FPS_TICKS );
    }

  }
  
}
