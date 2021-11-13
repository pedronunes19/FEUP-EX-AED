#include <iostream>
#include <vector>
#include <cmath>

long long minNecessary(int sum){
    int i = 0, min;
    do{
        i++;
        min = 9;
        min  *=  i;
    }while(min < sum);
    int j = 0;
    min = (i-1) * 9;
    while (min < sum){
        min = (i-1) * 9;
        j++;
        min += j;
    }
    return (j* pow(10, i)) + (pow(10, i-1)-1);
}

int main(){
    int t;
    std::vector <long long> v;
    std::cin >> t;
    for (int i=1;i<=t;i++){
        long long iNum0, sum, temp;
        std::cin >> iNum0 >> sum;
        iNum0 = std::max(minNecessary(sum), iNum0)  - 1;
        while (temp!=sum){
            temp=0;
            iNum0++;
            long long iNum = iNum0;
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
    for (long long i: v){
        std::cout << i << std::endl;
    }
    return 0;
}