#ifndef FSTV_SCENE
#define FSTV_SCENE

#include <SDL.h>
#include "init.h"

typedef struct FSTV_Scene
{
  SDL_Surface *bg;
  SDL_Surface *dest;
} Scene;

void create_scene(Scene *, const char *);
void setup_scene(Context , Scene *);
void draw_scene(Scene *);

void run_scene(Scene *);

#endif /* FSTV_SCENE */