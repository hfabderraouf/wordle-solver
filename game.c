#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utils.h"

int main()
{
    int orange[6];
    int o;
    int verte[6];
    int v;
    char string2[6];
    char string1[6];
    char string3[6];
    char string4[6];
    bool trouver = false;
    int i, j, repetition, n, choix;
    FILE *fichier;

    printf("\t\t\t----- word-guessing game -----\n");
    printf("\t\tPrincipes de ce jeu : \n");
    printf("\t1: Vous pouvez repeter jusqu a 6 fois \n");
    printf("\t2: Vous pouvez passer la main au bot\n");
    /* 
        printf("\t3:\n");
        printf("\t4:\n");
    */
    
    while (1)
    {
        printf("\n\t\tMENU\n");
        printf("\tEntrez 1 pour jouer\n");
        printf("\tEntrez 2 pour afficher le mot\n");
        printf("\tEntrez 3 pour donner la main au bot pour jouer\n");
        printf("\tEntrez 4 pour quitter le jeu\n");
        scanf("%d", &choix);

        // Ouverture de fichier
        fichier = fopen("./words/data.txt", "r");
        if (fichier == NULL)
        {
            perror("fopen");
            printf("Erreur d'ouverture du fichier \n");
            return 1;
        }

        srand(time(NULL));
        n = (rand() % 10) + 1;
        while (fscanf(fichier, "%s", string1) != EOF && n != 0)
        {
            n--;
        }
        majiscul(string1);
        fclose(fichier);

        switch (choix)
        {
        case 1:

            repetition = 1;
            while (repetition < 7)
            {
                v = 0;
                o = 0; // réinitialiser les indices
                printf("donnez la chaine: ");
                scanf("%5s", string2); // protéger contre overflow
                majiscul(string2);

                // vérifier si le mot est trouvé
                if (strcmp(string1, string2) == 0)
                {
                    printf("Bravo ! Mot trouvé : \033[32m%s\033[0m\n", string2);
                    trouver = true;
                    break; // sortir de la boucle repetition
                }

                // position des lettres
                for (i = 0; string2[i] != '\0' && i < 6; i++)
                {
                    for (j = 0; string1[j] != '\0' && j < 6; j++)
                    {
                        if (string2[i] == string1[j] && i == j)
                        {
                            verte[v++] = i;
                        }
                        else if (string2[i] == string1[j])
                        {
                            orange[o++] = i;
                        }
                    }
                }

                // affichage
                for (i = 0; string2[i] != '\0' && i < 6; i++)
                {
                    if (indix(verte, i))
                    {
                        printf("\033[32m%c\033[0m", string2[i]);
                    }
                    else if (indix(orange, i))
                    {
                        printf("\033[33m%c\033[0m", string2[i]);
                    }
                    else
                    {
                        printf("\033[31m%c\033[0m", string2[i]);
                    }
                }
                printf("\n");
                repetition++;
            }
            if (!trouver)
            {
        
                printf("Desole! Vous avez utilise toutes vos tentatives.\n");
                printf("Le mot etait: \033[34m%s\033[0m\n", string1);
                printf("Bonne chance pour la prochaine fois!\n");
            }   
            break;

        case 2:

            printf("\tle mot est: %s\n", string1);
            break;

        case 3:

            printf("\tEntrez le mot a rechercher: ");
            scanf("%5s", string3);
            majiscul(string3);

            majusculeAleatoire(string4); // mot aléatoire pour le bot

            repetition = 1;
            while (repetition < 7)
            {
                v = 0;
                o = 0;

                

                // position des lettres
                for (i = 0; string4[i] != '\0' && i < 6; i++)
                {
                    for (j = 0; string3[j] != '\0' && j < 6; j++)
                    {
                        if (string4[i] == string3[j] && i == j)
                        {
                            verte[v] = i;
                            v++;
                        }
                        else if (string4[i] == string3[j])
                        {
                            orange[o] = i;
                            o++;
                        }
                    }
                }

                // affichage
                if (strcmp(string3, string4) == 0)
                {
                    printf("le bot a trouve le mot!\n");
                    printf("le mot est : \033[32m%s\033[0m\n", string4);
                    break;
                }

                for (i = 0; string4[i] != '\0' && i < 6; i++)
                {
                    if (indix(verte, i))
                    {
                        printf("\033[32m%c\033[0m", string4[i]);
                    }
                    else if (indix(orange, i))
                    {
                        printf("\033[33m%c\033[0m", string4[i]);
                    }
                    else
                    {
                        printf("\033[31m%c\033[0m", string4[i]);
                    }
                }
                printf("\n");
                repetition++;

                Aleatoire(string4, verte);
            }
            break;

        case 4:

            exit(0);
            /*exit(0); sert � terminer imm�diatement le programme.
            Le param�tre 0 indique que le programme s�est termin� sans erreur.
            Si tu voulais signaler une erreur, tu pourrais mettre un autre code,
            par exemple exit(1);*/
            break;
        }
    }
    printf("\n\n\n\n");
    return 0;
}
