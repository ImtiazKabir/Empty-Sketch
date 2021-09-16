#ifndef INTERNAL_STUFF_FOR_MY_ENGINE
#define INTERNAL_STUFF_FOR_MY_ENGINE

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

/* Internal variables of the sketch, should not be changed */

#ifndef __EMSCRIPTEN__
extern bool __quit_window__;
#endif

static inline void __PRINT_ERROR__(char const * const func_name) {
  fprintf(stderr, "%s did not work\n---------------\n%s\n\n\n\n",
                    func_name, SDL_GetError());
  SDL_ClearError();
}

static inline void __CONSOLE_PRINT__(char const * const msg) {
  fprintf(stderr, "--> %s\n\n\n\n", msg);
}

static inline void __PROGRAM_REACHED__(void) {
  fprintf(stderr, "__PROGRAM_REACHED__ successful\n\n\n\n");
}

char *__get_path__(char const * const child);  /* lib/getpath.c */

#endif /*INTERNAL_STUFF_FOR_MY_ENGINE*/
