#ifndef GRAHPSTEST
#define GRAHPSTEST

#include "DirectedGraph.h"
#include "UndirectedGraph.h"
#include "DepthFirstPaths.h"
#include <iostream>
#include <vector>

int main(void) {
    UndirectedGraph gg(5);
    gg.addEdge(1, 3);
    gg.addEdge(2, 3);
    gg.addEdge(2, 1);
    std::cout << gg << std::endl;
    DFPaths DFP(gg, 1);
    std::vector<int> path = DFP.pathTo(3);
    for (const auto& w : path) {
        std::cout << w << " ";
    }
    std::cout << std::endl;
}

#endif