#ifndef CALC_H
#define CALC_H

#include "data.h"
#include "limits.h"
#include <cmath>

class Calc{
    private:
        vector <Data> data;
    public:
        Calc(vector<Data>);
        double NNalgo(vector <int>);
};

#endif