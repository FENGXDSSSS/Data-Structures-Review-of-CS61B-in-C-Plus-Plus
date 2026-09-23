// 左旋红黑树
/* #include <cstddef> */
#include <stack>
#include <iostream>

template <typename T>
class RedBlackTree {
private:
    class Node {
    public:
        inline
        Node(bool isBlack, T item, Node *left = nullptr, Node *right = nullptr);
        /* inline
        ~Node(); */
        inline 
        bool isBlack();
        inline
        void setBlack();
        inline
        void setRed();
        inline
        T get();
        inline
        void setItem(T item);
        
        Node *left;
        Node *right;
        bool _isBlack;
    private:
        
        T item;
    };
    Node *root;
    int _size;
    
    bool isRed(Node *node);
    bool isBlack(Node *node);
    Node* rotateRight(Node *node);
    Node* rotateLeft(Node *node);
    void flipColors(Node *node);
    void print(Node *node);
public:
    // 构造函数
    RedBlackTree();
    RedBlackTree(T item);
    // 析构函数-后序遍历
    ~RedBlackTree();
    // 插入数据
    void put(T item);
    Node* put(Node *root, T item);
    // 中序遍历
    void print();
    // 删除节点
    /* void remove(T item); */
};


// ----------------------------------------------LLRT成员函数实现(public)----------------------------------------------------- //
template <typename T>
RedBlackTree<T>::RedBlackTree() {
    _size = 0;
    root = nullptr;
}

template <typename T>
RedBlackTree<T>::RedBlackTree(T item) {
    root = new Node(false, item);
}

template <typename T>
RedBlackTree<T>::~RedBlackTree() {
    std::stack<Node*> st;
    
    st.push(root);
    Node *curr = nullptr;
    while (!st.empty()) {
        curr = st.top();
        st.pop();
        
        if (curr->left != nullptr) {
            st.push(curr->left);
        }

        if (curr->right != nullptr) {
            st.push(curr->right);
        }

        delete curr;
    }
       
}

template <typename T>
void RedBlackTree<T>::put(T item) {
    root = put(root, item);
    root->setBlack();
}

template <typename T>
typename RedBlackTree<T>::Node* RedBlackTree<T>::put(Node *root, T item) {
    if (root == nullptr) {
        return new Node(false, item);
    }
    if (item > root->get()) {
        root->right = put(root->right, item);
    } else if (item < root->get()) {
        root->left = put(root->left, item);
    } else {
        root->setItem(item);
    }
    // 如果右子节点是红色，左子节点不是红色，因为此为左倾黑红树，所以此节点左旋
    if (isRed(root->right) && !isRed(root->left)) {
        root = rotateLeft(root);
    }
    // 如果左子节点和左子节点的左子节点均为红色，该节点需要有序操作
    if (isRed(root->left) && isRed(root->left->left)) {
        root = rotateRight(root);
    }
    
    if (isRed(root->left) && isRed(root->right)) {
        flipColors(root);
    }
    
    return root;
}

template <typename T>
void RedBlackTree<T>::print() {
    print(root);
}
// ----------------------------------------------LLRT成员函数实现(private)----------------------------------------------------- //
template <typename T>
bool RedBlackTree<T>::isRed(Node *node) {
    return node != nullptr && !node->isBlack();
}

template <typename T>
bool RedBlackTree<T>::isBlack(Node *node) {
    return node != nullptr && node->isBlack();
}

// 右旋
template <typename T>
typename RedBlackTree<T>::Node* RedBlackTree<T>::rotateRight(Node *node) {
    Node *tempRoot = node; //当前父节点
    node = tempRoot->left;
    // 将原父节点的
    tempRoot->left = node->right;
    node->right = tempRoot;
    // 颜色互换
    bool color = node->isBlack();
    node->_isBlack = tempRoot->isBlack();
    tempRoot->_isBlack = color;
    
    return node;
}

// 左旋
template <typename T>
typename RedBlackTree<T>::Node* RedBlackTree<T>::rotateLeft(Node *node) {
    Node *tempRoot = node; // 当前父节点
    node = tempRoot->right;
    // 将原父节点的右子节点的左子节点赋给原父节点的右子节点
    tempRoot->right = node->left;
    node->left = tempRoot;
    // 颜色互换
    bool color = node->isBlack();
    /* node->_isBlack = tempRoot->isBlack();
    tempRoot->_isBlack = color; */
    tempRoot->isBlack() ? node->setBlack() : node->setRed();
    color ? tempRoot->setBlack() : tempRoot->setRed();

    return node;
}

template <typename T>
void RedBlackTree<T>::flipColors(Node *node) {
    node->setRed(); // 红节点的父节点
    // 父节点的左右子节点置黑
    node->left->setBlack();
    node->right->setBlack();
}

template <typename T>
void RedBlackTree<T>::print(Node *node) {
    std::stack<Node*> st;
    int flag = 0;
    if (node == nullptr) {
        return;
    }
    while (node != nullptr || !st.empty()) {
        if (node != nullptr) {
            st.push(node);
            node = node->left;
        } else {
            node = st.top();
            st.pop();
            if (flag % 10 == 0)
                std::cout << std::endl;
            std::cout << node->get() << " ";
            flag += 1;
            node = node->right;
        }
    }
}
// ----------------------------------------------Node成员函数实现----------------------------------------------------- //
template <typename T>
RedBlackTree<T>::Node::Node (bool isBlack, T item, Node *left, Node *right) {
    this->_isBlack = isBlack;
    this->item = item;
    this->left = left;
    this->right = right;
}

        /* template <typename T>
RedBlackTree<T>::Node::~Node () {
    delete this;
} */

template <typename T>
bool RedBlackTree<T>::Node::isBlack() {
    return this->_isBlack;
}

template <typename T>
void RedBlackTree<T>::Node::setBlack() {
    this->_isBlack = true;
}

template <typename T>
void RedBlackTree<T>::Node::setRed() {
    this->_isBlack = false;
}

template <typename T>
T RedBlackTree<T>::Node::get() {
    return this->item;
}

template <typename T>
void RedBlackTree<T>::Node::setItem(T item) {
    this->item = item;
}