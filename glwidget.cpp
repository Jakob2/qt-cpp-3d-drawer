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
    glClearColor(.7,.7,.7,1);
    glEnable(GL_DEPTH_TEST);
    Db db;
}

void GlWidget::paintGL(float zoom, vector<int> rotation, QString current){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glScalef(zoom, zoom, zoom);
    int c = current.toInt();
    if(Db::construct.size()>1) complex(Db::construct, rotation, c, Db::normal);
<<<<<<< HEAD
    else cout<<"VECTOR IS EMPTY"<<endl;
    //four(Db::things, rotation);
}

void GlWidget::paintGL(){

}

=======
    //four(Db::things, rotation);
}

>>>>>>> 4e5c2f3978a3d2d038cf18b8394c137600d51d01
void GlWidget::resizeGL(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w/(float)h, 0.01, 100.0);
    gluLookAt(1,1,1, 0,0,0, 0,1,0);
}
