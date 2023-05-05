#include "Scene.h"
#include "common.h"

#include <stdexcept>

Scene::Scene() {}

// returns camera starting position
glm::vec2 Scene::parseScene() {
    // TODO

    const glm::vec2 default_start(-1, -1);
    glm::vec2 start_pos = default_start;

    for (uint z = 0; z < 10; ++z) {
        for (uint x = 0; x < 10; ++x) {
            switch (WORLD[z][x]) {
                case None:
                    break;
                case Block:
                    // TODO
                    break;
                case Start:
                    start_pos = glm::vec2(x, z);
                    break;
                default: // TODO test this
                    throw std::runtime_exception("Invalid block code");
            }
        }
    }

    if (start_pos == default_start) {
        throw std::runtime_exception("Scene must have starting block definition");
    }

    return start_pos;
}
