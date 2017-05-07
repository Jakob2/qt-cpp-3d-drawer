#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>
#include "shapes.h"
#include "db.h"

class GlWidget : public QGLWidget, public Shapes, public Db
{
public:
    explicit GlWidget(QWidget * parent = 0);

    void initializeGL();
    //void paintGL();
    void paintGL(float zoom);
    void resizeGL(int w, int h, float centerX, float centerZ);

private:
    QTimer timer;
};

#endif // GLWIDGET_H
