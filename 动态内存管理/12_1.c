#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long key;
    /*其他成员*/
} Record;

float *myFunc(size_t n){
    //为一个double类型对象分配存储空间
    double *dPtr = malloc(sizeof(double));
    if(dPtr == NULL){ //内存不足
        /*处理错误*/
        return NULL;
    }else{
        *dPtr = 0.07;
        /*...*/
    }
    //为两个Record类型分配存储空间
    Record *rPtr;
    if(rPtr = malloc(2 * sizeof(Record)) == NULL){
        /*...处理内存不足错误...*/
                return NULL;
    }

    float *fPtr = malloc(n * sizeof(float));
    if(fPtr == NULL){
        return NULL;
    }
    return fPtr;
}

