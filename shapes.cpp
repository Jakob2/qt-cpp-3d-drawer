#include "shapes.h"
#include <GL/freeglut.h>
#include <iostream>
//#include <QGLWidget>
using namespace std;

Shapes::Shapes(){

}

void Shapes::four(vector<vector<float> >things, vector<int> rotation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(rotation[0], 1,0,0);
    glRotatef(rotation[1], 0,1,0);
    glRotatef(rotation[2], 0,0,1);
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex3f(things[0][0], things[0][1], things[0][2]);
        glColor3f(0,1,0);
        glVertex3f(things[1][0], things[1][1], things[1][2]);
        glColor3f(0,0,1);
        glVertex3f(things[2][0], things[2][1], things[2][2]);
        glColor3f(1,1,0);
        glVertex3f(things[3][0], things[3][1], things[3][2]);
    glEnd();
    axes();
    glPopMatrix();
}

void Shapes::axes(){
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(3,0,0);
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,3,0);
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,3);
    glEnd();
}
