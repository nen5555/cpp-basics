#include <iostream>
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

//第三步试验b时时生成.ow文件时 出现了 所以编译时看单文件