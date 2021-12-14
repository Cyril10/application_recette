#ifndef GESTION_INGREDIENT_H_INCLUDED
#define GESTION_INGREDIENT_H_INCLUDED

typedef struct{
	int id;
	char *nom;
	char *unite;
}ingredient;

typedef struct NoeudI{
    ingredient i;
    struct NoeudI *fg, *fd;
} noeud_ingredient;


noeud_ingredient* creer_arbre_ingredient(void);

noeud_ingredient* creer_noeud_ingredient(ingredient igredient1);

void ajouter_noeud_ingredient(ingredient i1, noeud_ingredient **n);

void afficher_noeud_ingredient(noeud_ingredient n);

void afficher_arbre_ingredient(noeud_ingredient *n);

void afficher_arbre_ingredient2(noeud_ingredient *n,int niveau);

void liberer_arbre_ingredient(noeud_ingredient **n);

#endif // GESTION_INGREDIENT_H_INCLUDED