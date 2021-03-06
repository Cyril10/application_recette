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

//on ajoute un noeud en fonction de l'id de l'ingredient
void ajouter_noeud_ingredient2(int id, char *nom, char *unite, noeud_ingredient **n){
	ingredient i;
	i.id=id;
	
	i.nom = (char *) calloc(strlen(nom), sizeof(char));
	strcpy(i.nom, nom);
	
	i.unite = (char *) calloc(strlen(unite), sizeof(char));
	strcpy(i.unite, unite);
	
	if((*n) == NULL) {
		(*n) = creer_noeud_ingredient(i);
	}
	else{
		if(i.id < (*n)->i.id){
			ajouter_noeud_ingredient2(id, nom, unite, &(*n)->fg);
		}
		else{
			ajouter_noeud_ingredient2(id, nom, unite, &(*n)->fd);
		}
	}
}

//permet d'afficher l'id d'un ingredient d'un noeud
void afficher_noeud_ingredient(noeud_ingredient n){
	printf("id de l'ingredient du noeud : %d\n", n.i.id);
	printf("nom de l'ingredient du noeud : %s\n", n.i.nom);
	printf("nom de l'unite du noeud : %s\n", n.i.unite);
	printf("---------------------------------");
}

//permet d'afficher tous les ingredients de l'arbre complet
void afficher_arbre_ingredient(noeud_ingredient *n){
	if( n!=NULL ){
		afficher_arbre_ingredient(n->fg);
		afficher_noeud_ingredient(*n);
		printf("\n");
		afficher_arbre_ingredient(n->fd);
	}
}

//Permet d'afficher les id d'ingredient comme un arbre binaire
void afficher_arbre_ingredient2(noeud_ingredient *n,int niveau){
    if(n != NULL){
        afficher_arbre_ingredient2(n->fd, niveau+1);
        for(int i=1; i<=niveau; i++){
            printf("----");
        }
        printf("%d\n", n->i.id);
        afficher_arbre_ingredient2(n->fg, niveau+1);
    }
}

noeud_ingredient* creer_arbre_ingredient2(void){
	noeud_ingredient *n1 = NULL;
	
	FILE *f_ingredient = NULL;
	
	//on ne peut pas créer d'ingredient ici car les nom et unite sont déclarer dynamiquement
	//donc l'adresse est la même pour tous les ingredient si on les déclarent ici
	//il faut donc les déclarer ailleurs (ici dans ajouter_noeud_ingredient2)
	//c'est ça la différence entre creer_arbre_igredient et creer_arbre_ingredient2
	//pareils avec ajouter_noeud_ingredient et ajouter_noeud_ingredient2
	int id_ingredient_temp=0;
	char nom_ingredient_temp[255];
	char unite_ingredient_temp[255];
	
	char c='a';
	char compteur_caractere=0;
	int compteur_ligne=0;
	int nb_lignes;
	
	f_ingredient = fopen("ingredient.txt" , "r");
	
	if(f_ingredient != NULL){
		nb_lignes=compteur_ligne_fichier(f_ingredient);
		
		fseek(f_ingredient, 0, SEEK_SET);
		
		//Ici, "! feof()" ne peut pas etre dans la condition, cela ne fonctionne pas
		while(compteur_ligne < nb_lignes){
			compteur_ligne++;
			
			//on initialise le compteur a 0
			compteur_caractere=0;
			
			//on recupere l'id
			fscanf(f_ingredient, "%d", &id_ingredient_temp);
			fseek(f_ingredient, 1, SEEK_CUR);
			
			//on recupere le nom de l'ingredient
			while (1) {
				c=fgetc(f_ingredient);
				if(c=='|'){break;}
				nom_ingredient_temp[compteur_caractere]=c;
				compteur_caractere++;
			}
			
			nom_ingredient_temp[compteur_caractere]='\0';
			
			//on met la variable compteur_caractere a zero
			compteur_caractere=0;
			
			while (1) {
				c = fgetc(f_ingredient);
				if(c=='|'){break;}
				unite_ingredient_temp[compteur_caractere]=c;
				compteur_caractere++;
			}
			
			unite_ingredient_temp[compteur_caractere]='\0';
			
			ajouter_noeud_ingredient2(id_ingredient_temp, nom_ingredient_temp, unite_ingredient_temp, &n1);
			
			//on reinitialise les tableau a 0
			memset(nom_ingredient_temp, '\0', strlen(nom_ingredient_temp)-1);
			memset(unite_ingredient_temp, '\0', strlen(unite_ingredient_temp)-1);
		}
	fclose(f_ingredient);
	}
	else{
		printf("erreur a l'ouverture du fichier");
	}
	return n1;
}

ingredient rechercher_ingredient(noeud_ingredient *n, int id){
	ingredient i;
	
	if(n != NULL){
		if(id < n->i.id){
			i = rechercher_ingredient(n->fg, id);
		}
		else{
			if(id > n->i.id){
				i = rechercher_ingredient(n->fd, id);
			}
			else{
				return n->i;
			}
		}
		return i;
	}
}

void liberer_arbre_ingredient(noeud_ingredient **n){
	if(*n != NULL){
		liberer_arbre_ingredient(&(*n)->fg);
		liberer_arbre_ingredient(&(*n)->fd);
		free(*n);
	}
}

int compteur_ligne_fichier(FILE *fichier){
	int c;
	int nb_lignes = 0;
	while((c=fgetc(fichier)) != EOF)
	{
		if(c=='\n')
			nb_lignes++;
	}
	return nb_lignes;
}