#include<iostream>
#include<algorithm>
#include<iomanip>

int main(){
    int x;
    int sum=0;
    int max=0;
    int min=0;
    int count = 1;
    
    
    while(std::cin >> x && x!=0 ){

        sum += x;
        count +=1;
        max = std::max(max,x);
        min = std::min(min,x);

    }

    double avg  = static_cast<double>(sum)/count;
    std::cout << "sum = " << sum << '\n';   
    std::cout << "max = " << max << '\n';   
    std::cout << "min = " << min << '\n';  
    
    std::cout << std::fixed << std::setprecision(2) << avg << '\n';  // 3.14


}