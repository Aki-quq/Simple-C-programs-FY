#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define arr 5

	int total (int size, int score[]);
	float average (int size, int sum);

	
int main() {
	int score[arr];
	
	for(int i = 0; i < arr; i++){
		
			printf("Insert element %d:\n", i + 1);
			scanf("%d", &score[i]);
	}
	
	int sum = total(arr, score);
	float avg = average(arr,sum );

	
	printf("sum: %d\n", sum);
	printf("average: %.2f\n", avg);
	
	return 0;
}

int total (int size, int score[]){
	int sum = 0;
	for (int i = 0; i < size; i++){
		sum += score[i];
	}
	
	return sum;
}

float average (int size, int sum){
	return (float)sum/size;
}