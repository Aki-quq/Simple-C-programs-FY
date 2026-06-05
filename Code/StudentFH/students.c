#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentrec{
	char studnum[13];
	char studname[26];
	char course[7];
	int year;
	int section; 
};
int main(int argc, char *argv[]) {
	struct studentrec student;
	FILE *fp;
	char line[100];
	char choice;
	char mode;

	
	do{
		printf("STUDENT RECORDS");
		printf("\nA.Add student record");
		printf("\nE.Edit student record");
		printf("\nV.View student record");
		printf("\nX.delete");
		printf("\nL.Leave");		
		printf("\nEnter choice: ");
		scanf(" %c", &mode);
		
		switch(mode){
			case 'A':
			do{
				do{
					printf("Enter student number: ");
					scanf(" %12s", student.studnum);
					while(getchar() != '\n');
					
					int dup = 0;
					
					fp = fopen("student.txt", "r");
					if(fp != NULL){
						while(fgets(line, sizeof(line), fp)){
							if(strstr(line, "Student number: ") && strstr(line, student.studnum) != NULL){
							dup = 1;
							break;	
							}
						}
						fclose(fp);
					}
					if(dup){
						printf("\nstudent number already in use, try another one.\n");
					}else{
						break;
					}
				} while(1);
				
				printf("Enter student name: ");
				scanf(" %25[^\n]", student.studname);
				
				printf("Enter student course: ");
				scanf(" %5s", student.course);
		
				printf("Enter student year: ");
				scanf(" %d", &student.year);
				
				printf("Enter student section: ");
				scanf(" %d", &student.section);
				
				fp = fopen("student.txt", "a");
				fprintf(fp, "Student number: %s\n Student name: %s\n Course: %s %d-%d\n\n", 
						student.studnum,
						student.studname,
						student.course,
						student.year,
						student.section
						);
						
						fclose(fp);
						
						printf("\nStudent record succesfully added!");
						printf("\nAdd another?[Y/N]");
						scanf(" %c", &choice);
				
			} while( choice == 'Y' || choice == 'y');
			break;
			
		case 'E':

			printf("Enter student number: ");
			scanf(" %12s", student.studnum);
			while(getchar() != '\n');
			
			int fnd = 0;
			char tar[30];
			
			snprintf(tar, sizeof(tar), "Student number: %s", student.studnum);
		
			fp = fopen("student.txt", "r");
			if(fp != NULL){
				while(fgets(line, sizeof(line), fp)){
					if(strstr(line, tar) != NULL){
						fnd = 1;
						}
						if(fnd){
							printf("%s", line);
							if(strcmp(line, "\n")==0){
								break;
							}
						}
					}
				fclose(fp);
			}
			if(!fnd){
				printf("\nStudent does not exist.\n");
				break;
			}
			
			printf("\nEnter updated details\n");
			
			printf("\nUpdated student name: ");
			scanf(" %25[^\n]", student.studname);
			
			printf("\nUpdated student course: ");
			scanf(" %5s", student.course);
		
			printf("\nUpdated student year: ");
			scanf(" %d", &student.year);
		
			printf("\nUpdated student section: ");
			scanf(" %d", &student.section);
			while(getchar()!='\n');
			
			char adata[10000] = "";
			char newdata[250];
			
			snprintf(newdata, sizeof(newdata), "Student number: %s\n Student name: %s\n Course: %s %d-%d\n\n", 
						student.studnum,
						student.studname,
						student.course,
						student.year,
						student.section
						);
						
			fp = fopen("student.txt", "r");
			if(fp != NULL){
				int skip = 0;
				while(fgets(line, sizeof(line), fp)){
					if(strstr(line, tar) != NULL){
						skip = 1;
						strcat(adata, newdata);
						}
						if(skip){
							printf("%s", line);
							if(strcmp(line, "\n")==0){
								skip = 0;
							}
						} else {
							strcat(adata, line);
						}
					} 
					fclose(fp);
				}
				fp = fopen("student.txt", "w");
					if(fp != NULL){
							fprintf(fp, "%s", adata);
							fclose(fp);
					}
				printf("\nRecords updated\n");
				printf("%s", newdata);
			break;
			
		case 'V':
			printf("Enter student number: ");
			scanf(" %12s", student.studnum);
			while(getchar() != '\n');
			
			int found = 0;
			char target[100];
			
			snprintf(target, sizeof(target), "Student number: %s", student.studnum);
		
			fp = fopen("student.txt", "r");
			if(fp != NULL){
				while(fgets(line, sizeof(line), fp)){
					if(strstr(line, target) != NULL){
						found = 1;
						}
						if(found){
							printf("%s", line);
							if(strcmp(line, "\n")==0){
								break;
							}
						}
					}
				fclose(fp);
			}
			if(!found){
				printf("\nStudent does not exist.\n");
			}
			break;
			
		case 'X':
			printf("Enter student number: ");
			scanf(" %12s", student.studnum);
			while(getchar() != '\n');
			
			int del = 0;
			char deltar[309];
			char deldata[5000] = "";
			
			snprintf(deltar, sizeof(deltar), "Student number: %s", student.studnum);
		
			fp = fopen("student.txt", "r");
			if(fp != NULL){
				while(fgets(line, sizeof(line), fp)){
					if(strstr(line, deltar) != NULL){
						del = 1;
						}
						if(del){
							printf("%s", line);
							if(strcmp(line, "\n")==0){
								break;
							}
						}
					}
				fclose(fp);
			}
			if(!fnd){
				printf("\nStudent does not exist.\n");
				break;
			}
			
			printf("\nDelete this record?[Y/N]: ");
			scanf(" %c", &choice);
			while(getchar() != '\n');
			if( choice != 'Y' && choice != 'y'){
				printf("\nDeletion cancelled...\n");
				break;
			}
			
			fp = fopen("student.txt", "r");
			if(fp != NULL){
				int skip = 0;
				while(fgets(line, sizeof(line), fp)){
					if(strstr(line, deltar) != NULL){
						skip = 1;
						}
						if(skip){
							if(strcmp(line, "\n")==0){
								skip = 0;
							}
						} else {
							strcat(deldata, line);
						}
					} 
					fclose(fp);
				}
				fp = fopen("student.txt", "w");
					if(fp != NULL){
							fprintf(fp, "%s", deldata);
							fclose(fp);
					}
				printf("\nStudent record deleted.\n");	
			break;
		case 'L':
			printf("Exiting program...");
			break;
		default:
			printf("invalid!!!");
		}
	} while( mode != 'L');


	return 0;
}