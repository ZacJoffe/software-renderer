#pragma once

// TODO use this with a mesh factory to create a concrete mesh type that we will use in the scene
enum MeshType {
    None,
    Block,
    Start,
};

class Mesh; // TODO (should also be pure virtual)

class Block : public Mesh {
    // TODO
};
