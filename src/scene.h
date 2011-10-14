#ifndef FSTV_SCENE
#define FSTV_SCENE

#include <SDL.h>
#include "config.h"
#include "sdlutil.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  typedef struct FSTV_Scene
  {
    SDL_Surface *bg;
    SDL_Surface *dest;
  } Scene;
  
  extern void setup_scene(Scene *, const char *bg_file);
  extern void draw_scene(Scene *);

#ifdef __cplusplus
}
#endif

#endif /* FSTV_SCENE */
