/* 
This example/mini project is a square that moves from left to right
    and vice versa, on the X-axis.

- The square speed is controllable in runtime [UP & DOWN keys]
- The width & height are configurable
- Pressing ESC closes the window.
*/

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

#define FPS     (60)

enum Direction{
    LEFT, RIGHT
};

struct Square{
    float x_pos{0};
    int8_t width{10};
    int8_t height{10};
    float speed{3};

    Direction state{RIGHT};
};

Square square;

void init_window_background(void){
    glClearColor(0.5,0.25,1,1);
}

void reshape_window(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-100,100,-100,100);

    glMatrixMode(GL_MODELVIEW);
}

void draw(void){
    /* Drawing the square */
    glBegin(GL_POLYGON);

    glVertex2f(square.x_pos,square.height/2);
    glVertex2f(square.x_pos,-(square.height/2));
    glVertex2f(square.x_pos+square.width,-(square.height/2));
    glVertex2f(square.x_pos+square.width,square.height/2);

    glEnd();

    /* Managing movement logic */
    switch (square.state)
    {
    case 1:
        if(square.x_pos<(100-square.width)){
            square.x_pos+=square.speed;
        }else{
            square.state=LEFT;
        }
        break;

    case 0:
        if(square.x_pos>(-100)){
            square.x_pos-=square.speed;
        }else{
            square.state=RIGHT;
        }
        break;

    default:
        break;
    }
}

void update(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    /* calling the function that actually draws on the buffer*/
    draw();

    /* swaps the Front buffer with Back buffer */
    glutSwapBuffers();
}

void update_FPS(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, update_FPS, 0);

}

void input_handler(unsigned char c, int x, int y){
    /* 27 represents ESC */
    if(c == 27){
        exit(0);
    }
}

void special_input_handler(int c, int x, int y){
    if(c == GLUT_KEY_UP){
        square.speed += 0.5;
    
    }else if (c == GLUT_KEY_DOWN){
        /* if speed became negative, the square will move in the opposite direction */
        if(square.speed>=0.5){
            square.speed-= 0.5;
        }
    }
}

int main(int argc, char**argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    /* intialize window position & size */
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    /* set window title */
    glutCreateWindow("OpenGL application");
    /* set the display function [the refresh function/ also contains what to be drawn on window] */
    glutDisplayFunc(update);
    /* set the reshape/resize function [will be called if window size is changed] */
    glutReshapeFunc(reshape_window);
    glutTimerFunc(0, update_FPS, 0);
    glutKeyboardFunc(input_handler);
    /*  */
    glutSpecialFunc(special_input_handler);
    /* set the intial window background */
    init_window_background();

    glutMainLoop();
}