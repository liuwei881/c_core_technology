#include <stdio.h>
#include <stdlib.h>

void error_exit(unsigned int error_n){
    char * error_msg[] = {
            "Unknown error code.\n",
            "Insufficient memory.\n",
            "Illegal memory access.\n"
    };
    unsigned int arr_len = sizeof(error_msg)/ sizeof(char *);
    if(error_n >= arr_len){
        error_n = 0;
    }
    fputs(error_msg[error_n], stderr);
    exit(1);
}

int main(){
    error_exit(0);
    return 0;
}