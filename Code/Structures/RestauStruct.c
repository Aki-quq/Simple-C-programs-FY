#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Restaurant {
	char name[80];
	char address [80];
	float cost;
	char foodType[80];
}restau[5];

int main() {

	for (int i = 0; i < 1; i++){
		printf("Enter name of Restaurant Employee: \n");
		fgets(restau[i].name, 80, stdin);
		restau[i].name[strcspn(restau[i].name, "\n")] = '\0';
		
		printf("Enter name of Restaurant Employees Address: \n");
		fgets(restau[i].address, 80, stdin);
		restau[i].address[strcspn(restau[i].address, "\n")] = '\0';
		
		printf("Enter name of food: \n");
		fgets(restau[i].foodType, 80, stdin);
		restau[i].foodType[strcspn(restau[i].foodType, "\n")] = '\0';
		
		printf("Enter food price: \n");
		scanf("%f", &restau[i].cost);
		getchar();

				
	}
	
	printf("\nEmployee:\n");
	for(int j = 0; j < 1; j++){
		printf("Name:%s\n", restau[j].name);
		printf("Address:%s\n", restau[j].address);
	}
	
		printf("\nMeals:\n");
	for(int k = 0; k < 1; k++){
		printf("Food Type:%s\n", restau[k].foodType);
		printf("cost:%.2f\n", restau[k].cost);
	}
	
	return 0;
}