#ifndef VECTOR_H
#define VECTOR_H

#include "global.h"

class Vector
{
public:
    Vector();

    static vector<float> direction(vector<float> a, vector<float> b);
    static vector<float> normal(vector<float> a, vector<float> b);
    static float absolute(vector<float> a);
    static vector<float> normalize(vector<float> a);
    static std::vector<float> vectorIntersection(std::vector<float> paramA, std::vector<float> paramB);
};

#endif // VECTOR_H
