#include "data.h"

Data::Data(){
    group = 0; // deafault at 0
}
  
double Data::getGroup(){
    return group;
}

vector<double> Data::getFeatures(){
    return features;
}

void Data::changeGroup(double x){
    group = x;
}

void Data::featureAdd(double x){
    features.push_back(x);
}

void Data::outputFeatures(){
    cout << "Class: " << group << endl;
    for(unsigned i = 0; i < features.size(); i++){
        cout << features.at(i) << ", ";
    }
    cout << endl;
}