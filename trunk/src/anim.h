#ifndef FSTV_ANIM
#define FSTV_ANIM

#include <SDL.h>

#define MAX_FRAMES 10

#define LOOP 0

typedef struct FSTV_Anim
{
  SDL_Surface *frames[MAX_FRAMES];
  int loaded;
  int current;
} Anim;

void add_frame_to(Anim *, const char *);
Anim create_anim(SDL_Surface *,
		 SDL_Rect initial_pos, const char *first_frame);
void show_anim(Anim *, SDL_Surface *, SDL_Rect);
void update_anim(Anim *);

#endif /* FSTV_ANIM */
