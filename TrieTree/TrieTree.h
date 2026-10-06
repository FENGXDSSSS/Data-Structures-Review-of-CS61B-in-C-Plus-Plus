// 字典树
#include <cstddef>
#include <map>
#include <stdexcept>
#include <string>

class Trie{
private:
    class Node {
    public:
        std::map<char, Node*> branch;
        bool isKey;
        int data;
        
        Node() : isKey(false), data(NULL) {}
        Node(bool _isKey, int _data) : isKey(_isKey), data(_data) {}
        int getData() { return data; }
        void setKey(char ch, Node* node) { branch[ch] = node; }
        void setIsKey(bool isOrNo) { isKey = isOrNo; }
        void setData(int val) { data = val; }
    };

    int _size;
    Node *root;
public:
    inline
    Trie();
    inline
    void insert(std::string key, int val);
    inline
    int get(std::string key);
    inline
    bool contains(std::string key);
    inline
    void remove(std::string key);
    inline
    int getSize();
};

Trie::Trie() {
    root = new Node();
    _size = 0;
}

void Trie::insert(std::string key, int val) {
    Node *parent = root;
    for (auto ch : key) {
        // 如果有ch节点向下推进
        if (parent->branch[ch] != nullptr) {
            parent = parent->branch[ch];
        } else {
            // 当前节点不存在ch分支
            parent->branch[ch] = new Node();
        }
    }
    parent->setIsKey(true);
    parent->setData(val);
}

int Trie::get(std::string key) {
    Node *parent = root;
    if (!contains(key)) {
        throw std::out_of_range(" ");
    }
    // 只有作为key的字符串才会执行循环
    for (auto ch : key) {
        parent = parent->branch[ch];
    }
    return parent->data;
}

bool Trie::contains(std::string key) {
    Node *parent = root;
    int flag = 0;
    for (int i = 0; i < key.size(); i += 1) {
        if (parent->branch.contains(key.at(i)) && key.at(key.size() - 1) == key.at(i)) {
            if (parent->isKey) {
                flag = 1;
                break;
            } else {
                break;
            }
        }
        // 如果包含元素
        if (parent->branch.contains(key.at(i))) {
            parent = parent->branch[key.at(i)];
        } else {
            return false;
        }
    }
    if (flag == 1) {
        return true;
    } else {
        return false;
    }
}

void Trie::remove(std::string key) {
    Node *parent = root;
    if (!contains(key)) {
        return;
    }
    for (auto ch : key) {
        parent = parent->branch[ch];
    }
    // 移除目标节点的isKey状态
    parent->setIsKey(false);
    parent->setData(NULL);
}