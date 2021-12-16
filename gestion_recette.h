#ifndef GESTION_RECETTE_H_INCLUDED
#define GESTION_RECETTE_H_INCLUDED
#include "gestion_ingredient.h"

typedef struct{
	char *nom;
	int nb_ingredient;
	ingredient ingre[50];
	double qtt_ingre[50];	//la qtt a la case 0 correspond a la qtt de l'ingredient dans la case 0 du tableau ingre
	int nb_etape;
	char *etape[40];		//permet de contenir toutes les etapes de la recette
	double note;				//note moyenne attribuer par les utilisateurs
	int nb_personne;		//permet de definir pour combien de personne est prevu la recette
	int difficulte; 		//allant de 1 a 5, 1 étant facile
}recette;

typedef struct NoeudR{
	recette r;
	struct NoeudR *fg, *fd;		//fils gauche et fils droit
} noeud_recette;

noeud_recette* creer_arbre_recette(noeud_ingredient *ni);

noeud_recette* creer_noeud_recette(recette r1);

void ajouter_noeud_recette(recette r1, noeud_recette **n);

void afficher_noeud_recette(noeud_recette n);

void afficher_arbre_recette(noeud_recette *n);

void afficher_arbre_recette2(noeud_recette *n, int niveau);

void liberer_arbre_recette(noeud_recette **n);

recette rechercher_recette(char *c, noeud_recette *n);

void afficher_recette(recette r);

void recopier_arbre_dans_fichier_recette(noeud_recette *n, FILE *f_recette);

void rajouter_recette(noeud_ingredient *n_i, noeud_recette **n_r);

#endif // GESTION_RECETTE_H_INCLUDED
