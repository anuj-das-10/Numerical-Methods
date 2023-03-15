// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 14. Write a C program to evaluate the following using Trapezoidal Rule.
//	   Integration of [x/(1 + x)]dx from 0 to 1.

#include<stdio.h>
#define f(x) x/(1+x)

void main() {
    int n, i;
    float x0, xn, h, sum;

    printf("Enter the Value of x0: ");
    scanf("%f", &x0);
    printf("Enter the Value of xn: ");
    scanf("%f", &xn);
    printf("Enter the number of Sub-Intervals: ");
    scanf("%d", &n);

    h = (xn - x0) / n;

//  Trapezoidal Rule
    sum = f(x0) + f(xn);
    for (i = 1; i < n; i++) {
        sum += 2 * f(x0 + i * h);
    }
    sum *= h / 2;
    printf("The Approximate Value of the Integral is: %.3f\n", sum);
}



