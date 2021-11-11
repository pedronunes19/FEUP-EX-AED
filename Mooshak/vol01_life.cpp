#include <iostream>

int main(){
    int n, count = 0;

    std::cin >> n;

    for (int i = 1; i <= n; i++){
        int temp;
        std::cin >> temp;
        if (temp == 42)
            count++;
        
    }
    std::cout << count << std::endl;
    return 0;
}