#ifndef GESTION_RECETTE_H_INCLUDED
#define GESTION_RECETTE_H_INCLUDED
#include "gestion_ingredient.h"

typedef struct{
	char *nom;
	int nb_ingredient;
	ingredient ingre[50];
	double qtt_ingre[50];		//la qtt a la case 0 correspond a la qtt de l'ingredient dans la case 0 du tableau ingre
	int nb_etape;
	char *etape[10];			//permet de contenir toutes les etapes de la recette
	int note;
	int nb_personne;		//permet de definir pour combien de personne est prevu la recette
	int difficulte;
}recette;

void creer_arbre_recette(noeud_ingredient *ni);

#endif // GESTION_RECETTE_H_INCLUDED
