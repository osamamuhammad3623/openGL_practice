#include "mainwindow.h"

#include <QApplication>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("OpenGL application");
    w.show();
    return a.exec();
}
