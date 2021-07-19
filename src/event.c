#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#include "engine_core.h"


bool event_handler() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return true;
    }
  }
  return false;
}
