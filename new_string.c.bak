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

//compare deux chaine de caractere
//return 1 si chaine1 est "avant" chaine2 (chaine1 = a et chaine2 = b)
//return -1 si chaine1 est "apres" chaine2 (chaine1 = b et chaine2 = a)
//return 0 si chaine1 = chaine2

int comparer_string(char *chaine1, char *chaine2){
	for(int i=0; i<10; i++){
		// /!\ a<b 
		if((*(chaine1+i)) < (*(chaine2+i))){
			return 1;
		}
		else{
			if((*(chaine1+i)) > (*(chaine2+i))){
				return -1;
			}
		}
	}
	return 0;
}