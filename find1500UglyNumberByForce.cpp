#include <iostream>
#include <limits.h>
#include <time.h>

using namespace std;

bool isUgly(int);


int main() {
    cout << "寻找第1500个丑数" << endl;
    clock_t start_time = clock();

    int count = 1;  //我们认为1是第1个丑数
    for(int i=2;i<INT_MAX;i++){
        if(isUgly(i)){
            if(++count == 1500) {
                cout << "第1500个丑数是: " << i << endl;
                break;
            }
        }
    }

    clock_t end_time = clock();
    cout << "运行总耗时(秒): " << static_cast<double>(end_time - start_time)/CLOCKS_PER_SEC << endl;
    return 0;
}

bool isUgly(int number){
    while(number > 1){
        if(number % 2 == 0) number /= 2; else break;
        if(number == 1) return true;
    }
    while(number > 1){
        if(number % 3 == 0) number /= 3; else break ;
        if(number == 1) return true;
    }
    while(number > 1){
        if(number % 5 == 0) number /= 5; else break;
        if(number == 1) return true;
    }
    return false;
}
