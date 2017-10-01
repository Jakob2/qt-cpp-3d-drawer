#include "vector.h"

Vector::Vector(){

}

vector<float> Vector::direction(vector<float> a, vector<float> b){
    vector<float> out;
    float x,y,z;
    x = b[0] - a[0];
    y = b[1] - a[1];
    z = b[2] - a[2];
    return out = {x,y,z};
}

vector<float> Vector::normal(vector<float> a, vector<float> b){
    vector<float> out;
    float x,y,z;
    x = a[1]*b[2] - a[2]*b[1];
    //x = a[2]*b[1] - a[1]*b[2];
    y = a[2]*b[0] - a[0]*b[2];
    z = a[0]*b[1] - a[1]*b[0];
    return out = {x,y,z};
}

float Vector::absolute(vector<float> a){
    float res;
    res = sqrt((pow(a[0],2)+pow(a[1],2)+pow(a[2],2)));
    return res;
}


vector<float> Vector::normalize(vector<float> a){
    vector<float> out;
    float x,y,z, abs;
    abs = Vector::absolute(a);
    x = a[0] / abs;
    y = a[1] / abs;
    z = a[2] / abs;
    return out = {x,y,z};
}

std::vector<float> Vector::vectorIntersection(std::vector<float> paramA, std::vector<float> paramB){
    float Ax,Ay,Az, mx,my,mz, Bx,By,Bz, nx,ny,nz;
    Ax = paramA[0];
    Ay = paramA[1];
    Az = paramA[2];
    mx = paramA[3];
    my = paramA[4];
    mz = paramA[5];

    Bx = paramB[0];
    By = paramB[1];
    Bz = paramB[2];
    nx = paramB[3];
    ny = paramB[4];
    nz = paramB[5];

    float a,b, t;
    a = -By*mx - Ax*my + Bx*my + Ay*mx;
    b = ny*mx - nx*my;

    t = (a/b);
    //std::cout<<"t= "<<t<<"\n---"<<std::endl;

    float x,y,z;

    x = Bx + t*nx;
    y = By + t*ny;
    z = Bz + t*nz;

    /*std::cout<<"x= "<<x<<std::endl;
    std::cout<<"y= "<<y<<std::endl;
    std::cout<<"z= "<<z<<std::endl;*/

    std::vector<float> out;
    return out = {x,y,z};
}

