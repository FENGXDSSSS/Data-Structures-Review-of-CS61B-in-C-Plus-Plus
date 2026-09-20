#include <chrono>
#include <iostream>
#include "LLRT.h"
#include "chrono"

int main(void) {
    RedBlackTree<int> a = RedBlackTree<int>();
    // 1000
    auto start = clock();
    for (int i = 0; i < 1000; i++) {
        a.put(i);
    }
    auto end = clock();
    std::cout << "数据量：1000          " <<(double)(end - start) / CLOCKS_PER_SEC << std::endl;

    // 10000
    start = clock();
    for (int i = 0; i < 10000; i++) {
        a.put(i);
    }
    end = clock();
    std::cout << "数据量：10000         " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
    
    // 100000
    start = clock();
    for (int i = 0; i < 100000; i++) {
        a.put(i);
    }
    end = clock();
    std::cout << "数据量：100000        " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    // 1000000
    start = clock();
    for (int i = 0; i < 1000000; i++) {
        a.put(i);
    }
    end = clock();
    std::cout << "数据量：1000000       " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    // 10000000
    start = clock();
    for (int i = 0; i < 10000000; i++) {
        a.put(i);
    }
    end = clock();
    std::cout << "数据量：10000000      " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    return 0;
} 