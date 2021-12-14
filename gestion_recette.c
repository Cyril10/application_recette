#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_string.h"
#include "gestion_recette.h"

void creer_arbre_recette(void){
	
	File *f_recette = NULL;
	recette r;
	char c = 'a';
	char mot_temp[255];
	int compteur=0;