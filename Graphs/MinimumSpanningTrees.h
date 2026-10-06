#include "UndirectedWeigehtedGraph.h"
#include <vector> 
#include <queue>
#include <algorithm>
#include <utility>
#include <climits> 

struct cmp {
    bool operator ()(std::pair<int, int> p1, std::pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

class MSTree {
private:
    std::vector<bool> markTo;
    std::vector<int> edgeTo;
    std::vector<int> distTo;
    UWGraph G;
    int s;
public:
    inline
    MSTree(const UWGraph& graph, int s);
    inline
    void primMST();
    inline
    void kruskalMST();
};

inline
MSTree::MSTree(const UWGraph& graph, int s) : G(graph) {
    markTo = std::vector<bool>(graph.V());
    edgeTo = std::vector<int>(graph.V());
    distTo = std::vector<int>(graph.V());
    this->s = s;
    std::fill(distTo.begin(), distTo.end(), INT_MAX);
}

inline
void MSTree::primMST() {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> fringe;
    distTo[s] = 0;
    std::pair<int, int> v;
    fringe.push(std::pair<int, int>(s, distTo[s]));
    while (!fringe.empty()) {
        v = fringe.top();
        fringe.pop();

        if (markTo[v.first]) continue;
        markTo[v.first] = true; 
        for (const auto& w : G.adj(v.first)) {
            if (markTo[w.first] == true) continue;
            if (w.second < distTo[w.first]) {
                distTo[w.first] = w.second;
                edgeTo[w.first] = v.first;
                fringe.push({w.first, distTo[w.first]});
            }
        }
    }
}

inline
void MSTree::kruskalMST() {
    
}