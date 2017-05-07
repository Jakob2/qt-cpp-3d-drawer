#include "shapes.h"
#include <GL/freeglut.h>
#include <iostream>
using namespace std;

Shapes::Shapes(){

}

void Shapes::four(float a, float b, float c, float d, vector<float> rgb, float zoom){
    glScalef(zoom, zoom, zoom);
    glPushMatrix();
    glBegin(GL_POLYGON);
        glColor3f(rgb[0], rgb[1], rgb[2]);
        glVertex3f(0,0,a);
        glVertex3f(0,0,b);
        glVertex3f(1,0,c);
        glVertex3f(1,0,d);
    glEnd();
    glPopMatrix();
}
