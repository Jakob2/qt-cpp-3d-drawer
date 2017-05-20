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
    glClearColor(0.5,0.5,0.5,1);
    glEnable(GL_DEPTH_TEST);
    Db db;
}

void GlWidget::paintGL(float zoom, vector<int> rotation, QString current){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glScalef(zoom, zoom, zoom);
    int c = current.toInt();
    if(Db::construct.size()>1) complex(Db::construct, rotation, c);
    four(Db::things, rotation);
}

void GlWidget::resizeGL(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(0.0, (float)w/(float)h, 0.01, 100.0);
    gluLookAt(0.0,0.0,0.0, 0.5,1.0,0.5, 0,1,0);
}
