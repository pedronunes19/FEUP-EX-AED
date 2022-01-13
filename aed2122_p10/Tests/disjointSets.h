// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#ifndef _DISJOINTSETS_H_
#define _DISJOINTSETS_H_

#include <unordered_map>

template <class T>
class DisjointSets {
    struct Node {
        T parent;
        int myrank; // to use on union by rank
    };

    unordered_map<T, Node> a;

public:
    void makeSet(const T& x);            // Create a set with a single element x
    T find(const T& x);                  // Find the representative of the set of element x
    void unite(const T& x, const T& y);  // Merge the sets of elements x and y

};

// Create a set with a single element x
template <class T>
void DisjointSets<T>::makeSet(const T& x) {
    try {
        a.at(x).parent = x;

    }catch(const exception &e){
        Node node;
        node.parent = x;
        node.myrank = 0;
        a.insert(pair<T, Node>(x, node));
    }
}

// Find the representative of the set of element x
template <class T>
T DisjointSets<T>::find(const T& x) {
    if (a.at(x).parent == x) return x;
    else return find(a.at(x).parent);
}

// Merge the sets of elements x and y
template <class T>
void DisjointSets<T>::unite(const T& x, const T& y) {
    T xRoot = find(x);
    T yRoot = find(y);
    if (xRoot==yRoot)
        return;
    if (a.at(xRoot).myrank > a.at(yRoot).myrank)
        a.at(yRoot).parent = xRoot;
    else if (a.at(xRoot).myrank < a.at(yRoot).myrank)
        a.at(xRoot).parent = yRoot;
    else{
        a.at(yRoot).parent = xRoot;
        a.at(xRoot).myrank++;
    }

}

#endif
