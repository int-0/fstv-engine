#include "actor.h"
#include "scene.h"
#include "sdlutil.h"
#include "anim.h"

#ifndef PSP
#include "pc/config.h"
#else
#include "psp/config.h"
#endif

#define FPS_TICKS (SDL_GetTicks() - fps_counter)

void create_scene(Scene *sc, const char *filename) {
  sc->bg = load_image( filename );
}

void setup_scene(Context ct, Scene *sc) {
  sc->dest = ct.screen;
}

void draw_scene(Scene *sc) {
  SDL_BlitSurface( sc->bg, NULL, sc->dest, NULL);
}

void run_scene(Scene *sc) {

  int fps_counter;

  int quit = 0;
  SDL_Event event;

  SDL_Rect offs;
  offs.x = 100;
  offs.y = 100;
  Anim anim = create_anim( sc->bg, offs, "toby_walk01.png" );
  add_frame_to( &anim, "toby_walk02.png" );
  add_frame_to( &anim, "toby_walk03.png" );
  add_frame_to( &anim, "toby_walk04.png" );
  add_frame_to( &anim, "toby_walk05.png" );
  add_frame_to( &anim, "toby_walk06.png" );

  Actor toby;
  toby.actions[0] = anim;
  toby.current_action = 0;
  toby.position = offs;
  toby.dest = sc->dest;

  while ( !quit ) {
    
    fps_counter = SDL_GetTicks();

    while ( SDL_PollEvent( &event ) ) {
      if ( event.type == SDL_QUIT ) {
	quit = -1;
      }
    }

    draw_scene( sc );
    draw_actor( &toby );
    update_actor( &toby );

    SDL_Flip( sc->dest );

    if ( FPS_TICKS < 1000 / FRAMES_PER_SECOND ) {
      SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - FPS_TICKS );
    }

  }
  
}
