#pragma once

#include <glm/glm.hpp>

struct Ray {
    glm::vec3 e; // start position
    glm::vec3 d; // direction of ray

    Ray(const glm::vec3 & e, const glm::vec3 & d) :
        e(e), d(d) {}

    glm::vec3 operator()(float t) const {
        return e + t * d;
    };
};
