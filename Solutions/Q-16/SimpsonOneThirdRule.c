// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 16. Write a C program to evaluate the following using Simpson's One-Third Rule.
//	   Integration of [x/(1 + x^2)]dx from 0 to 1.

#include<stdio.h>
#include<math.h>

#define f(x) x/(1+pow(x,2))

double simpsonOneThirdIntegration(double a, double b, int n) {
    double h = (b - a) / n;
    double x, sum = 0.0;
    int i;
//	Simpson's 1/3rd rule
    for (i = 0; i <= n; i++) {
        x = a + i * h;
        if (i == 0 || i == n) {
            sum += f(x);
        } else if (i % 2 == 1) {
            sum += 4 * f(x);
        } else {
            sum += 2 * f(x);
        }
    }
    return sum * h / 3.0;
}

void main() {
	int n;
    double a, b;
    printf("Enter the Lower Limit of Integration: ");
    scanf("%lf", &a);
    printf("Enter the Upper Limit of Integration: ");
    scanf("%lf", &b);
    reenter:
    printf("Enter the number of Sub-Intervals (must be even): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Number of Sub-Intervals must be Even.\n");
        goto reenter;
    }
    printf("The Definite Integral of f(x) from %g to %g with %d Sub-Intervals is: %g\n", a, b, n, simpsonOneThirdIntegration(a, b, n));
}


