#include<iostream>
#include<algorithm>
#include<iomanip>
#include<limits>

int main(){
    int x;
    long long  sum=0;
    int max   = std::numeric_limits<int>::lowest();
    int min   = std::numeric_limits<int>::max();
   
    int count = 0;

    
    
    
    while(std::cin >> x && x!=0 ){
        sum += x;
        count +=1;
        max = std::max(max,x);
        min = std::min(min,x);

    }

    double avg  = static_cast<double>(sum)/count;
    if(!count){
        max=0;
        min=0;
        avg=0;
    }

    
    
    std::cout << "sum = " << sum << '\n';   
    std::cout << "max = " << max << '\n';   
    std::cout << "min = " << min << '\n';  
    std::cout << "count = " << count <<"\n";
    
    std::cout <<"avg = "<< std::fixed << std::setprecision(2) << avg << '\n';  


}