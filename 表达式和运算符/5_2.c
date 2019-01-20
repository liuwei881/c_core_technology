#include <stdio.h>

double average(const float *array, int length);

int main(){
    float a[10] = {2.1, 2.2, 2.3};
    average(a, 3);
    return 0;
}

double average(const float *array, int length){
    double sum = 0.0;
    const float *end = array + length;

    if(length <= 0){
        return 0.0;
    }
    for(const float *p=array; p<end; ++p){
        sum += *p;
    }
    printf("sum=%f\n", sum/length);
    return sum/length;
}

