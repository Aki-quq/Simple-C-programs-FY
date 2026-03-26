#include <stdio.h>
#include <stdlib.h>
#define el 5

int min(int arr[], int size);
int max(int arr[], int size);
int odd(int arr[], int size);
int even(int arr[], int size);


int main() {
	int arr[el];
	
	for (int i = 0; i < el; i++){
		printf("Insert the elements %d: \n", i + 1);
		scanf("%d", &arr[i]);
	}

	int maxi = max(arr, el);
	int mini = min(arr, el);	
	int oddNum = odd(arr, el);
	int evenNum = even(arr, el);
	
	printf("The maximum of the array is %d\n", maxi);
	printf("The minimum of the array is %d\n", mini);
	printf("The amount of odd of numbers in the array is %d\n", oddNum);
	printf("The amount of even of numbers in the array is %d\n", evenNum);
	
	
	return 0;
}

int max(int arr[], int size){
	int max = arr[0];
	for (int i = 1; i < size; i++){
		if(arr[i] > max)
		max = arr[i];
	}
	
	return max;
}
int min(int arr[], int size){
	int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min)  
            min = arr[i];
    }
	
	return min;
}

int odd(int arr[], int size){
	int count = 0;
	for (int i = 0; i < size; i++){
		if (arr[i] % 2 != 0)
		count++;
	}
	return count;
}

int even(int arr[], int size){
	int count = 0;
	for (int i = 0; i < size; i++){
		if (arr[i] % 2 == 0)
		count++;
	}
	return count;
}

