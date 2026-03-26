#include <stdio.h>
#include <stdlib.h>
#define r 3
#define c 3

void divThree(int arr[r][c]){
	
	for (int i = 0; i < r; i++){
	 for (int j = 0; j < c; j++){
	 	if (i==j){
	 		printf ("%d", arr[i][j]);
		 }

		}
		
		printf("\n");
	}
}

int main() {
	int arr[r][c] = {
	{1,2,3},
	{4,5,6},
	{7,8,9}};
	
	divThree(arr);
	
	return 0;
		 
}