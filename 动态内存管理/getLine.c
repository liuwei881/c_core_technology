#include <stdio.h>

char *getLine(unsigned int len_max){
    char *linePtr = malloc(len_max + 1);
    if(linePtr != NULL){
        int c = EOF;
        unsigned int i = 0;
        while(i < len_max && (c = getchar()) != '\n' && c != EOF){
            linePtr[i++] = (char)c;
        }
        linePtr[i] = '\0';

        if(c == EOF && i == 0){
            free(linePtr);
            linePtr = NULL;
        }else{
            linePtr = realloc(linePtr, i+1);
        }
    }
    return linePtr;
}

int main(){
    char *line;
    if((line = getLine(128)) != NULL){
        /*...*/
        free(line);
    }
}