#include "shapes.h"
#include <GL/freeglut.h>
#include <iostream>
using namespace std;

Shapes::Shapes(){

}

void Shapes::four(vector<vector<float> >things, vector<float> rgb, vector<int> rotation){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(rotation[0], 1,0,0);
    glRotatef(rotation[1], 0,1,0);
    glRotatef(rotation[2], 0,0,1);
    glBegin(GL_POLYGON);
        glColor3f(rgb[0], rgb[1], rgb[2]);
        glVertex3f(things[0][0], things[0][1], things[0][2]);
        glVertex3f(things[1][0], things[1][1], things[1][2]);
        glVertex3f(things[2][0], things[2][1], things[2][2]);
        glVertex3f(things[3][0], things[3][1], things[3][2]);
    glEnd();
    glPopMatrix();
}
