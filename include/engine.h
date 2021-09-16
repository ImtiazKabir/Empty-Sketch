#ifndef ENGINE_FOR_EMS_SDL
#define ENGINE_FOR_EMS_SDL

#include <SDL2/SDL.h>  /* SDL_Renderer */
#include <stdint.h> /* uint32_t */

#include "internal_stuff.h"

#define TITLE_OF_WINDOW "TITLE OF WINDOW"
#define WIDTH (int)500
#define HEIGHT (int)500
#define FPS (uint32_t)60

void main_loop(void * v_renderer);
bool event_handler(void); /* event.c */
void setup(void);   /* once.c */
void clean_up(void);  /* once.c */
void update(void);  /* loop.c */
void draw(SDL_Renderer * renderer);  /* loop.c */

#endif /* ENGINE_FOR_EMS_SDL */
