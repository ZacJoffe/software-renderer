#pragma once

#include "Mesh.h"
#include "SDLContext.h"
#include <glm/glm.hpp>
#include <memory>
#include <vector>
#include <optional>
#include <utility>
#include "common.h"

namespace camera_constants {
    const static uint DEFAULT_FOVY = 90.0f;
}

class Camera {
public:
    Camera(const glm::vec3 & pos, const glm::vec3 & front);

    void castRays(const SDLContext & sdl_context, const uint nx, const uint ny, const std::vector<std::unique_ptr<Mesh>> & meshes) const; // TODO const?

private:
    std::optional<std::pair<float, glm::vec3>> calculateClosestIntersection(const Ray & ray, const std::vector<std::unique_ptr<Mesh>> & meshes) const;

    glm::vec3 m_pos;
    glm::vec3 m_front;
    glm::vec3 m_up;

    uint m_fovy;
};
