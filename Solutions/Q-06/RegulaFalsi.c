// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 6. Write a C program to find a root of the equation x*x-25 = 0 by using the Regula-False Method.

#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x) x*x-25

void main() {
	int i, n;
	float x0, x1, x2, f0, f1, f2, e;
	reenter:
		printf("Enter Two Initial Guesses:  \n");
		printf("x0:  ");	scanf("%f", &x0);
		printf("x1:  ");	scanf("%f", &x1);
		f0 = f(x0);
		f1 = f(x1);
			if(f0*f1 > 0.0) {
				system("cls");
 				printf("Incorrect Initial Guesses. Try Again!\n");
 				goto reenter;
			}
		printf("Enter Tolerable Error:  ");
		scanf("%f", &e);
		printf("Enter Maximum Iterations Allowed:  ");
		scanf("%d", &n);
			
	printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x0)\t\tf(x1)\t\tf(x2)\n");
	for(i=1; i<=n; i++) {
 		x2 = x0 - (x0-x1) * f0/(f0-f1);
 		f2 = f(x2);
 		printf("%d\t\t%f\t%f\t%f\t%f\t%f\t%f\n",i, x0, x1, x2,f0,f1 ,f2);
 	
	if(f0*f2 < 0) {
 		x1 = x2;
 		f1 = f2;
 	}
 	else {
 		x0 = x2;
 		f0 = f2;
 	}
}

if(fabs(f2) > e) {
	printf("Doesn't Converge in %d Iterations!", n);
}
else {
	printf("\nRoot of the Equation is: %f", x2);
}
}

