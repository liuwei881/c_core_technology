#include <stdio.h>
#include <float.h>

int main(){
    puts("\nCharacteristic of the type float\n");
    printf("Storage size: %d bytes\n"
           "Smallest positive value: %E\n"
           "Greatest positive value: %E\n"
           "Precision: %d decimal digits\n",
           (int)sizeof(float), FLT_MIN, FLT_MAX, FLT_DIG);
    puts("\nAn example of float precision:\n");
    double d_var = 12345.6;
    float f_var = (float)d_var;
    printf("has been stored in a variable\n"
           "of type float as the value "
           "%18.10f\n", d_var);
    printf("has been stored in a variable\n"
           "of type float as the value "
           "%18.10f\n", f_var);
    printf("The rounding error is  "
           "%18.10f\n", d_var - f_var);
    return 0;
}
