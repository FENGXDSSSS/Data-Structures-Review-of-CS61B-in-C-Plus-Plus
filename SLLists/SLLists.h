#ifndef __SLLists__
#define __SLLists__

// 单链表的实现
#include <iostream>
#include <stdexcept>
template <typename T>
class SLLists {
    // 公共方法(对外接口)
public:
    // 单链表的构造函数
    SLLists();
    SLLists(T data);

    // 析构函数
    ~SLLists();

    // 添加链表节点
    inline
    void addLast(T data); // 添加到末尾
    inline
    void addFirst(T data); // 添加到表头
    
    // 获取链表节点
    T get(int n);

    // 返回链表的项目的大小
    int getSize();
    
private:
    // 嵌套类，链表节点
    struct Node {
    public:
        // 节点的构造函数
        inline
        Node(T userData, Node* itNext = NULL);
        // 获取此节点的下一个节点地址
        inline
        Node* getNext();
        // 获取此节点的当前数据
        inline
        T getData();
        // 设置下一个节点
        inline 
        void setNext(Node* node);
    private:
        // 下一个节点，存放下一个节点的地址
        Node *next;
        // 数据
        T data;
    };
    int size; // 当前容量
    Node* head; // 哨兵节点
    /* SLLists的辅助方法 */
    void rDeleteNode(Node *node);
};
// --------------------------------------------SLLists成员方法实现----------------------------------------- //
/* SLLists 构造函数实现 */
template <typename T>
SLLists<T>::SLLists() {
    size = 0;
    head = new Node(T());
}

template <typename T>
SLLists<T>::SLLists(T data) {
    size = 1;
    head = new Node(T());
    head->setNext(new Node(data));
}
/* SLLists 析构函数实现 */
// 辅助SLLists析构的方法 
template <typename T>
void SLLists<T>::rDeleteNode(Node *node) {
    if (node->getNext() == NULL) {
        return;
    }
    rDeleteNode(node->getNext());
    delete node;
}

template <typename T>
SLLists<T>::~SLLists() {
    rDeleteNode(head);
}

/* add方法实现 */
// addLast
template <typename T>
void SLLists<T>::addLast(T data) {
    Node* tempNode = head;
    if (tempNode->getNext() == NULL) {
        tempNode->setNext(new Node(data));
        size += 1;
        return;
    } 
    while (tempNode->getNext() != NULL) {
        tempNode = tempNode->getNext();
    }
    if (tempNode->getNext() == NULL) {
        tempNode->setNext(new Node(data));
        size += 1;
    }
}

// addFirst
template <typename T>
void SLLists<T>::addFirst(T data) {
    if (head->getNext() == NULL) {
        head->setNext(new Node(data));
        size += 1;
        return;
    }
    Node* tempNode = head->getNext();
    head->setNext(new Node(data, tempNode));
    size += 1;
    return;
}

/* get方法实现 */
template <typename T>
T SLLists<T>::get(int n) {
    if (n >= size) {
        throw std::out_of_range("SLLists::get() : Index out of range");
    }
    Node* tempNode = head->getNext();
    if (n == 0) {
        return tempNode->getData();
    }
    while(n != 0) {
        tempNode = tempNode->getNext();
        n -= 1;
    }
    return tempNode->getData();
}

/* getSize方法实现 */
template <typename T> 
int SLLists<T>::getSize() {
    return this->size;
}

// --------------------------------------------Node成员方法实现-------------------------------------------- //
// Node 构造函数的外部实现
template <typename T>
SLLists<T>::SLLists::Node::Node(T userData, Node* itNext) 
    : data(userData), next(itNext){ }
template <typename T>
// getData
T SLLists<T>::Node::getData() {
    return this->data;
}
// getNode
template <typename T>
typename SLLists<T>::Node* SLLists<T>::Node::getNext() {
    return this->next;
}
// setNext
template <typename T>
void SLLists<T>::Node::setNext(Node* node) {
    this->next = node;
}
#endif