// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

/* 15. Write a C program for Integrating Simpson's One-Third Rule when the function values are given as:
		   x:	0.8		    0.9		    1.0		    1.1		    1.2
		f(x):	0.71736		0.78333		0.84147		0.92314		0.96356
*/

#include<stdio.h>

double simpsonOneThird(double a, double b, double fa, double fb, double fc, double h) {
	return (h/3) * (fa + 4*fc + fb);
}

void main() {
    int n, i;
    double x[5], f[5], a, b, h, fa, fb, fc, integral;
    printf("Enter the number of Intervals: ");
    scanf("%d", &n);
    
    printf("Enter the values of x and f(x):\n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &f[i]);
    }

    h = (x[n-1] - x[0]) / n;

    fa = f[0];
    fb = f[n-1];
    fc = f[n/2];
// Integrate using Simpson's 1/3rd rule
    integral = simpsonOneThird(x[0], x[n], fa, fb, fc, h);
    printf("Integral of f(x) from %.3lf to %.3lf is %lf\n", x[0], x[n-1], integral);
}


