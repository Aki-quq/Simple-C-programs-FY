#include <stdio.h>
#include <stdlib.h>



int main() {
	int **arr, r,c, target;
	
	printf("Enter rows: \n");
	scanf("%d", &r);
	printf("Enter columns: \n");
	scanf("%d", &c);
	
	arr = malloc(r * sizeof(int *));
	
	for(int i = 0; i < r; i++){
		*(arr+i) = malloc(c * sizeof(int));
	}
	
	printf("Enter values for array: \n");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			printf("arr[%d][%d]", i, j);
			scanf("%d", *(arr + i)+j);
		}
	}
	
	printf("Array: \n");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			printf("%d ", *(*(arr + i)+j));
		}
		printf("\n");
	}
	
	printf("Ascend: \n");
	int total = r*c;
	int *temp = malloc(total * sizeof(int ));
	
	int flat = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			*(temp + flat++) = *(*(arr + i)+j);
		}
	}
	for (int i = 0; i < total - 1; i++){
		for (int j = 0; j < total - i - 1; j++){
			if (*(temp + j) > *(temp + j + 1)){
				int swap = *(temp + j);
				*(temp + j) = *(temp + j + 1);
				*(temp + j + 1) = swap;
			}
		}
	}
	for (int i = 0; i < total; i++) {
    printf("%d ", *(temp + i));
}
		printf("\n");

	printf("Descend: \n");
	total = r*c;
	
	flat = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			*(temp + flat++) = *(*(arr + i)+j);
		}
	}
	for (int i = 0; i < total - 1; i++){
		for (int j = 0; j < total - i - 1; j++){
			if (*(temp + j) < *(temp + j + 1)){
				int swap = *(temp + j);
				*(temp + j) = *(temp + j + 1);
				*(temp + j + 1) = swap;
			}
		}
	}
			
				
				
	for (int i = 0; i < total; i++) {
    printf("%d ", *(temp + i));
}	printf("\n");
	
	printf("print diagonal: \n");
	for (int i = 0; i < r && i < c; i++){
			printf("%d", *(*(arr + i)+i));
		}
		printf("\n");
		
	printf("print reverse diagonal: \n");
	for (int i = 0; i < r && i < c; i++){
			printf("%d", *(*(arr + i)+(c - 1 - i)));
		}
		printf("\n");
		
	printf("Even values: \n");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			int val = *(*(arr + i)+j);
			if (val % 2 == 0){
				printf("%d ", val);
			} 
		}
		
	}printf("\n");
	
	printf("Odd values: \n");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			int val = *(*(arr + i)+j);
			if (val % 2 != 0){
				printf("%d ", val);
			} 
		}
		
	}printf("\n");
	
	
	int max = *(*(arr + 0)+0);
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			int val = *(*(arr + i)+j);
			if	( val > max) max = val;
		}
	}
	printf("Max: %d\n", max);
	
	int min = *(*(arr + 0)+0);
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			int val = *(*(arr + i)+j);
			if (val < min ) min = val;
		}
	}
		printf("Min: %d\n", min);
	
	printf("Search: \n");
	scanf("%d", &target);
	int found = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (*(*(arr + i)+j) == target){
				printf("%d found at row %d and column %d \n", target, i, j);
				found = 1;
			}
			
		}if (!found){
				printf("target not found\n");
			} 
		
	}
	
	
	
	free(arr);
	return 0;
}