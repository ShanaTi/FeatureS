#include "results.h"

vector<int> Results::preprint(vector<int> v){ //  since a vector index starts at 0, we must 
    vector<int> temp = v;                     //  increment by one before we output so it is   
    for(unsigned i = 0; i < temp.size(); i++){//  the correct number
        temp.at(i) += 1;
    }
    return temp;
}

void Results::output(){
    vector <int> temp = preprint(index); // prepare vector for output
    ostringstream outStr;
    if(!temp.empty()){
        copy(temp.begin(), temp.end() - 1, ostream_iterator<int>(outStr, ","));
        outStr << temp.back();
    }
 cout << "features set {" << outStr.str() <<"} with accuracy: " << accuracy << endl;
}

bool Algo::exists(int temp, vector<int> x){ //checks if the feature has been added to the tested dataset    
    for (unsigned i = 0; i < x.size(); i++){
        if (temp == x.at(i)){
            return true;
        }
    }
    return false;
}

void Algo::forward(Calc c, int size){
    priority_queue<Results> pQ;
    Results best; //stores value of current best accuracy
    Results current; 
    best.accuracy = 0;
    vector<int> x;

    current.index = x;
    current.accuracy = c.NNalgo(x);
    cout << "current accuracy " << current.accuracy << endl; // starting acc
    current.output();

    for (unsigned i = 0; i < size; i++){
        for (unsigned j = 0; j < size; j++){
            Results temp;
            vector<int> features = x;

            if (exists(j, features)){ //checks if feature is already in feature set
                continue;
            }
            features.push_back(j);
            temp.index = features;
            temp.accuracy = c.NNalgo(features);
            cout << "considering feature " << j + 1 << " with accuracy: " << temp.accuracy << endl;
            pQ.push(temp);
        }
        current = pQ.top();
        if(current.accuracy > best.accuracy){ //replace best accuracy if current is better
            best = current;
        }
        current.output();
        x = current.index;

        while(!pQ.empty()){ //clear priority queue
            pQ.pop();
        }
    }
    cout << "best features are" << endl;
    best.output();
}


void Algo::backward(Calc c, int size){ // similar to forward
    priority_queue<Results> pQ;
    Results best; 
    Results current;
    best.accuracy = 0;
    vector<int> x;
    vector<int>::iterator new_end;

    for (unsigned i = 0; i < size; i++){
        x.push_back(i);
    }
    current.index = x;
    current.accuracy = c.NNalgo(x);
    current.output();
    
      for (unsigned i = 0; i < size; i++){
         
        for (int j = 0; j < size; j++){
            Results temp;
            vector<int> features = x;
            if (!exists(j, features)){
                continue;
            }
            new_end = remove(features.begin(), features.end(), j); //remove from feature list
            features.erase(new_end);
            temp.index = features;
            temp.accuracy = c.NNalgo(features);
            cout << "considering removing feature " << j + 1 << " with accuracy: " << temp.accuracy << endl;
            pQ.push(temp);
        }
        current = pQ.top();
        if(current.accuracy > best.accuracy){
            best = current;
        }
        current.output();
        x = current.index;

        while(!pQ.empty()){
            pQ.pop();
        }
      }
    cout << endl << "best features are ";
    best.output();

}

