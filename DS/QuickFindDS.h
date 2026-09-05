#ifndef __QUEICKFINDDS__
#define __QUEICKFINDDS__


class QuickFDS {
public:
    /* QuickFDS构造函数 */
    inline
    QuickFDS(int n);

    /* QuickFDS析构函数 */
    inline
    ~QuickFDS();

    /* A 包含 B connect函数 */
    inline
    void connect(int a, int b);

    /* A 是否包含 B isConnect函数 */
    inline
    bool isConnect(int a, int b);

private:
    int *id;
    int n;
};

// --------------------------------------------QuickFDS成员函数实现(public)------------------------------------------------------ //
/* QuickFDS构造函数实现 */
QuickFDS::QuickFDS(int n) {
    this->n = n;
    id = new int[n];
    for (int i = 0; i < n; i++) 
       	id[i] = i;
}


/* QuickFDS析构函数实现 */
QuickFDS::~QuickFDS() {
    delete[] id;
}
/* connect函数实现 */
void QuickFDS::connect(int a, int b) {
    int aid = id[a];
    int bid = id[b];
    for (int i = 0; i < n; i++) {
        if (id[i] == aid) {
            id[i] = bid;
        }
    }
}
/* isConnect函数实现 */
bool QuickFDS::isConnect(int a, int b) {
    return id[a] == id[b];
}



#endif