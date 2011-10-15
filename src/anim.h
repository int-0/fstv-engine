#ifndef FSTV_ANIM
#define FSTV_ANIM

#include <SDL.h>

#define MAX_FRAMES 5

#define LOOP 0
#define NOLOOP 1

typedef struc FSTV_Anim
{
  SDL_Surface frames[MAX_FRAMES];
  int loaded;
  int current;
  int mode;
} Anim;

void add_frame_to(Anim *, const char *);
void show_anim(Anim *, SDL_Rect *, SDL_Surface *);

#endif /* FSTV_ANIM */
