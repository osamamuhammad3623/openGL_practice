#include "myopengl.h"
#include "GL/glut.h"
#include "GL/glu.h"
#include <QTimer>
#include <QDebug>

MyOpenGL::MyOpenGL(QWidget *parent)
    : QOpenGLWidget{parent}
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000/FPS);
}

void MyOpenGL::initializeGL()
{
    initializeOpenGLFunctions();
    /* init. the window with a black background */
    glClearColor(0,0,0,1);
    glutInitDisplayMode(GLUT_RGB);
}

void MyOpenGL::paintGL()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    /* calling the function that actually draws on the buffer*/
    draw();

    /* flush what's on the buffer to be displayed */
    glFlush();
}

void MyOpenGL::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
}
