// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

/* 	11. Write a C program to interpolate using Newton's Forward Interpolation Method. 
		Use it to find the value of y when x = 1.05. Given:
		x:	1.0		    1.1		    1.2		    1.3		    1.4		    1.5
		y:	0.24197		0.21785		0.19419		0.17137		0.14973		0.12952
*/

#include <stdio.h>

void main() {
    int n, i, j;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[n], y[n], xi;

    printf("Enter the values for x and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    
    printf("Enter the value of x to Interpolate: ");
    scanf("%lf", &xi);

    double h = x[1] - x[0]; 			
    double p = (xi - x[0]) / h; 			// Forward Difference Parameter		
    double y_interp = y[0]; 			

    for (i = 1; i < n; i++) {
        for (j = 0; j < n-i; j++) {
            y[j] = y[j+1] - y[j];
        }
        y_interp = y_interp + p*y[i]/i;
    }
    printf("Interpolated value of y at x = %.3f is %f\n", xi, y_interp);
}


