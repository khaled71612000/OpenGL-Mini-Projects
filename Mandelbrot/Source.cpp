////////////////////////////////////
////////mandelbrot//////////////////
////////////////////////////////////
#include <iostream>
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/transform.hpp>
#include<vector>

using namespace sf;

using namespace std;
using namespace glm;

GLuint InitShader(const char* vertex_shader_file_name, const char* fragment_shader_file_name);
GLuint shaderID;

vec3 vertices[] = {

    {-1,1,0 },
    {-1,-1,0},
    {1,-1,0},
    {-1,1,0},
    {1,-1,0},
    {1,1,0}
};

vec3 colors[] = {
        {1,0,0},
        {1,0,0},
        {1,0,0},
        {1,0,0},
        {1,0,0},
        {1,0,0}
};

void init() {
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        cout << "Error";
        getchar();
        return;
    }

    glClearColor(1.0, 1.0, 1.0, 0.0);
    GLuint bufferID;
    glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(vec3), (void)0);
    glEnableVertexAttribArray(0);


    //GLuint colorID;
    //glGenBuffers(1, &colorID);
    //glBindBuffer(GL_ARRAY_BUFFER, colorID);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
    //glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(colors), (void)0);
    //glEnableVertexAttribArray(1);

}

void Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

int main() {
    Window window(VideoMode(800, 800), "Task");
    init();

    shaderID = InitShader("VS.glsl", "FS.glsl");
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event) || event.key.code == Keyboard::Escape) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        glUseProgram(shaderID);

        Render();
        window.display();
    }
}
