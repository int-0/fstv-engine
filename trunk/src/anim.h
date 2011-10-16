#ifndef FSTV_ANIM
#define FSTV_ANIM

#include <SDL.h>

#define MAX_FRAMES 10

#define LOOP 0
#define NOLOOP 1

typedef struct FSTV_Anim
{
  SDL_Surface *frames[MAX_FRAMES];
  int loaded;
  int current;
  int mode;
} Anim;

void add_frame_to(Anim *, const char *);
void show_anim(Anim *, SDL_Rect *, SDL_Surface *);
void update_anim(Anim *);

#endif /* FSTV_ANIM */
