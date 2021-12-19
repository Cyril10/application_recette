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
		if(strcmp(r1.nom, ((*n)->r.nom)) > 0){		//on considere que l'ordre ce fait selon l'ordre ASCII des caractere ex : a<b
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

noeud_recette* creer_arbre_recette(noeud_ingredient *ni){
	noeud_recette *n1 = NULL;
	
	
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
		while(compteur_ligne < nb_lignes){
			compteur_ligne++;
			
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
			fseek(f_recette, 2, SEEK_CUR);
			
			ajouter_noeud_recette(r, &n1);
		}
		return n1;
		fclose(f_recette);
	}
}

void liberer_arbre_recette(noeud_recette**n){
	if(*n != NULL){
		liberer_arbre_recette(&(*n)->fg);
		liberer_arbre_recette(&(*n)->fd);
		free(*n);
	}
}

recette rechercher_recette(char *c, noeud_recette *n){
	recette r;
	r.nom=NULL;
	if(n != NULL){
		if(strcmp(c, n->r.nom) < 0){
			r = rechercher_recette(c, n->fg);
		}
		if(strcmp(c, n->r.nom) > 0){
			r = rechercher_recette(c, n->fd);
		}
		if(strcmp(c, n->r.nom) == 0){
			return n->r;
		}
	return r;
	}
}

void afficher_recette(recette r){
	printf("\n--------------------\n");
	printf("Nom : %s\n", r.nom);
	printf("Nb ingredient : %d\n", r.nb_ingredient);
	printf("Il faut : \n");
	for(int i = 0; i < r.nb_ingredient; i++){
		printf("%s : %lf %s\n", r.ingre[i].nom, r.qtt_ingre[i], r.ingre[i].unite);
	}
	printf("Il y a %d etape\n", r.nb_etape);
	for(int i = 0; i < r.nb_etape; i++){
		printf("etape %d : %s\n", i, r.etape[i]);
	}
	printf("Note : %lf / 5\n", r.note);
	printf("Pour %d personne\n", r.nb_personne);
	printf("Difficulte : %d / 5\n", r.difficulte);
	printf("--------------------\n");
}

//permet de recopier toutes les recettes de l'arbre dans le fichier texte recette
void recopier_arbre_dans_fichier_recette(noeud_recette *n, FILE *f_recette){
	if(n != NULL){
		recopier_arbre_dans_fichier_recette(n->fg, f_recette);
		
		fprintf(f_recette, "%s|%d|", n->r.nom, n->r.nb_ingredient);
		for(int i = 0; i < n->r.nb_ingredient; i++){
			fprintf(f_recette, "%d|%lf|", n->r.ingre[i].id, n->r.qtt_ingre[i]);
		}
		fprintf(f_recette, "%d|", n->r.nb_etape);
		for(int i = 0; i < n->r.nb_etape; i++){
			fprintf(f_recette, "%s|", n->r.etape[i]);
		}
		fprintf(f_recette, "%lf|%d|%d\n", n->r.note, n->r.nb_personne, n->r.difficulte);
		
		recopier_arbre_dans_fichier_recette(n->fd, f_recette);
	}
}

void rajouter_recette(noeud_ingredient *n_i, noeud_recette **n_r){
	recette r;
	
	printf("CREATION D'UNE NOUVELLE RECETTE\n");
	
	printf("nom  : ");
	r.nom = lecture();
	
	printf("\nnombre d'ingredient : ");
	scanf("%d", &r.nb_ingredient);
	getchar();
	printf("\n");
	
	for(int i = 0; i < r.nb_ingredient; i++){
		int id_ingredient_temp;
		printf("id de l'ingredient %d : ", i);
		scanf("%d", &id_ingredient_temp);
		getchar();
		printf("\n");
		
		ingredient i_temp = rechercher_ingredient(n_i, id_ingredient_temp);
		r.ingre[i] = i_temp;
		
		double qtt_ingredient_temp;
		printf("quantite de l'ingredient %s en %s : ", r.ingre[i].nom, r.ingre[i].unite);
		scanf("%lf", &r.qtt_ingre[i]);
		getchar();
		printf("\n");
	}
	
	printf("nombre d'etape : ");
	scanf("%d", &r.nb_etape);
	getchar();
	printf("\n");
	
	for(int i = 0; i < r.nb_etape; i++){
		printf("etape %d : ", i+1);
		r.etape[i] = lecture();
	}
	
	printf("\nnote : ");
	scanf("%lf", &r.note);
	printf("\n");
	
	printf("pour combien de personne : ");
	scanf("%d", &r.nb_personne);
	printf("\n"); 
	
	printf("difficulte : ");
	scanf("%d", &r.difficulte);
	printf("\n");
	
	ajouter_noeud_recette(r, n_r);
}

noeud_recette* sortir_plus_grand(noeud_recette **n_r){
	noeud_recette *temp = NULL;
	if(*n_r != NULL){
		if((*n_r)->fd != NULL){
			return sortir_plus_grand(&(*n_r)->fd);
		}
		else{
			temp = (*n_r);
			(*n_r) = (*n_r)->fd;
			return temp;
		}
	}
}

void supprimer_recette(noeud_recette **n_r, char *c){
	if(n_r != NULL){
		if(strcmp(c, ((*n_r)->r.nom)) < 0){
			supprimer_recette(&(*n_r)->fg, c);
		}
		else {
			if(strcmp(c, ((*n_r)->r.nom)) > 0){
				supprimer_recette(&(*n_r)->fd, c);
			}
			else{
				noeud_recette *temp = *n_r;
				if((*n_r)->fg == NULL){
					*n_r = (*n_r)->fd;
				}
				else{
					if ((*n_r)->fd == NULL){
						*n_r = (*n_r)->fg;
					}
					else{
						noeud_recette *temp2 = sortir_plus_grand(&(*n_r)->fg);
						temp2->fd = (*n_r)->fd;
						temp2->fg = (*n_r)->fg;
						*n_r = temp2;
					}
				}
			free(temp);
			}
		}
	}
}
	
void modifier_recette(noeud_recette **n_r, char *c){
	if(n_r != NULL){
		if(strcmp(c, (*n_r)->r.nom) < 0){
			modifier_recette(&(*n_r)->fg, c);
		}
		if(strcmp(c,(*n_r)->r.nom) > 0){
			modifier_recette(&(*n_r)->fd, c);
		}
		if(strcmp(c, (*n_r)->r.nom) == 0){
			int choix = -1;
			while (choix != 0){
				printf("Que voulez vous modifier ? \n");
				printf("1 - Le nom de la recette\n");
				printf("2 - La note\n");
				printf("3 - Le nombre de personne pour laquelle la recette est prevu\n");
				printf("4 - La difficulte de la recette\n");
				printf("0 - Revenir au menu principal\n");
				printf("Quel est votre choix : ");
				
				scanf("%d", &choix);
				getchar();
				
				system("cls");
				
				switch(choix){
					case 1 :
						printf("Nouveau nom de recette : ");
						(*n_r)->r.nom = NULL;
						(*n_r)->r.nom = lecture();
						
						printf("\nLe nouveau nom de la recette est : %s\n", (*n_r)->r.nom);
						break;
					case 2 :
						printf("Nouvelle note : ");
						
						scanf("%lf", &(*n_r)->r.note);
						getchar();
						
						printf("\nLa nouvelle note de la recette est : %lf\n", (*n_r)->r.note);
						break;
					case 3 :
						printf("Nouveau nombre de personne prevu pour la recette : ");
						
						scanf("%d", &(*n_r)->r.nb_personne);
						getchar();
						
						printf("\nLe nouveau nombre de personne est : %d\n", (*n_r)->r.nb_personne);
						break;
						
					case 4 :
						printf("Nouvelle difficulte : ");
						
						scanf("%d", &(*n_r)->r.difficulte);
						getchar();
						
						printf("\nLa nouvelle difficulte de la recette est : %d\n", (*n_r)->r.difficulte);
						break;
					
					case 0 :
						break;
					
					default :
						printf("Erreur lors de la saisie, resaisir\n");
				}
			}
		}
	}
}