#include <GL/glew.h>
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/OpenGL.hpp>

#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

GLuint InitShader(const char* vertex_shader_file_name, const char* fragment_shader_file_name);

GLuint shaderID;

using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode(400, 400), "Colors", sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    window.setActive(true);
    sf::Clock clock;

    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        cout << "ERROR GLEW!!";
        return 0;
    }


    float vertices[] = {
        //1st quadrant

                   0.0f,0.0f,0.0f,       0.0f,1.0f,0.5f,
                   0.6f,0.0f,0.0f,       0.0f,1.0f,0.5f,
                   0.6,0.3,0.0f,         0.0f,1.0f,0.5f,
        
                   0.0f,0.0f,0.0f,       0.0f,1.0f,0.0f,
                   0.6f,0.3f,0.0f,       0.0f,1.0f,0.0f,
                   0.3f,0.6f,0.0f,       0.0f,1.0f,0.0f,

                   0.0f,0.0f,0.0f,       0.0f, 1.0f, 0.8f,
                   0.3f,0.6,0.0f,        0.0f, 1.0f, 0.8f,
                   0.0f,0.6f,0.0f,       0.0f, 1.0f, 0.8f,

                   //2nd quadrant
                   0.0f,0.0f,0.0f,       1.0f, 0.5f, 0.0f,
                   -0.6f,0.0f,0.0f,      1.0f, 0.5f, 0.0f,
                   -0.6,0.3,0.0f,        1.0f, 0.5f, 0.0f,

                   -0.0f,0.0f,0.0f,      1.0f, 0.8f, 0.0f,
                   -0.6f,0.3f,0.0f,      1.0f, 0.8f, 0.0f,
                   -0.3f,0.6f,0.0f,      1.0f, 0.8f, 0.0f,

                   -0.0f,0.0f,0.0f,      1.0f,1.0f,0.0f,
                   -0.3f,0.6,0.0f,       1.0f,1.0f,0.0f,
                   -0.0f,0.6f,0.0f,      1.0f,1.0f,0.0f,
                   //3rd quadrant
                   0.0f,-0.0f,0.0f,      0.0f,0.0f,1.0f,
                   0.6f,-0.0f,0.0f,      0.0f,0.0f,1.0f,
                   0.6,-0.3,0.0f,        0.0f,0.0f,1.0f,

                   0.0f,-0.0f,0.0f,      0.5f, 1.0f, 1.0f,
                   0.6f,-0.3f,0.0f,      0.5f, 1.0f, 1.0f,
                   0.3f,-0.6f,0.0f,      0.5f, 1.0f, 1.0f,

                   0.0f,-0.0f,0.0f,      0.5f, 0.0f, 0.5f,
                   0.3f,-0.6,0.0f,       0.5f, 0.0f, 0.5f,
                   0.0f,-0.6f,0.0f,      0.5f, 0.0f, 0.5f,
                   //4th quadrant
                   -0.0f,-0.0f,0.0f,     1.0f,0.0f,0.0f,
                   -0.6f,-0.0f,0.0f,     1.0f,0.0f,0.0f,
                   -0.6,-0.3,0.0f,       1.0f,0.0f,0.0f,

                   -0.0f,-0.0f,0.0f,     1.0f,0.0f,1.0f,
                   -0.6f,-0.3f,0.0f,     1.0f,0.0f,1.0f,
                   -0.3f,-0.6f,0.0f,     1.0f,0.0f,1.0f,

                   -0.0f,-0.0f,0.0f,     0.8f, 0.0f, 0.8f,
                   -0.3f,-0.6,0.0f,      0.8f, 0.0f, 0.8f,
                   -0.0f,-0.6f,0.0f,     0.8f, 0.0f, 0.8f,


    }; 

    float rotAngle = 0.0f;

    GLuint VBO, VAO;

    //generate buffer
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


    shaderID = InitShader("vShader.glsl", "fShader.glsl");

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == evnt.Closed)
                window.close();

        }
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 modelmat = glm::mat4(1); //matrix init
        float t = clock.getElapsedTime().asMilliseconds();

        rotAngle += 4;
        modelmat = glm::rotate(modelmat, glm::radians(rotAngle), glm::vec3(0, 0, 1));
        glm::mat4 viewmat = glm::mat4(1);

        viewmat = glm::translate(viewmat, glm::vec3(0, 0, -3));
        glm::mat4 perspectivemat = glm::mat4(1);
        perspectivemat = glm::perspective(120.0f, 1.0f, 0.1f, 100.0f);
        int colorLocation = glGetUniformLocation(shaderID, "fcolor");

        int tranformLocation = glGetUniformLocation(shaderID, "transform");

        int modellocation = glGetUniformLocation(shaderID, "model");
        int viewloc = glGetUniformLocation(shaderID, "view");
        int prespectiveloc = glGetUniformLocation(shaderID, "perspective");

        glUniformMatrix4fv(modellocation, 1, GL_FALSE, glm::value_ptr(modelmat));
        glUniformMatrix4fv(viewloc, 1, GL_FALSE, glm::value_ptr(viewmat));
        glUniformMatrix4fv(prespectiveloc, 1, GL_FALSE, glm::value_ptr(perspectivemat));

        glUseProgram(shaderID);
        glBindVertexArray(VAO);
        
        glDrawArrays(GL_TRIANGLES, 0, 36);

        window.display();

    }
    return 0;
}