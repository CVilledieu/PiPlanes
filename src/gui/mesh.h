#ifndef MESH_H
#define MESH_H


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

Mesh* init_Mesh(MeshType type);

#endif