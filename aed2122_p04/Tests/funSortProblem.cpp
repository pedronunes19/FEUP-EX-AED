#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------


void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    if (products.size() <= 1)
        return;
    // sort by weight
    for (int i = 1; i < products.size(); i++){
        Product temp = products.at(i);
        unsigned j;
        for (j = i; j > 0 && temp.getWeight() < products.at(j-1).getWeight() ; j--){
            products.at(j) = products.at(j-1);
        }
        products.at(j) = temp;
    }
    // sort by price
    for (int i = 1; i < products.size(); i++){
        Product temp = products.at(i);
        unsigned j;
        for (j = i; j > 0 && temp.getPrice() < products.at(j-1).getPrice() ; j--){
            products.at(j) = products.at(j-1);
        }
        products.at(j) = temp;
    }

    if (products.size() > k)
        products.resize(k);
}


int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (nc > values.size())
        return -1;
    vector<unsigned int> v1 = values;
    sort(v1.begin(), v1.end());
    int min = v1.at(nc - 1) - v1.at(0);
    for (int i = 0; i < values.size()-nc + 1; i++){
        if (v1.at(i + nc - 1) - v1.at(i) < min)
            min = v1.at(i + nc - 1) - v1.at(i);
    }
    return min;
}



unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    int platforms = 1;
    for (int i = 0; i < arrival.size(); i++){
        int max = 1;
        for (int j = i+1; j<arrival.size() && arrival.at(j)<departure.at(i); j++){
            max++;
        }
        if (max > platforms)
            platforms = max;
    }
    return platforms;
}


void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

}

