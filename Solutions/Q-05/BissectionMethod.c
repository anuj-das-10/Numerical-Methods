// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 5. Write a C program to find a real root of the equation pow(x,2)-sin(x)-9 = 0 by using the Bisection Method.


#include<stdio.h>
#include<conio.h>
#include<math.h>

//  Function whose root is to be calculated
#define f(x) x*x-sin(x)-9    

void main() {
	int i = 0;
	float x0, x1, x2, f0, f1, f2, e;

	reenter:
	printf("Given, f(x) = x*x-sin(x)-9");		
	printf("\nEnter Two Initial Guesses:\n");
	printf("x0: ");   scanf("%f", &x0);
	printf("x1: ");   scanf("%f", &x1);

f0 = f(x0);
f1 = f(x1);


// Logic:  (+).(+) > 0.0  and  (-).(-) > 0.0   but 	(+).(-) < 0.0
	if((f0 * f1) > 0.0) {
 		system("cls");
 		printf("Incorrect Initial Guesses. \nTry Again!\n\n");
 		goto reenter;
	}

	printf("Enter Tolerable Error:  ");
	scanf("%f", &e);

	printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x0)\t\tf(x1)\t\tf(x2)\n");

	do  {
 		x2 = (x0 + x1)/2;
 		f2 = f(x2);
 		printf("%d\t\t%f\t%f\t%f\t%f\t%f\t%f\n", i, x0, x1, x2, f0, f1, f2);
 			if((f0*f2) < 0) {
 				x1 = x2;
 				f1 = f2;
 			}
 			else {
 				x0 = x2;
 				f0 = f2;
 			}
		i = i + 1;
	} while(fabs(f2) > e);

printf("\nRoot of the equation is: %f", x2);
printf("\nNumber of Iterations is: %d", i);
}
