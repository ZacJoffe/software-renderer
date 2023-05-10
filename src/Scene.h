#pragma once

#include "common.h"
#include "Mesh.h"
#include "Camera.h"
#include "SDLContext.h"

#include <glm/glm.hpp>
#include <memory>
#include <vector>

// TODO refactor this into a file
// TODO this should be much bigger
static constexpr uint WORLD[10][10] = {
    /*
       x--->
    z
    |
    |
    |
    v
     */
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 2, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
}; // TODO reverse so that origin is at at bottom left

class Scene {
public:
    Scene();

    glm::vec2 parseScene();
    // std::vector<std::unique_ptr<Mesh>> getMeshes() const;
    void draw(const SDLContext & sdl_context, const std::unique_ptr<Camera> & camera);

private:
    std::vector<std::unique_ptr<Mesh>> m_meshes;
};
