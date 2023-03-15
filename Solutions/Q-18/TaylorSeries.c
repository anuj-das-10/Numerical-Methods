// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 18. Write a C program for solving a differential equation y = (3*x + y/2) and y(0)=1. 
//	   Find the values of y(0,1) and y(0,2) by using the Taylor Series Method.

#include<stdio.h>
#include<math.h>

#define f(x,y) 3*x + y/2

void main() {
	int n, i;
    double x0, y0, h, x, y, k1, k2, k3, k4;
    
    printf("Enter the Initial Value of x: ");
    scanf("%lf", &x0);
    printf("Enter the Initial Value of y: ");
    scanf("%lf", &y0);
    printf("Enter the Step Size: ");
    scanf("%lf", &h);
    printf("Enter the Number of Iterations: ");
    scanf("%d", &n);

    printf("x0 = %lf, y0 = %lf\n", x0, y0);
    for (i = 1; i <= n; i++) {
        x = x0 + i * h;
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h/2, y0 + k1/2);
        k3 = h * f(x0 + h/2, y0 + k2/2);
        k4 = h * f(x0 + h, y0 + k3);
        y = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        printf("x%d = %lf, y%d = %lf\n", i, x, i, y);

        x0 = x;
        y0 = y;
    }
    printf("The value of y(0, %d) is %lf\n", n, y);
}



