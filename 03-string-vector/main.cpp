#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
#include<string>
#include<cctype>
#include<sstream>

void printAll(const std::vector<int>& v);
void printReverse(const std::vector<int>& v);
bool median(std::vector<int> v,double& result);
int countGreater(const std::vector<int>& v,int threshold);

int countWords(const std::string& s);
bool isPalindrome(const std::string& s);
std::string toUpper(const std::string& s);

int main(){
    std::vector<int> v;
    int x;
    double result;
    int threshold=1;

    while(std::cin >> x && x!=0 ){
        v.push_back(x);
    }

    printAll(v);
    printReverse(v);
    if(median(v,result)){
        std::cout << "result" << result << std::endl;
    }else{
        std::cout << "v is empty" << std::endl;
    };
    int num = countGreater(v,threshold);
    std::cout << "number" <<num << std::endl;


    std::cin.ignore();
    std::string line;
    std::getline(std::cin,line);

    int count = 0;
    count = countWords(line);
    std::cout << "the word's count is: "<<count << std::endl;
    std::string s_upper = toUpper(line);
    std::cout << "s_upper "<< s_upper << std::endl;

  std::istringstream iss(s_upper);
std::string word;
while (iss >> word) { 
    
    if(word.empty())
    {
        std::cout << "the word is empty" <<std::endl;
    }
    if(isPalindrome(word)){
        std::cout << "the word is pa" << word <<std::endl;
    }else{
         std::cout << "the word is not pa" << word <<std::endl;
    };

}  
}


int countWords(const std::string& s){
    int count = 0;
    std::istringstream iss(s);
    std::string word;
    while(iss >> word){
        count += 1;
    }
    return  count;
}

std::string toUpper(const std::string& s){
    std::string s_copy;
    s_copy =s;
    for(char& ch:s_copy)
        ch = std::toupper(static_cast<unsigned char>(ch));

    return s_copy;
}

bool isPalindrome(const std::string& s){

    if(s.empty()){
        return false;
    }
        if(s.size()!=0){
            for(size_t i=0;i<s.size()/2;i++){
                if(std::toupper(static_cast<unsigned char>(s[i])) != std::toupper(static_cast<unsigned char>(s[s.size()-1-i]))){
                    return false;
                }
            }

        } ;
        return true;
    };




void printAll(const std::vector<int>& v){
    for(int x:v){
        std::cout << x <<" ";
    };
    std::cout << std::endl;
};

void printReverse(const std::vector<int>& v){
    for(int i=v.size()-1;i>-1;i--){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

};

bool median(std::vector<int> v,double& result){


    std::sort(v.begin(),v.end());
    if(v.empty()){
        return false;
    }else{
        if(v.size()%2==1){
            result = v[v.size()/2];
        }else{
            result= static_cast<double> (v[v.size()/2]+v[v.size()/2-1])/2;
        };

    }
    return true;
};

int countGreater(const std::vector<int>& v,int threshold){
    std::vector<int>v_copy =v;
    std::sort(v_copy.begin(),v_copy.end());
    int count = 0;
    if(v_copy.empty()){
        return false;
    }
    for(int x:v_copy ){
        if(x>threshold)
        {
            count+=1;
        }
    }
    //std::cout << count <<std::endl;
    return count;
};




