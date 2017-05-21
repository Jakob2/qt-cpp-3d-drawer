#include "shapes.h"
#include <GL/freeglut.h>
#include <iostream>
//#include <QGLWidget>
using namespace std;

int display;

Shapes::Shapes(){

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

void Shapes::complex(vector<vector<vector<float>>> &construct, vector<int> &rotation, int current){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(rotation[0], 1,0,0);
    glRotatef(rotation[1], 0,1,0);
    glRotatef(rotation[2], 0,0,1);
    axes();
    for(int i=0; i<(int)construct.size(); i++){
        if(i==current) glColor4f(1,0,0,1);
        else glColor4f(1,0,0,0.3);
        if(!display){
            glBegin(GL_POLYGON);
                glVertex3f(construct[i][0][0], construct[i][0][1], construct[i][0][2]);
                if(i==current) glColor4f(0,1,0,1);
                glVertex3f(construct[i][1][0], construct[i][1][1], construct[i][1][2]);
                if(i==current) glColor4f(0,0,1,1);
                glVertex3f(construct[i][2][0], construct[i][2][1], construct[i][2][2]);
                if(i==current) glColor4f(1,1,0,1);
                glVertex3f(construct[i][3][0], construct[i][3][1], construct[i][3][2]);
            glEnd();
        }else{
            if(i==current){
                glBegin(GL_POLYGON);
                    glVertex3f(construct[i][0][0], construct[i][0][1], construct[i][0][2]);
                    glColor4f(0,1,0,1);
                    glVertex3f(construct[i][1][0], construct[i][1][1], construct[i][1][2]);
                    glColor4f(0,0,1,1);
                    glVertex3f(construct[i][2][0], construct[i][2][1], construct[i][2][2]);
                    glColor4f(1,1,0,1);
                    glVertex3f(construct[i][3][0], construct[i][3][1], construct[i][3][2]);
                glEnd();
            }
        }
    }
    glPopMatrix();
}
