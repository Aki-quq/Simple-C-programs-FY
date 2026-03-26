#include <stdio.h>
#include  <conio.h>
#include <stdlib.h>

struct students{
		char *name;
		char *course;
		int year;
}students[2];
	
	

int main (){
	
	printf("display of information of the following students year and course.\n");
	
	for (int  i= 0; i < 5; i++ ){
		students[i].name = (char*)malloc(30 * sizeof(char));
        students[i].course = (char*)malloc(30 * sizeof(char));
		
	printf("Enter students name:\n");
	scanf("%s", students[i].name);
	printf("Enter students course:\n");
	scanf("%s", students[i].course);
	printf("Enter students year:\n");
	scanf("%d", &students[i].year);
	}

	
	printf("\nstudents info\n");
	for (int j = 0; j < 5; j++){
		printf("%s is from %s, year %d\n", 
		students[j].name, 
		students[j].course, 
		students[j].year );
	}
	
	return 0;
}