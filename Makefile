CC = gcc
CFLAGS = -Wall -Wextra -Wconversion -Wpedantic -Wformat=2 -Wno-unused-parameter\
					-Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -O3
BINOUT = build/main.exe


SRC = lib/getpath.c lib/whereami.c src/main.c src/sketch.c src/loop.c\
			src/once.c src/event.c src/MEOW.c


INC = -Iinclude
LIB = lib
SDL_LIB = -lSDL2 -lSDL2 -lSDL2_image
SDL_FILE = build\main.exe
DEFINE = -DSDL_MAIN_HANDLED -DSTB_RECT_PACK_IMPLEMENTATION\
				-DSTB_TRUETYPE_IMPLEMENTATION -DSTBTTF_IMPLEMENTATION\
				-DSTB_DS_IMPLEMENTATION

EMCC = emcc
EMOUT = index.js
EMFLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png", "jpg"]'
ASSETS = build/assets
EMFILE = index.data index.js index.wasm


.PHONY: default ems sdl run drm

default:
	echo try with ems or sdl

ems:
	$(EMCC) $(CFLAGS) $(DEFINE) -o $(EMOUT) $(EMFLAGS) --preload-file $(ASSETS) \
	$(SRC) $(INC) -isystem $(LIB)

sdl:
	$(CC) $(CFLAGS) $(DEFINE) $(SRC) -o $(BINOUT) $(SDL_LIB) $(INC) -isystem \
	$(LIB)

run:
	build/main.exe

drm:
	drmemory build/main.exe

clean:
	del /f $(SDL_FILE) $(EMFILE)
