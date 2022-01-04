// AED 2021/2022 - Aula Pratica 09
// Pedro Ribeiro (DCC/FCUP) [03/01/2022]

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

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
            cout << w << " ";
            dfs(w);
        }
    }
}

int Graph::dfs1(int v) {
    int nnodes = 1;
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            nnodes += dfs1(w);
    }
    return nnodes;
}

list<int> Graph::dfs2(int v) {
    list<int> res;
    res.push_back(v);
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
            list<int> aaa = dfs2(w);
            for (int a: aaa)
                res.push_back(a);
        }
    }
    return res;
}

// Depth-First Search: example implementation
void Graph::bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

int Graph::bfs2(int v, int v1) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    queue<pair<int,int>> q; // queue of unvisited nodes with distance to v
    q.push({v, 0});
    nodes[v].visited = true;
    int thing = -1;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front().first, u1 = q.front().second; q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                if (w == v1) {
                    thing = u1+1;
                }
                q.push({w, u1 + 1});
                nodes[w].visited = true;
            }
        }
    }
    if (v == v1)
        return 0;
    return thing;
}

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Contando diferentes somas de pares

int Graph::outDegree(int v) {
    if (v < 1 || v > n) return -1;
    return nodes.at(v).adj.size();
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos

int Graph::connectedComponents() {
    int count = 0;
    for (int i = 1; i <= n; i++) nodes.at(i).visited = false;
    for (int i = 1; i <= n; i++){
        if (!nodes.at(i).visited){
            count++;
            dfs(i);
        }
    }
    return count;
}

// ..............................
// b) Componente gigante

int Graph::giantComponent() {
    int max = 0;
    for (int i = 1; i <= n; i++) nodes.at(i).visited = false;
    for (int i = 1; i <= n; i++){
        if (!nodes.at(i).visited){
            int comp = dfs1(i);
            if (comp>max)
                max=comp;
        }
    }
    return max;
}


// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------

list<int> Graph::topologicalSorting() {
    list<int> order;
    for (int i =1; i<=n; i++) nodes.at(i).visited=false;
    for (int v =1; v<=n; v++){
        if(!nodes.at(v).visited){
            list<int> aaa = dfs2(v);
            for (int a: aaa)
                order.push_back(a);
        }
    }
    return order;
}

// ----------------------------------------------------------
// Exercicio 4: Distancias em grafos nao pesados
// ----------------------------------------------------------

// ..............................
// a) Distancia entre dois nós

int Graph::distance(int a, int b) {
    return bfs2(a, b);
}

// ..............................
// b) Diametro

int Graph::diameter() {
    if (connectedComponents()>1)
        return -1;
    int max = 0;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            int d = bfs2(i, j);
            if (d > max)
                max = d;
        }
    }
    return max;
}

// ----------------------------------------------------------
// Exercicio 5: To or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    return false;
}
