// 广度优先路径
#include <stdexcept>
#include <vector>
#include "Graphs.h"
#include <deque>

class BFPaths {
private:
    std::vector<bool> markTo;
    std::vector<int> edgeTo;
    int s;
    std::vector<int> path;
    inline
    void bfs(Graph G, int v);
public:
    inline
    BFPaths(Graph G, int V);
    inline
    std::vector<int>& pathTo(int v);
    inline
    bool hasPathTo(const int& v) { return markTo[v]; }
};

inline
BFPaths::BFPaths(Graph G, int s) {
    this->s = s;
    bfs(G, s);
}

inline 
void BFPaths::bfs(Graph G, int v) {
    std::deque<int> fringe;
    fringe.push_back(v);
    markTo[v] = true;
    while (!fringe.empty()) {
        int w = fringe.front();
        fringe.pop_front();
        for (int x : G.adj(w)) {
            if (!markTo[x]) {
                fringe.push_back(x);
                markTo[x] = true;   
                edgeTo[x] = w;
            }
        }
    }
}

inline
std::vector<int>& BFPaths::pathTo(int v) {
    path.clear();
    if (hasPathTo(v)) {
        throw std::out_of_range("BFPaths::pathTo: not hasPathTo");
    }
    int x = 0;
    for (x = v; x != s; x = edgeTo[x]) {
        path.push_back(x);
    }
    path.push_back(x);
    std::reverse(path.begin(), path.end());
    return path;
}
