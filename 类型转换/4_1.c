#include <stdlib.h>
#define ARR_LEN 20

int floatcmp(const void* p1, const void* p2){
    float x = *(float *)p1, y = *(float *)p2;
    return (x<y)? -1:((x==y) ? 0:1);
}

int main(){
    float *pNumbers = malloc(ARR_LEN * sizeof(float));
    qsort(pNumbers, ARR_LEN, sizeof(float), floatcmp);
    return 0;
}


