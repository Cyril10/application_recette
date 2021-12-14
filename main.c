#include<stdlib.h>
#include<stdio.h>
#include "gestion_recette.h"
#include "gestion_ingredient.h"
#include "new_string.h"

int main(void){
	
	
	noeud_ingredient* n_i;
	n_i = creer_arbre_ingredient2();
	creer_arbre_recette(n_i);
	
	liberer_arbre_ingredient(&n_i);
	
	return EXIT_SUCCESS;
	
}
	
/*	char *c;
	printf("Quelle est la recette que vous chercher : ");
	c=lecture();
	
	printf("\nRECETTE TROUVE : \n");
	r=rechercher_noeud(c, arbre_de_recette);
	afficher_recette(r);*/
	
	/*char *c1, *c2;
	
	c1=lecture();
	c2=lecture();
	
	printf("\n---%d", comparer_string(c1, c2));*/