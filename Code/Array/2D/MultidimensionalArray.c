#include <stdio.h>
#include <string.h>




int main() {
	int i, j, table[5][5], r, c;
	
	printf("enter rows:\n");
	scanf("%d", &r);
	printf("enter rows:\n");
	scanf("%d", &c);
	
	printf("Enter elements of the array:\n");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			printf("Enter value for table[%d][%d]\n", i, j);
			scanf("%d", &table[i][j]);
		}
	}
	
	printf("The elements you gave are:\n");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			printf("%d", table[i][j]);
		}
		printf("\n");
	}
	
}



