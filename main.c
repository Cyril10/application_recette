#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include "gestion_recette.h"
#include "gestion_ingredient.h"
#include "new_string.h"

int main(void){
	
	
	/*noeud_ingredient* n_i;
	n_i = creer_arbre_ingredient2();
	creer_arbre_recette(n_i);
	
	liberer_arbre_ingredient(&n_i);*/
	
	recette r, r1, r2, r3;
	printf("lire le nom de la premiere recette\n");
	r.nom=lecture();
	
	printf("lire le nom de la deuxieme recette\n");
	r1.nom=lecture();
	
	printf("nom 3 recette\n");
	r2.nom=lecture();
	
	printf("nom 4eme recette\n");
	r3.nom=lecture();
	
	noeud_recette* n_r=creer_noeud_recette(r);
	ajouter_noeud_recette(r1, &n_r);
	ajouter_noeud_recette(r2, &n_r);
	ajouter_noeud_recette(r3, &n_r);
	afficher_arbre_recette(n_r);
	printf("\n\n");
	afficher_arbre_recette2(n_r, 1);
	
	
	
	
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