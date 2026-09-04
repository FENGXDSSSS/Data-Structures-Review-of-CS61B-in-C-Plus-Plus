#include <iostream>
#include "ALists.h"

int main() {
    ALists<int> list = ALists<int>();
    for (int i = 1; i <= 100; i++) {
        list.add(i);
    }
    std::cout << list.getSize() <<std::endl;
    std::cout << list.get(0) << std::endl;
    std::cout << list.get(99) << std::endl;
    std::cout << list.get(18) << std::endl;

    for (int i = 0; i <= 90; i++) {
        list.removeLast();
    }
    std::cout << list.getSize() << std::endl;
    std::cout << list.get(8) << std::endl;

    list.remove(2);

    return 0;
}