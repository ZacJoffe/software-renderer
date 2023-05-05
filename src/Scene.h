#pragma once

#include "Mesh.h"
#include <array>
#include <vector>
#include <glm/glm.hpp>

// TODO refactor this into a file
// TODO this should be much bigger
static const std::array<std::array<MeshType, 10>, 10> WORLD = [
    /*
       x--->
    z
    |
    |
    |
    v
     */
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 2, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
]; // TODO reverse so that origin is at at bottom left

class Scene {
public:
    Scene();

    glm::vec2 parseScene();

private:
    std::vector<Mesh> m_meshes;
};
