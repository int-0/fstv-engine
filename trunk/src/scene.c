#include "scene.h"
#include "sdlutil.h"

void create_scene(Scene *sc, const char *filename) {
  sc->bg = load_image( filename );
}

void setup_scene(Context ct, Scene *sc) {
  sc->dest = ct.screen;
}

void draw_scene(Scene *sc) {
  SDL_Rect offset;
  offset.x = 0;
  offset.y = 0;

  SDL_BlitSurface( sc->bg, NULL, sc->dest, &offset);
}
