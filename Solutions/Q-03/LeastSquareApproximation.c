// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

/*  3. Write a C program to implement the Least Square Approximation for fitting a Straight line y=mx+c, 
	   where "m" is the slope and "c" is the intercept on the y-axis for data points:
       (-1,10), (0,9), (1,7), (2,5), (3,4), (4,3), (5,0), (6,-1).    	
*/

#include <stdio.h>

// Function to calculate the Slope and Intercept of the Least Square Approximation
void leastSquareApproximation(float x[], float y[], int n, float *m, float *c) {
	int i;
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    for (i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }
    *m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    *c = (sum_y - *m * sum_x) / n;
}

void main() {
    int i, size; 
    float m, c; 	// Slope and Intercept of the least Square Approximation

    printf("Enter the Number of Data Points: ");
    scanf("%d", &size);
	float x[size], y[size];
// Get the x-coordinates and y-coordinates of the data points 
    printf("Enter the x & y coordinates of the data points (x , y):\n");
    for (i = 0; i < size; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    leastSquareApproximation(x, y, size, &m, &c);

    printf("Equation of the Least Square Approximation is: y = %.2fx + %.2f\n", m, c);

}


