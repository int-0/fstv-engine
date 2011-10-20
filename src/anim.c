#include "anim.h"
#include "sdlutil.h"

void add_frame_to(Anim *ani, const char *frame) {
  if ( ani->loaded == MAX_FRAMES ) {
    return;
  }
  ani->frames[ani->loaded] = load_image( frame );
  ++ani->loaded;
}

Anim create_anim(SDL_Surface *dest,
		 SDL_Rect initial_pos, const char *first_frame) {
  Anim new_anim;
  new_anim.loaded = 0;
  new_anim.current = 0;
  add_frame_to( &new_anim, first_frame );

  return new_anim;
}

void update_anim(Anim *ani) {
  ++ani->current;
  if ( ani->current == ani->loaded ) {
    ani->current = 0;
  }
}

void show_anim(Anim *ani, SDL_Surface *dest, SDL_Rect pos) {
  SDL_BlitSurface( ani->frames[ani->current], NULL, dest, &pos );
}
