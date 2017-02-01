#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int findInsertPlace(vector<int> v, int value);

int main(){
    //先生成一个随机数组, 数组长度为N, 元素为100以内的随机整数
    int N;
    cout << "输入你想排序的随机数组的长度: ";
    cin >> N;
    int randomList[N];
    for(int i = 0; i < N; i++){
        randomList[i] = rand()%100;
    }

    cout << "生成的随机数组如下: " << endl;
    for(int i = 0; i<N;i++){
        cout << randomList[i] << " " ;
    }
    cout << endl;

    cout << "下面我们用插入法进行排序" << endl;
    vector<int> sortedResult;
    sortedResult.push_back(randomList[0]);
    for(int i = 1; i< N; i++){
        int insertPosition = findInsertPlace(sortedResult, randomList[i]);
        sortedResult.insert(sortedResult.begin()+insertPosition,randomList[i]);
    }

    cout << "排序后的数组为:" << endl;
    vector<int>::const_iterator it;
    for(it=sortedResult.begin(); it!=sortedResult.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}

int findInsertPlace(vector<int> v, int value){
    //这里假定V是已经按从小到大排好序的向量,该函数要找出value可以插入的位置
    int result = 0;
    if(value >= v[v.size()-1]) result = v.size();
    if(value < v[0]) result = 0;
    for(int i=0; i<v.size()-1;i++){
        if(value >= v[i] && value <= v[i+1]){
            result = i+1;
        }
    }
    return result;
}
