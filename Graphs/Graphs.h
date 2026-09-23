// 无向图
#include <stdexcept>
#include <vector>
#include <ostream>

class Graph {
private:
    std::vector<std::vector<int>> adjList;
    int _V; // number of vertexs
    int _E; // number of edges
public:
    // 定义顶点个数
    inline
    Graph(int V);
    // 添加边
    inline
    void addEdge(int fVertex, int sVertex);
    // 获取指定节点的edges列表
    inline
    std::vector<int>& adj(int vertex);
    inline
    int V() { return _V; }
    inline
    int E() { return _E; }
    friend std::ostream& operator << (std::ostream& os, Graph graph);
};

inline
std::ostream& operator << (std::ostream& os, Graph graph) {
    for (int i = 0; i < graph.V(); i += 1) {
        for (const auto& sv : graph.adj(i)) {
            os << i << " - " << sv << std::endl;
        }
    }
    return os;
}

// --------------------------------------实现----------------------------------- //
inline
Graph::Graph(int V) {
    _V = V;
    adjList = std::vector<std::vector<int>>(V);
    _E = 0;
}

// 无向图的添加
inline 
void Graph::addEdge(int fVertex, int sVertex) {
    // 异常
    if (fVertex > V() || sVertex > V()) {
        throw std::out_of_range("Graph::addEdge(): over number of vertex...");
    }
    for (const auto& v : adjList[fVertex]) {
        if (v == sVertex) {
            return;
        }
    }
    adjList[fVertex].push_back(sVertex);
    adjList[sVertex].push_back(fVertex);
}

inline
std::vector<int>& Graph::adj(int vertex) {
    return adjList[vertex];
}