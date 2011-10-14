#ifndef FSTV_INIT
#define FSTV_INIT

#include <SDL.h>

typedef struct FSTV_Context
{
  SDL_Surface *screen;
} Context;

int init_ftve(Context *ct);
int shutdown_ftve();

#endif /* FSTV_INIT */
