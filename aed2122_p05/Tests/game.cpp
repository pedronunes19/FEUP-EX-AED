#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
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

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

//-----------------------------------------------------------------


void Game::addKid(const Kid k1) {
    kids.push_back(k1);
}


list<Kid> Game::getKids() const {
    return kids;
}


void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}


Kid Game::loseGame(string phrase) {
    list<Kid> temp = kids;
    int last = 0;
    while(temp.size() > 1) {
        int n = numberOfWords(phrase);
        n += last;
        while (n > temp.size()) {
            n -= temp.size();
        }
        last = n-1;
        auto it1 = temp.begin();
        advance(it1, n - 1);
        temp.erase(it1);
    }
    return temp.front();
}


list<Kid> Game::removeOlder(unsigned id) {
    list<Kid> l;
    for (auto it = kids.begin(); it != kids.end(); it++){
        if (it->getAge() > id){
            l.push_back(*it);
            kids.erase(it);
            it--;
        }
    }
    return l;
}


queue<Kid> Game::rearrange() {
    queue <Kid> f, m, rem;
    for (Kid k: kids){
        if (k.getSex() == 'f')
            f.push(k);
        else
            m.push(k);
    }
    kids.clear();
    int nm, nf;
    if (f.size() < m.size())
        nf = 1, nm = m.size()/f.size();
    else
        nm = 1, nf = f.size()/m.size();
    while (true){
        if (f.size() < nf)
            break;
        for (int i = 1; i <= nf; i++) {
            kids.push_back(f.front());
            f.pop();
        }
        if (m.size() < nm)
            break;
        for (int i = 1; i <= nm; i++) {
            kids.push_back(m.front());
            m.pop();
        }
    }
    while (!f.empty()){
        rem.push(f.front());
        f.pop();
    }
    while (!m.empty()){
        rem.push(m.front());
        m.pop();
    }

    return(rem);
}


bool Game::operator==(Game& g2) {
	return kids==g2.getKids();
}


list<Kid> Game::shuffle() const {
    list <Kid> res, aux = kids;
    while (!aux.empty()) {
        int random = rand() % 2;
        if (random){
            res.push_back(aux.back());
            aux.pop_back();
        }
        else{
            res.push_back(aux.front());
            aux.pop_front();
        }
    }
    return res;
}
