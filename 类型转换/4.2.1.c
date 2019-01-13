#include <stdio.h>

int main(){
    int *iPtr = 0;
    int iArray[] = {0, 10, 20};
    int array_length = sizeof(iArray) / sizeof(int);
    printf("The array starts at the address %p.\n", iArray);

    * iArray = 5;
    iPtr = iArray + array_length - 1;
    printf("The last element of the array is %d.\n", * iPtr);
    return 0;
}

