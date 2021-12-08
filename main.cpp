#include <iostream>
#include <sstream>
#include <fstream>
#include "data.h"
using namespace std;

vector <Data> transfer(string dataFile); // reads in features from input file

int main(int argc, char*argv[]){
    if(argc != 2){
        cout << "Error, please enter file name" << endl;
        return 1;
    }
    string hold(argv[0]);
    string input(argv[1]);
    cout << input << endl;;
    vector<Data> d = transfer(input);
    cout << d.size() << endl;
    for (unsigned i = 0; i < d.size(); i++){
        d.at(i).outputFeatures();
        cout << endl;
    }
    return 0;
}


vector <Data> transfer(string dataFile){
    ifstream inStr;
    inStr.open(dataFile.c_str());

    vector <Data> d;
    while(inStr.good()) {
        Data temp;
        string line;
        double group = 5555;

        getline(inStr, line);
        istringstream transfer(line);
        transfer >> group;

        if(group == 5555){
            break;
        }
        else{
            temp.changeGroup(group);
        }

        double tem;
        while (transfer >> tem){
            temp.featureAdd(tem);
        }
        d.push_back(temp);

    }
     return d;
}