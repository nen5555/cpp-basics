#include <iostream>
#include "ring_buffer.h"
#include "ring_buffer.h"


int main() {
    RingBuffer buffer;

    for (int i = 0; i < 5; ++i) {
        if (buffer.push(i)) {
            std::cout << "Pushed: " << i << std::endl;
        } else {
            std::cout << "Buffer full, cannot push: " << i << std::endl;
        }
    }

    int value;
    while (buffer.pop(value)) {
        std::cout << "Popped: " << value << std::endl;
    }

    return 0;
}