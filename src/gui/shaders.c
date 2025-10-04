#include "shaders.h"
#include <stdlib.h>
#include <stdio.h>
#include "glad/glad.h"

unsigned int init_program();
static void load_shader(const char* fname, GLenum type);
static unsigned int load_shader_file(const char* fname, GLenum type);
static void create_UniformInfo(ShaderProgram* sp);

ShaderProgram* create_shader_program(void){
    ShaderProgram* sp = malloc(sizeof(ShaderProgram));
    if(!sp){
        return NULL;
    }
        
    sp->id = init_program();
    sp->uniform_count = 0;
    create_UniformInfo(sp);

    return sp;
}

unsigned int init_program(){
    unsigned int vertex_shader, fragment_shader, sp_id, ok;
    fragment_shader = load_shader_file(FRAGMENT_SHADER_FILE, GL_FRAGMENT_SHADER);
    vertex_shader = load_shader_file(VERTEX_SHADER_FILE, GL_VERTEX_SHADER);
    sp_id = glCreateProgram();
    glAttachShader(sp_id, vertex_shader);
    glAttachShader(sp_id, fragment_shader);
    glLinkProgram(sp_id);

    // Check for linking errors
    int ok;
    char infoLog[512];
    glGetProgramiv(sp_id, GL_LINK_STATUS, &ok);
    if(!ok){
        glGetProgramInfoLog(sp_id, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    return sp_id;
}

static unsigned int load_shader_file(const char* fname, GLenum type){
    
    unsigned int shader = glCreateShader(type);
	FILE *fp;
	fp = fopen(fname, "rb");
	if (fp == NULL){
			printf("%s\n", "failed to open shader file");
			glfwTerminate();
		}

	fseek(fp, 0, SEEK_END);
	long length = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *Src = (char *)malloc(length + 1);
	fread(Src, 1, length, fp);
	Src[length] = '\0';
	fclose(fp);

	const char *shSrc = Src;

	glShaderSource(shader, 1, &shSrc, NULL);
	glCompileShader(shader);

	int ok = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
	if(!ok){
		glDeleteShader(shader);
		printf("%s\n", "Shader failed to compile");
		glfwTerminate();
	}
	free(Src);
	return shader;
}

static void create_UniformInfo(ShaderProgram* sp){
    sp->uniforms[VIEW].location = glGetUniformLocation(sp->id, UN_VIEW);
    sp->uniforms[VIEW].un_type = VIEW;
    sp->uniform_count++;

    sp->uniforms[MODEL].location = glGetUniformLocation(sp->id, UN_MODEL);
    sp->uniforms[MODEL].un_type = MODEL;
    sp->uniform_count++;

    sp->uniforms[PROJECTION].location = glGetUniformLocation(sp->id, UN_PROJECTION);
    sp->uniforms[PROJECTION].un_type = PROJECTION;
    sp->uniform_count++;

    sp->uniforms[COLOR].location = glGetUniformLocation(sp->id, UN_COLOR);
    sp->uniforms[COLOR].un_type = COLOR;
    sp->uniform_count++;
}

void set_uniform_data(UniformInfo* uni, void* data){
    switch(uni->un_type){
        case VIEW:
            glUniformMatrix4fv(uni->location, 1, GL_FALSE, (float*)data);
            break;
        case MODEL:
            glUniformMatrix4fv(uni->location, 1, GL_FALSE, (float*)data);
            break;
        case PROJECTION:
            glUniformMatrix4fv(uni->location, 1, GL_FALSE, (float*)data);
            break;
        case COLOR:
            glUniform4fv(uni->location, 1, (float*)data);
            break;
        default:
            // Catch errors
            printf("%s\n", "Error: Unknown uniform type");
            break;
    }
}