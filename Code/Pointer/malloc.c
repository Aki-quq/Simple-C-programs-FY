#include <stdio.h>
#include <stdlib.h>

void reorder(int n, int *x);

int main() 
{
    int i, n, *x;
    int choice;

    printf("Enter the size of your array: \n");
    scanf("%d", &n);
    

    x = (int*)malloc(n * sizeof(int));
    if (x == NULL) {
        printf("Malloc invalid\n");
        return 1;
    }
    
    do {
    	for (i = 0; i < n; ++i) {
        printf("i = %d x = ", i + 1);
        scanf("%d", x + i);
    }
    	printf("Choose to print the odd or even elements:\n");
    	printf("1. for even\n");
    	printf("2. for descending\n");
    	printf("3. order");
    	printf("Enter number:\n");
    	
    	switch(choice){
    		case 1:
    			printf("\nList of even numbers that was inserted:\n");
    			
    			for (i = 0; i < n; ++i){
    				if (*(x + i) % 2 == 0);
    				printf("i = %d x = %d (Even)\n", i + 1, *(x + i));
    				break;
    		
    		case 2:
    			printf("\nList of odd numbers that was inserted:\n");
    			    reorder(n, x);
    			for (i = 0; i < n; ++i){
    				if (*(x + i) % 1 == 0);
    				printf("i = %d x = %d (odd)\n", i + 1, *(x + i));
    				break;
				
			case 3: 
				printf("\nList of odd and even ordered:");
				   reorder(n, x);

   				 printf("\n\nReordered list of even and odd numbers:\n\n");
					for (i = 0; i < n; ++i) {
				  		  if (*(x + i) % 2 == 0)
				        		printf("i = %d x = %d (Even)\n", i + 1, *(x + i));
				    		else
				        		printf("i = %d x = %d (Odd)\n", i + 1, *(x + i));
						}
				
				}
				
		}

	
	} while (choice != 0);
    return 0;
}

void reorder(int n, int *x){
    int i, item, temp;

    for (item = 0; item < n - 1; ++item) {
        for (i = item + 1; i < n; ++i) {
            if (*(x + i) < *(x + item)) {
                temp = *(x + item);
                *(x + item) = *(x + i);
                *(x + i) = temp;
            }
        }
    }
}