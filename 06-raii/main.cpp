#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
#include<string>
#include<cctype>
#include<sstream>




class Tracer{
    public:
        Tracer(const std::string& name):name_(name) { std::cout << "contruct " << name << '\n'; }
        ~Tracer() { std::cout << "destruct " << name_ << '\n'; }

    private:
    std::string name_;
};

void makeOne(){
    Tracer d("d");
}

class IntBuffer{
    public:
    //explicit IntBuffer(int size):data_(new int[size]{}),size_(size){}
    explicit IntBuffer(int size):data_(size),size_(size){}
    //~IntBuffer(){  delete[] data_ ;};
    int size() const;
    bool set(int index,int value);
    bool get(int index,int &value) const;
    
    private:
    //int* data_;
    std::vector<int> data_ ;
    int size_;

    //IntBuffer(const IntBuffer&) = delete;             // 禁止拷贝构造
    //IntBuffer& operator=(const IntBuffer&) = delete;  // 禁止拷贝赋值
};

bool IntBuffer::set(int index,int value){
    if(index < 0 || index >= static_cast<int>(data_.size()))
    {
        return false;
    }
    else {
        data_[index]=value;
    }
    return true;
}

bool IntBuffer::get(int index,int& value) const{
    if(index < 0 || index >= static_cast<int>(data_.size()))
    {
        return false;
    }
    else {
        value =data_[index];
    }
    return true;
}

int main(){
    Tracer a("a");
    {
        Tracer b("b");
        Tracer c("c");
    }
    makeOne();
    Tracer e("e");

    IntBuffer b1(4);
    IntBuffer b2=b1;
    std::cout<<b1.set(0,5)<<std::endl;
    std::cout<<b1.set(3,9)<<std::endl;
    std::cout<<b1.set(4,1)<<std::endl;
    std::cout<<b1.set(-1,1)<<std::endl;
}







//猜测一下 构造函数和析构 函数

//使用完析构 那么先 con a 
//b c在一起 先构造b 再构造 c 然后des 再des b
//makeone直接 构造d 然后des d
//last con e des e des a

//猜测顺序 con a con b con c des c des b con d des d con e des e des a

//构造函数运行后 确定运行周期结束 后 会自动析构
// 堆还是栈 反正是先进后出 可能是底层结构的问题

//忘记删除时 报错
/*
=================================================================
==98553==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 16 byte(s) in 1 object(s) allocated from:
    #0 0x7767ee4576c8 in operator new[](unsigned long) ../../../../src/libsanitizer/asan/asan_new_delete.cpp:98
    #1 0x573d3119b3c6 in IntBuffer::IntBuffer(int) /workspaces/cpp-basics/06-raii/main.cpp:27
    #2 0x573d3119ad1a in main /workspaces/cpp-basics/06-raii/main.cpp:48
    #3 0x7767ed7c41c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x7767ed7c428a in __libc_start_main_impl ../csu/libc-start.c:360
    #5 0x573d3119a504 in _start (/workspaces/cpp-basics/06-raii/main+0x4504) (BuildId: ed71be4f8a97971aae24abea93dd1762e791f347)

SUMMARY: AddressSanitizer: 16 byte(s) leaked in 1 allocation(s).
*/

//拷贝错误
/*
=================================================================
==99318==ERROR: AddressSanitizer: attempting double-free on 0x502000000010 in thread T0:
    #0 0x79ba47bbd1f8 in operator delete[](void*) ../../../../src/libsanitizer/asan/asan_new_delete.cpp:155
    #1 0x644a01d6f733 in IntBuffer::~IntBuffer() /workspaces/cpp-basics/06-raii/main.cpp:28
    #2 0x644a01d6ee20 in main /workspaces/cpp-basics/06-raii/main.cpp:50
    #3 0x79ba46f291c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x79ba46f2928a in __libc_start_main_impl ../csu/libc-start.c:360
    #5 0x644a01d6e564 in _start (/workspaces/cpp-basics/06-raii/main+0x4564) (BuildId: baf1cbee0c21d743447f316cc7a4fd3acf651200)

0x502000000010 is located 0 bytes inside of 16-byte region [0x502000000010,0x502000000020)
freed by thread T0 here:
    #0 0x79ba47bbd1f8 in operator delete[](void*) ../../../../src/libsanitizer/asan/asan_new_delete.cpp:155
    #1 0x644a01d6f733 in IntBuffer::~IntBuffer() /workspaces/cpp-basics/06-raii/main.cpp:28
    #2 0x644a01d6ee11 in main /workspaces/cpp-basics/06-raii/main.cpp:50
    #3 0x79ba46f291c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x79ba46f2928a in __libc_start_main_impl ../csu/libc-start.c:360
    #5 0x644a01d6e564 in _start (/workspaces/cpp-basics/06-raii/main+0x4564) (BuildId: baf1cbee0c21d743447f316cc7a4fd3acf651200)

previously allocated by thread T0 here:
    #0 0x79ba47bbc6c8 in operator new[](unsigned long) ../../../../src/libsanitizer/asan/asan_new_delete.cpp:98
    #1 0x644a01d6f4e0 in IntBuffer::IntBuffer(int) /workspaces/cpp-basics/06-raii/main.cpp:27
    #2 0x644a01d6ed86 in main /workspaces/cpp-basics/06-raii/main.cpp:48
    #3 0x79ba46f291c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x79ba46f2928a in __libc_start_main_impl ../csu/libc-start.c:360
    #5 0x644a01d6e564 in _start (/workspaces/cpp-basics/06-raii/main+0x4564) (BuildId: baf1cbee0c21d743447f316cc7a4fd3acf651200)

SUMMARY: AddressSanitizer: double-free ../../../../src/libsanitizer/asan/asan_new_delete.cpp:155 in operator delete[](void*)
==99318==ABORTING
*/

/* 编译错误 
@nen5555 ➜ /workspaces/cpp-basics/06-raii (main) $ g++ -std=c++17 -Wall -Wextra -Werror=return-type -g -fsanitize=address,undefined main.cpp -o main
main.cpp: In function ‘int main()’:
main.cpp:52:18: error: use of deleted function ‘IntBuffer::IntBuffer(const IntBuffer&)’
   52 |     IntBuffer b2=b1;
      |                  ^~
main.cpp:37:5: note: declared here
   37 |     IntBuffer(const IntBuffer&) = delete;             // 禁止拷贝构造
      |     ^~~~~~~~~
*/

// 如果只构造 不删除  容易内存泄漏
//默认只复制data_的话 那么b1结束后  其指针指向的区域已经释放 这时候b2 还是指向b1指向的方向 非法访问

// std::vector<int> data_ 是不是复制时 直接生成一块b1指向的副本 这样 删除 b1后 b2正常访问