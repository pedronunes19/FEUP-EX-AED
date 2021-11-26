#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string adn;
    cin >> adn;
    map<char, int> count;
    vector<char> order;
    for (int i = 0; i < adn.length(); i++){
        try{
            count.at(adn[i])++;
        }
        catch(exception){
            count.insert(pair<char, int>(adn[i], 1));
            order.push_back(adn[i]);
        }

    }

    stable_sort(order.begin(), order.end(), [count](char a, char b){ return count.at(a)>count.at(b);});

    for (char c: order)
        cout << c << ' ' << count.at(c) << endl;
    return 0;
}