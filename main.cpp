#include "data.h"
#include "calc.h"
#include "results.h"
using namespace std;

vector <Data> transfer(string dataFile); // reads in features from input file

int main(int argc, char*argv[]){
    if(argc != 2){
        cout << "Error, please enter file name" << endl;
        return 1;
    }
    string hold(argv[0]);
    string input(argv[1]);
    cout << "filename: " << input << endl;;
    vector<Data> d = transfer(input);
    int size = d.at(0).getFeatures().size();
    Calc c(d);
    Algo r;
    char choice;
    cout  << "Which algorithm do you want to use?" << endl;
    cout << "`1` Forward Selection" << endl;
    cout << "`2` Backward Selection" << endl;
    cin >> choice;

    if (choice == '1'){
        r.forward(c, size);
    }
    else if (choice == '2'){
        r.backward(c, size);
    }
    
    

    return 0;
}


vector <Data> transfer(string dataFile){ //read in data
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