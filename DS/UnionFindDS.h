#ifndef __UINIOFINDDS__
#define __UINIOFINDDS__
#include <vector>

class UnionFindDS {
public:
    /* UnionFindDS构造函数 */
    inline
    UnionFindDS(int n);

    /* isConnect函数实现 */
    inline
    bool isConnect(int a, int b);
    
    /* Connect函数实现 */
    inline
    void Connect(int a, int b);

private:
    inline
    int find(int a);

    std::vector<int> parent;
};
// --------------------------------------------UnionFindDS成员函数实现(public)------------------------------------------------------ //
/* UnionFindDS构造函数实现 */
inline
UnionFindDS::UnionFindDS(int n) {
    parent = std::vector<int>(n);
    for (int i = 0; i < parent.size(); i++) {
        parent[i] = -1;
    }
}

/* isConnect函数实现 */
inline
bool UnionFindDS::isConnect(int a, int b) {
    return find(a) == find(b);
}

/* connect函数实现 */
inline
void UnionFindDS::Connect(int a, int b) {
    int ap = find(a);
    int bp = find(b);
    if (ap != bp) {
        parent[ap] = bp;
    }
}

// --------------------------------------------UnionFindDS成员函数实现(private)------------------------------------------------------ //
/* find函数实现 */
inline
int UnionFindDS::find(int a) {
    int r = a;
    while (parent[r] >= 0) {
        r = parent[r];
    }
    return r;
}

#endif