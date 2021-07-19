#ifndef D07D45CE_AA78_4D49_B29A_EBD0B6BCD4AD
#define D07D45CE_AA78_4D49_B29A_EBD0B6BCD4AD

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "internal_stuff.h"

#define TITLE_OF_WINDOW "TITLE OF WINDOW"
#define WIDTH (int)500
#define HEIGHT (int)500
#define FPS (uint32_t)60

void main_loop(void *v_renderer);
bool event_handler();
void setup();
void update();
void draw(SDL_Renderer *renderer);
void clean_up();

#endif /* D07D45CE_AA78_4D49_B29A_EBD0B6BCD4AD */
