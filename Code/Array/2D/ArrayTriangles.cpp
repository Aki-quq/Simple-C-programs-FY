#include <stdio.h>
#include <stdlib.h>

void triangle(int arr[3][3]){
	
		for (int i = 0; i<3; i++){
		for (int j = 0; j < 3; j++){
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}


int main (){
	int arr[3][3] = 
	{'1',' ',' ',
	'1','2',' ',
	'1','2','3'};
	
triangle(arr);
	
	return 0;
	
}