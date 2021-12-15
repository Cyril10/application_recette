#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_string.h"
#include "gestion_recette.h"
#include "gestion_ingredient.h"

noeud_recette* creer_noeud_recette(recette r1){
	noeud_recette *nouveau = (noeud_recette*)malloc(sizeof(noeud_recette));
	if(nouveau==NULL){
		exit(EXIT_FAILURE);
	}
	else{
		nouveau->r = r1;
		nouveau->fg = NULL;
		nouveau->fd = NULL;
		return nouveau;
	}
}

//on ajoute les noeud en fonction du nom de la recette
void ajouter_noeud_recette(recette r1, noeud_recette **n){
	if((*n) == NULL) {
		(*n) = creer_noeud_recette(r1);
	}
	else{
		if(strcmp(r1.nom, ((*n)->r.nom))==1){		//on considere que l'ordre ce fait selon l'ordre ASCII des caractere ex : a<b
			ajouter_noeud_recette(r1, &(*n)->fd);
		}
		else{
			ajouter_noeud_recette(r1, &(*n)->fg);
		}
	}
}

void afficher_noeud_recette(noeud_recette n){
	printf("nom de la recette : %s\n", n.r.nom);
}	


void afficher_arbre_recette(noeud_recette *n){
	if(n != NULL){
		afficher_arbre_recette(n->fg);
		afficher_noeud_recette(*n);
		printf("\n");
		afficher_arbre_recette(n->fd);
	}
}

void afficher_arbre_recette2(noeud_recette *n, int niveau){
	if(n != NULL) {
		afficher_arbre_recette2(n->fd, niveau+1);
		for(int i=1; i<=niveau; i++){
			printf("----");
		}
		printf("%s\n", n->r.nom);
		afficher_arbre_recette2(n->fg, niveau+1);
	}
}

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
			
			//on recupere les ingredients et les quantite pour les mettres dans les tableaux de la recette
			for(int compteur_temp = 0; compteur_temp < r.nb_ingredient; compteur_temp++){
				
				//on recupere l'id de l'ingredient compteur_temp
				int id_ingredient_temp;
				fscanf(f_recette, "%d", &id_ingredient_temp);
				fseek(f_recette, 1, SEEK_CUR);
			
				//on met l'ingredient compteur_temp dans le tableau d'ingredient de la recette a la position compteur_temp
				ingredient i_temp = rechercher_ingredient(ni, id_ingredient_temp);
				r.ingre[compteur_temp]=i_temp;
			
				//on recupere le nombre d'unite de l'ingredient compteur_temp
				double qtt_ingredient_temp;
				fscanf(f_recette, "%lf", &qtt_ingredient_temp);
				fseek(f_recette, 1, SEEK_CUR);
				
				//on met la premiere qtt d'ingredient dans le tableau
				r.qtt_ingre[compteur_temp]=qtt_ingredient_temp;

			}
			
			//on recupere le nombre d'etape de la recette
			fscanf(f_recette, "%d", &r.nb_etape);
			fseek(f_recette, 1, SEEK_CUR);

			for(int compteur_temp=0; compteur_temp < r.nb_etape; compteur_temp++){
				//on recupere l'etapes dans un tableau temporaire de chaine de caractere 
				char tab_temp[500];
				while (1) {
					c=fgetc(f_recette);
					if(c=='|'){break;}
					tab_temp[compteur_caractere]=c;
					compteur_caractere++;
				}
				
				tab_temp[compteur_caractere]='\0';
				compteur_caractere=0;
				
				//on met l'etape dans une chaine de caractere dynamique pour gagner de la place
				//car trop grande difference du nb de caractere entre les etapes
				char *tab_temp_dyna;
				tab_temp_dyna = (char *)calloc(strlen(tab_temp), sizeof(char));
				
				strcpy(tab_temp_dyna, tab_temp);
				
				r.etape[compteur_temp]=tab_temp_dyna;
				
				
			}
			
			//on recupere la note de la recette
			fscanf(f_recette, "%lf", &r.note);
			fseek(f_recette, 1, SEEK_CUR);
			
			//on recupere la donnee pour cmb de personne est prevu la recette
			fscanf(f_recette, "%d", &r.nb_personne);
			fseek(f_recette, 1, SEEK_CUR);
			
			//on recupere la difficulte de la recette
			fscanf(f_recette, "%d", &r.difficulte);
			
			
		fclose(f_recette);
	}
}

/*PERMET DE VERIFIER PENDANT QUE JE CODE
			printf("nom : %s\n", r.nom);
			printf("nombre d'ingredient : %d\n", r.nb_ingredient);
			
			for(int compteur_temp = 0; compteur_temp < r.nb_ingredient; compteur_temp++){
				printf("id de l'ingredient %d : %d\n", compteur_temp, r.ingre[compteur_temp].id);
				printf("qtt de l'ingredient %d : %lf\n", compteur_temp, r.qtt_ingre[compteur_temp]);
				printf("nom de l'ingredient %d : %s\n", compteur_temp, r.ingre[compteur_temp].nom);
			}
			printf("nb d'etape : %d\n", r.nb_etape);
			printf("etape 1: %s\n", r.etape[0]);
			printf("etape 2: %s\n", r.etape[1]);
			printf(" note de la recette : %lf\n", r.note);
			printf("nombre de personne pour la recette : %d\n", r.nb_personne);
			printf("difficulte de la recette : %d\n", r.difficulte);
*/