#ifndef MYOPENGL_H
#define MYOPENGL_H

#include <QObject>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QTimer>

#define FPS     (60)

class MyOpenGL : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit MyOpenGL(QWidget *parent = nullptr);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    QTimer* timer;

    void draw();
};

#endif // MYOPENGL_H
