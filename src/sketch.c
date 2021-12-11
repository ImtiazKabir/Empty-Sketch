#include <SDL2/SDL.h>
#include <stdbool.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "sketch.h"

typedef struct MainLoopParam {
  SDL_Renderer * renderer;
  bool quit_flag;
  int const WIDTH;
  int const HEIGHT;
  int const FPS;
} MainLoopParam_t;

void main_loop(void *v_param);


void MEOW_Repeat(
  SDL_Renderer *renderer,
  int const WIDTH,
  int const HEIGHT,
  int const FPS
) {
  /* Definition and setting variables for sketch */
  setup();

  MainLoopParam_t param = {
    .renderer = renderer,
    .quit_flag = false,
    .WIDTH = WIDTH,
    .HEIGHT = HEIGHT,
    .FPS = FPS
  };

  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop_arg(main_loop, &param, 0, 1);
  #else
  while (!param.quit_flag) {
    main_loop(&param);
  }
  #endif

  /* cleaning up sekcth "things" */
  clean_up();
}


void main_loop(void *v_param) {
  MainLoopParam_t * param = (MainLoopParam_t *) v_param;

  /* handle event */
  if (event_handler()) {
    #ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();
    #else
    param->quit_flag = true;
    return;
    #endif /* __EMSCRIPTEN__ */
  }

  /* update and draw */
  update();

  draw(param->renderer);
  SDL_Delay(1000 / (unsigned)param->FPS);
  SDL_RenderPresent(param->renderer);
}


