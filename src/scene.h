#ifndef FSTV_SCENE
#define FSTV_SCENE

#include <SDL.h>
#include "pc/config.h"
#include "common/sdlutil.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  typedef struct FSTV_Scene
  {
    SDL_Surface *bg;
    SDL_Surface *dest;
  } Scene;
  
  extern setup_scene(scene *, string bg_file);
  extern draw_scene(scene *);

#ifdef __cplusplus
}
#endif

#endif /* FSTV_SCENE */
