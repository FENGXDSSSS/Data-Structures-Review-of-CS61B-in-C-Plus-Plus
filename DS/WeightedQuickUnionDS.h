#ifndef __WQUDS__
#define __WQUDS__
#include <vector>

class WQUDS {
public:
    /* WQUDS构造函数 */
    inline 
    WQUDS(int n);

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

// --------------------------------------------WQUDS成员函数实现(private)------------------------------------------------------ //
/* WQUDS构造函数实现 */
inline
WQUDS::WQUDS(int n) {
    parent = std::vector<int>(n);
    for (int i = 0; i < parent.size(); i++) {
        parent[i] = -1;
    }
}

/* connect函数实现 */
inline
void WQUDS::connect(int a, int b) {
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
bool WQUDS::isConnect(int a, int b){
    return find(a) == find(b);
}


// --------------------------------------------WQUDS成员函数实现(private)------------------------------------------------------ //
/* find函数实现 */
inline 
int WQUDS::find(int a) {
    int r = a;
    while (parent[r] >= 0) {
        r = parent[r];
    }
    return r;
}

#endif