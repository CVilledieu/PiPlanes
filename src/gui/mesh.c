#include "mesh.h"
#include "glad/glad.h"


Mesh* create_mesh(float* vertices, size_t vert_size, unsigned int* indices, size_t ind_size){
    unsigned int EBO, VBO;
    Mesh* mesh = malloc(sizeof(Mesh));
    glGenVertexArrays(1, &mesh->VAO);
    glGenBuffers(1, VBO);
    glGenBuffers(1, EBO);

    glBindVertexArray(mesh->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vert_size, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, ind_size, indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    mesh->index_count = ind_size / sizeof(unsigned int);
    return mesh;
}