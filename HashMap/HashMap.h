// 哈希表实现
#include <optional> // optional模板对象可以包含值也可以不包含值
#include <set>
#include <vector>

template <typename K, typename V>
class HashMap {
private:
    //=======structrue=======//
    class Node {
    public:
        K key;
        V val;
        Node(K k, V v) : key(k), val(v) {}
    };
    //=======
    std::vector<std::vector<Node>> buckets;
    int _size;
    int bucketSize;
    double loadFactor = 0.75;
    /* 定义哈希对象，
       如使用自定义类型需要在自定义类型内定义该类型的hash计算方法*/
    std::hash<K> myHash;
    //=======function=======//
    int floorMod(int a, int b);
    double load();
    bool isOverLoad();
    Node* findNode(const int& hashKey,const K& key);
    void resizeBuckets(const int& newSize);
public:
    HashMap() : HashMap(16) {}

    HashMap(int initialSize);

    HashMap(int initialSize, double maxLoad);
    // 清除所有映射
    void clear();

    bool containsKey(const K& key);

    std::optional<V> get(K key);

    int size();

    void put(K key, V val);

    std::set<K> keySet();

    std::optional<V> remove(K key);

    bool isEmpty() { return _size == 0; }
};

// ---------------------------------------------HashMap成员函数实现(public)----------------------------------------------------- //

template <typename K, typename V>
HashMap<K, V>::HashMap(int initialSize) {
    _size = 0;
    bucketSize = initialSize;
    buckets = std::vector<std::vector<Node>>(bucketSize);
}

template <typename K, typename V>
HashMap<K, V>::HashMap(int initialSize, double maxLoad) {
    _size = 0;
    bucketSize = initialSize;
    buckets = std::vector<std::vector<Node>>(bucketSize);
    loadFactor = maxLoad;
}

template <typename K, typename V>
void HashMap<K, V>::put(K key, V val) {
    size_t hashKey = myHash(key);
    if (isOverLoad()) {
        resizeBuckets(bucketSize * 2);
    }
    if (containsKey(key)) {
        Node* item = findNode(hashKey, key);
        if (item != nullptr)
            item->val = val;
    } else {
        buckets[floorMod(hashKey, bucketSize)].push_back(Node(key, val));
        _size += 1;
    }
}

template <typename K, typename V>
bool HashMap<K, V>::containsKey(const K &key) {
    int hashKey = myHash(key);
    for (const auto& item : buckets[floorMod(hashKey, bucketSize)]) {
        if (item.key == key) {
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
std::optional<V> HashMap<K, V>::get(K key) {
    int hashKey = myHash(key);
    if (!containsKey(key))
        return std::nullopt;
    for (const auto& item : buckets[floorMod(hashKey, bucketSize)]) {
        if (item == key) {
            return item.val;
        }
    }
}

template <typename K, typename V>
int HashMap<K, V>::size() {
    return _size;
}

template <typename K, typename V>
std::set<K> HashMap<K, V>::keySet() {
    std::set<K> resSet;
    if (isEmpty()) {
        return resSet;
    }
    for (const auto& bucket : buckets) {
        for (const auto& item : bucket) {
            resSet.insert(item.key);
        }
    }
    return resSet;
}

template <typename K, typename V>
std::optional<V> HashMap<K, V>::remove(K key) {
    int hashKey = myHash(key);
    V resV;
    int index = floorMod(hashKey, bucketSize);
    for (int i = 0; i < index; i += 1) {
        if (buckets[index][i].key == key) {
            resV = buckets[index][i].val;
            // 删除该桶中元素, 最后元素转移到删除元素位置，该桶执行pop_back()删除末尾元素
            buckets[index][i] = buckets[index].back();
            buckets[index].pop_back();
            _size -= 1;
            return resV;
        }
    }
    return std::nullopt;
}

template <typename K, typename V>
void HashMap<K, V>::clear() {
    if (isEmpty()) {
        return;
    }
    for (auto& bucket : buckets) {
        bucket.clear();
    }
    _size = 0;
    return;
}

// ---------------------------------------------HashMap成员函数实现(private)---------------------------------------------------- //
template <typename K, typename V>
int HashMap<K, V>::floorMod(int a, int b) {
    int res = a % b;
    if (res < 0) {
        res += b;
    }
    return res;
}

template <typename K, typename V>
double HashMap<K, V>::load() {
    return size() / (double)bucketSize;
}

template <typename K, typename V>
bool HashMap<K, V>::isOverLoad() {
    return load() > loadFactor;
}

template <typename K, typename V>
typename HashMap<K, V>::Node* HashMap<K, V>::findNode(const int& hashKey, const K& key) {
    for (auto& item : buckets[floorMod(hashKey, bucketSize)]) {
        if (item.key == key) {
            return &item;
        }
    }
    return nullptr;
}
// 时间复杂度是O(n)但是, 在hashMap的resize被均摊进了N次插入中，因为n次插入才可能执行一次resize
template <typename K, typename V>
void HashMap<K, V>::resizeBuckets(const int& newSize) {
    std::vector<std::vector<Node>> tempBuckets(newSize);
    int hashKey = 0;
    for (const auto& bucket : buckets) {
        for (Node node : bucket) {
            hashKey = myHash(node.key);
            tempBuckets[floorMod(hashKey, newSize)].push_back(node);
        }
    }
    buckets = std::move(tempBuckets);
    bucketSize = newSize;
}