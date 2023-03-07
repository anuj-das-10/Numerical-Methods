// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 4. Write a C program to find the real root of the equation pow(x,3)-4x+1 = 0 by using the Method of Successive Approximation.

#include <stdio.h>
#include <math.h>

#define f(x) pow(x,3)-4*x+1
#define g(x) (pow(x,3)+1)/4
// The Desired Accuracy
#define EPSILON 0.0001 

void main() {
    double x0, x1, error;
    printf("Enter the Initial Approximation x[0]: ");
    scanf("%lf", &x0);

    do {
        x1 = g(x0); 				// Apply the iterative formula
        error = fabs(x1 - x0); 		// Calculate the error
        x0 = x1; 					// Update x[0] for the next iteration
    } while(error >= EPSILON);

    printf("The real root of the equation is: %.4lf\n", x1);
    printf("The error is: %.4lf\n", error);
}

