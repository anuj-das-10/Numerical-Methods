// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

/*	8. Write a C program to solve the following set of equations by Gauss Elimination Method:
		2.x1 + 4.x2 + 2.x3 = 15
		2.x1 + x2 + 2.x3 = -54
		x1 + x2 - 2.x3 = 0	
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
    int n = 3, i, j, k; 	// Number of unknowns
    double A[n][n+1]; 		// Augmented Matrix
    double x[n]; 			// Solution

    printf("Enter the Augmented Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

// Gaussian Elimination
    for (k = 0; k < n - 1; k++) {
        for ( i = k + 1; i < n; i++) {
            double factor = A[i][k] / A[k][k];
            for (j = k; j <= n; j++) {
                A[i][j] -= factor * A[k][j];
            }
        }
    }

// Back Substitution
    x[n - 1] = A[n - 1][n] / A[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        double sum = 0.0;
        for (j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (A[i][n] - sum) / A[i][i];
    }

// Print Solution
    printf("\nThe Solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x%d:  %lf\n", i + 1, x[i]);
    }
}

