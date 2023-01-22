#include "opengl_window.h"

int main(void){
    OpenGL_Window *window = new OpenGL_Window(800,600, "OpenGL Window");

    window->main_loop();

    delete window;
}