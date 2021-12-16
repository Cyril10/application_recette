#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lecture(void){
    char temp[255];
	
    fgets(temp,255,stdin);
	temp[strcspn(temp, "\n")]=0;
	size_t s = strlen(temp);
	char *string = (char*)malloc(s+1);
	strcpy(string, temp);
	return string;
}