#pragma once
#include "Camera.h"
#include "common.h"
#include "Ray.h"
#include "Scene.h"
#include "SDLContext.h"

#include <memory>

class Window {
public:
    // TODO make this a singleton
    Window(uint width, uint height);

    void launch();

private:
    void run();
    void initSDL();
    void initWorld();

    bool pollInputs(); // returns true if quit
    void appLogic();
    void draw();

    SDLContext m_sdl_context;
    uint m_width;
    uint m_height;

    std::unique_ptr<Camera> m_camera;
    std::unique_ptr<Scene> m_scene;
};
