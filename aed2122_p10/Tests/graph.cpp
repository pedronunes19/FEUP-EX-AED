// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}


// ----------------------------------------------------------
// Exercicio 3: Algoritmo de Prim
// ----------------------------------------------------------

int Graph::prim(int r) {
    for (Node & i : this->nodes){
        i.distance = INT_MAX;
        i.parent = NULL;
    }
    nodes.at(r).distance=0;
    MinHeap<int, int> q(n, -1);
    for (int i = 1; i<=n; i++){
        q.insert(i, nodes.at(i).distance);
    }
    while(q.getSize()!=0){
        int min = q.removeMin();
        for (Edge e : nodes.at(min).adj){
            if (q.hasKey(e.dest) && e.weight < nodes.at(e.dest).distance){
                nodes.at(e.dest).parent = &nodes.at(min);
                nodes.at(e.dest).distance = e.weight;
                q.decreaseKey(e.dest, e.weight);
            }

        }
    }
    int res = 0;
    for (int i = 1; i<=n; i++)
        res+=nodes.at(i).distance;
    return res;
}


// ----------------------------------------------------------
// Exercicio 5: Algoritmo de Kruskal
// ----------------------------------------------------------
// TODO
int Graph::kruskal() {
    return 0;
}
