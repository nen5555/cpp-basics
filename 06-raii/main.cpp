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

int main(){
    Tracer a("a");
    {
        Tracer b("b");
        Tracer c("c");
    }
    makeOne();
    Tracer e("e");

}



//猜测一下 构造函数和析构 函数

//使用完析构 那么先 con a 
//b c在一起 先构造b 再构造 c 然后des 再des b
//makeone直接 构造d 然后des d
//last con e des e des a

//猜测顺序 con a con b con c des c des b con d des d con e des e des a

//构造函数运行后 确定运行周期结束 后 会自动析构
// 堆还是栈 反正是先进后出 可能是底层结构的问题