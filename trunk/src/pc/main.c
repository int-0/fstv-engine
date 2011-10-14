#include "scene.h"
#include "init.h"

int main(int argc, char** argv) {

  Context *ct;

  init_ftve( ct );
  shutdown_ftve();

  return 0;
}
