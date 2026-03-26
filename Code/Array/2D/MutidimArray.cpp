#include <stdio.h>
#include <stdlib.h>
#define rows 3
#define cols 3

int search(int arr[][cols], int r, int target);
void myArr(int arr[][cols], int r);
void ascend(int arr[][cols], int r);
void descend(int arr[][cols], int r);
void Diag(int arr[][cols], int r);
void revDiag(int arr[][cols], int c);
int rowsSum(int arr[][cols], int r);
int colsSum(int arr[][cols], int c);

int main (){
	int arr[rows][cols], target;
	
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			printf("Insert element at [%d][%d]: \n", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	
	printf("search for an element: \n");
	scanf("%d", &target);
	search(arr, rows, target);
	printf("\n");
		
	printf("My array:\n");
	myArr(arr,rows);
	printf("\n");
	
	printf("My array ascending order: \n");
	ascend(arr, rows);
	printf("\n");
	
	printf("My array descending order: \n");
	descend(arr, rows);
	printf("\n");
		
	printf("Diagonal Search:\n");
	Diag(arr,rows);
	printf("\n");
		
	printf("reverse Diagonal Search:\n");
	revDiag(arr,cols);
	printf("\n");
		
	printf("Rows summed:\n");
	for (int i= 0; i < rows; i++){
		printf("rows %d: %d\n", i, rowsSum(arr, i));
	}
	
	printf("Columns summed:\n");
	for (int j= 0; j < cols; j++){
		printf("columns %d: %d\n", j, colsSum (arr,j));
	}
	
	return 0;

}

int search(int arr[][cols], int r, int target){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < cols; j++){
			if(arr[i][j] == target){
			printf("%d is found at [%d][%d]\n", target, i, j);	
			return 1;
			} 
			printf("%d not found", target);
			return 0;
		}
	}
}

void myArr(int arr[][cols], int r){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < cols; j++){
			printf("%d ",arr[i][j]);
			}
		printf("\n");
	}
}

void ascend(int arr[][cols], int r){
	int flat[rows * cols];
	int k = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < cols; j++){
			flat[k++] = arr[i][j];
		}
	}
	
	for (int i = 0; i < r * cols - 1; i++){
		for (int j = 0; j < r * cols - i - 1; j++){
			if (flat[j] > flat[j + 1]){
				int temp = flat[j];
				flat[j] = flat[j + 1];
				flat[j+1] = temp;
			}
		}
	}
	
	k=0;
	for(int i = 0; i < r; i++){
		for (int j = 0; j < cols; j++){
			printf("%d ", flat[k++]);
		}
		printf("\n");
	}
	
}
void descend(int arr[][cols], int r){
	int flat[rows * cols];
	int k = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < cols; j++){
			flat[k++] = arr[i][j];
		}
	}
	
	for (int i = 0; i < r * cols - 1; i++){
		for (int j = 0; j < r * cols - i - 1; j++){
			if (flat[j] < flat[j + 1]){
				int temp = flat[j];
				flat[j] = flat[j + 1];
				flat[j+1] = temp;
			}
		}
	}
	
	k=0;
	for(int i = 0; i < r; i++){
		for (int j = 0; j < cols; j++){
			printf("%d ", flat[k++]);
		}
		printf("\n");
	}	
}

void Diag(int arr[][cols], int r){
    for (int i = 0; i < r; i++){       
        
            printf("%d ", arr[i][i]);
        

    }
}
void revDiag(int arr[][cols], int c){
	for (int j = 0; j < c; j++){
			printf("%d ",arr[j][c - 1 - j]);
		}
		
}

int rowsSum(int arr[][cols], int r){
	int sum = 0;
	for (int j = 0; j < cols; j++){
		sum += arr[r][j];
	}
	return sum;
}

int colsSum (int arr[][cols], int c){
	int sum = 0;
	for (int i = 0; i < rows; i++){
		sum += arr[i][c];
	}
	return sum;
}