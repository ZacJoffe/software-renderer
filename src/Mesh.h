#pragma once

#include "Ray.h"
#include "materials.h"

#include <glm/glm.hpp>
#include <optional>
#include <memory>

// TODO use this with a mesh factory to create a concrete mesh type that we will use in the scene
enum MeshType {
    none,
    block,
    start,
};

struct Mesh {
    std::unique_ptr<Material> material;
    virtual std::optional<float> testIntersection(const Ray & ray) const = 0;
};

class Block : public Mesh {
public:
    Block(const glm::vec2 & pos, const std::unique_ptr<Material> & material);

    std::optional<float> testIntersection(const Ray & ray) const override;

private:
    // glm::vec3 m_pos; // center?
    glm::vec3 m_min;
    glm::vec3 m_max;
};
