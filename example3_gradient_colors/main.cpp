/* 
This example/mini-project focuses on performing color gradient on shapes.
- drawing a polygon with different vertex colors
*/

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

#define FPS     (60)


void init_window_background(void){
    glClearColor(0,1,1,1);
}

void reshape_window(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-100,100,-100,100);

    glMatrixMode(GL_MODELVIEW);
}

void draw(void){

    /* to make a color gradient, assign defferent colors for vertices in the same shape */

    glBegin(GL_POLYGON);

    // top left [RED]
    glColor3f(1,0,0);
    glVertex2f(-50, 50);
    // botom left [GREEN]
    glColor3f(0,1,0);
    glVertex2f(-50, -50);
    // bottom right [BLUE]
    glColor3f(0,0,1);
    glVertex2f(50, -50);
    // top right [WHITE]
    glColor3f(1,1,1);
    glVertex2f(50, 50);

    glEnd();

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
    /* set the intial window background */
    init_window_background();

    glutMainLoop();
}