#version 330 core
layout (location = 0) in vec2 Pos;

uniform mat4 un_view;
uniform mat4 un_model;
uniform mat4 un_projection;

void main()
{  
    
    gl_Position = un_projection * un_view * un_model * vec4(Pos, 0.0, 1.0);

}