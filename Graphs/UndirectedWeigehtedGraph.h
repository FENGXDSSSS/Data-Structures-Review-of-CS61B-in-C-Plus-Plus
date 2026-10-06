#include <vector>
#include <map>
#include <ostream>

class UWGraph {
private: 
    int _v;
    int _e;
    std::vector<std::map<int, int>> adjList;
public:
    inline
    UWGraph(int v);
    inline
    void addEdge(int fVectex, int sVectex, int weight);
    inline
    const std::map<int, int>& adj(int vertex) const ;
    inline
    int V() const { return _v; }
    inline
    int E() const { return _e; }
    friend std::ostream& operator << (std::ostream& os, const UWGraph& graph);
};

inline
std::ostream& operator << (std::ostream& os, const UWGraph& graph) {
    for (int i = 0; i < graph.V(); i += 1) {
        for (const auto& sv : graph.adj(i)) {
            os << i << " - " << sv.first << std::endl;
        }
    }
    return os;
}

// --------------------------------------实现----------------------------------- //
inline
UWGraph::UWGraph(int v) {
    _v = v;
    _e = 0;
    adjList = std::vector<std::map<int, int>>(v);
}

inline
void UWGraph::addEdge(int fVertex, int sVertex, int weight) {
    // 异常处理
    if (fVertex > V() || sVertex > V()) {
        throw std::out_of_range("UWGraph::addEdge(): over number of vertex");
    }
    adjList[fVertex][sVertex] = weight;
    adjList[sVertex][fVertex] = weight;
}

inline
const std::map<int, int>& UWGraph::adj(int vertex) const {
    return adjList[vertex];
}