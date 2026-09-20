#include <iostream>
#include "SLLists.h"

int main(void) {
    SLLists<int> testList = SLLists<int>();
    
    for (int i = 0; i < 4; i++) {
        testList.addLast(i * 2);
    }
    
    for (int i = 0; i < testList.getSize(); i++) {
        std::cout << testList.get(i) << " ";
    }
    std::cout << std::endl;

    SLLists<int> testList2 = SLLists<int>();
    for (int i = 1; i < 4; i++) {
        testList2.addLast(i);
    }
    for (int i = 0; i < testList2.getSize(); i++) {
        std::cout << testList2.get(i) << " ";
    }
    std::cout << std::endl;
    
    


    testList.get(1);
}