// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 21. Write a C program to approximate y when x=0.1, 0.2, 0.3 and h=0.1 using Runge-Kutta Method. 
// Given x=0, when y=1 and f(y,x)=x+y.

#include <stdio.h>
#define f(x,y) x+y

void main() {
    int i, n = 3;
	double x0 = 0, y0 = 1, x, y, k1, k2, k3, k4, h;
    
    printf("Enter the Step Size(h): ");
    scanf("%lf", &h);

    for (i = 1; i <= n; i++) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h/2, y0 + k1/2);
        k3 = h * f(x0 + h/2, y0 + k2/2);
        k4 = h * f(x0 + h, y0 + k3);

        y = y0 + (k1 + 2*k2 + 2*k3 + k4)/6;
        x = x0 + h;

        printf("y(%0.1f) = %0.6f\n", x, y);
        x0 = x;
        y0 = y;
    }
}


