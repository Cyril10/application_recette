#include<stdlib.h>
#include<stdio.h>
#include"gestion_recette.h"
#include "arbre.h"
#include "new_string.h"

int main(void){

	recette r;
	r.nom="moule frite";
	r.nb_ingredients=3;
	
	noeud *arbre_de_recette;
	arbre_de_recette=creer_noeud(r);
	
	r.nom="pate saumon";
	r.nb_ingredients=2;
	ajouter_noeud(r, &arbre_de_recette);
	
	r.nom="bouche";
	r.nb_ingredients=18;
	ajouter_noeud(r, &arbre_de_recette);
	
	//afficher_arbre(arbre_de_recette);
	
	afficher_arbre(arbre_de_recette);
	
	char *c;
	printf("Quelle est la recette que vous chercher : ");
	c=lecture();
	
	printf("\nRECETTE TROUVE : \n");
	r=rechercher_noeud(c, arbre_de_recette);
	afficher_recette(r);
	
	/*char *c1, *c2;
	
	c1=lecture();
	c2=lecture();
	
	printf("\n---%d", comparer_string(c1, c2));*/
	
	liberer_arbre(&arbre_de_recette);
	
    return EXIT_SUCCESS;
	
}


/*noeud *arbre=creerNoeud(6);
	ajouterNoeud(2, &arbre);
	ajouterNoeud(8, &arbre);
	ajouterNoeud(1, &arbre);
	ajouterNoeud(4, &arbre);
	ajouterNoeud(10, &arbre);
	ajouterNoeud(9, &arbre);
	printf("\n");
	afficherArbre(arbre);
	printf("------\n");
	libererArbre(&arbre);*/
	
