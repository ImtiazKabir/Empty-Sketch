#define STB_RECT_PACK_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION
#define STBTTF_IMPLEMENTATION

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef USING_EMSCRIPTEN
#include <emscripten.h>
#endif

#include "engine_core.h"

void main_loop(void *v_renderer) {
  SDL_Renderer *renderer = (SDL_Renderer *)v_renderer;


  // setup part
  static bool __run_setup__ = true;
  if (__run_setup__) {
    setup();
    __run_setup__ = false;
  }

  // handle event
  if (event_handler()) {
    clean_up();
#ifdef USING_EMSCRIPTEN
    emscripten_cancel_main_loop();
#else
    __quit_window__ = true;
    return;
#endif
  }

  // update and draw
  update();
  draw(renderer);
  SDL_Delay(1000 / FPS);
  SDL_RenderPresent(renderer);
}
