#pragma once

#include "common.h"
#include "Mesh.h"

#include <glm/glm.hpp>
#include <vector>

// TODO refactor this into a file
// TODO this should be much bigger
static const uint WORLD[10][10] = {
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

private:
    std::vector<Mesh> m_meshes;
};
