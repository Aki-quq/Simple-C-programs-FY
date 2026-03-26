#include <stdio.h>

void menu();
float cel(float fah);
float fah(float cel);

int main (){
	int choose;
	float from, to;
	do {
	
	menu();
	printf("Enter your choice:\n");
	scanf("%d", &choose);
	
	switch(choose){
		case 1:
			printf("Please enter Celsius: \n");
			scanf("%f", &from);
			
			to = fah( to );
			
			printf("%.2f converted to fahrenheit is %.2f", from, to);
		
		break;
		
		case 2:
			printf("Please enter fahrenheit: \n");
			scanf("%f", &from);
			
			to = cel( to );
			
			printf("%.2f converted to fahrenheit is %.2f", from, to);
			
		break;	
		
		default:
			printf("Invalid input\n");
	}
			
	} while (choose == 1);
	
	
	
	return 0;
	
}

void menu(){
	printf("\n====temperature converter====\n");
	printf("[1] Celsius to Fahrenheit\n");
	printf("[2] Fahrenheit to Celsius\n");
	
}

float fah(float cel){
	return (cel*1.8)+32;
}

float cel(float fah){
	return (fah-32)*1.8;
}