#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <MLV/MLV_all.h>

#include "type.h"


void printsauvegarde(){
  FILE *fic= fopen("save1.txt","r");
  FILE *fich= fopen("save2.txt","r");
  FILE *fichi = fopen("save3.txt","r");
  int premier[4][4];
  int deuxieme[4][4];
  int troisieme[4][4];
  
  if(fscanf(fic,"%d %d %d %d",&premier[0][0],&premier[1][0],&premier[2][0],&premier[3][0])!= 4 ) {}
  if(fscanf(fic,"%d %d %d %d",&premier[0][1],&premier[1][1],&premier[2][1],&premier[3][1])!= 4 )  {}
  if(fscanf(fic,"%d %d %d %d",&premier[0][2],&premier[1][2],&premier[2][2],&premier[3][2])!= 4 ) {}
  if(fscanf(fic,"%d %d %d %d",&premier[0][3],&premier[1][3],&premier[2][3],&premier[3][3])!= 4 ) {}
  
  if(fscanf(fich,"%d %d %d %d",&deuxieme[0][0],&deuxieme[1][0],&deuxieme[2][0],&deuxieme[3][0])!=4 ) {}
  if(fscanf(fich,"%d %d %d %d",&deuxieme[0][1],&deuxieme[1][1],&deuxieme[2][1],&deuxieme[3][1])!=4 ) {}
  if(fscanf(fich,"%d %d %d %d",&deuxieme[0][2],&deuxieme[1][2],&deuxieme[2][2],&deuxieme[3][2])!=4 ) {}
  if(fscanf(fich,"%d %d %d %d",&deuxieme[0][3],&deuxieme[1][3],&deuxieme[2][3],&deuxieme[3][3])!=4 ) {}
  
  if(fscanf(fichi,"%d %d %d %d",&troisieme[0][0],&troisieme[1][0],&troisieme[2][0],&troisieme[3][0])!=4 ) {}
  if(fscanf(fichi,"%d %d %d %d",&troisieme[0][1],&troisieme[1][1],&troisieme[2][1],&troisieme[3][1])!=4 ) {}
  if(fscanf(fichi,"%d %d %d %d",&troisieme[0][2],&troisieme[1][2],&troisieme[2][2],&troisieme[3][2])!=4 ) {}
  if(fscanf(fichi,"%d %d %d %d",&troisieme[0][3],&troisieme[1][3],&troisieme[2][3],&troisieme[3][3])!=4 ) {}
  
  
}
  
  void save(int tab[][4],int savve){
    FILE *fic = NULL;
    int i;
int j;
  int haut[4][4];
  if (savve == 1){
     fic = fopen("save1.txt","r");
  }
  else if (savve == 2){
    fic = fopen("save2.txt","r");
  }
  else if (savve == 3){
   fic = fopen("save3.txt","r");
  }
  if(fscanf(fic,"%d %d %d %d",&haut[0][0],&haut[1][0],&haut[2][0],&haut[3][0])!=4 ) {}
  if(fscanf(fic,"%d %d %d %d",&haut[0][1],&haut[1][1],&haut[2][1],&haut[3][1])!=4 ) {}
  if(fscanf(fic,"%d %d %d %d",&haut[0][2],&haut[1][2],&haut[2][2],&haut[3][2])!= 4 )  {}
  if(fscanf(fic,"%d %d %d %d",&haut[0][3],&haut[1][3],&haut[2][3],&haut[3][3])!= 4 ) {}
  
  for (i=0;i<4;i++){
    for(j=0;j<4 ;j++){
      tab[i][j] = haut[i][j];
    }}
  fclose(fic);
}

void putsave(int tab[][4],int savve){
  FILE *fic = NULL;
 
  if (savve == 1){
    fic = fopen("save1.txt","w");
  }
  else if (savve == 2){
    fic = fopen("save2.txt","w");
  }
  else if (savve == 3){
    fic = fopen("save3.txt","w");
  }
  fprintf(fic,"%d %d %d %d\n",tab[0][0],tab[1][0],tab[2][0],tab[3][0]);
  fprintf(fic,"%d %d %d %d\n",tab[0][1],tab[1][1],tab[2][1],tab[3][1]);
  fprintf(fic,"%d %d %d %d\n",tab[0][2],tab[1][2],tab[2][2],tab[3][2]);
  fprintf(fic,"%d %d %d %d\n",tab[0][3],tab[1][3],tab[2][3],tab[3][3]);
     
  fclose(fic);
 
}

int est2048(int tab[][4], int fin)
{
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (tab[i][j] == 2048)
            {
                fin = 1;
            }
        }
    }
    return (fin);
}


void s_sleep(int seconds)
{
    /* Init. */
    time_t start_time = 0;
    time_t current_time = 0;

    /* Operate. */
    start_time = time(NULL);
    while (current_time - start_time + 1 <= seconds)
    {
        current_time = time(NULL);
    }
}

int tiempo()
{
    time_t now;
    int min,s;
    int temps;
    time(&now);
    struct tm *local = localtime(&now);
    min = local->tm_min;       
    s = local->tm_sec;       
    temps = (min*60) + s ;
    return temps;
}


int scorebet(char joueur[50], int scorej)
{
      FILE *fic ;

    FILE *fich = fopen("scorebet.txt", "r");
    /* int place[10]; */
    char joueurattente[20];
    char joueurattentee[20];
    int scoreattente;
    int scoreattentee;
    /*   int points[10];*/
    int i = 0;
    int z=0;
    classement score[10];
    /*int scorej = 650;*/
    /* char  joueur[20] = "Benoit";*/
    if (fich == NULL)
    {
        exit(1);
    }

    for(i=0;i<10;i++){

        if(fscanf(fich,"%s %d %d", score[i].nom, &score[i].place, &score[i].score)!=3){
        
        }
    }
    for(i=0;i<10;i++){
        if (z==1){
            strcpy(joueurattentee,score[i].nom);
            scoreattentee=score[i].score;
            strcpy(score[i].nom,joueurattente);
            score[i].score = scoreattente;
            strcpy(joueurattente,joueurattentee);
            scoreattente = scoreattentee;
        }else 
            if(scorej>score[i].score){
                strcpy(joueurattente,score[i].nom);
                scoreattente=score[i].score;
                strcpy(score[i].nom,joueur); 
                score[i].score=scorej;
    
                z=1;
            }
    }
    fclose(fich);
    fic = fopen("scorebet.txt","w");

    printf("\n\n\n");
    for (i=0;i<10;i++){
        fprintf(fic,"%s %d %d\n",score[i].nom,score[i].place,score[i].score);
    }

    for (i=0;i<10;i++){
        printf("%d - %s avec %d de points de score\n",score[i].place,score[i].nom,score[i].score);
	MLV_draw_text(50,100+50*i,"%d - %s avec %d de points de score",MLV_COLOR_WHITE,score[i].place,score[i].nom,score[i].score);
    }
        MLV_actualise_window();

    MLV_wait_mouse(NULL,NULL);


    
    return (0);
}

