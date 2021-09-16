#ifndef ENIGNE_PARAM_H
#define ENGINE_PARAM_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct MainLoopParam {
  SDL_Renderer * renderer;
  bool setup_flag;
  bool quit_flag;
} MainLoopParam_t;

#endif /* ENGINE_PARAM_H */