#ifndef FSTV_SCENE
#define FSTV_SCENE

#include <SDL.h>
#include "init.h"
#include "actor.h"

#define MAX_ACTORS 100

#define DEAD 0
#define LIVE 1

typedef struct FSTV_Scene
{
  SDL_Surface *bg;
  SDL_Surface *dest;

  Actor actors[MAX_ACTORS];
  int live[MAX_ACTORS];
} Scene;

void create_scene(Scene *, const char *);
void setup_scene(Context , Scene *);
void update_scene(Scene *);
void draw_scene(Scene *);

void run_scene(Scene *);

int free_actor_slot(Scene *);
void add_actor(Scene *, Actor);

#endif /* FSTV_SCENE */
