#ifndef __DEQUE__
#define __DEQUE__
/* 接口 */
template<typename T>
class Deque {
public:
    virtual void addFirst(T data) = 0;

    virtual void addLast(T data) = 0;

    virtual ~Deque(){};

    bool isEmpty();

    virtual int getSize() = 0;

    virtual void printDeque() = 0;

    virtual T removeFirst() = 0;
    
    virtual T removeLast() = 0;

    virtual T get(int index) = 0;
};

template<typename T>
bool Deque<T>::isEmpty() {
    return this->getSize() == 0;
}

#endif