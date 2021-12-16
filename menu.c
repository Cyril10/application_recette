#include <stdio.h>
#include <stdlib.h>
#include "gestion_ingredient.h"
#include "gestion_recette.h"
#include "new_string.h"

void menu(noeud_ingredient* n_i, noeud_recette* n_r){
	char temp1='\0';
	char *temp2;
	int choix=-1;
	while (choix != 0){
		
		//afficher le menu
		printf("----------------------------------------------------------\n");
		printf("1 : Afficher toutes les recettes dans l'ordre alphabetique\n");
		printf("2 : Afficher une recette selon son nom\n");
		printf("3 : Rajouter une recette\n");
		printf("0 : Quitter le menu\n");
		printf("----------------------------------------------------------\n");
		printf("Quel est votre choix : ");
		
		scanf("%d", &choix);
		getchar();		//obliger de mettre ce getchar pour le entree du scanf
		
		//efface le menu quand on a fait son choix
		system("cls");
		
		switch(choix){
			case 1 :
				//on affiche les recettes dans l'ordre alphabetique tant que l'utilisateur ne tape pas m
				while(temp1 != 'm'){
					printf("Afficher toutes les recettes dans l'ordre alphabetique\n");
					afficher_arbre_recette(n_r);
					printf("\n");
					
					printf("saisir m pour revenir au menu\n");
					scanf("%c", &temp1);
					getchar();
					
					system("cls");	//on efface l'ecran et on reaffiche le menu si l'utilisateur n'a pas entrer m
				}
				temp1 = '\0';		//remet la var temp a "0"
				system("cls");
				break;
			
			case 2 :
				while(temp1 != 'm'){
					printf("Afficher une recette selon son nom\n");
					printf("Quelle recette voulez vous voir ?");
					temp2=lecture();
					
					afficher_recette(rechercher_recette(temp2, n_r));
					
					printf("saisir m pour revenir au menu\n");
					scanf("%c", &temp1);
					getchar();
					
					system("cls");
				}
				temp1 = '\0';
				system("cls");
				break;
				
			case 3 :
				//on affiche tous les ingredients car on a besoin de l'id de l'ingredient pour pouvoir le rajouter
				afficher_arbre_ingredient(n_i);
				
				rajouter_recette(n_i, &n_r);
				
				FILE *f_recette = NULL;
				f_recette = fopen("recette.txt", "r+");
				recopier_arbre_dans_fichier_recette(n_r, f_recette);
				fclose(f_recette);
				
				system("cls");
				
			case 0 :
				printf("Vous avez quitte le menu\n");
				break;
				
			default :
				printf("Erreur lors de la saisie, resaisir\n");
		}
	}
}