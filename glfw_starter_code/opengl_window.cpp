#include "opengl_window.h"

void OpenGL_Window::draw(void){

}

void OpenGL_Window::resize(void){
    int current_w, current_h;
    glfwGetWindowSize(window_ptr, &current_w, &current_h);
    glViewport(0,0,current_w,current_h);
}

OpenGL_Window::OpenGL_Window(int w, int h, const char* title){
    
    glfwInit();

    // configure OPenGL version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create a window and make it the active context
    window_ptr = glfwCreateWindow(w,h,title, NULL, NULL);
    glfwMakeContextCurrent(window_ptr);

    glewInit();
}

OpenGL_Window::~OpenGL_Window(){
    glfwTerminate();
}

void OpenGL_Window::input_handler(void){
    if(glfwGetKey(window_ptr, GLFW_KEY_ESCAPE)){
        glfwSetWindowShouldClose(window_ptr, true);
    }
}

void OpenGL_Window::main_loop(void){
    
    while(!glfwWindowShouldClose(window_ptr)){
        resize();
        input_handler();
        // this is a state-setting function, to set the clear color (can be used as default background)
        glClearColor(0.5f,0.5f,0.5f,1.0f);
        // clear screen (set the clear-color)
        glClear(GL_COLOR_BUFFER_BIT);

        draw();
        
        glfwSwapBuffers(window_ptr);
        glfwPollEvents();
    }
}