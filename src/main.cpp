#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdexcept>
#include <string>

struct SDLContext {
    SDL_Window * window;
    SDL_Renderer * renderer;
};

SDLContext init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        const std::string err(SDL_GetError());
        throw std::runtime_error("SDL could not initialize! SDL Error: " + err);
    }

    SDL_Window * window = SDL_CreateWindow("raycaster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (!window) {
        const std::string err(SDL_GetError());
        throw std::runtime_error("Window could be not created! SDL Error: " + err);
    }

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, NULL);
    if (!renderer) {
        const std::string err(SDL_GetError());
        throw std::runtime_error("Renderer could not be created! SDL Error: " + err);
    }

    return SDLContext {
        window,
        renderer
    };
}

int main() {
    const SDLContext context = init();
    for (;;) {}

    return 0;
}
