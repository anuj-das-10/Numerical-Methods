// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

/* 13.  Write a C program to interpolate using Lagrange's Interpolation Method. 
		Use it to find the value of y when x = 6. Given:
		x:	3		7		9		10
		y:	168		120		72		63	
*/

#include <stdio.h>

void main() {
    int n, i, j;
    float x[20], y[20], xn, sum = 0, prod;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }
    
    printf("Enter the value of x for which y is to be calculated: ");
    scanf("%f", &xn);

    for (i = 0; i < n; i++) {
        prod = 1;
        for (j = 0; j < n; j++) {
            if (i != j) {
                prod = prod * (xn - x[j]) / (x[i] - x[j]);
            }
        }
        sum = sum + y[i] * prod;
    }
    printf("The Interpolated value of y for x = %.3f is %.6f\n", xn, sum);
}


