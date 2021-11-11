#include <iostream>
#include <vector>

int main(){
    int t;
    std::vector <int> v;
    std::cin >> t;
    for (int i=1;i<=t;i++){
        int iNum0, sum, temp;
        std::cin >> iNum0 >> sum;
        while (temp!=sum){
            temp=0;
            iNum0++;
            int iNum = iNum0;
            while(iNum>=10){
                temp += iNum%10;
                iNum -=iNum%10;
                iNum /=10;
            }
            temp+=iNum;
        }
        v.push_back(iNum0);
        temp = 0;

    }
    for (int i: v){
        std::cout << i << std::endl;
    }
    return 0;
}