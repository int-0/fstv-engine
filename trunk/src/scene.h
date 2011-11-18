#ifndef FSTV_SCENE
#define FSTV_SCENE

#include <SDL.h>
#include "init.h"
#include "actor.h"
#include "player.h"

#define MAX_ACTORS 100
#define MAX_PLAYERS 4

#define DEAD 0
#define LIVE 1

typedef struct FSTV_Scene
{
  SDL_Surface *bg;
  SDL_Surface *dest;

  Actor actors[MAX_ACTORS];
  Player players[MAX_PLAYERS];

  int live_actor[MAX_ACTORS];
  int live_player[MAX_PLAYERS];
} Scene;

void create_scene(Scene *, const char *);
void setup_scene(Context , Scene *);
void update_scene(Scene *);
void draw_scene(Scene *);

void run_scene(Scene *);

int free_actor_slot(Scene *);
void add_actor(Scene *, Actor);

int free_player_slot(Scene *);
void add_player(Scene *, Player);

#endif /* FSTV_SCENE */
