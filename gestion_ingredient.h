#ifndef GESTION_INGREDIENT_H_INCLUDED
#define GESTION_INGREDIENT_H_INCLUDED

typedef struct{
	int id;
	char *nom;
	char *unite;
}ingredient;

typedef struct NoeudI{
    ingredient i;
    struct NoeudI *fg, *fd;		//fils gauche et fils droit
} noeud_ingredient;


noeud_ingredient* creer_noeud_ingredient(ingredient igredient1);

void ajouter_noeud_ingredient2(int id, char *nom, char *unite, noeud_ingredient **n);

void afficher_noeud_ingredient(noeud_ingredient n);

void afficher_arbre_ingredient(noeud_ingredient *n);

void afficher_arbre_ingredient2(noeud_ingredient *n,int niveau);

noeud_ingredient* creer_arbre_ingredient2(void);

ingredient rechercher_ingredient(noeud_ingredient *n, int id);

void liberer_arbre_ingredient(noeud_ingredient **n);

int compteur_ligne_fichier(FILE *fichier);

#endif // GESTION_INGREDIENT_H_INCLUDED