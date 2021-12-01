#include <iostream>
#include <vector>
#include <list>
#include <limits>

using namespace std;

unsigned int numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

string loseGame(string phrase, list<string> &l) {
    int last = 0;
    while(l.size() > 1) {
        int n = numberOfWords(phrase);
        n += last;
        while (n > l.size()) {
            n -= l.size();
        }
        last = n-1;
        auto it1 = l.begin();
        advance(it1, n - 1);
        l.erase(it1);
    }
    return l.front();
}

int main(){
    int n;
    vector<string> res;
    cin >> n;
    for (int i = 0; i<n; i++){
        string p;
        int num;
        list<string>kids;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, p);
        cin >> num;
        for (int j = 0; j< num; j++){
            string name;
            cin >> name;
            kids.push_back(name);
        }
        string aa = loseGame(p, kids) ;
        if (aa == "Carlos")
            res.push_back("O Carlos nao se livrou");
        else
            res.push_back("O Carlos livrou-se (coitado do " + aa + "!)");

    }
    for (string cbrcbrec: res){
        cout << cbrcbrec << endl;
    }

    return 0;
}