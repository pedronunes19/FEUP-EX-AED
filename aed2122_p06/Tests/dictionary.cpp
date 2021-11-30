#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

BST<WordMean> Dictionary::getWords() const {
	return words;
}

bool operator<(const WordMean &a, const WordMean &b) {
    return (a.word < b.word);
}

ostream& operator <<(ostream& out , const WordMean &a) {
    out << a.word << endl << a.meaning;
    return out;
}

// ---------------------------------------------


void Dictionary::readFile(ifstream &f) {
    while (!f.eof()){
        string w, m;
        getline(f, w);
        getline(f, m);
        words.insert(WordMean (w, m));
    }
}


string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {
    int aux = -1;
    for (auto it = words.begin(); it != words.end(); it++){
        if ((*it).getWord() == word1)
            return (*it).getMeaning();
        if ((*it).getWord() > word1){
            if (it != words.begin()){
                auto itrpre = words.begin();
                for (int aaaaa = 1; aaaaa <= aux; aaaaa++)
                    itrpre++;
                previous = *itrpre;
            }
            if (it != words.end())
                next = *it;
            return "word not found";
        }
        aux++;
    }
}


bool Dictionary::update(string word1, string mean1) {
    if (words.find(WordMean(word1, mean1)).getWord() == "") {
        words.insert(WordMean(word1, mean1));
        return false;
    }
    words.remove(words.find(WordMean(word1, mean1)));
    words.insert(WordMean(word1, mean1));
    return true;
}


void Dictionary::print() const {
    words.printTree();
}
