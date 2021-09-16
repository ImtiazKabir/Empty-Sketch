#include <SDL2/SDL.h>
#include "engine.h"

void draw(SDL_Renderer * renderer) {
  if (SDL_SetRenderDrawColor(renderer, 55, 55, 55, 255) == -1) {
    __PRINT_ERROR__("Setting the background color with SDL_SetRenderDrawColor");
  }
  if (SDL_RenderClear(renderer) == -1) {
    __PRINT_ERROR__("Clearing the window for background with SDL_RenderClear");
  }
}


void update(void) {}
