#include "Scene.h"

#include "common.h"
#include "materials.h"

#include <memory>
#include <stdexcept>

Scene::Scene() {}

// returns camera starting position
glm::vec2 Scene::parseScene() {
    const glm::vec2 default_start(-1, -1);
    glm::vec2 start_pos = default_start;

    for (uint z = 0; z < 10; ++z) {
        for (uint x = 0; x < 10; ++x) {
            switch (WORLD[z][x]) {
                case none:
                    break;
                case block:
                    m_meshes.push_back(std::make_unique<Block>(glm::vec2(x, z), std::make_unique<BlueMaterial>()));
                    break;
                case start:
                    start_pos = glm::vec2(x, z);
                    break;
                default: // TODO test this
                    throw std::runtime_error("Invalid block code");
            }
        }
    }

    if (start_pos == default_start) {
        throw std::runtime_error("Scene must have starting block definition");
    }

    return start_pos;
}

// std::vector<std::unique_ptr<Mesh>> Scene::getMeshes() const {
//     return m_meshes;
// }

void Scene::draw(const SDLContext & sdl_context, const std::unique_ptr<Camera> & camera) {
    // TODO replace hardcoded resolution
    camera->castRays(sdl_context, 640, 480, m_meshes);
}
