#ifndef FSTV_ACTOR
#define FSTV_ACTOR

#include "anim.h"
#include <SDL.h>

#define MAX_ACTIONS 10

typedef struct FSTV_Actor
{
  Anim *actions[MAX_ACTIONS];
  int current_action;
  SDL_Rect position;
  SDL_Surface *dest;
} Actor;

void draw_actor(Actor *actor);
void update_actor(Actor *actor);

#endif /* FSTV_ACTOR */
