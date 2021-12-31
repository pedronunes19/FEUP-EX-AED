// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2021]

#include <set>
#include <map>
#include "funWithBSTs.h"
#include "bst.h"

// ----------------------------------------------------------
// Exercicio 1: Colecao de Cromos
// ----------------------------------------------------------

int FunWithBSTs::newBag(const vector<int>& collection, const vector<int>& bag) {
    std::set<int> stuff;
    for (int i: collection)
        stuff.insert(i);
    int init = stuff.size();
    for (int i: bag)
        stuff.insert(i);
    int end = stuff.size();
    return end-init;
}

// ----------------------------------------------------------
// Exercicio 2: Batalha de Pokemons
// ----------------------------------------------------------

int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {
    std::multiset<int> alice1, bruno1;
    for (int i: alice)
        alice1.insert(i);
    for (int i: bruno)
        bruno1.insert(i);
    // rounds
    while (!alice1.empty() && !bruno1.empty()){
        auto a = alice1.rbegin(), b = bruno1.rbegin();
        if (*a < *b) {
            // alice1.extract(*a); if C++ 17
            int newCard = *b - *a;
            alice1.erase(alice1.find(*a));
            bruno1.erase(bruno1.find(*b));
            bruno1.insert(newCard);
            continue;
        }
        else if (*a > *b) {
            // bruno1.extract(*b); if C++ 17
            int newCard = *a - *b;
            bruno1.erase(bruno1.find(*b));
            alice1.erase(alice1.find(*a));
            alice1.insert(newCard);
            continue;
        }
        else{
            alice1.erase(alice1.find(*a));
            bruno1.erase(bruno1.find(*b));
        }
    }

    if (!alice1.empty())
        return alice1.size();
    if (!bruno1.empty())
        return 0-bruno1.size();
    return 0;
}

// ----------------------------------------------------------
// Exercicio 3: Reviews Cinematograficas
// ----------------------------------------------------------

// ..............................
// a) Contando Filmes

int FunWithBSTs::numberMovies(const vector<pair<string, int>>& reviews) {
    std::set <std::string> movies;
    for (pair<string, int> mr : reviews){
        movies.insert(mr.first);
    }
    return movies.size();
}

// ..............................
// b) O filme com mais reviews

void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {
    std::map<string, int> count;
    m = 0; n = 0;
    for (const pair<string, int>& mr: reviews){
        try{
            count[mr.first]++;
        }
        catch(exception &e){
            count.insert(pair<string, int>(mr.first, 1));
        }
    }
    for (auto & it : count){
        if (it.second == m)
            n++;
        else if (it.second > m){
            m = it.second;
            n = 1;
        }
    }
}

// ..............................
// c) Os melhores filmes

vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {
    vector<string> answer;
    set<string> m;
    for (const pair<string, int>& mr: reviews){
        m.insert(mr.first);
    }
    for (const string &n : m){
        float s1 = 0, s2 = 0;
        for (const pair<string, int>& mr: reviews){
            if (mr.first == n){
                s1++;
                s2+=mr.second;
            }
        }
        if (s2/s1 >= k)
            answer.push_back(n);
    }
    return answer;
}
