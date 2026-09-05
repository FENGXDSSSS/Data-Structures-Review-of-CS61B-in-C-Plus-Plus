#include <ctime>
#include <iostream>
#include "ArrayQueue.h"

using namespace std;

int main(void) {
    cout << "1111" << endl;
    ArrayQueue<int> a = ArrayQueue<int>();
    srand(time(NULL));

    for (int i = 1; i <= 100; i++) {
        
        int randint = rand() % 100 + 1;
        if (randint >= 50) {
            a.addLast(i);
        } else {
            a.addFirst(i);
        }
    }

    for (int i = 0; i < 100; i++) {
        cout << a.removeLast() << " ";
    
    }

    cout << endl;
    return 0;
}   