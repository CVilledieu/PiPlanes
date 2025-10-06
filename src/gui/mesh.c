#include "mesh.h"
#include "glad/glad.h"


static const float SQUARE_VERT[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};

static const unsigned int SQUARE_INDEX[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};
static const unsigned int SQUARE_INDEX_COUNT = 6;

static const float TRIANGLE_VERT[] = {
     0.5f, -0.5f, 0.0f,  
    -0.5f, -0.5f, 0.0f,   
     0.0f,  0.5f, 0.0f   
};


void create_Mesh(Mesh* mesh);

Mesh* init_Mesh(MeshType type){
    Mesh* mesh = malloc(sizeof(Mesh));
    mesh->type = type;
    mesh->VAO = 0;
    mesh->index_count = 0;
    return mesh;
}

void create_Mesh(Mesh* mesh){
    switch(mesh->type){
        case MESH_TRIANGLE:
            create_TRIANGLE(mesh);
            break;
        case MESH_SQUARE:
            create_SQUARE(mesh);
            break;
        default:
            //Handle error
            break;
    }
}


void create_SQUARE(Mesh* mesh){
    unsigned int EBO, VBO;
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

void create_TRIANGLE(Mesh* mesh){
    unsigned int VBO;
    glGenVertexArrays(1, &mesh->VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(mesh->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, TRIANGLE_VERT_SIZE, TRIANGLE_VERT, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    mesh->index_count = 3;
}