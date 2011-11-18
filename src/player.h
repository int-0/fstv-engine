#ifndef FSTV_PLAYER
#define FSTV_PLAYER

#include "anim.h"
#include <SDL.h>

#define STANDBY  0
#define FIRING   1
#define UP       2
#define DOWN     4
#define LEFT     8
#define RIGHT   16

#define MAX_ACTIONS 32

typedef struct FSTV_Player
{
  Anim uactions[MAX_ACTIONS];
  Anim dactions[MAX_ACTIONS];
  int current_uaction;
  int current_daction;
  int xd_ofs;
  int yd_ofs;
  SDL_Rect position;
  SDL_Surface *dest;
} Player;

void draw_player(Player *player);
void update_player(Player *player);

#endif /* FSTV_PLAYER */
