#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED
#include "gestion_recette.h"

typedef struct Noeud{
    recette r;
    struct Noeud *fg, *fd;
} noeud;

//Creer un noeud
//param i la valeur du noeud
/*noeud* creer_noeud(recette r);

//Affiche un noed
//param n le noeud a afficher
void afficher_noeud(noeud n);

//Ajoute un neoud a la suite, a droite si plus grand, a gauche si plus petit
//param i la valeur du nouveau noeud
//param n le poiteur du poiteur du noeud
void ajouter_noeud(recette recette1, noeud **n);

//Afficher l'arbre completement du plus petit au plus grand
//param *n le noeud
void afficher_arbre(noeud *n);

//Recherhce un noeud
//param i la valeur qu'on chercher
//param *n le noeud
recette rechercher_noeud(char *c, noeud *n);

//Permet de compter le nombre de noeud
//param *n le noeud
int compter_noeud(noeud *n);

void liberer_arbre(noeud **n);*/
#endif // ARBRE_H_INCLUDED