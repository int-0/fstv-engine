#include "scene.h"
#include "init.h"

#include <pspkernel.h>

int done = 0;

int exit_callback(int arg1, int arg2, void *common) {
  done = 1;
  return 0;
}

int CallbackThread(SceSize args, void *argp) {
  int cbid;
  cbid = sceKernelCreateCallback( "Exit Callback", exit_callback, NULL );
  sceKernelRegisterExitCallback( cbid );
  sceKernelSleepThreadCB();
  return 0;
}

int SetupCallbacks(void) {
  int thid = 0;
  thid = sceKernelCreateThread( "update_thread",
				CallbackThread, 0x11, 0xFA0, 0, 0 );
  if( thid >= 0 ) {
    sceKernelStartThread( thid, 0, 0 );
  }
  return thid;
}

int main(int argc, char** argv) {

  Context ct;
  Scene sc;

  SetupCallbacks();

  if ( init_ftve( &ct ) ) {
    
    create_scene( &sc, "boc_pantalla01.jpg" );
    setup_scene( ct, &sc );
    draw_scene( &sc);

    run_scene( &sc );

    shutdown_ftve();
  } else  {
    printf("Failed to start FSTV engine.\n");
  }
  return 0;
}
