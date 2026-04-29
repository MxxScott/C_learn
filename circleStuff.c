/*********************
Program: 2.20 Diameter, Circumference, Area of a Circle
Date: 23/10/23
Author: C.Adjetey
*********************/
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//declaration of variables
	float radius;
	const float PI = 3.14159;
	
	
	puts("This program will compute and dispaly the Diameter, Circumference and Area of Circle");
	//accepting radius
	printf("Enter the radius of the circle: ");
	scanf("%f", &radius);
	
	//computation and display
	printf("The diameter of the circle is %.2f.\n", (radius * 2));
	printf("The circumference of the circle is %.2f.\n",(2 * PI * radius));
	printf("The area of the circle is %.2f.\n", (PI * pow(radius,2)));
	
	puts("End of Program");
	
	
	return 0;
}
