#include <SDL2/SDL.h>
#include <stdbool.h>

#include "engine.h"

bool event_handler(void) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return true;
    }
  }
  return false;
}
