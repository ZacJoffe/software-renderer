#pragma once
#include <SDL2/SDL.h>

struct SDLContext {
    SDL_Window * window; // TODO unique ptrs
    SDL_Renderer * renderer;
    SDL_Event event;
};
