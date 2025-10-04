#ifndef MESH_H
#define MESH_H

#define BASIC_TRIANGLE_VERT float[9] {0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f,  0.0f, 0.5f, 0.0f}

typedef enum {
    MESH_TRIANGLE,
    MESH_SQUARE, 
    MESH_LINE,
    MESH_GLYPH,
    MESH_TYPE_COUNT
} MeshType;

typedef struct {
    unsigned int VAO;
    MeshType type;
    unsigned int index_count;
} Mesh;


#endif