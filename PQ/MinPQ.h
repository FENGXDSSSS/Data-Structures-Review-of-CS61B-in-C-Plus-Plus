// 最小优先队列————直接继承自最小二叉堆
#include "../heap\MinHeap.h"

template <typename T>
class MinPQ : public MinHeap<T> {
private:
    
public:
    MinPQ() : MinHeap<T>() {}
    MinPQ(T item) : MinHeap<T>(item) {}

};

//------------------------------------------------------MinPQ成员函数实现------------------------------------------------------//













// 怎么感觉目前就没了？？？？？？二叉堆就是优先队列吧（存疑
// 之后再扩充吧（笑