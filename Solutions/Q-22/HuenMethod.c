// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 22. Huen's Method.

#include<stdio.h>
#include<conio.h>

#define f(x,y) -x*y

void main() {
	float x1, y1, h, xf;
	float x2, y2, s1, s2;
	printf("Enter the following values : \n");
	printf("x1: ");		scanf("%f", &x1);			// 0
	printf("y1: ");		scanf("%f",&y1);			// 1
	printf("xf: ");		scanf("%f",&xf);			// 0.25
	printf("h: ");		scanf("%f",&h);				// 0.05
	
	while(x1 <= xf) {
		printf("x = %f\ty = %f\n",x1,y1);
		s1 = f(x1,y1);
		x2 = x1 + h;
		y2 = y1 + h * s1;
		s2 = f(x2,y2);
		y2 = y1 + h * (s1+s2)/2;
		x1 = x2;
		y1 = y2;
	}
}
