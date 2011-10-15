#include "scene.h"
#include "init.h"

int main(int argc, char** argv) {

  Context ct;
  Scene sc;

  if ( init_ftve( &ct ) ) {
    
    create_scene( &sc, "boc_pantalla01.jpg" );
    setup_scene( ct, &sc );
    draw_scene( &sc);

    SDL_Flip( ct.screen );

    run_scene( &sc );

    shutdown_ftve();
  } else  {
    printf("Failed to start FSTV engine.\n");
  }
  return 0;
}
