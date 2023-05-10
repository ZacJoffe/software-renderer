#pragma once

#include <glm/glm.hpp>

struct Material {
    virtual glm::vec3 getColor() const = 0;
};

struct BlueMaterial : public Material {
    glm::vec3 getColor() const {
        return glm::vec3(0.0f, 0.0f, 1.0f);
    }
};

// TODO more materials
