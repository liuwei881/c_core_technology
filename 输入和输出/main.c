#include <stdio.h>
#include <stdbool.h>

_Bool isReadWriteable(const char *filename){
    FILE* fp = fopen("./filename", "r+");
    if(fp != NULL){
        fclose(fp);
        return true;
    }else{
        return false;
    }
}