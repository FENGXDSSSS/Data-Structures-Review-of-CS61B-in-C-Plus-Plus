#include <iostream>
#include "SLLists.h"

int main(void) {
    SLLists<int> testList = SLLists<int>();
    testList.addFirst(1);
    testList.addLast(2);
    std::cout << testList.get(0) << std::endl << testList.get(1) << std::endl;
    testList.get(1);
}