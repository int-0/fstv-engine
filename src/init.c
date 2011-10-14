#include "init.h"

#ifdef FSTV_LINUX
#include "pc/config.h"
#endif

int init_ftve(Context *ct) {

  if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1) {
    return -1;
  }
      
  ct->screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
  				 SDL_SWSURFACE );

  if ( ct->screen == NULL ) {
    return -1;
  }				 

  SDL_WM_SetCaption( "FSTV Engine", NULL );

  return 0;
}

int shutdown_ftve() {
  SDL_Quit();
  return 0;
}
