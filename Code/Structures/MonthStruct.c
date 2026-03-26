#include <stdio.h>
#include <stdlib.h>

struct month {
	int numMonth;
	char month [20];
	int days;

}mnth[12];

int main() {
	struct month Months[12] = {
		{1, "January", 31},
		{2, "February", 28},
		{3, "March", 31},
		{4, "April", 30},
		{5, "May", 31},
		{6, "June", 30},
		{7, "July", 31},
		{8, "August", 31},
		{9, "September", 30},
		{10, "October", 31},
		{11, "November", 30},
		{12, "December", 31},
	};
	
	printf("%-6s %-15s %-6s\n", "Month", "Name", "Days");
	printf("________________________________\n");
	
	for(int i = 0; i < 12; i++){
	printf("%-6d %-15s %-6d\n", 
		Months[i].numMonth, 
		Months[i].month,
		Months[i].days 
		);
	}
	
	
	return 0;
}