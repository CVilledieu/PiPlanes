#ifndef SHADERS_H
#define SHADERS_H

#define BASIC_VERTEX_FILE "shaders/basic.vert.glsl"
#define BASIC_FRAGMENT_FILE "shaders/basic.frag.glsl"

// Uniform Names
#define UN_VIEW "un_view"
#define UN_MODEL "un_model"
#define UN_PROJECTION "un_projection"
#define UN_COLOR "un_color"

// Had used this for uniform struct, but found it unnecessary
//Leaving in, because I feel it could be useful later. 
typedef enum {
    VEC2,
    VEC3,
    VEC4,
    MAT3,
    MAT4    
} DataType;

typedef enum {
    VIEW,
    MODEL,
    PROJECTION,
    COLOR,
    UNIFORM_TYPE_COUNT
} UniformType;

typedef struct {
    unsigned int location;
    UniformType un_type;
} UniformInfo;

typedef enum {
    BASIC, 
    GLYPH, //Text rendering shader, but could also be used for all textured rendering
    SHADER_TYPE_COUNT
} ShaderType;

typedef struct {
    unsigned int id;
    int uniform_count;
    ShaderType type;
    UniformInfo uniforms[UNIFORM_TYPE_COUNT];
} ShaderProgram;

void init_shader_program(ShaderProgram* sp);
void set_uniform_data(UniformInfo* uni, void* data);


#endif