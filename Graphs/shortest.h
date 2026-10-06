#include "WeightedGraph.h"
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <climits>

 struct cmp { 
    bool operator ()(std::pair<int, int> p1, std::pair<int, int> p2) {
        return p1.second > p2.second;
    }
 };

class ShortestPath {
private:
    std::vector<int> edgeTo;
    std::vector<int> distTo;
    WeightedGraph G;
    int s;
public:
    inline
    ShortestPath(const WeightedGraph& G, int s);
    inline
    void dijkstra();
    inline
    void aStar();
};

inline
ShortestPath::ShortestPath(const WeightedGraph& graph, int s) : G(graph) {
    this->s = s;
    edgeTo = std::vector<int>(graph.V());
    distTo = std::vector<int>(graph.V());
    std::fill(distTo.begin(), distTo.end(), INT_MAX);
}

// 起点s到各个节点的最短路径
inline
void ShortestPath::dijkstra() {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> fringe; // 优先队列
    distTo[s] = 0;
    fringe.push(std::pair<int, int>(s, 0));
    std::pair<int, int> vertex;
    while (!fringe.empty()) {
        vertex = fringe.top(); // 访问队首元素
        fringe.pop(); // 队首元素出队
        if (vertex.second > distTo[vertex.first])
            continue;
        for (const auto& v : G.adj(vertex.first)) {
            int weight = v.second; // 获取权重
            // 比较两种路径的距离，保留距离更小的路径
            if (weight + vertex.second < distTo[v.first]) {
                distTo[v.first] = weight + vertex.second;
                edgeTo[v.first] = vertex.first;
                fringe.push(std::pair<int, int>(v.first, distTo[v.first]));
            }
        }
    }
}
// 当前数据源不适合实现aStar。aStar算法倾向使用向量信息，数据源不包含向量信息的情况下会退化成dijkstra算法。
inline
void ShortestPath::aStar() {

}