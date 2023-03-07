// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 7. Write a C program to find a real root of the equation sin(x) = 1 + pow(x,3) 
//	  correct to 3 decimal places by using the Newton-Raphson Method.

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) x*x*x-sin(x)+1				//	f(x)
#define g(x) 3*x*x-cos(x)				//  f'(x)

void main() {
	float x0, x1, f0, f1, g0, e;
	int step = 1, N;
 
	printf("Enter Initial Guess(x0):  ");
	scanf("%f", &x0);
	printf("Enter Tolerable Error: ");
	scanf("%f", &e);
	printf("Enter Maximum Iteration: ");
	scanf("%d", &N);
	
	printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	do {
 		g0 = g(x0);
 		f0 = f(x0);
 		x1 = x0 - f0 / g0;
 	printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, f0, x1, f1);
 	x0 = x1;
 
if(step >= N) {
	printf("Doesn't Converge in %d Iterations!", N);
 	exit(0);
}
step = step + 1;
f1 = f(x1); 

}while(fabs(f1) >= e);

printf("\nRoot of the Equation is: %.3f", x1);
printf("\nNumber of Iterations Required: %d", step);
}

