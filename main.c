#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gestion_recette.h"
#include "gestion_ingredient.h"
#include "new_string.h"
#include "menu.h"

int main(void){
	
	//on fait l'arbre d'ingredient via le fichier
	noeud_ingredient* n_i;
	n_i = creer_arbre_ingredient2();

	//on fait l'arbre de recette via le fichier recette
	noeud_recette* n_r;
	n_r = creer_arbre_recette(n_i);
	
	system("cls");
	menu(n_i, n_r);
	
	liberer_arbre_recette(&n_r);
	liberer_arbre_ingredient(&n_i);
	return EXIT_SUCCESS;
	
}

/*test
	afficher_arbre_recette(n_r);
	
	char c[20]="Soupe de courge";
	recette r;
	r = rechercher_recette(c, n_r);
	
	afficher_recette(r);*/