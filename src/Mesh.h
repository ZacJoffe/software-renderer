#pragma once

#include "Ray.h"
#include <glm/glm.hpp>

// TODO use this with a mesh factory to create a concrete mesh type that we will use in the scene
enum MeshType {
    None,
    Block,
    Start,
};

struct Mesh {
    virtual bool testCollision(const Ray & ray) const = 0;
};

class Block : public Mesh {
public:
    Block(const glm::vec2 & pos);

    // TODO https://gamedev.stackexchange.com/questions/18436/most-efficient-aabb-vs-ray-collision-algorithms
    bool testCollision(const Ray & ray) const override;

private:
    // glm::vec3 m_pos; // center?
    glm::vec3 m_min;
    glm::vec3 m_max;
};
