#ifndef GLWiDGET_H
#define GLWiDGET_H

#include <QGLWidget>
#include <QTimer>
#include "global.h"
#include "shapes.h"
#include "db.h"

class GlWidget : public QGLWidget, public Shapes, public Db
{
public:
    explicit GlWidget(QWidget * parent = 0);

    void initializeGL();
    void paintGL(float zoom, vector<int> rotation, QString current);
    void resizeGL(int w, int h);

private:
    QTimer timer;
};

#endif // GLWiDGET_H
