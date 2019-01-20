#include <stdio.h>

int main(){
    int i=0;
    char a[10] = "Jim";
    printf("%c\n", a[i]++);
    printf("%c\n", ++a[i]);
    return 0;
}

