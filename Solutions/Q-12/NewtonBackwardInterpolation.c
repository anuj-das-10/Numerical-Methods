// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

/*	12. Write a C program to interpolate using Newton's Backward Interpolation Method. 
		Use it to find the value of y when x = 0.75. Given:
		x:	0.0		0.2		    0.4		    0.6		    0.8		    1.0
		y:	1.0		0.961538	0.833333	0.555556	0.3125		0.2
*/

#include <stdio.h>
void main() {
    int n, i, j;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[n], y[n];

    // read in data points for x and y
    printf("Enter the data points for x and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double xi;
    printf("Enter the value of x to Interpolate: ");
    scanf("%lf", &xi);

    double h = x[1] - x[0]; 
    double p = (xi - x[n-1]) / h; 					// Backward Difference Parameter
    double y_interp = y[n-1]; 

    for (i = 1; i < n; i++) {
        for (j = n-1; j >= i; j--) {
            y[j] = y[j] - y[j-1];
        }
        y_interp = y_interp + p*y[n-i-1]/i;
    }
    printf("Interpolated value of y at x = %.3f is %f\n", xi, y_interp);
}


