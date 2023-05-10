#include "Mesh.h"

Block::Block(const glm::vec2 & pos, const std::unique_ptr<Material> & material) {
    // TODO
}

std::optional<float> Block::testIntersection(const Ray & ray) const {
    // TODO https://gamedev.stackexchange.com/questions/18436/most-efficient-aabb-vs-ray-collision-algorithms
    return {};
}
