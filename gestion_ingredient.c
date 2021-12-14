#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_ingredient.h"

//permet de créer un noeud (arbre) d'ingredient et de le retouner
noeud_ingredient* creer_noeud_ingredient(ingredient i1){
	noeud_ingredient *nouveau = (noeud_ingredient *)malloc(sizeof(noeud_ingredient));
	if(nouveau==NULL){
		exit(EXIT_FAILURE);
	}
	else{
		nouveau->i=i1;
		nouveau->fg = NULL;
		nouveau->fd = NULL;
		return nouveau;
	}
}

//permet d"ajouter un ingredient dans l'arbre en fonction de l'id de l'ingredient
void ajouter_noeud_ingredient(ingredient i1, noeud_ingredient **n){
	
	if((*n) == NULL){
		(*n) = creer_noeud_ingredient(i1);
	}
	else{
		if( i1.id < (*n)->i.id ) {
			ajouter_noeud_ingredient(i1, &((*n)->fg));
		}
		else{
			ajouter_noeud_ingredient(i1, &((*n)->fd));
		}
	}
}

//permet d'afficher l'id d'un ingredient d'un noeud
void afficher_noeud_ingredient(noeud_ingredient n){
	printf("id de l'ingredient du noeud : %d\n", n.i.id);
}

//permet d'afficher tous les id des ingredients de l'arbre complet
void afficher_arbre_ingredient(noeud_ingredient *n){
	if( n!=NULL ){
		afficher_arbre_ingredient(n->fg);
		afficher_noeud_ingredient(*n);
		afficher_arbre_ingredient(n->fd);
	}
}

int compteur_ligne_fichier(FILE *fichier){
	int c;
	int nb_lignes = 1;
	while((c=fgetc(fichier)) != EOF)
	{
		if(c=='\n')
			nb_lignes++;
	}
	return nb_lignes;
}

noeud_ingredient* creer_arbre_ingredient(void){
	noeud_ingredient *n1=NULL;
	
	FILE *f_ingredient = NULL;
	ingredient i;
	char c='a';
	char mot_temp[255]; //permet de lire les nom et unite a partir du fichier (gain de place en utilisant une seule variable plutot que deux)
	int compteur_caractere=0; //permet de compter le nombre de caractere pour le nom et l'unite
	int compteur_ligne=0; //permet de savoir sur qu'elle ligne on est
	int nb_lignes; //permet de savoir le nombre de ligne qu'il y a dans notre fichier
	
	f_ingredient = fopen("ingredient.txt", "r");
	if(f_ingredient!=NULL){
		nb_lignes=compteur_ligne_fichier(f_ingredient);
		fclose(f_ingredient);
	}
	
	f_ingredient = fopen("ingredient.txt", "r");
	if(f_ingredient!=NULL){
		
		//Ici, "! feof()" ne peut pas etre dans la condition, cela ne fonctionne pas
		while(compteur_ligne < nb_lignes){ //permet de savoir si on est arriver a la fin du fichier
			compteur_ligne++;
			//on initialise le comtpeur a 0
			compteur_caractere=0;
			
			//on récupère l'id
			fscanf(f_ingredient, "%d", &i.id);
			fseek(f_ingredient, 1, SEEK_CUR);
			
			//on récupère le nom de l'ingredient
			while (1) {
				c=fgetc(f_ingredient);
				if(c=='|'){break;}
				mot_temp[compteur_caractere]=c;
				compteur_caractere++;
			}
					
			mot_temp[compteur_caractere]='\0';
			i.nom = (char*)calloc(strlen(mot_temp), sizeof(char));
			strcpy(i.nom, mot_temp);
			
			//on met la variable mot_temp a zero pour stocker l'unite dedans
			memset(mot_temp, '\0', strlen(mot_temp)-1);
			compteur_caractere=0;
			
			//on recupere l'unite de l'ingredient
			while(1){
				c=fgetc(f_ingredient);
				if(c=='|'){break;}
				mot_temp[compteur_caractere]=c;
				compteur_caractere++;
			}
			
			mot_temp[compteur_caractere]='\0';
			i.unite = (char*)calloc(strlen(mot_temp), sizeof(char));
			strcpy(i.unite, mot_temp);

			memset(mot_temp, '\0', strlen(mot_temp)-1);
			
			printf("%s\n", i.nom);
			ajouter_noeud_ingredient(i, &n1);
			free(i.nom);
			free(i.unite);
			
		}
	fclose(f_ingredient);
	}
	else{
		printf("erreur a l'ouverture du fichier");
	}
	
	return n1;
}

void afficher_arbre_ingredient2(noeud_ingredient *n,int niveau){
    if(n){
        afficher_arbre_ingredient2(n->fd, niveau+1);
        for(int i=1; i<=niveau; i++){
            printf("----");
        }
        printf("%d\n", n->i.id);
        afficher_arbre_ingredient2(n->fg, niveau+1);

    }
}

void liberer_arbre_ingredient(noeud_ingredient **n){
	if(*n != NULL){
		liberer_arbre_ingredient(&(*n)->fg);
		liberer_arbre_ingredient(&(*n)->fd);
		free(*n);
	}
}