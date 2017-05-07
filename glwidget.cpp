#include "glwidget.h"
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>
using namespace std;

GlWidget::GlWidget(QWidget * parent) : QGLWidget(parent){
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16);
}


void GlWidget::initializeGL(){
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    Db db;
}

void GlWidget::paintGL(float zoom){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    vector<float> rgb;
    rgb = {1,0,0};
    this->four(Db::things[0][0], Db::things[0][1], Db::things[0][2], Db::things[0][3], rgb, zoom);
}

void GlWidget::resizeGL(int w, int h, float centerX, float centerZ){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(0.0, (float)w/(float)h, 0.01, 40.0);
    gluLookAt(0.0,0.0,0.0, centerX,1.0,centerZ, 0,1,0);
}
