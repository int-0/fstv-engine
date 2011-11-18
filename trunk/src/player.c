#include "player.h"
#include "anim.h"

#include <SDL.h>

void draw_player(Player *player) {
  /* Calculate bottom sprite position */
  SDL_Rect dpos;
  dpos.x = player -> position.x + player -> xd_ofs;
  dpos.y = player -> position.y + player -> yd_ofs;
  dpos.w = player -> position.w;
  dpos.h = player -> position.h;
  /* first: bottom */
  show_anim(&player->dactions[player->current_daction],
	    player->dest,
	    dpos);
  /* second: up */
  show_anim(&player->uactions[player->current_uaction],
	    player->dest,
	    player->position);
}

void update_player(Player *player) {
  update_anim(&player->uactions[player->current_uaction]);
  update_anim(&player->dactions[player->current_daction]);
}


