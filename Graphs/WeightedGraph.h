#include <vector>
#include <map>
#include <ostream>

class WeightedGraph {
private:
    int _v;
    int _e;
    // map为edge和weight的映射
    std::vector<std::map<int, int>> adjList;
public:
    inline
    WeightedGraph(int V);
    inline
    void addEdge(int fVertex, int sVertex, int weight);
    inline
    std::map<int, int>& adj(int vertex);
    inline
    int V() const { return _v; }
    inline
    int E() const { return _e; }
    friend std::ostream& operator << (std::ostream& os, WeightedGraph graph);
};

inline
std::ostream& operator << (std::ostream& os, WeightedGraph graph) {
    for (int i = 0; i < graph.V(); i += 1) {
        for (const auto& sv : graph.adj(i)) {
            os << i << " - " << sv.first << std::endl;
        }
    }
    return os;
}

// --------------------------------------实现----------------------------------- //
inline
WeightedGraph::WeightedGraph(int v) {
    _v = v;
    _e = 0;
    adjList = std::vector<std::map<int, int>>(v);
}

inline
void WeightedGraph::addEdge(int fVertex, int sVertex, int weight) {
    // 处理异常
    if (fVertex > V() || sVertex > V()) {
        throw std::out_of_range("WeightedGraph::addEdge(): over number of vertex...");
    }
    for (const auto& v : adjList[fVertex]) {
        if (v.first == fVertex) {
        adjList[fVertex].insert(sVertex, weight);
        }
    }
    adjList[fVertex].insert(sVertex, weight);
    
}

inline
std::map<int, int>& WeightedGraph::adj(int vertex) {
    return adjList[vertex];
}

