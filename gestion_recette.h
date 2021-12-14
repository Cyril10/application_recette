#ifndef GESTION_RECETTE_H_INCLUDED
#define GESTION_RECETTE_H_INCLUDED

typedef struct{
	char *nom;
	int nb_ingredient;
	ingredient ingre[];
	float qtt_ingre[];		//la qtt a la case 0 correspond a la qtt de l'ingredient dans la case 0 du tableau ingre
	int nb_etape;
	char *etape[];			//permet de contenir toutes les etapes de la recette
	int note;
	int nb_personne;		//permet de definir pour combien de personne est prevu la recette
	int difficulte;
}recette;

recette lire_recette(void);

void afficher_recette(recette r);

void lire_toutes_les_recettes(recette r[10]);

#endif // GESTION_RECETTE_H_INCLUDED
