#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_string.h"
#include "gestion_recette.h"
#include "gestion_ingredient.h"



void creer_arbre_recette(noeud_ingredient *ni){
	
	FILE *f_recette = NULL;
	recette r;
	char c = 'a';
	char mot_temp[255];
	int compteur_caractere=0;
	int compteur_ligne=0;
	int nb_lignes;
	
	f_recette = fopen("recette.txt", "r");
	if(f_recette != NULL){
		nb_lignes=compteur_ligne_fichier(f_recette);
		fclose(f_recette);
	}
	
	f_recette = fopen("recette.txt", "r");
	if(f_recette != NULL){
		//Ici, "! feof()" ne peut pas etre dans la condition, cela ne fonctionne pas
		/*while(compteur_ligne < nb_lignes){
			compteur_ligne++;*/
			
			//on initialise le compteur a 0
			compteur_caractere=0;
			
			//on recupere le nom de la recette
			while (1){
				c=fgetc(f_recette);
				if(c=='|'){break;}
				mot_temp[compteur_caractere]=c;
				compteur_caractere++;
			}
			
			mot_temp[compteur_caractere]='\0';
			r.nom = (char *) calloc(strlen(mot_temp), sizeof(char));
			strcpy(r.nom, mot_temp);
			
			//on met les variable mot_temp et compteur_caractere a zero
			memset(mot_temp, '\0', strlen(mot_temp)-1);
			compteur_caractere=0;
			
			//on recupere le nombre d'ingredient pour la recette
			fscanf(f_recette, "%d", &r.nb_ingredient);
			fseek(f_recette, 1, SEEK_CUR);
			
			//on recupere l'id du premier ingredient
			int id_ingredient_temp;
			fscanf(f_recette, "%d", &id_ingredient_temp);
			fseek(f_recette, 1, SEEK_CUR);
			
			//on met le premier ingredient dans le tableau d'ingredient de la recette
			ingredient i_temp = rechercher_ingredient(ni, id_ingredient_temp);
			r.ingre[0]=i_temp;
			
			//on recupere le nombre d'unite du premier ingredient 
			double qtt_ingredient_temp;
			fscanf(f_recette, "%lf", &qtt_ingredient_temp);
			fseek(f_recette, 1, SEEK_CUR);
			
			//on met la premiere qtt d'ingredient dans le tableau
			r.qtt_ingre[0]=qtt_ingredient_temp;
			
			printf("nom : %s\n", r.nom);
			printf("nombre d'ingredient : %d\n", r.nb_ingredient);
			printf("id de l'ingredient 1: %d\n", r.ingre[0].id);
			printf("qtt de l'ingredient 1 : %lf\n", r.qtt_ingre[0]);
			
		fclose(f_recette);
	}
}