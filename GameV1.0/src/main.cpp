#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>

#include <iostream>

#include "shader.h"

int main(void)
{
    GLFWwindow* window;

    // Init OpenGL Libraries // 
    if (!glfwInit())
        return -1;


    // Create a window and OpenGL context //
    window = glfwCreateWindow(640, 480, "Game V1.0", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }



    // Make window context current //
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "GLEW could not Init, Must be called after making context current" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    float pos[6]={ -0.5f, -0.5f,
                    0.0f,  0.5f,
                    0.5f, -0.5f };

    unsigned int buffer;

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), pos, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        unsigned int shader = CreateShader(vertexShader, fragmentShader);
        glUseProgram(shader);


    // Loop until the window is closed //
    while (!glfwWindowShouldClose(window))
    {
        // Render //
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap front and back buffers //
        glfwSwapBuffers(window);

        // Poll for and process events //
        glfwPollEvents();
    }

    // terminate glfw context // 
    glfwTerminate();
    return 0;
}