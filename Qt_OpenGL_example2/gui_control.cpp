#include "myopengl.h"
#include "GL/glut.h"
#include <math.h>
#include "mainwindow.h"

float x_origin{}, y_origin{};

void MyOpenGL::draw(void){

    glTranslatef(x_origin, y_origin, 0); /* move the center of the window to (x,y,z) */
    glBegin(GL_QUADS);
    glColor3f(0,0.25,0.5);
    glVertex2f(-25,25); // top left
    glVertex2f(-25,-25); // bottom left
    glVertex2f(25,-25); // bottom right
    glVertex2f(25,25); // top right
    glEnd();
    /* reset the matrix state, to separate the square movement from the following
     * objects [if exist] */
    glLoadIdentity();

    /* other objects can be drawn here [Begin, ..., End], and their movement won't be affected */
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    y_origin = value;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    x_origin = value;
}
