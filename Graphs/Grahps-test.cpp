#include "Graphs.h"
#include <iostream>

int main(void) {
    Graph gg(5);
    gg.addEdge(1, 3);
    gg.addEdge(2, 3);
    gg.addEdge(2, 1);
    std::cout << gg;
}