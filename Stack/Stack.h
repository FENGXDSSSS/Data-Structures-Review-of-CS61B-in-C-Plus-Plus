#ifndef __STACK__
#define __STACK__
#include <iostream>
#include <stack>
#include <stdexcept>

template <typename T>
class Stack {
public:
    /* Stack构造函数 */
    inline
    Stack();
    inline
    Stack(T data);

    /* Stack析构函数 */
    inline
    ~Stack();
    
    /* 入栈方法 */
    inline
    void push(T data);

    /* 出栈方法 */
    inline
    T pop();

    /* 返回栈顶元素 */
    inline
    T peek();

    /* 是否为空 */
    inline
    bool isEmpty();

    /* 返回栈当前的size */
    inline
    int getSize();
private:
    /* 辅助方法 */
    void reMaxCapa(int newMax);
    // 栈的数据存放容器
    T *item;
    // 数据索引
    int index;
    // 数据大小
    int size;
    // 数据最大容量---用于动态调整
    int maxCapacity;
};


// ------------------------------------------Stack成员函数实现-------------------------------------------- //
/* Stack构造函数实现 */
template <typename T>
Stack<T>::Stack() {
    maxCapacity = 8;
    item = new int[maxCapacity];
    size = 0;
    index = -1; // 栈内无数据索引值为-1;
}

template <typename T>
Stack<T>::Stack(T data) {
    maxCapacity = 8;
    item = new int[maxCapacity];
    item[0] = data;
    size = 1;
    index = 0;
}

/* Stack析构函数实现 */
template <typename T>
Stack<T>::~Stack() {
    delete[] item;
}

/* 入栈方法实现 */
template <typename T>
void Stack<T>::push(T data) {
    if (maxCapacity <= size) {
        reMaxCapa(maxCapacity * 2);  
    }
    index += 1;
    item[index] = data;
    size += 1;
}

/* 出栈方法实现 */
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack<T> is empty");
    }
    T temp = item[index];
    index -= 1;
    size -= 1;
    if (size == maxCapacity / 2) {
        reMaxCapa(maxCapacity / 2);
    }
    return temp;
}

/* 栈顶元素方法实现 */
template <typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Stack<T> is empty");
    }
    return item[index];
}

/* 栈是否为空的实现 */
template <typename T>
bool Stack<T>::isEmpty() {
    return size == 0 && index == -1;
}

/* getSize方法实现 */
template <typename T>
int Stack<T>::getSize() {
    return size;
}

// -------------------------------辅助方法实现------------------------------- //
/* reMaxCapa方法实现 */
template <typename T>
void Stack<T>::reMaxCapa(int newMax) {
    T *tempItem = new T[newMax];
    std::copy(item, item + size, tempItem);
    delete[] item;
    maxCapacity = newMax;
    item = tempItem;
}

#endif