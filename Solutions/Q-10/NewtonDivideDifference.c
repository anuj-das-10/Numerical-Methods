// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

/* 10. Write a C program to interpolate a function using Newton's Divided Difference Formula.
	   Use it to find the value of f(8). Given:
	   x:	4	 	5	 	7		10		11		12
	f(x):	48	 	100		294		900		1210	2028

*/

#include <stdio.h>

void main() {
    int n, i, j;
    float x[20], y[20], xn, sum, prod, fx[20][20];

    printf("Enter the Number of Data Points: ");
    scanf("%d", &n);

    printf("Enter the x and y=f(x) Values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
        fx[i][0] = y[i];
    }

    printf("Enter the value of x for which y is to be calculated: ");
    scanf("%f", &xn);

    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            fx[j][i] = (fx[j+1][i-1] - fx[j][i-1])/(x[j+i]-x[j]);
        }
    }

    sum = fx[0][0];
    for (i = 1; i < n; i++) {
        prod = 1;
        for (j = 0; j < i; j++) {
            prod = prod * (xn - x[j]);
        }
        sum = sum + fx[0][i] * prod;
    }
    printf("The Interpolated Value of y for x = %.3f is %.3f\n", xn, sum);
}

