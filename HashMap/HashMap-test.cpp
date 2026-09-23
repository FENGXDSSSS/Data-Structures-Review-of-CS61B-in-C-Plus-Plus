#include <iostream>
#include "HashMap.h"
#include <unordered_map>
#include <ctime>

using namespace std;

int main(void) {
    HashMap<int, int> a;
    HashMap<int, int> b;
    HashMap<int, int> c;
    HashMap<int, int> d;
    double start = clock();
    for (int i = 0; i < 100000; i += 1) {
        a.put(i, i);
    }
    double end =clock();
    cout << "数据量100000: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    for (int i = 0; i < 1000000; i += 1) {
        b.put(i, i);
    }
    end = clock();
    cout << "数据量1000000: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    
    start = clock();
    for (int i = 0; i < 10000000; i += 1) {
        c.put(i, i);
    }
    end = clock();
    cout << "数据量10000000: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    
    start = clock();
    for (int i = 0; i < 100000000; i += 1) {
        d.put(i, i);
    }
    end = clock();
    cout << "数据量100000000: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    // ------------------删除-----------------//
    start = clock();
    for (int i = 0; i < 100000; i += 1) {
        a.remove(i);
    }
    end = clock();
    cout << "数据量100000: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    for (int i = 0; i < 1000000; i += 1) {
        b.remove(i);
    }
    end = clock();
    cout << "数据量1000000: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    for (int i = 0; i < 10000000; i += 1) {
        c.remove(i);
    }
    end = clock();
    cout << "数据量10000000: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    for (int i = 0; i < 100000000; i += 1) {
        d.remove(i);
    }
    end = clock();
    cout << "数据量100000000: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    unordered_map<int, int> aa;
    start = clock();
    for (int i = 0; i < 100000000; i += 1) {
        aa[i] = i;
    }
    end = clock();
    cout << "标准库map数据量100000000: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    for (int i = 0; i < 100000000; i += 1) {
        aa.erase(i);
    }
    end = clock();
    cout << "标准库map erase数据量100000000: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
