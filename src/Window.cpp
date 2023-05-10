#include "Window.h"

#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <stdexcept>
#include <string>

// DELETEME
#include <iostream>

Window::Window(uint width, uint height) :
    m_width(width), m_height(height) {}

void Window::launch() {
    run();
}

void Window::run() {
    initSDL();
    initWorld();

    for (;;) {
        if (pollInputs()) {
            break;
        }

        appLogic();
        draw();
    }

    SDL_DestroyRenderer(m_sdl_context.renderer);
    SDL_DestroyWindow(m_sdl_context.window);
    SDL_Quit();
}

void Window::initSDL() {
    m_sdl_context = SDLContext();

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        const std::string err(SDL_GetError());
        throw std::runtime_error("SDL could not initialize! SDL Error: " + err);
    }

    m_sdl_context.window = SDL_CreateWindow(
        "raycaster",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_width,
        m_height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );
    if (!m_sdl_context.window) {
        const std::string err(SDL_GetError());
        throw std::runtime_error("Window could be not created! SDL Error: " + err);
    }

    m_sdl_context.renderer = SDL_CreateRenderer(m_sdl_context.window, -1, 0);
    if (!m_sdl_context.renderer) {
        const std::string err(SDL_GetError());
        throw std::runtime_error("Renderer could not be created! SDL Error: " + err);
    }
}

void Window::initWorld() {
    m_scene = std::make_unique<Scene>();
    const glm::vec2 camera_pos = m_scene->parseScene();

    m_camera = std::make_unique<Camera>(
        glm::vec3(camera_pos.x, 1.0f, camera_pos.y),
        glm::vec3(0.0f, 0.0f, -1.0f)
    );
}

bool Window::pollInputs() {
    while (SDL_PollEvent(&m_sdl_context.event)) {
        switch (m_sdl_context.event.type) {
            case SDL_KEYDOWN:
                switch (m_sdl_context.event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        return true;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                break;
            default:
                break;
        }
    }

    return false;
}

void Window::appLogic() {
    // TODO
}

void Window::draw() {
    SDL_SetRenderDrawColor(m_sdl_context.renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_sdl_context.renderer);

    // for (uint x = 0; x < m_width; ++x) {
    //     for (uint y = 0; y < m_height; ++y) {
    //     }
    // }
    m_scene->draw(m_sdl_context, m_camera);
}
