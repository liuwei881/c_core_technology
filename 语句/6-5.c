#include <stdio.h>

void bubbleSort(float arr[], int len){
    int isSorted = 0;
    do{
        float temp;
        isSorted = 1;
        --len;
        for(int i=0; i<len; ++i){
            if(arr[i] > arr[i+1]){
                isSorted = 0;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }while(!isSorted);
}

