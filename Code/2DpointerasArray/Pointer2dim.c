#include <stdio.h>
#include <stdlib.h>


int** createArr(int r, int c);
void fillArr(int **arr, int r, int c);
void printArr(int **arr, int r, int c);
int rowsSum(int **arr, int r, int c);
int colsSum(int **arr, int r, int c, int col);
void findMinMax(int **arr, int r, int c);
void sortAscend(int **arr, int r, int c, int ascending);
void searchArr(int **arr, int r, int c, int target);
void printOddEven(int **arr, int r, int c, int wantEven);
void printDiag(int **arr, int r, int c);
void freeArr(int **arr, int r);

int main (){
	int r,c;
	
	printf("Enter Rows: \n");
	scanf("%d", &r);
	
	printf("Enter Columns: \n");
	scanf("%d", &c);
	
	int **arr = createArr(r,c);
	
	fillArr(arr, r, c);
	printArr(arr, r, c);

	printf("\nRow sum: \n");
	for (int i = 0; i < r; i++){
		printf("Row %d: %d\n", i, rowsSum(arr, i, c));
	}
	
	printf("\nColumn sum: \n");
	for (int j = 0; j < c; j++){
		printf("Col %d: %d\n", j, colsSum(arr, r, c, j));
	}
	
	findMinMax(arr, r, c);
	
	printf("\nAscending order:\n");
	sortAscend(arr, r, c, 1);
	printArr(arr, r, c);
	
	printf("\nDescending order:\n");
	sortAscend(arr, r, c, 0);
	printArr(arr, r, c);
	
    printOddEven(arr, r, c, 1);
    printOddEven(arr, r, c, 0);
	
	int target;
	printf("\nSearch for an element: \n");
	scanf("%d", &target);
	searchArr(arr, r, c, target);
	
	printf("\n Diagonal printing\n");
	printDiag(arr, r, c);
	
	freeArr(arr, r);
	printf("\nMemory cleared. Buh-bye!\n");
	
	return 0;

}

int** createArr(int r, int c){
	int **arr = malloc(r * sizeof(int *));
	
	for (int i = 0; i < r; i++){
		*(arr+i) = malloc(c * sizeof(int));
	}
	return arr;
}

void fillArr(int **arr, int r, int c){
	printf("\nENTER VALUES: \n");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			printf("arr[%d][%d]: ", i,j);
			scanf("%d", *(arr+i)+j);
		}
	}
}

void printArr(int **arr, int r, int c){
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++){
			printf("%3d", *(*(arr+i)+j));
		}
		printf("\n");
	}
}

int rowsSum(int **arr, int r, int c){
	int sum = 0;
	for (int j = 0; j < c; j++){
		sum += *(*(arr+r)+j);
	}
	return sum;
}
int colsSum(int **arr, int r, int c, int col){
	int sum = 0;
	for (int i = 0; i < r; i++){
		sum += *(*(arr+i)+col);
	}
	return sum;
}


void findMinMax(int **arr, int r, int c){
		int min = *(*(arr + 0)+ 0);
		int max = *(*(arr + 0)+ 0);
		
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++){
				int val = *(*(arr + i)+ j);
				if (val < min) min = val;
				if (val > max) max = val;
			}
			
			printf("\n Min: %d\n", min);
			printf("\n Max: %d\n", max);
}

void sortAscend(int **arr, int r, int c, int ascending){
	int total = r * c;
	int *temp = malloc (total * sizeof(int));
	
	int flat = 0;
	for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++){
				*(temp + flat++) = *(*(arr + i)+ j);
			}
			
	for (int i = 0; i < total - 1; i++)
			for (int j = 0; j < total - i - 1; j++){
				int a = *(temp + j);
				int b = *(temp + j + 1);
				int shouldSwap = ascending ? a > b : a < b;
				if (shouldSwap){
					*(temp + j) = b;
					*(temp + j + 1) = a;
				}
			}
			
	flat = 0;
	for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			*(*(arr + i)+ j) = *(temp + flat++);
	
	free(temp);
}

void searchArr(int **arr, int r, int c, int target){
	int found = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (*(*(arr + i)+ j) == target ){
				printf("%d is found at arr[%d][%d]\n", target, i, j);
					found = 1;
			}
				
		
		if (!found)
					printf("Target not found.\n");
				
				
}

void printOddEven(int **arr, int r, int c, int wantEven){
	printf(wantEven ? "\nEven:":"\nOdd:");
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				int val = *(*(arr + i)+ j);
				if (wantEven ? val % 2 == 0 :val % 2 != 0 ){
					printf("%d", val);
				}
				
			}
		}
			
	}

void printDiag(int **arr, int r, int c){
	printf("Diagonal Print: \n");
	for (int i = 0; i < r && i < c; i++){
		printf("%d", *(*(arr+i)+i));
	}
		
		printf("\n");
	
		
	printf("Reverse Diagonal Print: \n");
	for (int i = 0; i < r && i < c; i++){
		printf("%d", *(*(arr+i)+(c - 1 - i)));
	}
		
		printf("\n");	
	
}
void freeArr(int **arr, int r){
	for (int i = 0; i < r; i++)
	free(*(arr+i));
	free(arr);
}