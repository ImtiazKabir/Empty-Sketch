#ifndef ENGINE_MECHANISM_H
#define ENGINE_MECHANISM_H

#include <SDL2/SDL.h>

void init_everything(SDL_Window **window, SDL_Renderer **renderer);
void start_everything(SDL_Renderer *renderer); /* engine.c */
void clean_everything(SDL_Window *window, SDL_Renderer *renderer);

#endif /* ENGINE_MECHAISM_H */
