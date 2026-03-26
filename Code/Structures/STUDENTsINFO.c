#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentRecord {
    int ID;
    char fname[50];   
    char lname[50];   
    int units;
    float avg;
} st[10];

int main() {
    for (int i = 0; i < 2; i++) {
        printf("Enter student's ID: \n");
        scanf("%d", &st[i].ID);
        
        getchar();
        
        printf("Enter student's first name: \n");
        fgets(st[i].fname, 50, stdin);
        st[i].fname[strcspn(st[i].fname, "\n")] = '\0';
        
        printf("Enter student's last name: \n");
        fgets(st[i].lname, 50, stdin);
        st[i].lname[strcspn(st[i].lname, "\n")] = '\0';
        
        printf("Enter student's amount of units: \n");
        scanf("%d", &st[i].units);
        
        printf("Enter student's average grade: \n");
        scanf("%f", &st[i].avg);
    }

    printf("\nStudents Info\n");
    for (int j = 0; j < 2; j++) {
        printf("%s, %s\n ID no.: %d\n Units: %d\n Average Grade: %.2f\n\n",
            st[j].lname,   
            st[j].fname,
            st[j].ID,
            st[j].units,
            st[j].avg
        );
    }

    return 0;
}