// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 19. Write a C program for solving a differential equation y = pow(x,3)+y and y(0)=1. 
//	   Find y(0,2) when h=0.01 by Euler's Method.


#include <stdio.h>
#include <math.h>

#define f(x,y) pow(x,3)+y

void main() {
    double x0, y0, x, y, h, y_at_x=2;

    printf("Enter the Initial Condition(x0, y0): ");
    scanf("%lf %lf", &x0, &y0);
    printf("Enter the Step Size(h): ");
    scanf("%lf", &h);
    x = x0;
    y = y0;    
// Use the Euler's method to approximate y at x=2
    while (x < y_at_x) {
        y = y + h * f(x, y);
        x = x + h;
    }
    printf("y(%lf) = %lf\n", x, y);
}


