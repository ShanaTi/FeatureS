#include "calc.h"

Calc::Calc(vector<Data> d){
    data = d;
}

double Calc::NNalgo(vector<int> current){ //nearest neighbor algo
    double correct = 0;
    double total = 0;
    double tempDist = 0;

    for (unsigned i = 0; i < data.size(); i++){
        double curDist = INT_MAX;

        Data nn; 
        
        for (unsigned j = 0; j  < data.size(); j++){
            if (j == i){
                continue;
            }
            tempDist = 0;
            for (unsigned k = 0; k < current.size(); k++){ 
                tempDist += pow(data.at(i).getFeatures().at(current.at(k)) - data.at(j).getFeatures().at(current.at(k)), 2);
            }

            if (tempDist < curDist){
                curDist = tempDist;
                nn = data.at(j);
            }
        }

        if(nn.getGroup() == data.at(i).getGroup()){
            correct++;
        }

    total++;
    }

    return  correct/total;
}

