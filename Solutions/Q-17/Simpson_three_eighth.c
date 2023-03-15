// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 17. Write a C program to evaluate the following using Simpson's Three-Eighth Rule.
//	   Integration of [sqrt(1 - 8*pow(x,3)]dx from 0 to 0.3

#include<stdio.h>
#include<math.h>

#define f(x) sqrt(1 - 8*pow(x, 3))

void main() {
    double a, b;
    int n, i;
    double h, sum;
    double x0, x1, x2, x3;

    printf("Enter the Lower Limit: ");
    scanf("%lf", &a);

    printf("Enter the Upper Limit: ");
    scanf("%lf", &b);

    printf("Enter the number of Sub-Intervals (must be a multiple of 3): ");
    scanf("%d", &n);

    h = (b - a) / n;
    sum = f(a) + f(b);

    for (i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 3 * f(x);
        }
    }

    double result = 3 * h / 8 * sum;
    printf("The Approximate Value of the Integral is: %lf\n", result);
}


