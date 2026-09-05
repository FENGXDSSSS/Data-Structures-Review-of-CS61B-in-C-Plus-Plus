#ifndef __WQUDSPC__
#define __WQUDSPC__
#include <vector>

class WQUDSPC {
public:
    /* WQUDSQC构造函数 */
    inline
    WQUDSPC(int n);

    /* connect函数 */
    inline
    void connect(int a, int b);

    /* isconnect函数 */
    inline 
    bool isConnect(int a, int b);

private:
    /* find函数实现 */    
    inline 
    int find(int a);
    
    std::vector<int> parent;
};

// --------------------------------------------WQUDSQC成员函数实现(private)------------------------------------------------------ //
/* WQUDSQC构造函数实现 */
inline
WQUDSPC::WQUDSPC(int n) {
    parent = std::vector<int>(n);
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
}

/* connect函数实现 */
inline
void WQUDSPC::connect(int a, int b) {
    int aParent = find(a);
    int bParent = find(b);
    
    if (aParent == bParent) {
        return;
    }

    int aParentSize = -parent[aParent];
    int bParentSize = -parent[bParent];
    
    if (aParentSize < bParentSize) {
        parent[aParent] = bParent;   
        parent[bParent] = -(aParentSize + bParentSize);
    } else {
        parent[bParent] = aParent;
        parent[aParent] = -(aParentSize + bParentSize);
    }
}

/* isconnect函数实现 */
inline
bool WQUDSPC::isConnect(int a, int b) {
    return find(a) == find(b);
}

// --------------------------------------------WQUDSQC成员函数实现(private)------------------------------------------------------ //
/* find函数实现 */
int WQUDSPC::find(int a) {
    int r = a;
    while (parent[r] >= 0) {
        r = parent[r];
    }
 
    int cur = a;
    while (cur != r) {
        int next = parent[cur];
        parent[cur] = r;
        cur = next;
    }
    return r;
}


#endif