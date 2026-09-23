// 二叉最小堆实现
#include <stdexcept>
#include <vector>

template <typename T> 
class MinHeap {
private:
    std::vector<T> key;
    int _size;
    
    // 首元素下沉
    void sink(int index);
    // 末尾元素上浮
    void swim(int index);
    // 交换元素
    void swap(int index1, int index2);
public:
    MinHeap();
    MinHeap(T keyItem);
    
    void put(T keyItem);
    // 弹出/返回优先级最高的元素
    T removeMin();
    // 返回优先级最高的元素
    T peek(); 
    // 返回大小
    int size();
};

// ----------------------------------------------LLRT成员函数实现(public)----------------------------------------------------- //
/* 构造函数 */
template <typename T>
MinHeap<T>::MinHeap() {
    _size = 0;
}

template <typename T>
MinHeap<T>::MinHeap(T keyItem) {
    key.push_back(keyItem);
    _size = 1;
}

/* put函数实现 */
template <typename T>
void MinHeap<T>::put(T keyItem) {
    // 元素添加到数组末, 使用swim调整位置
    key.push_back(keyItem);
    
    swim(size() - 1);
}

/* removeMin函数实现 */
template <typename T>
T MinHeap<T>::removeMin() {
    if (size() == 0) {
        throw std::out_of_range("Heap<T>::peek() : The heap is empty");
    }
    T result = key[0];
    key[0] = key.back();
    key.pop_back();
    sink(0);

    return result;
}

/* peek函数实现 */
template <typename T>
T MinHeap<T>::peek() {
    if (size() == 0) {
        throw std::out_of_range("Heap<T>::peek() : The heap is empty");
    }
    return key[0];
}

/* size函数实现 */
template <typename T>
int MinHeap<T>::size() {
    return key.size();
}

// ----------------------------------------------LLRT成员函数实现(private)----------------------------------------------------- //
/* sink函数实现 */
// 堆顶元素下沉
template <typename T>
void MinHeap<T>::sink(int index) {
    int lIndex = index * 2 + 1;
    int rIndex = index * 2 + 2;
    int minIndex = 0;
    // 堆可能没有右根节点，但一定有左根节点，所以右根节点循环内处理
    while (lIndex < size()) {
        // 获取子节点最小节点，如果没有右子节点，最小子节点是左子节点
        if (rIndex < size() && key[lIndex] > key[rIndex]) {
            minIndex = rIndex;
        } else {
            minIndex = lIndex;
        }
        // 互换元素
        if (key[index] > key[minIndex]) {
            swap(index, minIndex);
            index = minIndex;
        } else {
            break;
        }
        lIndex = index * 2 + 1;
        rIndex = index * 2 + 2;
    }
}

// 堆尾元素上浮
/* swim函数实现 */
template <typename T>
void MinHeap<T>::swim(int index) {
    int pIndex = 0;
    while (true) {
        pIndex = (index - 1) / 2;

        if (key[pIndex] > key[index]) {
            swap(pIndex, index);
            index = pIndex;
        } else {
            break;
        }
        if (pIndex == 0)
            return;
    }
}

/* swap函数实现 */
template <typename T>
void MinHeap<T>::swap(int index1, int index2) {
    T item = key[index1];
    key[index1] = key[index2];
    key[index2] = item;

    return;
}