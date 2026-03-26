#include <stdio.h>
#include <stdlib.h>


int main (){
	int **arr, r,c, target;
	
	printf("Insert rows: \n");
	scanf("%d", &r);
	printf("Insert rows: \n");
	scanf("%d", &c);
	
	arr = malloc( r * sizeof(int *));
	for(int i = 0; i < r; i++){
		*(arr+i) = malloc(c * sizeof(int));
		
	}
	
	for(int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
				printf("\nInsert in %d %d: ", i, j);
		scanf("%d", *(arr+i)+j);	
		}

	}
	printf("\nArray:\n");
	for(int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
				printf("%d  ", *(*(arr+i)+j));
		}
	printf("\n");
	}
	
	int max = 0;
	for(int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
		int val = *(*(arr+i)+j);
		if (val > max) max = val;	
		}
	}
	printf("\nMax: %d  ", max);
	
		printf("\n");
		
	printf("\ndiagonal Search: ");
	scanf("%d", &target);
			int found = 0;
			
	for(int i = 0; i < r && i < c; i++){
		int j = (c - 1) - i;

		
		if(*(*(arr+i)+i) == target){
			printf("\nTarget %d found at %d %d", target, i, i);
			found = 1;
		}
		if (i !=j && *(*(arr+i)+j) == target){
			printf("\nTarget %d found at %d %d", target, i, j);
			found = 1;
		}
		
	} 
	

	if(!found){
		printf("\nTarget %d not found ", target);
	}

		printf("\nEven\n");
	for(int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
		int val = *(*(arr+i)+j);
		if (val % 2 == 0) {
			printf("\%d  ", val);}
		}
	}
		printf("\n");
		
		printf("\nOdd\n");
	for(int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
		int val = *(*(arr+i)+j);
		if (val % 2 != 0) {
			printf("\%d  ", val);}
		}
	}
		printf("\n");
		 
	for (int i = 0; i < r; i++){
		free(*(arr+1));
	}
	 free(arr);
	return 0;
}
	

