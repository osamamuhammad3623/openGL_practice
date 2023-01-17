#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>  
using namespace std;


// a function to resize the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// a function to control input
void process_input(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE)== GLFW_PRESS){
        // if Esc key is pressed, close the window
        glfwSetWindowShouldClose(window, true);
    }
}


int main(void) {

    // initialize GLFW with some options (version & profile)
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    /* GLAD manages function pointers for OpenGL so we want to
    initialize GLAD before we call any OpenGL function */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // set the OpenGL window size
    glViewport(0, 0, 800, 600);

    // this is a state-setting function, to set the clear color (can be used as default background)
    glClearColor(0.5, 0.5, 0.5, 1);

    /* when window is resized */
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    /* note: We register the callback functions
    after we’ve created the window and before the render loop is initiated */


    while(!glfwWindowShouldClose(window))
    {
        // check/handle/process input
        process_input(window);

        // rendering (drawing)

        // clear screen (set the clear-color)
        glClear(GL_COLOR_BUFFER_BIT);

        // check & call events, and swap buffers 
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}
