#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utils.h"

void majiscul(char string[6])
{
    int i = 0;
    while (string[i] != '\0' && i < 6)
    {
        string[i] = toupper(string[i]);
        i++;
    }
}

void majusculeAleatoire(char string[6])
{
    for (int i = 0; i < 6; i++)
    {
        string[i] = 'A' + rand() % 26;
    }
}

void Aleatoire(char string[6], int verte[6])
{

    for (int i = 0; i < 6; i++)
    {
        if (!indix(verte, i))
        {
            string[i] = 'A' + rand() % 26;
        }
    }
}

bool indix(int tableau[6], int ind)
{
    for (int i = 0; i < 6; i++)
    {
        if (tableau[i] == ind)
        {
            return true;
        }
    }
    return false;
}