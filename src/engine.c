#include <SDL2/SDL.h>
#include <stdbool.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "engine.h"

typedef struct MainLoopParam {
  SDL_Renderer * renderer;
  bool setup_flag;
  bool quit_flag;
} MainLoopParam_t;

void main_loop(void *v_param);


void start_everything(SDL_Renderer *renderer) {
  MainLoopParam_t param = {
    .renderer = renderer,
    .setup_flag = true,
    .quit_flag = false
  };


  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop_arg(main_loop, &param, 0, 1);
  #else
  while (!param.quit_flag) {
    main_loop(&param);
  }
  #endif
}


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


