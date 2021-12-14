#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_string.h"
#include "gestion_recette.h"

//Permet d'ajouter une recette dans le fichier "recette.txt"
//La fonction ajoute la recette après celle déjà dans le fichier
//Le fichier doit déjà être créer

void ajouter_recette(void){

    FILE *f_recette = NULL;
	char *nom;
	int nb_ingredients;

    f_recette = fopen ("recette.txt", "a+");

    if(f_recette!=NULL){

        printf("Nom de la nouvelle recette : ");
		nom=lecture();
		printf("\n");
		
		printf("Nombre d'ingredient pour la recette : ");
		scanf("%d", &nb_ingredients);
		
		fprintf(f_recette,"%s|%d\n", nom, nb_ingredients);
		
    }

    fclose(f_recette);
}

//Permet de lire la première recette inscrite dans le fichier texte recette.txt

recette lire_une_recette(void){
	FILE *f_recette = NULL;
	recette r;
	char c='a';
	char nom[255];
	int i=0;
	
	f_recette = fopen("recette.txt", "r+");
	
	if(f_recette!=NULL){
		
		while(1){
			c=fgetc(f_recette);
			if(c=='|'){break;}
			nom[i]=c;
			i++;
		}
		
		nom[i]='\0';
		size_t s = strlen(nom);
		r.nom= (char*)malloc(s); //Faute
		strcpy(r.nom, nom);
	
	
		fscanf(f_recette, "%d", &r.nb_ingredients);
	
		fclose(f_recette);
	}
	
	return r;
}

//Permet de lire toutes les recettes du fichiers texte recette.txt

void lire_toutes_les_recettes(recette tabR[10]){
	FILE *f_recette = NULL;
	recette r;
	char c='a';
	char nom[255];
	int i=0, j=0;
	
	f_recette = fopen("recette.txt", "r+");
	
	if(f_recette!=NULL){
		
		//Tant que l'on est pas a la fin du fichier on prends les infos
		
		while(! feof(f_recette)){
			i=0;
			
			//Permet de connaitre le nom de la recette
			while(1){
				c=fgetc(f_recette);
				if(c=='|'){break;}
				nom[i]=c;
				i++;
			}
		
			nom[i]='\0';
			size_t s = strlen(nom);
			r.nom= (char*)malloc(s); //faute
			strcpy(r.nom, nom);
			
			//permet de connaitre le nombre d'ingredient de la recette
			fscanf(f_recette, "%d", &r.nb_ingredients);
			
			tabR[j]=r;
			j++;
			
			if(! feof(f_recette)){fseek(f_recette, 2, SEEK_CUR);}
			
			//permet de mettre le mémoier de la chaine de caractere nom a 0
			memset(nom, '\0', strlen(nom)-1);
		}
		
	}
	fclose(f_recette);
}

//Permet d'afficher la recette entrée en paramètre

void afficher_recette(recette r){
	printf("--------------------------------------\n");
	printf("NOM : %s\n", r.nom);
	printf("NOMBRE INGREDIENTS : %d\n", r.nb_ingredients);
	printf("--------------------------------------\n");
}
