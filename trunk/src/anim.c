#include "anim.h"
#include "sdlutil.h"

void add_frame_to(Anim *ani, const char *frame) {
  if ( ani->loaded == MAX_FRAMES ) {
    return;
  }
  ani->frames[ani->loaded] = load_image( frame );
  ++ani->loaded;
}

void update_anim(Anim *ani) {
  ++ani->current;
  if ( ani->current >= ani->loaded ) {
    switch ( ani->mode ) {
    case LOOP:
      ani->current = 0;
      break;
    case NOLOOP:
      ani->current = ani->loaded;
      break;
    }
  }
}

void show_anim(Anim *ani, SDL_Rect *ofs, SDL_Surface *dest) {
  SDL_BlitSurface( ani->frames[ani->current], NULL, dest, ofs );
}

