// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

/* 9. Write a C program to solve the following set of equations by Gauss-Seidel Method:
		27x + 6y - z = 85
		6x + 15y + 2z = 72
		x + y + 54z = 110	
*/

#include <stdio.h>
#include <math.h>

#define N 3

void Gauss_Seidel(double a[][N], double b[], double x[], int n, int max_iterations, double tolerance) {
    int i, j, k, iteration_count = 0;
    double sum, new_solution[N], error = 1.0;

// Continue Iterating until max_iterations or tolerance is reached
    while (iteration_count < max_iterations && error > tolerance) {
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            new_solution[i] = sum / a[i][i];
        }

// Calculate the error between old and new solutions
        error = 0.0;
        for (k = 0; k < n; k++) {
            error += fabs((new_solution[k] - x[k]) / new_solution[k]);
            x[k] = new_solution[k];
        }
        iteration_count++;
    }
}

void main() {
    double a[N][N], b[N], x[N];
    int i, j, max_iterations;
    double tolerance;

    printf("Enter the co-efficients of the Equations:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the Constants on the RHS:\n");
    for (i = 0; i < N; i++) {
        printf("b[%d]: ", i);
        scanf("%lf", &b[i]);
    }

    // Get the initial guess and iteration parameters from the user
    printf("Enter the Initial Guess for the Solution:\n");
    for (i = 0; i < N; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
    }

    printf("Enter the Maximum Number of Iterations allowed: ");
    scanf("%d", &max_iterations);

    printf("Enter the Tolerance for Convergence: ");
    scanf("%lf", &tolerance);

    Gauss_Seidel(a, b, x, N, max_iterations, tolerance);

    printf("\nThe Solution is:\n");
    for (i = 0; i < N; i++) {
        printf("x[%d]: %.3lf\n", i, x[i]);
    }
}


