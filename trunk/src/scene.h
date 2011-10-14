#ifndef FSTV_SCENE
#define FSTV_SCENE

#include <SDL.h>
#include "config.h"
#include "sdlutil.h"

typedef struct FSTV_Scene
{
  SDL_Surface *bg;
  SDL_Surface *dest;
} Scene;

void setup_scene(Scene *, const char *bg_file);
void draw_scene(Scene *);

#endif /* FSTV_SCENE */
