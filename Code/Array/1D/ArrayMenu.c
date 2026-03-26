#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void showArr(int arr[],int size);
int reInsert(int arr[],int size);
int showMin(int arr[],int size);
int showMax(int arr[],int size);
int showEven(int arr[],int size);
int showOdd(int arr[],int size);



int main() {
	int arr[SIZE], choice;
	char leave;
	
	printf("Insert array elements:\n");
	for (int i = 0; i < SIZE; i++){
		printf("\nArr[%d]:", i+1);
		scanf("%d", &arr[i]);
	}
	
	do {
	printf("\n====Array Menu program====\n");
	printf("[1]Show array\n");
	printf("[2]insert\n");
	printf("[3]Show minimum\n");
	printf("[4]Show maximum\n");
	printf("[5]Show odd\n");
	printf("[6]Show even\n");
	printf("[0]Exit\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	
	switch(choice){

		case 1:
			showArr(arr, SIZE);
			break;
		case 2:
			reInsert(arr, SIZE);
			break;
		case 3:
			printf("Minimum: %d\n",showMin(arr, SIZE));
			break;
		case 4:
			printf("Maximum: %d\n",showMax(arr, SIZE));
			break;
		case 5:
			showOdd(arr, SIZE);
			break;
		case 6:
			showEven(arr, SIZE);
			break;
		case 0:
            printf("Are you sure you want to exit? (y/n): ");
            scanf(" %c", &leave);    
            if (leave == 'y' || leave == 'Y') {
                printf("Exiting program...\n");
            } else {
                printf("Returning to menu...\n");
                choice = 1;             
            }
			break;
		default:
			printf("Invalid input, try again.");
			break;
	}
	
	} while (choice != 0);
	
	
	return 0;
}
void showArr(int arr[],int size){
	printf("Array:");
	for (int i = 0; i < SIZE; i ++){
		printf("%2d", arr[i]);
	}
	printf("\n");
}

int reInsert(int arr[],int size){
	printf("re-insert new elements in array:\n");
	for (int i = 0; i < SIZE; i++){
		printf("\nArr[%d]:", i+1);
		scanf("%d", &arr[i]);
	}
	printf("\n");
}

int showMin(int arr[],int size){
	int min = arr[0];
	for (int i = 0; i < size; i ++){
		if (arr[i]<min)
		min = arr[i];
	}
	return min;
}

int showMax(int arr[],int size){
	int max = arr[0];
	for (int i = 0; i < size; i ++){
		if (arr[i]>max)
		max = arr[i];
	}
	return max;
}

int showEven(int arr[],int size){
	printf("Even numbers in your array:");
	for (int i = 0; i < size; i ++){
		if (arr[i] % 2 == 0){
			printf(" %d", arr[i]);
		}
	}
			printf("\n");
}

int showOdd(int arr[],int size){
	printf("Odd numbers in your array:");
	for (int i = 0; i < size; i ++){
		if (arr[i] % 2 != 0){
			printf(" %d", arr[i]);
		}
	}
			printf("\n");
}