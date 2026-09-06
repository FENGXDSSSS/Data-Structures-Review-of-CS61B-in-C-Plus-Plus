#ifndef __BBST__
#define __BBST__
#include <stdexcept>
#include <utility>

template <typename K, typename T>
class BST {
public:
    /* BST构造函数 */
    BST();

    /* BST析构函数 */
    ~BST();

    /* put方法 */
    void put(K inputKey, T inputVal);
    
    /* get方法 */
    T get(K key);

    /* size方法 */
    inline
    int size() { return size;}

    /* remove方法 */
    void remove(K inputKey);

private:
    // 节点类
    class Node {
    public:
        /* Node构造函数 */
        inline
        Node(K key, T val, Node *left = nullptr, Node *right = nullptr);

        /* Node析构函数 */
        inline
        ~Node();

        inline
        K getKey() {return key;}
        inline
        T getValue() {return value;}
        inline
        void setKey(K key) {return this->key = key;}
        inline
        void setValue(T val) {return this->value = val;}
        inline
        Node* left() {return _left;}
        inline
        Node* right() {return _right;}
        inline
        void setLeft(Node *root) {_left = root;}
        inline
        void setRight(Node *root) {_right = root;}
    private:
        Node *_left;
        Node *_right;
        K key;
        T value;
    };
    
    Node* find(Node *root, K key);
    bool isNoneChild(Node *Node);
    bool isOneChild(Node *Node);
    bool isTwoChild(Node *Node);
    std::pair<Node*, int> findParent(Node *root, Node *Node);
    Node* findRMin(Node *node);

    Node *root;
    int _size;
};

// ----------------------------------------------BST成员函数实现(public)----------------------------------------------------- //
/* BST构造函数实现 */
template <typename K, typename T>
BST<K,T>::BST() {
    root = nullptr;
    _size = 0;
}

/* BST构造函数实现 */
template <typename K, typename T>
BST<K,T>::~BST() {
    delete root;
}

/* put函数实现 */
template <typename K, typename T>
void BST<K, T>::put(K inputKey, T inputVal) {
    // 初始节点
    if (root == nullptr) {
        root = new Node(inputKey, inputVal);
        _size += 1;
        return;
    }
    Node *node = root;
    Node *parent = nullptr;
    int bias = -1;
    while (node != nullptr) {
        parent = node;
        if (node->getKey() < inputKey) {
            node = node->right();
            bias = 1;
        } else if (node->getKey() > inputKey){
            node = node->left();
            bias = 0;
        } else {
            node->setValue(inputVal);
            return;
        }
    }
    _size += 1;
    if (bias == 1)
        parent->setRight(new Node(inputKey, inputVal));
    
    else 
        parent->setLeft(new Node(inputKey, inputVal));
}

/* get函数实现 */
template <typename K, typename T>
T BST<K, T>::get(K key) {
    Node *node = find(root, key);
    if (node == nullptr) {
        throw std::out_of_range("Key not found in BST!");
    } else {
        return node->getValue();
    }
}

/* remove函数实现 */
template <typename K, typename T>
void BST<K, T>::remove(K inputKey) {
    Node *node = find(root, inputKey);
    if (node == nullptr) {
        return;
    }
    _size -=1;
    // 根节点的删除
    if (root == node) {
        if (isNoneChild(node)) {
            delete node;
            root = nullptr;
            return;
        } else if (isOneChild(node)) {
            if (node->right() != nullptr) {
                Node *rootR = node->right();
                delete node;
                root = rootR;
            } else {
                Node *rootL = node->left();
                delete node;
                root = rootL;
            }
        } else {
            Node *rMin = findRMin(node);
            // 先将Rmin右节点给rMin的父节点
            // 再将rMin移到root节点再移交root节点的L,R
            if (isOneChild(rMin)) {
                std::pair<Node*, int> rMinPa = findParent(root, rMin);
                rMinPa.second == 0 ? rMinPa.first->setLeft(rMin->right()) : rMinPa.first->setRight(rMin->right());
                root->setKey(rMin->getKey());
                root->setValue(rMin->getValue());
                delete rMin;
            } else if (isNoneChild(rMin)) {
                root->setKey(rMin->getKey());
                root->setValue(rMin->getValue());
                std::pair<Node*, int> rMinPa = findParent(root, rMin);
                rMinPa.second == 1 ? rMinPa.first->setRight(nullptr) : rMinPa.first->setLeft(nullptr) ; 
                delete rMin;
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        }
    } else {
        // 非根节点的删除
        if (isNoneChild(node)) {
            std::pair<Node*, int> nodePa = findParent(root, node);
            if (nodePa.second == 1) {
                nodePa.first->setRight(nullptr); // 父亲的右指针置空
            } else if (nodePa.second == 0) {
                nodePa.first->setLeft(nullptr);  // 父亲的左指针置空
            }
            delete node;
            return;
        } else if (isOneChild(node)) {
            std::pair<Node*, int> nodePa = findParent(root, node);
            if (nodePa.second == 1) {
                nodePa.first->setRight(node->right() == nullptr ? node->left() : node->right());
            } else if (nodePa.second == 0) {
                nodePa.first->setLeft(node->right() == nullptr ? node->left() : node->right());
            }
            delete node;
            return;
        } else {
            Node *rMin = findRMin(node);
            if (isNoneChild(rMin)) {
                node->setKey(rMin->getKey());
                node->setValue(rMin->getValue());
                std::pair<Node*, int> rMinPa = findParent(root, rMin);
                rMinPa.second == 1 ? rMinPa.first->setRight(nullptr) : rMinPa.first->setLeft(nullptr) ; 
                delete rMin;
                
            } else {
                std::pair<Node*, int> rMinPa = findParent(root, rMin);
                rMinPa.second == 0 ? rMinPa.first->setLeft(rMin->right()) : rMinPa.first->setRight(rMin->right());
                node->setKey(rMin->getKey());
                node->setValue(rMin->getValue());
                delete rMin;
            }
        }
    }
}

// ----------------------------------------------BST成员函数实现(private)---------------------------------------------------- //
/* find函数实现 */
template <typename K, typename T>
typename BST<K, T>::Node* BST<K, T>::find(Node *root, K key) {
    Node *node = root;
    while (node != nullptr) {
        int cmp = node->getKey() == key ? 0 : node->getKey() < key ? 1 : -1;

        if (cmp == 0) {
            return node; // 返回找到的节点
        // 向下继续查找
        } else if (cmp > 0) {
            node = node->right();
        } else {
            node = node->left();
        }
    }
    // 为查询到该节点
    return nullptr;
}

/* isNoneChild函数实现 */
template <typename K, typename T>
bool BST<K, T>::isNoneChild(Node *node) {
    return node->left() == nullptr && node->right() == nullptr;
}

/* isOneChild函数实现 */
template <typename K, typename T>
bool BST<K, T>::isOneChild(Node *node) {
    if (node->left() == nullptr && node->right() == nullptr) {
        return false;
    } else if (node->left() != nullptr && node->right() != nullptr) {
        return false;
    } else {
        return true;
    }
}

/* findParent函数实现 */
template <typename K, typename T>
std::pair<typename BST<K, T>::Node*, int> BST<K, T>::findParent(Node *root, Node *node) {
    Node *parent = nullptr;
    int bias = -1;
    while (root != nullptr) {
        parent = root;

        if (root->getKey() == node->getKey()) {
            std::pair<Node*, int> res = std::pair<Node*, int>(node, bias);
            return res;
        } else if (root->getKey() < node->getKey()) {
            root = root->right();
            bias = 1;
        } else {
            root = root->left();
            bias = 0;
        }
    }
    // 没有该节点
    return NULL;
}

/* */
template <typename K, typename T>
typename BST<K, T>::Node* BST<K, T>::findRMin(Node *node) {
    node = node->right();
    while (node->left() != nullptr) {
        node = node->left();
    }
    return node;
}

// ----------------------------------------------Node成员函数实现------------------------------------------------------------ //
/* Node构造函数实现 */
template <typename K, typename T>
BST<K,T>::Node::Node(K key, T val, Node *left, Node *right) {
    this->key = key;
    this->value = val;
    this->_left = left;
    this->_right = right;
}

/* Node析构函数实现 */
template <typename K, typename T>
BST<K,T>::Node::~Node() {
    delete _left;
    delete _right;
}

#endif