#include <iostream>
#include <vector>

using namespace std;


int minNecessary(const vector<int> & values, int atmost);
int minKM(const vector<int> & values, int numSt) {
    if (values.size() < numSt || values.size()==0 || numSt==0)
        return -1;
    int right = 0, left = 0;
    for (int i = 0; i < values.size(); i++){
        left = max(left, values.at(i));
        right += values.at(i);
    }
    while (left < right){
        int middle = (left+right)/2;
        if (minNecessary(values, middle) > numSt)
            left = middle+1;
        else
            right = middle;
    }
    return left;
}

int minNecessary(const vector<int> & values, int atmost){
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




int main(){
    int n;
    vector<int> km, res;
    cin >> n;
    for (int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        km.push_back(temp);
    }
    cin >> n;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        res.push_back(minKM(km, num));
    }
    for (int i = 0; i<res.size(); i++){
        cout << res.at(i) << endl;
    }
    return 0;
}