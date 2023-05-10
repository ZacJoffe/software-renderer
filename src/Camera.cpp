#include "Camera.h"

#include <SDL2/SDL_render.h>
#include <limits>
#include <utility>
#include <vector>

// DELETEME
#include <iostream>

using namespace camera_constants;

Camera::Camera(const glm::vec3 & pos, const glm::vec3 & front) :
    m_pos(pos), m_front(front), m_fovy(DEFAULT_FOVY), m_up(glm::vec3(0.0f, 1.0f, 0.0f)) {}

void Camera::castRays(const SDLContext & sdl_context, const uint nx, const uint ny, const std::vector<std::unique_ptr<Mesh>> & meshes) const {
    const float d = (static_cast<float>(ny) / 2.0f) / glm::tan(glm::radians(m_fovy / 2.0f));
    const glm::vec2 pixel_tl(-static_cast<float>(nx) / 2.0f, static_cast<float>(ny) / 2.0f);

    const glm::vec3 vz = m_front;
    const glm::vec3 vx = glm::normalize(glm::cross(vz, m_up));
    const glm::vec3 vy = glm::cross(vx, vz); // TODO normalize?
    // const glm::mat4 view = glm::lookAt(m_pos, m_pos + m_front, m_up);

    std::vector<std::vector<glm::vec3>> colors(ny);

    for (uint y = 0; y < ny; ++y) {
        std::vector<glm::vec3> colors_row(nx);

        for (uint x = 0; x < nx; ++x) {
            const glm::vec2 pixel(pixel_tl.x + x, pixel_tl.y - y);
            const glm::vec3 direction = d * vz + pixel.x * vx + pixel.y * vy;

            const Ray ray(m_pos, direction);
            if (const auto intersection_context = calculateClosestIntersection(ray, meshes)) {
                // shade based on mesh material
                colors_row[x] = intersection_context->second;
            } else {
                // shade background
                colors_row[x] = glm::vec3(0.0f, 0.0f, 0.0f);
            }
        }

        colors[y] = std::move(colors_row); // TODO move needed?
    }

    for (uint y = 0; y < ny; ++y) {
        for (uint x = 0; x < nx; ++x) {
            SDL_SetRenderDrawColor(sdl_context.renderer, colors[y][x].r, colors[y][x].g, colors[y][x].b, 255);
            SDL_RenderDrawPoint(sdl_context.renderer, x, y); // TODO explicit cast from uint to int?
        }
    }
}

std::optional<std::pair<float, glm::vec3>> Camera::calculateClosestIntersection(const Ray & ray, const std::vector<std::unique_ptr<Mesh>> & meshes) const {
    float t_min = std::numeric_limits<float>::max();
    glm::vec3 color;

    for (const auto & mesh : meshes) {
        if (const auto t = mesh->testIntersection(ray); t < t_min) {
            t_min = *t;
            color = mesh->material->getColor();
        }
    }

    return t_min == std::numeric_limits<float>::max() ? std::nullopt : std::optional<std::pair<float, glm::vec3>>(std::make_pair(t_min, color));
}
