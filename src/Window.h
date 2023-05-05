#pragma once
#include <SDL2/SDL.h>

struct SDLContext {
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Event event;
};

class Window {
public:
    // TODO make this a singleton
    Window();

    void launch();

private:
    void run();
    void init();
    bool pollInputs(); // returns true if quit
    void appLogic();
    void draw();

    SDLContext m_sdl_context;
};
