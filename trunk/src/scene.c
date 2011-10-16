#include "scene.h"
#include "sdlutil.h"
#include "anim.h"

void create_scene(Scene *sc, const char *filename) {
  sc->bg = load_image( filename );
}

void setup_scene(Context ct, Scene *sc) {
  sc->dest = ct.screen;
}

void draw_scene(Scene *sc) {
  SDL_Rect offset;
  offset.x = 0;
  offset.y = 0;

  SDL_BlitSurface( sc->bg, NULL, sc->dest, &offset);
}

void run_scene(Scene *sc) {

  int quit = 0;
  SDL_Event event;

  Anim anim;
  anim.loaded = 0;
  anim.current = 0;
  anim.mode = LOOP;
  add_frame_to( &anim, "toby_walk01.png" );
  add_frame_to( &anim, "toby_walk02.png" );
  add_frame_to( &anim, "toby_walk03.png" );
  add_frame_to( &anim, "toby_walk04.png" );
  add_frame_to( &anim, "toby_walk05.png" );
  add_frame_to( &anim, "toby_walk06.png" );
  
  SDL_Rect offs;
  offs.x = 100;
  offs.y = 100;

  while ( !quit ) {

    while ( SDL_PollEvent( &event ) ) {
      if ( event.type == SDL_QUIT ) {
	quit = -1;
      }
    }

    show_anim( &anim, &offs, sc->dest );
    update_anim( &anim );

    SDL_Flip( sc->dest );

  }
  
}
