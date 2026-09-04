#ifndef __ALISTS__
#define __ALISTS__
#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T>
class ALists {
public:
    /* ALists构造函数 */
    inline
    ALists();
    inline
    ALists(T data);
    
    /* ALists析构函数 */
    ~ALists();
    /* 添加列表元素 */
    inline
    void add(T data);

    /* 删除元素 */
    void removeLast();
    void remove(int index);

    /* 获取列表元素 */
    T get(int n);

    /* getSize获取列表大小 */
    int getSize();
private:
    T *dataList;
    int maxLimit;
    int size;
    /* 辅助函数 */
    void reMaxLimit(int newMaxLimit);
};

// ---------------------------------------ALists成员方法实现--------------------------------------- //
/* ALists构造函数 */
template <typename T>
ALists<T>::ALists() {
    maxLimit = 8;
    dataList = new int[maxLimit];
    size = 0;
} 

template <typename T>
ALists<T>::ALists(T data) {
    maxLimit = 8;
    dataList = new int[maxLimit];
    dataList[0] = data;
    size = 1;
}

/* ALists析构函数 */
template <typename T>
ALists<T>::~ALists() {
    delete[] dataList;
}

/* ALists辅助方法实现*/
template <typename T>
void ALists<T>::reMaxLimit(int newMaxLimit) {
    T *tempList = new T[newMaxLimit];
    std::copy(dataList, dataList + size, tempList);
    delete[] dataList;
    dataList = tempList;
    maxLimit = newMaxLimit;
}

/* add函数实现 */
template <typename T>
void ALists<T>::add(T data) {
    if (size == maxLimit) {
        reMaxLimit(maxLimit * 2);
    }
    dataList[size] = data;
    size += 1;
}

/* remove函数实现 */
template <typename T>
void ALists<T>::removeLast() {
    size -= 1;
    if (size == maxLimit / 2) {
        reMaxLimit(maxLimit / 2);
    }
}

template <typename T>
void ALists<T>::remove(int index) {
    if (size <= index) {
        throw std::out_of_range("ALists::remove() : Index out of range");
    }
    T *tempList = new T[maxLimit];
    std::copy(dataList, dataList + index, tempList);
    std::copy(dataList + index + 1, dataList + size, tempList + index);
    delete[] dataList;
    dataList = tempList;
    size -= 1;
    if (size == maxLimit / 2) {
        reMaxLimit(maxLimit / 2);
    }
}

/* get方法实现 */
template <typename T>
T ALists<T>::get(int n) {
    if (size <= n) {
        throw std::out_of_range("ALists::get(int n) : Index out of range");
    }
    return dataList[n];
}

/* getSize方法实现 */
template <typename T>
int ALists<T>::getSize() {
    return size;
}

#endif