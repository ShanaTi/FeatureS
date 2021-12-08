#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
using namespace std;

class Data{
    private:
    double group;
    vector<double> features;
    
    public:
    Data();
    double getGroup();
    vector<double> getFeatures();
    void changeGroup(double);
    void featureAdd(double);
    void outputFeatures();
};

#endif