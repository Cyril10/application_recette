#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "new_string.h"

/*noeud* creer_noeud(recette recette1){
	noeud *nouveau = (noeud *)malloc(sizeof(noeud));
	if(nouveau==NULL){
		exit(EXIT_FAILURE);
	}
	else{
		nouveau->r=recette1;
		nouveau->fg = NULL;
		nouveau->fd = NULL;
		return nouveau;
	}
}

//Affiche un noeud

void afficher_noeud(noeud n){
	afficher_recette(n.r);
}

//Ajoute un Noeud dans l'arbre si le nom de la recette1 est "superieur" 
//(en supposant que a<b) alors on le met a gauche sinon a droite
//on fait l'inverse pour mettre dans l'ordre alphabétique
 

void ajouter_noeud(recette recette1, noeud **n){
	
	if((*n)==NULL){
		(*n) = creer_noeud(recette1);
	}
	else {
		if(comparer_string(recette1.nom , ((*n)->r.nom))==-1){
			ajouter_noeud(recette1, &(*n)->fd);
		}
		else{
			ajouter_noeud(recette1, &(*n)->fg);
		}
	}
}

void afficher_arbre(noeud *n){
	if(n!=NULL){
		afficher_arbre(n->fg);
		afficher_noeud(*n);
		afficher_arbre(n->fd);
	}
}

recette rechercher_noeud(char *c, noeud *n){
	recette r;
	r.nom="NULL";
	r.nb_ingredients=0;
	if(n!=NULL){
		if(comparer_string(n->r.nom, c)==-1){
			r = rechercher_noeud(c, n->fg);
			printf("\n|%s|\n", c);
			printf("|%s|\n", n->r.nom);
		}
		else {
			if(comparer_string(n->r.nom, c)==1){
			r = rechercher_noeud(c, n->fd);
			
			}
			else {
			return n->r;
			}
		}
	}
	return r;
}

int compter_noeud(noeud *n){
	int compte = 0;
	if(n!=NULL){
		compte += compter_noeud(n->fg);
		compte++;
		compte += compter_noeud(n->fd);
	}
	return compte;
}

void liberer_arbre(noeud **n){
	if(*n != NULL){
		liberer_arbre(&(*n)->fg);
		liberer_arbre(&(*n)->fd);
		//printf("Effacement de la recette %s\n", (*n)->r.nom);
		free(*n);
	}
}*/