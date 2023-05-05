#pragma once
#include "Camera.h"
#include "common.h"
#include "Ray.h"

#include <SDL2/SDL.h>

struct SDLContext {
    SDL_Window * window; // TODO unique ptrs
    SDL_Renderer * renderer;
    SDL_Event event;
};

class Window {
public:
    // TODO make this a singleton
    Window(uint width, uint height);

    void launch();

private:
    void run();
    void init();

    bool pollInputs(); // returns true if quit
    void appLogic();
    void draw();

    SDLContext m_sdl_context;
    uint m_width;
    uint m_height;

    Camera m_camera;
};
