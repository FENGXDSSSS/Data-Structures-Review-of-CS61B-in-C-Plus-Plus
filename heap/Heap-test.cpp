#include <ctime>
#include <iostream>
#include "MinHeap.h"
#include <stdlib.h>


int main(void) {
    MinHeap<int> a;
    MinHeap<int> b;
    MinHeap<int> c;
    MinHeap<int> d;
    MinHeap<int> e;
    srand(time(0));  
    double start = clock();
    for (int i = 0; i < 1000; i++) {
        a.put(rand() % 1000);
    }
    double end = clock();
    std::cout << "put:" << std::endl;
    std::cout << "数据量1000: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
    
    srand(time(0));  
    start = clock();
    for (int i = 0; i < 10000; i++) {
        b.put(rand() % 10000);
    }
    end = clock();
    std::cout << "数据量10000: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    srand(time(0));  
    start = clock();
    for (int i = 0; i < 100000; i++) {
        c.put(rand() % 100000);
    }
    end = clock();
    std::cout << "数据量100000: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    srand(time(0));  
    start = clock();
    for (int i = 0; i < 1000000; i++) {
        d.put(rand() % 1000000);
    }
    end = clock();
    std::cout << "数据量1000000: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    srand(time(0));  
    start = clock();
    for (int i = 0; i < 10000000; i++) {
        e.put(rand() % 10000000);
    }
    end = clock();
    std::cout << "数据量10000000: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    //---------------------------------------removeMin----------------------------------------//
    srand(time(0));  
    start = clock();
    for (int i = 0; i < 1000; i++) {
        a.removeMin();
    }
    end = clock();
    std::cout << "removeMin:" << std::endl;
    std::cout << "数据量1000: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    srand(time(0));  
    start = clock();
    for (int i = 0; i < 10000; i++) {
        b.removeMin();
    }
    end = clock();
    std::cout << "数据量10000: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    srand(time(0));  
    start = clock();
    for (int i = 0; i < 100000; i++) {
        c.removeMin();
    }
    end = clock();
    std::cout << "数据量100000: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    srand(time(0));  
    start = clock();
    for (int i = 0; i < 1000000; i++) {
        d.removeMin();
    }
    end = clock();
    std::cout << "数据量1000000: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    srand(time(0));  
    start = clock();
    for (int i = 0; i < 10000000; i++) {
        e.removeMin();
    }
    end = clock();
    std::cout << "数据量10000000: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
    
    return 0;
}