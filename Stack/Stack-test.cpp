#include <cstddef>
#include <iostream>
#include "Stack.h"

int main(void) {
    Stack<int> stack = Stack<int>();
    
    for (int i = 1; i <= 100; i++) {
        stack.push(i);
    }
    std::cout << stack.peek() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.getSize() <<std
    std::cout << stack.isEmpty() << std::endl;::endl;
    for (int i = 1; i <= 99; i++) {
        stack.pop();
    }
    std::cout << stack.isEmpty() << std::endl;
    std::cout << stack.getSize() << std::endl;
    
    return 0;
}