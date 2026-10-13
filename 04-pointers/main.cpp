#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
#include<string>
#include<cctype>
#include<sstream>


void swapByPtr(int*a ,int *b){
    int p =0;;
    p=*a;
    *a = *b;
    *b = p;

} //int a,int b只是值传递 相当于传了一个副本 修改副本 不会改变原来的值 int &a,int&b 引用传递 可以理解为指向同一块区域的别名 修改内存区的值 达到改变数值
//int *a int *b 直接传 a,b的地址 *a来指向a区域，然后表达式中 *a直接修改区域的数字
//注意 值传递和引用传递 都为 函数（a,b）指针传递 函数（&a，&b）

int* findMax(int* arr,int n){
    int *p = arr;
    if(n==0)
    return nullptr;

   
    for(int i=0;i<n;i++){
       if( *p < arr[i])
        p = &arr[i];

    }
    return p;
}
int main(){

    int a = 10;
    int* p =&a;
    std::cout <<"a的地址为" << p << std::endl;
    std::cout <<"a的数值为" << *p << std::endl;
    *p=20;
    std::cout <<"a修改后的数值为" << *p << std::endl;

    int c =20;
    int d = 30;

    
    std::cout <<"c的数值为" << c << std::endl;
    std::cout <<"d的数值为" << d << std::endl;
    swapByPtr(&c,&d);

    std::cout <<"交换后c的数值为" << c << std::endl;
    std::cout <<"交换后d的数值为" << d << std::endl;

    //int arr[5] = {3,9,1,7,4};
    int arr1[5] = {13,9,1,7,4};
    //int arr2[5] = {3,9,1,7,14};
    

    int* max=nullptr;
    if(findMax(arr1,5) == nullptr){
        std::cout << " arr is empty" <<std::endl;
    }

    max = findMax(arr1,5);

    std::cout <<"max的数值为" << *max << std::endl;

    *max= 0;
    for(int x:arr1){
        std::cout << x <<" ";
    }
    std::cout <<std::endl;

    // int * nupt = nullptr;
    // int nuptnum = *nupt;

    //  std::cout <<"manuptx的数值为" << nuptnum << std::endl;








}

