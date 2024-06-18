#version 140

in vec3 vertex_position;


uniform mat4 shift;


void main(){
        gl_Position = vec4(vertex_position.x,sin(2*3.14*1*vertex_position.x),vertex_position.z,1.0f);
}