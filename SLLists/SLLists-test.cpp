#include <iostream>
#include "SLLists.h"

int main(void) {
    SLLists<int> testList = SLLists<int>();
    testList.addFirst(1); // index == 0 size == 1
    testList.addLast(2); // index == 1 size == 2
    std::cout << testList.get(0) << std::endl << testList.get(1) << std::endl;
    testList.insert(3, 1); // index == 1 size == 3
    std::cout << testList.get(1) << " " << testList.get(2) << std::endl; // 3 2
    testList.insert(4, 0); // index == 0 size == 4
    std::cout << testList.get(0) << " " << testList.get(1) << std::endl; // 4 1
    std::cout << "Size: " << testList.getSize() << std::endl;
    testList.insert(5,4); // index == 5 size == 5
    std::cout << testList.get(4) << " " << std::endl; // 5
    testList.insert(6, 10);
    testList.get(1);
}