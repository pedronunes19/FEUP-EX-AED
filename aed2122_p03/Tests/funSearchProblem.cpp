#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------


int FunSearchProblem::facingSun(const vector<int> & values) {
    int res = 0;
    int currMax;
    try{
        currMax = values.at(0);
        res++;
    }
    catch(exception){
        return 0;
    }
    for (int i = 1; i < values.size(); i++){
        if(values.at(i) > currMax){
            currMax = values.at(i);
            res++;
        }
    }
    return res;
}


int FunSearchProblem::squareR(int num) {
    if (num==1 || num==0)
        return num;
    int left = 0, right = num/2, middle, res;
    while(left<=right){
        middle = (right+left)/2;
        if (middle*middle == num)
            return middle;
        if (middle*middle < num) {
            left = middle + 1;
            res = middle;
        }
        else if (middle*middle > num)
            right = middle - 1;
    }
    return res;
}


int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    int res = 0, currMin = 2;
    for (int v: values){
        if (v > 0){
            if (res == 0)
                res = 1;
            if (v < currMin) {
                currMin = v;
                res = v + 1;
            }
        }
    }
    return res;
}

int minStudNecessary(const vector<int> & values, int st);
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    if (values.size() < numSt || values.size()==0 || numSt==0)
        return -1;
    int right = 0, left = 0;
    for (int i = 0; i < values.size(); i++){
        left = max(left, values.at(i));
        right += values.at(i);
    }
    while (left < right){
        int middle = (left+right)/2;
        if (minStudNecessary(values, middle) > numSt)
            left = middle+1;
        else
            right = middle;
    }
    return left;
}

int minStudNecessary(const vector<int> & values, int atmost){
    int st = 1, pages = 0;
    for (int v: values){
        if (pages + v > atmost){
            st++;
            pages = v;
        }
        else
            pages += v;
    }
    return st;
}

