#ifndef SHAPES_H
#define SHAPES_H

#include <vector>
#include "global.h"
#include "vector.h"
using namespace std;

class Shapes
{
public:
    Shapes();
    void axes();
    void complex(vector<vector<vector<float>>> &construct, vector<int> &rotation, int current, vector<vector<float>> &normal);
    void dart(std::vector<float> base, std::vector<float> end);
};

#endif // SHAPES_H
