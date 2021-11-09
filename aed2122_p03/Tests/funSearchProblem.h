#ifndef SRC_FUNSP_H_
#define SRC_FUNSP_H_

#include <iostream>
#include <vector>

using namespace std;

class FunSearchProblem{
public:
    FunSearchProblem();
    /**
     * find the smallest positive integer that is not in values
     * @param values
     * @return
     */
    static int smallestMissingValue(const vector<int> & values);
    /**
     * determine how many buildings are facing the sun, according to their height
     * @param values
     * @return
     */
    static int facingSun(const vector<int> & values);
    /**
     * find the integer part of a number's square root using binary search
     * @param num
     * @return
     */
    static int squareR(int num);
    static int minPages(const vector<int> & values, int numSt);
};

#endif