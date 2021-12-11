#ifndef RESULTS_H
#define RESULTS_H

#include <vector>
#include <queue>
#include <iterator>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Data.h"
#include "calc.h"
using namespace std;

struct Results{
    double accuracy; // accuracy of each feature set
    vector <int> index;

    bool operator < (const Results & ex) const{ //  comparator for priority queue
        return accuracy < ex.accuracy; 
    }
    vector<int> preprint(vector <int> p);
    void output();
};

class Algo{
    public:
    bool exists(int, vector<int>); //check if feature already exists in feature set
    void forward(Calc, int); //forward selection
    void backward(Calc, int); // backward selection
};

#endif