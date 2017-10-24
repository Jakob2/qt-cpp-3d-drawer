#include "shapes.h"
#include <GL/freeglut.h>
#include <iostream>
//#include <QGLWidget>
using namespace std;

//int display;

Shapes::Shapes(){

}

void Shapes::axes(){
    glLineWidth(1.0);
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

void Shapes::complex(vector<vector<vector<float>>> &construct, vector<int> &rotation, int current, vector<vector<float>> &normal){
    float r, g, b;
    vector<float> base;
    vector<float> end;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(rotation[0], 1,0,0);
    glRotatef(rotation[1], 0,1,0);
    glRotatef(rotation[2], 0,0,1);
    axes();
    for(int i=0; i<(int)construct.size(); i++){
<<<<<<< HEAD

        cout<<"calling"<<endl;

=======
>>>>>>> 4e5c2f3978a3d2d038cf18b8394c137600d51d01
        //mid =  {construct[i][0][0],construct[i][0][1],construct[i][0][2]};
        vector<float> va = {construct[i][0][0],construct[i][0][1],construct[i][0][2]};
        vector<float> vb = {construct[i][1][0],construct[i][1][1],construct[i][1][2]};
        vector<float> vc = {construct[i][2][0],construct[i][2][1],construct[i][2][2]};
        vector<float> vd = {construct[i][3][0],construct[i][3][1],construct[i][3][2]};
<<<<<<< HEAD
        /*cout<<"POSI: "<<i<<endl;
        cout<<"MID INPUT va: "<<va[0]<<" - "<<va[1]<<" - "<<va[2]<<endl;
        cout<<"MID INPUT vb: "<<vb[0]<<" - "<<vb[1]<<" - "<<vb[2]<<endl;
        cout<<"MID INPUT vc: "<<vc[0]<<" - "<<vc[1]<<" - "<<vc[2]<<endl;
        cout<<"MID INPUT vd: "<<vd[0]<<" - "<<vd[1]<<" - "<<vd[2]<<endl;*/
        vector<float> mid = middle(va,vb,vc,vd);

        //cout<<"SHAPE NORMAL: "<<mid[0]<<" - "<<mid[1]<<" - "<<mid[2]<<" / "<<normal[i][1]<<" - "<<normal[i][2]<<" - "<<normal[i][3]<<endl;
=======
        cout<<"POSI: "<<i<<endl;
        cout<<"MID INPUT va: "<<va[0]<<" - "<<va[1]<<" - "<<va[2]<<endl;
        cout<<"MID INPUT vb: "<<vb[0]<<" - "<<vb[1]<<" - "<<vb[2]<<endl;
        cout<<"MID INPUT vc: "<<vc[0]<<" - "<<vc[1]<<" - "<<vc[2]<<endl;
        cout<<"MID INPUT vd: "<<vd[0]<<" - "<<vd[1]<<" - "<<vd[2]<<endl;
        vector<float> mid = middle(va,vb,vc,vd);

        cout<<"SHAPE NORMAL: "<<mid[0]<<" - "<<mid[1]<<" - "<<mid[2]<<" / "<<normal[i][1]<<" - "<<normal[i][2]<<" - "<<normal[i][3]<<endl;
>>>>>>> 4e5c2f3978a3d2d038cf18b8394c137600d51d01
        end = {mid[0]-normal[i][1]/2,mid[1]-normal[i][2]/2,mid[2]-normal[i][3]/2};
        dart(mid,end);

        r = construct[i][4][0];
        g = construct[i][4][1];
        b = construct[i][4][2];
        if(i==current) glColor4f(1,0,0,1);
        //else glColor4f(1,0,0,0.3);
        else glColor4f(r,g,b,0.3);
        if(!REAL){
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
        }else if(REAL){
            glBegin(GL_POLYGON);
            glColor4f(r,g,b,1);
                glVertex3f(construct[i][0][0], construct[i][0][1], construct[i][0][2]);
                glVertex3f(construct[i][1][0], construct[i][1][1], construct[i][1][2]);
                glVertex3f(construct[i][2][0], construct[i][2][1], construct[i][2][2]);
                glVertex3f(construct[i][3][0], construct[i][3][1], construct[i][3][2]);
            glEnd();
        }
    }
    glPopMatrix();
}

void Shapes::dart(std::vector<float> base, std::vector<float> end){
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(base[0],base[1],base[2]);
    glVertex3f(end[0],end[1],end[2]);
    glEnd();
<<<<<<< HEAD
    //cout<<"DRAW A DART"<<endl;
=======
    cout<<"DRAW A DART"<<endl;
>>>>>>> 4e5c2f3978a3d2d038cf18b8394c137600d51d01
}

vector<float> Shapes::middle(vector<float> a, vector<float> b, vector<float> c, vector<float> d){
    vector<float> k;
    vector<float> e;
    k = Vector::direction(a,d);
    e = Vector::direction(a,b);
    /*k[0] = sqrt(pow(k[0],2));
    k[1] = sqrt(pow(k[1],2));
    k[2] = sqrt(pow(k[2],2));

    e[0] = sqrt(pow(e[0],2));
    e[1] = sqrt(pow(e[1],2));
    e[2] = sqrt(pow(e[2],2));*/
    float x,y,z;
    x = a[0]+k[0]/2;
    y = a[1]+k[1]/2;
    z = a[2]+k[2]/2;
    vector<float> E = {x,y,z};

    x = b[0]+k[0]/2;
    y = b[1]+k[1]/2;
    z = b[2]+k[2]/2;
    vector<float> G = {x,y,z};

    x = a[0]+e[0]/2;
    y = a[1]+e[1]/2;
    z = a[2]+e[2]/2;
    vector<float> F = {x,y,z};

    x = d[0]+e[0]/2;
    y = d[1]+e[1]/2;
    z = d[2]+e[2]/2;
    vector<float> H = {x,y,z};

    vector<float> m = Vector::direction(E,G);
    vector<float> n = Vector::direction(F,H);

    /*m[0] = sqrt(pow(m[0],2));
    m[1] = sqrt(pow(m[1],2));
    m[2] = sqrt(pow(m[2],2));

    n[0] = sqrt(pow(n[0],2));
    n[1] = sqrt(pow(n[1],2));
    n[2] = sqrt(pow(n[2],2));*/


<<<<<<< HEAD
    /*cout<<"E: "<<E[0]<<" - "<<E[1]<<" - "<<E[2]<<endl;
=======
    cout<<"E: "<<E[0]<<" - "<<E[1]<<" - "<<E[2]<<endl;
>>>>>>> 4e5c2f3978a3d2d038cf18b8394c137600d51d01
    cout<<"G: "<<G[0]<<" - "<<G[1]<<" - "<<G[2]<<endl;
    cout<<"F: "<<F[0]<<" - "<<F[1]<<" - "<<F[2]<<endl;
    cout<<"H: "<<H[0]<<" - "<<H[1]<<" - "<<H[2]<<endl;
    cout<<"m: "<<m[0]<<" - "<<m[1]<<" - "<<m[2]<<endl;
<<<<<<< HEAD
    cout<<"n: "<<n[0]<<" - "<<n[1]<<" - "<<n[2]<<endl;*/
=======
    cout<<"n: "<<n[0]<<" - "<<n[1]<<" - "<<n[2]<<endl;
>>>>>>> 4e5c2f3978a3d2d038cf18b8394c137600d51d01


    vector<float> paramA = {E[0],E[1],E[2], m[0],m[1],m[2]};
    vector<float> paramB = {F[0],F[1],F[2], n[0],n[1],n[2]};

    vector<float> mid = Vector::vectorIntersection(paramA, paramB);

    //cout<<"MIDDLE: "<<mid[0]<<mid[1]<<mid[2]<<endl;

    return mid;
}
