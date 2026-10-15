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

    int a;
    int b;
    buffer.pop(a);
    buffer.pop(b);
     std::cout << "Popped: " << a << std::endl;
     std::cout << "Popped: " << b << std::endl;

    buffer.push(5);
    buffer.push(6);

    int value;
    while (buffer.pop(value)) {
        std::cout << "Popped: " << value << std::endl;
    }

    return 0;
}

//第三步试验b时时生成.ow文件时 出现了 所以编译时看单文件
//只单独编译 main.cpp 到.o文件 正常 运行时错误，应该是链接

//单独h文件加const 
/*
ing_buffer.h:3:7: note: 'class RingBuffer' defined here
    3 | class RingBuffer{
      |       ^~~~~~~~~~
ring_buffer.cpp:19:6: error: no declaration matches 'bool RingBuffer::push(int)'
   19 | bool RingBuffer::push(int a) {
      |      ^~~~~~~~~~
*/

/*
都加了const/
ring_buffer.h:8:5: warning: type qualifiers ignored on function return type [-Wignored-qualifiers]
    8 |     const int size();
      |     ^~~~~
In file included from ring_buffer.cpp:1:
ring_buffer.h:6:5: warning: type qualifiers ignored on function return type [-Wignored-qualifiers]
    6 |     const bool empty();
      |     ^~~~~
ring_buffer.h:7:5: warning: type qualifiers ignored on function return type [-Wignored-qualifiers]
*/