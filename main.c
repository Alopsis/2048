#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "type.h"
#include "joueur.h"
#include "initialisation.h"
#include "fusion.h"
#include "mlv.h"



void f_buffer(void)
{ 
    int c;
    while ((c = getchar()) != EOF && c != '\n')
        ;
}

    
int main()
{

    /* Documentation des fonctions :*/
    /* Random entre deux et quatre : var = random | fonction = deuxquatre(random)*/
    /* Remplir le tableau : var = tab | fonction = remplirletableau(tab) */
    int random;
    char dem = 'z';
    int tab[4][4];
    int demandeje = 0;
    int vide;
    int fin = 0;
    int temps;
    int tempsdeux;
    int fusionpos;
    int sauvegarde;
    int score = 0;
    int scoretmp;
    int rejoue = 1;
    int savve;
    int randomswap;
    char nom[50];
    int testdeplpos =0;
    int person=0;
    strcpy(nom,"test");

    /* creation de la fenetre MLV */
    demandeje = creationfenetre();
    /* Initialisation du jeu */
    /*initjeu();*/
    /* Remplissage du tableau avec des 0 :)*/
    remplirletableau(tab);
  
    /* demande du mode de jeu du 2048 */
   
    if(demandeje == 5){
      /*   printf("Quel sauvegarde voulez vous restaurer ? \n");
      printsauvegarde();
      scanf("%d",&savve);
      save(tab,savve);
      demandeje =1 ;
      */
    }
    temps = tiempo();
    if(demandeje == 1){
      strcpy(nom,mlv_demande_nom(nom));
    }
    if(demandeje == 5){
      strcpy(nom,mlv_demande_nom(nom));
      sauvegarde = mlv_choix_sauvegarde();
      save(tab,sauvegarde);
      demandeje=1;
    }
    
    /* printf("Votre nom est %s \n",nom);*/
    if (demandeje == 1)
      {
	

	person = 1;
	while (fin != rejoue)
	  {
	  
	    vide = 0;
	    random = 0;
	    
	    /* Tirage d'un nombre aléatoire entre 2 et 4 */
	    random = deuxquatre(random);
	    
	    /* mise en place du nombre de case vide dans la variable "vide" */
	    vide = checkvide(tab);
	    if (vide == 0)
	      {
		fusionpos = fusposfindejeu(tab);
		if (fusionpos == 0)
		  {
		    break;
		  }
	      }
            vide = randomonvide(vide);
	    
	    if (testdeplpos == 0)
	      placedanslevide(tab, vide, random);
	    printableau(tab);
	    mlv_affiche_tableau(tab);
	 
	    testdeplpos=0;
	   
	    dem = mlv_recup_event();
	    printf("Vous avez appuyé sur %c\n",dem);
	
	    if( dem == 'p'){
	      savve = mlv_affichage_sauvegarde();

	      putsave(tab,savve);
	    }
            if(dem == 'f'){
	      break;
            }
	    
	    
            /*teste si le deplacement demandé est possible*/
            while (deplacementpossible(dem, tab)==0)
	      {
		testdeplpos=1;
                printf("deplacement impossible");
		  dem = mlv_recup_event();
		  if (deplacementpossible('z',tab) == 0 &&
		      deplacementpossible('q',tab) == 0 && 
		      deplacementpossible('s',tab) == 0&&
		      deplacementpossible('d',tab) == 0 ){
		    break;
		    
		  }
	      }
	    
	   
            
	      
                /* Slide du tableau vers le "dem" demandé */
                slide(dem, tab);
		
                /* Fusion des cases possibles avec le "dem" demandé */
                scoretmp = fusion(dem, tab);
                score = scoretmp + score;
		
                /* Slidage du tableau pour faire le slide apres fusion */
                slide(dem, tab);
		
                /* Regarde si une case est égal a 2048*/
                fin = est2048(tab, fin);
	      
            if (fin == 1)
	      {
		break;
	      }
	  }
      }
    if (demandeje == 2)
      {
	
	while (fin != rejoue)
	  {
	    randomswap = rand() % (4 -1) + 1;
	    if (randomswap == 1)
	      {
		dem = 'z';
	      }
	    if (randomswap == 2)
	      {
		dem = 'q';
	      }
	    if (randomswap == 3)
	      {
		dem = 's';
	      }
	    if (randomswap == 4 || randomswap == 5)
	      {
		dem = 'd';
	      }
	    randomswap++;
	    printf("test\n");
	    
	    
	    /* affectation des variables */
	    vide = 0;
	    random = 0;
	    s_sleep(1);
	    /* Tirage d'un nombre aléatoire entre 2 et 4 */
	    random = deuxquatre(random);
	    
	    /* mise en place du nombre de case vide dans la variable "vide" */
	    vide = checkvide(tab);
	    if (vide == 0)
	      {
		fusionpos = deplacementpossible(dem,tab);
		if (fusionpos==0){
		  break;
		}
		
	      }
	    /* Mise en place du nombre aléatoire ( 2 ou 4 ) dans la case "vide" */
	    
	    vide = randomonvide(vide);
	    
	    /* Place le nombre dans le tableau */
	    if ( testdeplpos == 0)
	      placedanslevide(tab, vide, random);
	    
	    /* Ecrit le tableau */
	    printableau(tab);
	    
	    mlv_affiche_tableau(tab);
	    
	    if(deplacementpossible(dem,tab) == 0){
	      
	      
	      if (deplacementpossible('z',tab) == 0 &&
		  deplacementpossible('q',tab) == 0 && 
		  deplacementpossible('s',tab) == 0&&
		  deplacementpossible('d',tab) == 0 ){
		break;
		
	      }
	    }
	    
	    printf("le car %c \n",dem);
	    
            /* Slide du tableau vers le "dem" demandé */
            slide(dem, tab);
	    
            /* Fusion des cases possibles avec le "dem" demandé */
            scoretmp = fusion(dem, tab);
	    
	    
            score = score + scoretmp;

            /* Slidage du tableau pour faire le slide apres fusion */
            slide(dem, tab);

            /* Regarde si une case est égal a 2048*/
            fin = est2048(tab, fin);
            if (fin == 1)
            {
               break;
            }
      }
    }

    if (demandeje == 3)
    {
        randomswap = 0;
        while (fin != rejoue)
        {
            /* affectation des variables */
            vide = 0;
            random = 0;
            if (randomswap == 0)
            {
                dem = 'z';
                randomswap++;
            }
            else if (randomswap == 1)
            {
                dem = 'q';
                randomswap++;
            }
            else if (randomswap == 2)
            {
                dem = 's';
                randomswap++;
            }
            else if (randomswap == 3)
            {
                dem = 'd';
                randomswap = 0;
            }
            s_sleep(1);
            /* Tirage d'un nombre aléatoire entre 2 et 4 */
            random = deuxquatre(random);

            /* mise en place du nombre de case vide dans la variable "vide" */
            vide = checkvide(tab);
            if (vide == 0)
            {
	      fusionpos = fusposfindejeu(tab);
                if (fusionpos==0){
                    break;
                }
                
            }
            /* Mise en place du nombre aléatoire ( 2 ou 4 ) dans la case "vide" */
            vide = randomonvide(vide);

            /* Place le nombre dans le tableau */
	    if ( testdeplpos == 0)
            placedanslevide(tab, vide, random);

	    mlv_affiche_tableau(tab);
	      while(deplacementpossible(dem,tab) == 0){
	      
	      randomswap = rand() % (4) + 1;
	      if (randomswap == 1)
		{
		  dem = 'z';
		}
	      if (randomswap == 2)
		{
		  dem = 'q';
		}
	      if (randomswap == 3)
		{
		  dem = 's';
		}
	      if (randomswap == 4)
		{
		  dem = 'd';
		}
	      if (deplacementpossible('z',tab) == 0 &&
		  deplacementpossible('q',tab) == 0 && 
		  deplacementpossible('s',tab) == 0&&
		  deplacementpossible('d',tab) == 0 ){
		break;
		
	      }
	    }
	      
	    testdeplpos=0;
            /* Slide du tableau vers le "dem" demandé */
            slide(dem, tab);

            /* Fusion des cases possibles avec le "dem" demandé */

            scoretmp = fusion(dem, tab);
            score = score + scoretmp;

            /* Slidage du tableau pour faire le slide apres fusion */
            slide(dem, tab);

            /* Regarde si une case est égal a 2048*/
            fin = est2048(tab, fin);
            if (fin == 1)
            {
	      break;
            }
        }
    }

    if (demandeje == 4)
    {

        while (fin != rejoue)
        {
            /* affectation des variables */
            vide = 0;
            random = 0;
            s_sleep(1);
	    dem = 'z';
            randomswap = rand() % (4 - 1) + 1;
            if (randomswap == 1)
            {
                dem = 'z';
            }
            if (randomswap == 2)
            {
                dem = 'q';
            }
            if (randomswap == 3)
            {
                dem = 's';
            }
            if (randomswap == 4)
            {
                dem = 'd';
            }
            /* Tirage d'un nombre aléatoire entre 2 et 4 */
            random = deuxquatre(random);

            /* mise en place du nombre de case vide dans la variable "vide" */
            vide = checkvide(tab);
              if (vide == 0)
            {
	      fusionpos = fusposfindejeu(tab);
                if (fusionpos==0){
                    break;
                }
                
            }

            /* Mise en place du nombre aléatoire ( 2 ou 4 ) dans la case "vide" */
            vide = randomonvide(vide);

            /* Place le nombre dans le tableau */
	    if(testdeplpos == 0)
            placedanslevide(tab, vide, random);

	    mlv_affiche_tableau(tab);
	      while(deplacementpossible(dem,tab) == 0){
	      
	      randomswap = rand() % (4) + 1;
	      if (randomswap == 1)
		{
		  dem = 'g';
		}
	      if (randomswap == 2)
		{
		  dem = 'd';
		}
	      if (randomswap == 3)
		{
		  dem = 'h';
		}
	      if (randomswap == 4)
		{
		  dem = 'b';
		}
	      if (deplacementpossible('z',tab) == 0 &&
		  deplacementpossible('q',tab) == 0 && 
		  deplacementpossible('s',tab) == 0&&
		  deplacementpossible('d',tab) == 0 ){
		break;
		
	      }
	    }
           


            /* Slide du tableau vers le "dem" demandé */
            slide(dem, tab);

            /* Fusion des cases possibles avec le "dem" demandé */
          
            scoretmp = fusion(dem, tab);
            score = score + scoretmp;

            /* Slidage du tableau pour faire le slide apres fusion */
            slide(dem, tab);

            /* Regarde si une case est égal a 2048*/
            fin = est2048(tab, fin);
            if (fin == 1)
            {
	      break;
            }
        }
    }
    tempsdeux = tiempo();
    tempsdeux= tempsdeux - temps;
    mlv_affiche_finjeu(tempsdeux,score);
    /*printf("\nVotre partie a durée %d secondes \n",tempsdeux);
      printf("Vous avez fini le 2048 ! \nVous avez un score de %d \n", score);*/
    if (person == 1){
            mlv_affichage_score();

          scorebet(nom,score);

    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Voici les meilleurs scores ! \n");
    
    }

    exit(EXIT_SUCCESS);
}
