#include <stdio.h>

float calcArea (float l, float w);

int main () {
	float l, w, area;
	
	printf("Insert Length:\n");
	scanf("%f", &l);
	printf("Insert Width:\n");
	scanf("%f", &w);
	
	area = calcArea ( l, w );
	printf("The area of %.2f and %.2f is %.2f.\n", l, w, area);
	
	return 0;	
}

float calcArea(float l, float w) {    
    return l * w;

}