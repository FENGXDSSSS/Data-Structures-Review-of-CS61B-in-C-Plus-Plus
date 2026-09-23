#include <iostream>
#include "SLLists.h"

int main(void) {
    SLLists<int> a;
    SLLists<int> b;
    
    for (int i = 0; i < 10; i += 2) {
        a.addLast(i);
    }
    
    for (int i = 1; i < 10; i += 2) {
        b.addLast(i);
    }
    std::cout << "a: " ;
    for (int i = 0; i < a.getSize(); i += 1) {
        std::cout  << a.get(i) << " " ;
    }
    std::cout << std::endl ;
    std::cout << "b: " ;
    for (int i = 0; i < b.getSize(); i += 1) {
        std::cout << b.get(i) << " " ;
    }
    std::cout << std::endl;

    std::cout << "a + b: " ;
    SLLists<int> c =  SLLists<int>::merge(a, b);
    for (int i = 0; i < c.getSize(); i += 1) {
        std::cout <<  c.get(i) << " " ;
    }
    std::cout << std::endl;
}