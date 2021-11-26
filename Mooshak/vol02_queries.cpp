#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int nS, nP;
    vector<int> s, p;
    cin >> nS;
    for (int i = 0; i < nS; i++ ){
        int aux;
        cin >> aux;
        s.push_back(aux);
    }
    cin >> nP;
    for (int i = 0; i < nP; i++ ){
        int aux;
        cin >> aux;
        p.push_back(aux);
    }

    for (int np:p){
        vector <int> answer;
        int diff = 1000000;
        for(int  i = 0; i < s.size(); i++){
            for(int  j = i+1; j < s.size(); j++){
                int temp = s.at(i) + s.at(j);
                if (abs(temp-np) <= diff){
                    if(abs(temp-np) < diff)
                        answer.clear();
                    diff = abs(temp-np);
                    if (find(answer.begin(), answer.end(), temp) == answer.end())
                        answer.push_back(temp);
                }    
            }
        }
        int aaaaa = 0;
        sort(answer.begin(), answer.end());
        for (int a:answer){
            if (!aaaaa)
                cout << a;
            else 
                cout << ' ' << a;
            aaaaa++;

        }
        cout << endl;
    }

    return 0;
}