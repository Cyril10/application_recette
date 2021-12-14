#ifndef GESTION_RECETTE_H_INCLUDED
#define GESTION_RECETTE_H_INCLUDED

typedef struct{
	int nb_ingredients;
	char *nom;
}recette;

void ajouter_recette(void);

recette lire_recette(void);

void afficher_recette(recette r);

void lire_toutes_les_recettes(recette r[10]);

#endif // GESTION_RECETTE_H_INCLUDED
