#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fichier = fopen("data.txt", "w");
    char string[6];
    int i;

    printf("\n\n rempliez le fichier avec 10 mots d une taille inf strictement a  6\n");
    for (i = 0; i < 10; i++)
    {
        printf("mot %d: ", i + 1);
        scanf("%s", &string);
        fprintf(fichier, "%s\n", string);
    }

    fclose(fichier);

    printf("\n\n\n\n");
    return 0;
}