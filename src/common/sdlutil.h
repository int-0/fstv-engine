#ifndef SDL_UTIL
#define SDL_UTIL


#include <SDL.h>
#include <SDL_image.h>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

extern SDL_Surface *load_image( std::string filename );

#ifdef __cplusplus
}
#endif

#endif /* SDL_UTIL */

