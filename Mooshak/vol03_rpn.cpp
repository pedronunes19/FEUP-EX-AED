#include <iostream>
#include <stack>
#include <vector>
#include <limits>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> res, ops;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i<n; i++){
        string aaa;
        getline(cin, aaa);
        aaa += 'n';
        ops.push_back(aaa);
    }
    for (int i = 0; i<n; i++){
        stack<int> s;
        for(int k = 0; k < ops.at(i).size(); k++){  
            if (ops.at(i).at(k)== ' '){
                continue;
            }
            if (ops.at(i).at(k) == 'n'){
                if (s.size() != 1){
                    res.push_back("Expressao Incorrecta");
                    break;
                }
                else{
                    res.push_back(to_string(s.top()));
                    s.pop();
                    break;
                }
            }
            else if (ops.at(i).at(k) =='*' || ops.at(i).at(k) == '+' || ops.at(i).at(k) == '/' || ops.at(i).at(k) == '-'){
                if (s.size() < 2){
                    res.push_back("Expressao Incorrecta");
                    break;
                }
                int n1, n2;
                n2 = s.top();
                s.pop();
                n1 = s.top();
                s.pop();
                switch(ops.at(i).at(k)){
                    case '/':
                        n1 = n1/n2;
                        break;
                    case '+':
                        n1 = n1+n2;
                        break;
                    case '*':
                        n1 = n1*n2;
                        break;
                    case '-':
                        n1 = n1-n2;
                        break;
                }
                s.push(n1);
            }
            else{
                string ICantBelieveImDoingThis = to_string(ops.at(i).at(k)-48);
                int OhMyGod = 1;
                while(ops.at(i).at(k+OhMyGod) != ' ' && ops.at(i).at(k+OhMyGod) != 'n'){
                    ICantBelieveImDoingThis += ops.at(i).at(k+OhMyGod);
                    OhMyGod++;
                }
                s.push(stoi(ICantBelieveImDoingThis));
                k += (OhMyGod-1);
            }
        
    }


    }
    for (int i = 0; i<res.size(); i++){
        bool isN = true;
        for (char c: res.at(i)){
            if (!isdigit(c)){
                isN = false;
                break;
            }
        }
        if(isN)
            cout << stoi(res.at(i)) << endl;
        else
            cout <<res.at(i) << endl;
    }
    return 0;
}