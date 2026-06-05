#include <stdio.h>
#include <stdlib.h>

void creating(const char *file);
void printing(const char *file);
void append(const char *file);
void userinput(const char *file);
void rewritespecific(const char *file);
void seeking(const char *file);
void seekspecific(const char *file);
void allprinting(const char *file);

int main() {
	const char *file = "TextFile.txt";

	creating(file);
	printing(file);
	append(file);
	userinput(file);
	//rewritespecific(file);
	seeking(file);
	seekspecific(file);
	allprinting(file);
	
	//renames file
	rename("C:\\Users\\reign\\OneDrive\\Desktop\\COMPROG2\\Code\\FileHandling\\TextFile.txt","C:\\Users\\reign\\OneDrive\\Desktop\\COMPROG2\\Code\\FileHandling\\bestfile.txt");
	
	//remove("C:\\Users\\reign\\OneDrive\\Desktop\\COMPROG2\\Code\\FileHandling\\TextFile.txt")
	
	return 0;
}

void creating(const char *file){
	FILE *fp;
	
	fp = fopen(file, "w");
	
	if(fp == NULL){
		printf("File can not be accessed\n");
	} else {
		printf("File is accessible\n");
	}
	
	char text[100] = "Reign Allyson Lasco";
	
	fprintf(fp, "%s\n", text);
	
	fclose(fp);
}

void printing(const char *file){
	FILE *fp;
	
	fp = fopen(file, "r");
	
	char text1[100];
	
		if(fp == NULL){
		printf("\nFile can not be accessed\n");
	} else {
		printf("File is accessible\n");
	}
	
	//prints all 
	
	while(fscanf(fp, "%s", text1) != EOF){
		printf("%s ", text1);
	}
	
	fclose(fp);
}

void append(const char *file){
	FILE *fp;
	
	fp = fopen(file, "a");
	
	char text2[100] = "Bachelor of Science in Computer Science";
	
		if(fp == NULL){
		printf("\nFile can not be accessed\n");
	} else {
		printf("File is accessible\n");
	}
	
	fprintf(fp, "%s\n", text2);
	
	fclose(fp);
}

void userinput(const char *file){
	FILE *fp;
	
	fp = fopen(file, "a");
	
	char text3[100];
	
		if(fp == NULL){
		printf("\nFile can not be accessed\n");
	} else {
		printf("File is accessible\n");
	}
	
	printf("\nInsert new text:");
	fgets(text3, sizeof(text3), stdin);
	fprintf(fp, "%s\n", text3);
	
	fclose(fp);
}

void rewritespecific(const char *file){
	FILE *fp;
	
		fp = fopen(file, "w+");
	//text before
	fputs("I love sleep", fp);
	
		if(fp == NULL){
		printf("\nFile can not be accessed\n");
	} else {
		printf("File is accessible\n");
	}
	//text after
	fseek(fp, 8, SEEK_SET);
	fputs("love art", fp);
	
	fclose(fp);
}

void seeking(const char *file){
	FILE *fp;
	
	fp = fopen(file, "r");
	
	char text4;
	
		if(fp == NULL){
		printf("\nFile can not be accessed\n");
	} else {
		printf("File is accessible\n");
	}
	//seeks 3rd letter
	fseek(fp, 3, SEEK_SET);
	text4 = fgetc(fp);	
	printf("%c\n", text4);
	//seeks starting from the third letter and counts
	fseek(fp, 3, SEEK_CUR);
	text4 = fgetc(fp);	
	printf("%c\n", text4);
	//Seeks starting from the EOL
	fseek(fp, -5, SEEK_END);
	text4 = fgetc(fp);	
	printf("%c\n", text4);
	
	fclose(fp);
}

void seekspecific(const char *file){
	FILE *fp;
	
	fp = fopen(file, "r");
	
	char text5[100];
	
		if(fp == NULL){
		printf("\nFile can not be accessed\n");
	} else {
		printf("File is accessible\n");
	}
	
	fseek(fp, 5, SEEK_SET);
	fgets(text5, sizeof(text5), fp);
	printf("%s\n", text5);
	
	
	fclose(fp);
}

void allprinting(const char *file){
	FILE *fp;
	
	fp = fopen(file, "r");
	
	char text7[100];
	
		if(fp == NULL){
		printf("File can not be accessed\n");
	} else {
		printf("File is accessible\n");
	}
	
	while(fgets(text7, sizeof(text7), fp) != NULL){
		printf("%s ", text7);
	}
	
	fclose(fp);
}
