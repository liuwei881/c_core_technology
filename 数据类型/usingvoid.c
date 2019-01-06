#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum {ARR_LEN = 100};

int main(){
    int i, *pNumbers = malloc(ARR_LEN * sizeof(int));
    if(pNumbers == NULL){
        fprintf(stderr, "Insufficient memory.\n");
        exit(i);
    }
    srand((unsigned)time(NULL));

    for(i=0; i<ARR_LEN; ++i){
        pNumbers[i] = rand() % 10000;
    }
    printf("\n%d random numbers between 0 and 0000:\n", ARR_LEN);
    for(i=0; i<ARR_LEN; ++i){
        printf("%6d", pNumbers[i]);
        if(i%10 == 9){
            putchar('\n');
        }
    }
    free(pNumbers);
    return 0;
}
