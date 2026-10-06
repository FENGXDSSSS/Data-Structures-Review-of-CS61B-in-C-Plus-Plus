#ifndef UNDIRECTEDGRAPH
#define UNDIRECTEDGRAPH

#include "Graphs.h"

class UndirectedGraph : public Graph {
public:
    UndirectedGraph(int V) : Graph(V) {}
};

#endif