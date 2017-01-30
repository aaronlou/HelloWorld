#include <iostream>
#include <stdlib.h>
#include <queue>
#include <time.h>
using namespace std;
typedef unsigned long ul;
ul findNthUglyNumber(int);

int main(){
    int N;
    cout << "输入想查找第几个丑数: N= " << endl;
    cin >> N;
    clock_t start_time = clock();
    ul result = findNthUglyNumber(N);
    clock_t end_time = clock();

    cout << "第" << N << "个丑数为: " << result << endl;
    cout << "运行总耗时(秒): " << static_cast<double>(end_time - start_time)/CLOCKS_PER_SEC << endl;
    return 0;
}

ul findNthUglyNumber(int n){
    if(n == 1) return  1;
    queue<ul> q1,q2,q3;
    q1.push(2);
    q2.push(3);
    q3.push(5);
    ul minValue;
    while(n-- > 1){
        minValue = min(min(q1.front(),q2.front()),q3.front());
        if (minValue == q1.front()){
            q1.pop();
            q1.push(minValue*2);
            q2.push(minValue*3);
            q3.push(minValue*5);
        }else if(minValue == q2.front()){
            q2.pop();
            q2.push(minValue*3);
            q3.push(minValue*5);
        }else{
            q3.pop();
            q3.push(minValue*5);
        }
    }
    return minValue;
}

