#ifndef __ARRAYDEQUE__
#define __ARRAYDEQUE__

#include "Deque.h"
#include <stdexcept>

template<typename T>
class ArrayQueue : public Deque<T> {
public:
    /* ArrayQueue构造函数 */
    ArrayQueue();

    /* ArrayQueue析构函数*/
    ~ArrayQueue() override;

    /* 入队方法 */
    void addFirst(T data) override;
    void addLast(T data) override;

    /* 获取队列元素 */
    T get(int index) override;

    /* 获取队列大小 */
    int getSize() override;

    /* 输出队列 */
    void printDeque() override;

    /* 删除元素 */
    T removeFirst() override;
    T removeLast() override;
    
private:
    /* 辅助方法 */
    void reLength(int newLength);
    void reduce(int newLength);
    T *list;
    int nextBack; // setback的下一个地址
    int nextFirst;// setfirst的下一个地址
    int size;
    int arrLength;
};


// -----------------------------------------ArrayQueue成员函数实现---------------------------------------------------//
/* ArrayQueue构造函数实现 */
template <typename T>
ArrayQueue<T>::ArrayQueue() {
    size = 0;
    arrLength = 16;
    list = new T[arrLength];
    nextFirst = arrLength / 2 - 1;
    nextBack = arrLength / 2;
}

/* ArrayQueue析构函数实现 */
template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] list;
}

/* 入队方法实现 */
template <typename T>
void ArrayQueue<T>::addFirst(T data) {
    if (size == arrLength) {
        reLength(arrLength * 2);
    }
    list[nextFirst] = data;
    nextFirst = (nextFirst - 1 + arrLength) % arrLength;
    size += 1;
}

template <typename T>
void ArrayQueue<T>::addLast(T data) {
    if (size == arrLength) {
        reLength(arrLength * 2);
    }
    list[nextBack] = data;
    nextBack = (nextBack + 1) % arrLength;
    size += 1;
}

/* get方法实现 */
template <typename T>
T ArrayQueue<T>::get(int index) {
    if (index >= size || index < 0) {
        throw std::out_of_range("ArrayQueue<T>::get(int index): Index out of range");
    }
    return list[(index + arrLength + nextFirst + 1) % arrLength];
}

/* getSize方法实现 */
template <typename T>
int ArrayQueue<T>::getSize() {
    return size;
}

/* printDeque方法实现 */
template <typename T>
void ArrayQueue<T>::printDeque() {

    return;
}

/* 删除方法实现 */
template <typename T>
T ArrayQueue<T>::removeFirst() {
    if (this->isEmpty()) {
        throw std::out_of_range("ArrayQueue<T>::get(int index): Deque is empty");
    }
    T temp;
    nextFirst = (nextFirst + 1) % arrLength;
    temp = list[nextFirst];
    size -= 1;
    if (size == arrLength / 2 && arrLength != 16) {
        reLength(arrLength / 2);
    }
    return temp;
}

template <typename T> 
T ArrayQueue<T>::removeLast() {
    if (size == 0) {
        throw std::out_of_range("ArrayQueue<T>::get(int index): Deque is empty");
    }
    T temp;
    nextBack = (nextBack - 1 + arrLength) % arrLength;
    temp = list[nextBack];
    size -= 1;
    if (size == arrLength / 2 && arrLength != 16) {
        reLength(arrLength / 2);
    }
    return temp;
}

// ------------------------------------辅助方法--------------------------------------//
/* 重置列表大小 */
template <typename T>
void ArrayQueue<T>::reLength(int newLength) {
    T *tempList = new T[newLength];
    int head = (nextFirst + 1) % arrLength;
    if (head + size <= arrLength) {
        std::copy(list + head, list + size + head, tempList);
    } else {
        int rightLen = arrLength - head;
        int leftLen = size - rightLen;
        
        std::copy(list + head, list + arrLength, tempList);
        std::copy(list, list + leftLen,tempList + rightLen);
    }

    delete[] list;
    list = tempList;
    arrLength = newLength;
    nextFirst = arrLength - 1;
    nextBack = size;
}
#endif