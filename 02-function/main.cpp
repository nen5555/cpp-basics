#include<iostream>
#include<algorithm>
#include<limits>


bool isPrime(int n);
int gcd(int a,int b);
void swapByValue(int a,int b);
void swapByRef(int &a,int&b);
bool safeDivide(double a,double b,double& result);

int main(){

    int a=5;
    int b=6;
    double result = 0;

    std::cout << std::boolalpha << isPrime(7) << '\n';
    std::cout << std::boolalpha << isPrime(-1) << '\n';
    std::cout << std::boolalpha << isPrime(0) << '\n';
    std::cout << std::boolalpha << isPrime(1) << '\n';
    std::cout << std::boolalpha << isPrime(8) << '\n';

    std::cout <<"the gcd(a,b) is" <<gcd(0,2)<<"\n";
    std::cout <<"the gcd(a,b) is" <<gcd(4,2)<<"\n";
    std::cout <<"the gcd(a,b) is" <<gcd(7,2)<<"\n";
    std::cout <<"the gcd(a,b) is" <<gcd(46,92)<<"\n";
    std::cout <<"the gcd(a,b) is" <<gcd(6,9)<<"\n";

    swapByValue(a,b);

    std::cout <<"the swapByValue the a =" << a <<"\n"; 
    std::cout <<"the swapByValue the b =" << b <<"\n"; 

    swapByRef(a,b);

    std::cout <<"the swapByValue the a =" << a <<"\n"; 
    std::cout <<"the swapByValue the b =" << b <<"\n"; 

    double c=0;
    double d=1;
    double e=0;
    double f=5;

    if(safeDivide(d,c,result)){
        std::cout << "result" <<result<<std::endl;
    }else{
        std::cout <<"分子或分母为0" <<std::endl;
    }
    if(safeDivide(e,c,result)){
        std::cout << "result" <<result<<std::endl;
    }else{
        std::cout <<"分子或分母为0" <<std::endl;
    }
    if(safeDivide(f,d,result)){
        std::cout << "result" <<result<<std::endl;
    }else{
        std::cout <<"分子或分母为0" <<std::endl;
    }

    if(safeDivide(d,f,result)){
        std::cout << "result" <<result<<std::endl;
    }else{
        std::cout <<"分子或分母为0" <<std::endl;
    }



}

bool isPrime(int n){
    int i=2;
    if(n<2)
        return 0;
    else{
        for(i=2;i<n-1;i++){
            if(n%i == 0)
            return 0;
        };
        return 1;
    }
};
int gcd(int a,int b){
    int j_min = a>b?b:a;
    int j_max = a>b?a:b;
    int i=2;
    if(j_max == 0 && j_min ==0)
    {
        return 0;
    }else if(j_max !=0 && j_min==0){
        return j_max;
    }  
    else if(j_max % j_min ==0){
        return j_min;
    }else{
        for(i=j_min-1;i>0;i--){
        if(a%i == 0 && b%i==0)
            return i;
        }
    };
    return 0;
};

void swapByValue(int a,int b){
    int swap=0;
    swap =a;
    a=b;
    b=swap;
};//swap为中间数字 先将a的数字赋值给swap,然后将b的数值赋值给a,最后将swap存储的数字赋值给b。但是主函数传送到函数内的只是副本
// 函数里面的a,b交换了 是副本交换
//只在函数内 所以函数外数字没交换

void swapByRef(int &a,int& b){
  int temp=0;
  temp =a;
  a=b;
  b=temp;
};//int&a 相当于输入x 然后给取名 a,就是相当于int型变量，不过 不能通过去指针来改变 x的原始数据

bool safeDivide(double a,double b,double& result){
    
    if(b==0)
        return 0;
    else{
        result = (a)/b;
    }

    return 1;
    
    
};
