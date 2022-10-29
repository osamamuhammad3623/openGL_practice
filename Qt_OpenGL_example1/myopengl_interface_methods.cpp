#include "myopengl.h"
#include "GL/glut.h"
#include "square.h"

void MyOpenGL::draw(void){
    /* Drawing the square */
    glBegin(GL_POLYGON);

    /* top left */
    glVertex2f(square.x_pos-(square.width/2),square.y_pos+(square.height/2));
    /* bottom left */
    glVertex2f(square.x_pos-(square.width/2),square.y_pos-(square.height/2));
    /* bottom right */
    glVertex2f(square.x_pos+(square.width/2),square.y_pos-(square.height/2));
    /* top right */
    glVertex2f(square.x_pos+(square.width/2),square.y_pos+(square.height/2));

    glEnd();

    /* Managing movement logic */
    switch (square.state)
    {
    case RIGHT:
        if(square.x_pos<(100-square.width)){
            square.x_pos += square.speed;
        }else{
            square.state=LEFT;
        }
        break;

    case LEFT:
        if(square.x_pos>(-100)){
            square.x_pos -= square.speed;
        }else{
            square.state=RIGHT;
        }
        break;

    default:
        break;
    }
}
