#define STB_RECT_PACK_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION
#define STBTTF_IMPLEMENTATION

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "engine.h"
#include "param.h"


void main_loop(void *v_param) {
  // setup part
  MainLoopParam_t * param = (MainLoopParam_t *) v_param;
  if (param->setup_flag) {
    setup();
    param->setup_flag = false;
  }

  // handle event
  if (event_handler()) {
    clean_up();
    #ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();
    #else
    param->quit_flag = true;
    return;
    #endif /* __EMSCRIPTEN__ */
  }

  // update and draw
  update();

  SDL_Renderer * renderer = param->renderer;
  draw(renderer);
  SDL_Delay(1000 / FPS);
  SDL_RenderPresent(renderer);
}


