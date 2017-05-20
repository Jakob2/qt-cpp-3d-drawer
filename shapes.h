#ifndef SHAPES_H
#define SHAPES_H

#include <vector>
using namespace std;

class Shapes
{
public:
    Shapes();
    void four(vector<vector<float>> &things, vector<int> &rotation);
    void axes();
    void complex(vector<vector<vector<float>>> &construct, vector<int> &rotation, int current);
};

#endif // SHAPES_H
