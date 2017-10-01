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


