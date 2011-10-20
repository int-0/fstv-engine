#include "actor.h"
#include "anim.h"

void draw_actor(Actor *actor) {
  show_anim(&actor->actions[actor->current_action],
	    actor->dest,
	    actor->position);
}

void update_actor(Actor *actor) {
  update_anim(&actor->actions[actor->current_action]);
}


