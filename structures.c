#include <string.h>

typedef struct
{
    int id;
    char *nomIngredient;
    char *unite;
}Ingredient;

typedef struct
{
    int numero;
    char *descriptif;
}Etape;

typedef struct
{
    char* nomRecette;
    int nbIngredient;
    int nbEtape;
    Ingredient *listeIngredient;
    Etape *listeEtape;
    double note;
    int nbPersonnesInit; //Nb de personnes initialement prévus
    int difficulte;
}Recette;


void ajouterIngredientFichier(FILE* fichier)
{
    //On remet le curseur au debut du fichier
    fseek(fichier,0,SEEK_SET);

    Ingredient i;
    i.id = 0;

    //Variables temporaires pour stocker les chaines de caracteres
    char tempNom[50];
    char tempUnite[15];
    char chaine[1000];

    //On lit tout le fichier et on compte le nombre de ligne
    //afin de connaitre le nombre d'ingredient pour connaitre
    //l'id du prochain ingredient
    while (fgetc(fichier) != EOF)
    {
        fgets(chaine, 1000, fichier);
        i.id++;
    }
    fprintf(fichier, "%d|", i.id);

    //On demande le nom puis le stock dans tempNom
    printf("Nom de l'ingredient : ");
    gets(tempNom);

    //On initialise i.nomIngredient et on affecte la valeur de tempNom
    //à la variable
    i.nomIngredient = (char*)malloc(strlen(tempNom)*sizeof(char));
    i.nomIngredient = tempNom;
    //On ecrit le nom de l'ingredient à la suite de l'id dans le fichier texte
    fprintf(fichier, "%s|", i.nomIngredient);

    //On effectue la meme chose pour i.unite avec la variable tempUnite
    printf("Precisez l'unite de l'ingredient : ");
    gets(tempUnite);

    i.unite = (char*)malloc(strlen(tempUnite)*sizeof(char));
    i.unite = tempUnite;
    fprintf(fichier, "%s\n", i.unite);

    free(i.nomIngredient);
    free(i.unite);
}

void lectureIngredientFichier(FILE* fichier)
{
    //On remet le curseur au debut du fichier
    fseek(fichier, 0, SEEK_SET);

    Ingredient i;

    //Variables temporaires pour stocker les chaines de caracteres
    char tempNom[50] = "";
    char tempUnite[15] = "";
    //Variable stockant les caracteres du fichier un par un
    char c[1];
    c[0] = fgetc(fichier);

    //Lecture du fichier ligne par ligne;
    while (c[0] != EOF)
    {
        i.id = c[0];

        //Remise à vide des variables temporaires
        strcpy(tempNom, "");
        strcpy(tempUnite, "");

        fseek(fichier,1,SEEK_CUR);
        c[0] = fgetc(fichier);

        while(c[0] != '-')
        {
            strcat(tempNom, c);
            c[0] = fgetc(fichier);
        }
        i.nomIngredient = (char*)malloc(strlen(tempNom)*sizeof(char));
        i.nomIngredient = tempNom;

        c[0] = fgetc(fichier);

        while(c[0] != '\n')
        {
            strcat(tempUnite, c);
            c[0] = fgetc(fichier);
        }
        i.unite = (char*)malloc(strlen(tempUnite)*sizeof(char));
        i.unite = tempUnite;

        c[0] = fgetc(fichier);
        printf("%c %s %s\n", i.id, i.nomIngredient, i.unite);
    }
    free(i.nomIngredient);
    free(i.unite);
}

