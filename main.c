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

/*FILE *f_recette = NULL;
	f_recette = fopen("recette.txt", "r+");
	
	recopier_arbre_dans_fichier_recette(n_r, f_recette);
	
	fclose(f_recette);*/