// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 20. Write a C program for solving a differential equation y = pow(x,2)+y and y(0)=1. 
//	   Find y(0.02) when h = 0.01 by Modified Euler's Method.

#include <stdio.h>
#include <math.h>

#define f(x,y) pow(x,2)+y

void main() {
    double x0, y0, x, y, h. y_at_x=0.02;
    printf("Enter the Initial Condition(x0, y0): ");
    scanf("%lf %lf", &x0, &y0);
    printf("Enter the value of h: ");
    scanf("%lf", &h);

    x = x0;
    y = y0;
    while (x < y_at_x) {
// Compute the next value of y using the RK4 method
        double k1 = h * f(x, y);
        double k2 = h * f(x + h, y + k1);
        y = y + 0.5 * (k1 + k2);
        x = x + h;
    }
    printf("y(%lf) = %lf\n", x, y);
}


