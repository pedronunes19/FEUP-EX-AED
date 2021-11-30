#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include "bst.h"

class WordMean {
    string word;
    string meaning;
    friend bool operator <(const WordMean & a, const WordMean & b);
    friend ostream& operator <<(ostream& out ,const WordMean & a);
public:
    WordMean(string w, string m);
    string getWord() const;
    string getMeaning() const;
    void setMeaning(string m);
    void setWord(string w);
};

class Dictionary
{
      BST<WordMean> words;
public:
      Dictionary(): words(WordMean("","")) {};
      BST<WordMean> getWords() const;
      void readFile(ifstream& f);
      string consult(string word1, WordMean& previous, WordMean& next) const;
      bool update(string word1, string mean1);
      void print() const;
};

#endif
