#include <stdio.h>

double circularArea(double r);

int main(){
    double radius = 1.0, area = 0.0;
    printf("Areas of Circles\n\n");
    printf("Radius Area\n"
           "------------------\n");

    area = circularArea(radius);
    printf("%10.1f %10.2f\n", radius, area);

    radius = 5.0;
    area = circularArea(radius);
    printf("%10.1f %10.2f\n", radius, area);
    return 0;
}

//函数circularArea()计算圆的面积
//参数：圆的半径
//返回值：圆的面积

double circularArea(double r){
    const double pi = 3.1415926536; //pi是一个常量
    return pi * r * r;
}