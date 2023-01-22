#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
using namespace std;


class OpenGL_Window{
private:
    GLFWwindow *window_ptr;
        
    // a function to resize the window at every frame
    void resize(void);

public:

    OpenGL_Window(int w, int h, const char* title);
    ~OpenGL_Window();

    void main_loop(void);
    
    // a function to control input
    void input_handler(void);

    // a function to draw whatever you want! abstracted from OpenGL pipeline
    void draw(void);

};