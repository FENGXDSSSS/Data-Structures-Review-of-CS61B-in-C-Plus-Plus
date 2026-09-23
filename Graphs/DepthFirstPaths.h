// 深度优先路径
#include <stdexcept>
#include <vector>
#include "Graphs.h"

class DFPaths {
private:
    std::vector<bool> markTo; // 标记顶点是否连通起点s
    std::vector<int> edgeTo; // 
    int s;
    std::vector<int> path;
    void dfs(Graph G, int s);
public:
    inline
    DFPaths(Graph G, int v);
    inline
    std::vector<int>& pathTo(int v);
    inline
    bool hasPathTo(int v);
};

inline
DFPaths::DFPaths(Graph G, int s) {
    this->s = s;
    dfs(G, s);
}

inline
void DFPaths::dfs(Graph G, int v) {
    markTo[v] = true;
    for (const auto& w : G.adj(v)) {
        if (markTo[w] == false) {
            edgeTo[w] = v;
            dfs(G, w);
        }
    }
}

inline
std::vector<int>& DFPaths::pathTo(int v) {
    path.clear();
    if (hasPathTo(v)) {
        throw std::out_of_range("DFPaths::pathTo: not hasPathTo");
    }
    int x = 0;
    for (x = v; x != s; x = edgeTo[x]) {
        path.push_back(x);
    }
    path.push_back(x);
    std::reverse(path.begin(), path.end());
    return path;
}

inline
bool DFPaths::hasPathTo(int v) {
    return markTo[v];
}