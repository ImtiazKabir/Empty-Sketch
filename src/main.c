#include <SDL2/SDL.h>
#include "mechanism.h"

int main(void) {
  SDL_Window * window;
  SDL_Renderer * renderer;
  init_everything(&window, &renderer);
  start_everything(renderer);
  clean_everything(window, renderer);
  return 0;
}
