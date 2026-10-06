#ifndef DIRECTEDGRAPH
#define DIRECTEDGRAPH

#include "Graphs.h"

class DirectedGraph : public Graph {
public: 
    DirectedGraph(int V) : Graph(V) {}
    inline
    void addEdge(int fVector, int sVector);
};

inline
void DirectedGraph::addEdge(int fVector, int sVector) {
    if (fVector > V() || sVector > V()) {
        throw std::out_of_range("Graph::addEdge(): over number of vertex...");
    }
    for (const auto& w : adj(fVector)) {
        if (w == sVector) {
            return;
        }
    }
    adjList[fVector].push_back(sVector);
}

#endif