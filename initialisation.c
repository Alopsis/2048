#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "type.h"


int deuxquatre(int i)
{
    srand(time(NULL));
    i = rand() % (10 - 0) + 0;
    if (i < 9)
        i = 2;
    if (i == 9)
        i = 4;
    return (i);
}

    
void remplirletableau(int tab[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = 0;
        }
    }
}



void printableau(int tab[][4])
{
    int i, j;
    printf("\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf(" %d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



int checkvide(int tab[][4])
{
  int vide=0 , i ,j;
  for (i = 0; i < 4; i++)
    {
      for (j = 0; j < 4; j++)
        {
	  if (tab[i][j] == 0)
            {
	      vide++;
            }
        }
    }
  return (vide);
}



int randomonvide(int vide)
{
    int placenombre;
    placenombre = rand() % (vide - 0) + 0;
    return (placenombre);
}



void placedanslevide(int tab[][4], int vide, int deuxquatre)
{
    int i, j;
    int tmp = -1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (tab[i][j] == 0)
            {
                tmp++;
            }
            if (tmp == vide)
            {
                tab[i][j] = deuxquatre;
                break;
            }
        }
        if (tmp == vide)
        {
            break;
        }
    }
}



