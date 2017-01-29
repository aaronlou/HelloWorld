//
// Created by 娄思源 on 2017/1/28.
//
#include <stdio.h>
#include <limits.h>

#define N 10
#define dictListLength INT_MAX

void initList(void);
int list[N];
int dictList[dictListLength];

void initDictList(void);
int findInDictList(void);

int main(){

    initList();
    initDictList();
    printf("我们找到的不在数组中的最小正整数是: %d \n", findInDictList());
    return 0;
}

void initList(void){
    printf("初始化数组----->");
    for(int i = 0; i < N; i++){
        printf("请输入第%d个元素 \n",i);
        scanf("%d",&list[i]);
    }

    printf("目前数组中的元素分别是: ");
    for(int i = 0; i < N; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

void initDictList(void){
    for(int i =0;i<N;i++){
        dictList[list[i]] = 1;
    }
}

int findInDictList(void){
    for(int i =0;i < dictListLength;i++){
        if(dictList[i] == 0){
            return i;
        }
    }
    return 0;
}



