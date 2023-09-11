#include <stdlib.h>
#include <stdio.h>
#include "type.h"


int fusion(char dem, int tab[][4])
{

    /*int score ; */
    int i;
    int score = 0;

    /* Demande du slidage au joueur */
    /* Ici on demande mais lors du main il sera donner en parametre ! */

    /* Fin de la demande au joueur */

    if (dem == 'd')
    {
        for (i = 0; i < 4; i++)
        {
            if (((tab[i][2] == tab[i][3]) && (tab[i][3] != 0)) || (tab[i][1] == tab[i][2] && (tab[i][2] != 0)) || ((tab[i][0] == tab[i][1]) && (tab[i][1] != 0)))
            {
	      if (tab[i][2] == tab[i][3])
                {
                  
                    tab[i][3] = tab[i][2] + tab[i][3];
                    score = score + tab[i][3];
                    tab[i][2] = 0;
                }

	      else if (tab[i][1] == tab[i][2])
                {
                 
                    tab[i][2] = tab[i][1] + tab[i][2];
                    score = score + tab[i][2];
                    tab[i][1] = 0;
                }

                if (tab[i][0] == tab[i][1])
                {
                   
                    tab[i][1] = tab[i][0] + tab[i][1];
                    score = score + tab[i][1];
                    tab[i][0] = 0;
                }


	     
	      /*if ( (tab[i][0] == tab[i][1]) && (tab[i][2] != tab[i][1])){
        
		tab[i][1] = tab[i][1] + tab[i][0];
		tab[i][0] = 0;
		score = score + tab[i][1];
		

	      }
	      if((tab[i][2] == tab[i][3] && tab[i][2] != tab[i][1])){
	tab[i][3] = tab[i][2] + tab[i][3];
		tab[i][2] = 0;
		score = tab[i][3] + score;
	      }
	      if ((tab[i][2] == tab[i][1] )&&( tab[i][2] != tab[i][3])) {
		tab[i][2] = tab[i][2] + tab[i][1] ;
		tab[i][1] = 0;
		score = tab[i][2] + score;
		}*/
            }
        }
    }
    else if (dem == 'q')
    {
        for (i = 0; i < 4; i++)
        {
            if (((tab[i][1] == tab[i][0]) && (tab[i][0] != 0)) || (tab[i][2] == tab[i][1] && (tab[i][1] != 0)) || ((tab[i][3] == tab[i][2]) && (tab[i][2] != 0)))
            {
	      if ((tab[i][1] == tab[i][0]))
                {
                  
                    tab[i][0] = tab[i][1] + tab[i][0];
                    score = score + tab[i][0];
                    tab[i][1] = 0;
                }

	      else if (tab[i][2] == tab[i][1])
                {
                   
                    tab[i][1] = tab[i][2] + tab[i][1];
                    score = score + tab[i][1];
                    tab[i][2] = 0;
                }

	      if (tab[i][3] == tab[i][2])
                {
                  
                    tab[i][2] = tab[i][3] + tab[i][2];
                    score = score + tab[i][2];
                    tab[i][3] = 0;
                }
		


	      
	      /*if ( (tab[i][3] == tab[i][2])  && (tab[i][2] != tab[i][1])){
		
		tab[i][2] = tab[i][2] + tab[i][3];
		tab[i][3] = 0;
		score = tab[i][2] +score;
		
		

	      }
	      if ((tab[i][1] == tab[i][0]) &&( tab[i][2] != tab[i][1])){
		tab[i][0] = tab[i][1] + tab[i][0];
		tab[i][1] = 0;
		score = tab[i][0] + score;
	      }
	      if ((tab[i][1] == tab[i][2] )&&( tab[i][1] != tab[i][0])) {
		tab[i][1] = tab[i][1] + tab[i][2] ;
		tab[i][2] = 0;
		score = tab[i][1] + score;
		}*/
	    }
        }
    }
    else if (dem == 's')
    {
        for (i = 0; i < 4; i++)
        {
            if (((tab[2][i] == tab[3][i]) && (tab[3][i] != 0)) || (tab[1][i] == tab[2][i] && (tab[2][i] != 0)) || ((tab[0][i] == tab[1][i]) && (tab[1][i] != 0)))
            {
	       if (tab[2][i] == tab[3][i])
                {
                   
                    tab[3][i] = tab[2][i] + tab[3][i];
                    score = score + tab[3][i];
                    tab[2][i] = 0;
                }

	       else if (tab[1][i] == tab[2][i])
                {
                   
                    tab[2][i] = tab[1][i] + tab[2][i];
                    score = score + tab[2][i];
                    tab[1][i] = 0;
                }

		  if (tab[0][i] == tab[1][i])
                {

             
                    tab[1][i] = tab[0][i] + tab[1][i];
                    score = score + tab[1][i];
                    tab[0][i] = 0;
                }
	      /*if ( (tab[0][i] == tab[1][i]) && (tab[2][i] != tab[1][i])){
	
		tab[1][i] = tab[1][i] + tab[0][i];
		tab[0][i] = 0;
		score = tab[1][i] + score ;

	      }
	      if ((tab[2][i] == tab[3][i]) &&( tab[2][i] != tab[1][i])){
		  	tab[3][i] = tab[2][i] + tab[3][i];
		tab[2][i] = 0;
		score = tab[3][i]+score;
		}
	      if ((tab[i][2] == tab[i][1] )&&( tab[i][2] != tab[i][3])) {
		tab[i][2] = tab[i][2] + tab[i][1] ;
		tab[i][1] = 0;
		score = score + tab[i][2];
	      }*/
        
            }
        }
    }
    else if (dem == 'z')
    {
        for (i = 0; i < 4; i++)
        {
            if (((tab[1][i] == tab[0][i]) && (tab[0][i] != 0)) || (tab[2][i] == tab[1][i] && (tab[1][i] != 0)) || ((tab[3][i] == tab[2][i]) && (tab[2][i] != 0)))
            {
	      if ((tab[1][i] == tab[0][i]))
                {
                   
                    tab[0][i] = tab[1][i] + tab[0][i];
                    score = score + tab[1][i];
                    tab[1][i] = 0;
                }

	      else if (tab[2][i] == tab[1][i])
                {
                
                    tab[1][i] = tab[2][i] + tab[1][i];
                    score = score + tab[2][i];
                    tab[2][i] = 0;
                }

                if (tab[3][i] == tab[2][i])
                {
                 
                    tab[2][i] = tab[3][i] + tab[2][i];
                    score = score + tab[3][i];
                    tab[3][i] = 0;
                }


	      
	      /* if ( (tab[3][i] == tab[2][i])  && (tab[2][i] != tab[1][i])){
	
		tab[2][i] = tab[2][i] + tab[3][i];
		tab[3][i] = 0;
		score = tab[2][i] + score;
	      }
	      
	      if ((tab[1][i] == tab[0][i]) &&( tab[2][i] != tab[1][i])){
		tab[0][i] = tab[1][i] + tab[0][i];
		tab[1][i] = 0;
		score = tab[0][i] + score ;
	      }
		  
	      if ((tab[1][i] == tab[2][i] )&&( tab[1][i] != tab[0][i])) {
		tab[1][i] = tab[1][i] + tab[2][i] ;
		tab[2][i] = 0;
		score = tab[1][i] + score;
		}*/
            }
        }
    }
    return (score);
}










void slide(char dem, int tab[][4])
{
    int i;
    /* Vidage du buffer */
    /* Prise en compte du slide vers la |DROITE|*/
    if (dem == 'd')
    {
        for (i = 0; i < 4; i++)
        {
            while (((tab[i][2] != 0) && (tab[i][3] == 0)) || ((tab[i][1] != 0) && (tab[i][2] == 0)) || ((tab[i][0] != 0) && (tab[i][1] == 0)))
            {
                if ((tab[i][2] != 0) && (tab[i][3] == 0))
                {
                    tab[i][3] = tab[i][2];
                    tab[i][2] = 0;
                }

                if ((tab[i][1] != 0) && (tab[i][2] == 0))
                {
                    tab[i][2] = tab[i][1];
                    tab[i][1] = 0;
                }

                if ((tab[i][0] != 0) && (tab[i][1] == 0))
                {
                    tab[i][1] = tab[i][0];
                    tab[i][0] = 0;
                }
            }
        }
    }

    /* Prise en compte du slide vers la |GAUCHE|*/

    if (dem == 'q')
    {
        for (i = 0; i < 4; i++)
        {
            while (((tab[i][1] != 0) && (tab[i][0] == 0)) || ((tab[i][2] != 0) && (tab[i][1] == 0)) || ((tab[i][3] != 0) && (tab[i][2] == 0)))
            {
                if ((tab[i][1] != 0) && (tab[i][0] == 0))
                {
                    tab[i][0] = tab[i][1];
                    tab[i][1] = 0;
                }

                if ((tab[i][2] != 0) && (tab[i][1] == 0))
                {
                    tab[i][1] = tab[i][2];
                    tab[i][2] = 0;
                }

                if ((tab[i][3] != 0) && (tab[i][2] == 0))
                {
                    tab[i][2] = tab[i][3];
                    tab[i][3] = 0;
                }
            }
        }
    }

    /* Prise en compte du slide vers la |HAUT|*/

    if (dem == 'z')
    {
        for (i = 0; i < 4; i++)
        {
            while (((tab[1][i] != 0) && (tab[0][i] == 0)) || ((tab[2][i] != 0) && (tab[1][i] == 0)) || ((tab[3][i] != 0) && (tab[2][i] == 0)))
            {
                if ((tab[1][i] != 0) && (tab[0][i] == 0))
                {
                    tab[0][i] = tab[1][i];
                    tab[1][i] = 0;
                }

                if ((tab[2][i] != 0) && (tab[1][i] == 0))
                {
                    tab[1][i] = tab[2][i];
                    tab[2][i] = 0;
                }

                if ((tab[3][i] != 0) && (tab[2][i] == 0))
                {
                    tab[2][i] = tab[3][i];
                    tab[3][i] = 0;
                }
            }
        }
    }

    /* Prise en compte du slide vers la |BAS|*/

    if (dem == 's')
    {
        for (i = 0; i < 4; i++)
        {
            while (((tab[2][i] != 0) && (tab[3][i] == 0)) || ((tab[1][i] != 0) && (tab[2][i] == 0)) || ((tab[0][i] != 0) && (tab[1][i] == 0)))
            {
                if ((tab[2][i] != 0) && (tab[3][i] == 0))
                {
                    tab[3][i] = tab[2][i];
                    tab[2][i] = 0;
                }

                if ((tab[1][i] != 0) && (tab[2][i] == 0))
                {
                    tab[2][i] = tab[1][i];
                    tab[1][i] = 0;
                }

                if ((tab[0][i] != 0) && (tab[1][i] == 0))
                {
                    tab[1][i] = tab[0][i];
                    tab[0][i] = 0;
                }
            }
        }
    }
}






int fusposfindejeu(int tab[][4]){
  int i;     
  for (i = 0; i < 4; i++)
    {
      if (((tab[i][2] == tab[i][3]) && (tab[i][3] != 0)) || (tab[i][1] == tab[i][2] && (tab[i][2] != 0)) || ((tab[i][0] == tab[i][1]) && (tab[i][1] != 0)))
        {
	  if (tab[i][2] == tab[i][3])
            {
	      return(1);
            }

	  if (tab[i][1] == tab[i][2])
            {
	      return(1);                }

	  if (tab[i][0] == tab[i][1])
            {
	      return(1);
            }
        }
    }
  
  for (i = 0; i < 4; i++)
    {
      if (((tab[i][1] == tab[i][0]) && (tab[i][0] != 0)) || (tab[i][2] == tab[i][1] && (tab[i][1] != 0)) || ((tab[i][3] == tab[i][2]) && (tab[i][2] != 0)))
        {
	  if ((tab[i][1] == tab[i][0]))
            {
	      return(1);
            }
	  
	  if (tab[i][2] == tab[i][1])
            {
	      return(1);
            }
	  
	  if (tab[i][3] == tab[i][2])
            {
	      return(1);
            }
        }
    }
  
  for (i = 0; i < 4; i++)
    {
      if (((tab[2][i] == tab[3][i]) && (tab[3][i] != 0)) || (tab[1][i] == tab[2][i] && (tab[2][i] != 0)) || ((tab[0][i] == tab[1][i]) && (tab[1][i] != 0)))
        {
	  if ((tab[2][i] == tab[3][i]))
            {
	      return(1);
            }

	  if (tab[1][i] == tab[2][i])
            {
	      return(1);
            }

	  if (tab[0][i] == tab[1][i])
            {
	      return(1);
            }
        }
    }
  
  for (i = 0; i < 4; i++)
    {
      if (((tab[1][i] == tab[0][i]) && (tab[0][i] != 0)) || (tab[2][i] == tab[1][i] && (tab[1][i] != 0)) || ((tab[3][i] == tab[2][i]) && (tab[2][i] != 0)))
        {
	  if ((tab[1][i] == tab[0][i]))
            {
	      return(1);
            }

	  if (tab[2][i] == tab[1][i])
            {
	      return(1);
            }

	  if (tab[3][i] == tab[2][i])
            {
	      return(1);
            }
        }
    }
  printf("Perdu\n");  
  return(0);
}









int deplacementpossible(char dem,int tab[][4])
{
  int i;

    
    if (dem == 'd')
    {        
        for (i = 0; i < 4; i++)
        {
	  if ( (tab[i][3]==0 && (tab[i][2]!=0 || tab[i][1]!=0 || tab[i][0]!=0)) || (tab[i][2]==0 && (tab[i][1]!=0 || tab[i][0]!=0)) || (tab[i][1]==0 && tab[i][0]!=0) || (tab[i][1]==tab[i][0] && tab[i][1]!=0) || (tab[i][1]==tab[i][2] && tab[i][2]!=0) || (tab[i][3]==tab[i][2] && tab[i][3]!=0) )
	    return 1;
	}
    }

	
    else if (dem == 'q')
    {
        for (i = 0; i < 4; i++)
        {
	  if ( (tab[i][0]==0 && (tab[i][1]!=0 || tab[i][2]!=0 || tab[i][3]!=0)) || (tab[i][1]==0 && (tab[i][2]!=0 || tab[i][3]!=0)) || (tab[i][2]==0 && tab[i][3]!=0) || (tab[i][2]==tab[i][3] && tab[i][2]!=0) || (tab[i][1]==tab[i][2] && tab[i][1]!=0) || (tab[i][0]==tab[i][1] && tab[i][0]!=0) )
	    return 1;
	}
    }

    
    else if (dem == 's')
    {
        for (i = 0; i < 4; i++)
        {
	  if ( (tab[3][i]==0 && (tab[2][i]!=0 || tab[1][i]!=0 || tab[0][i]!=0)) || (tab[2][i]==0 && (tab[1][i]!=0 || tab[0][i]!=0)) || (tab[1][i]==0 && tab[0][i]!=0) || (tab[1][i]==tab[0][i] && tab[1][i]!=0) || (tab[1][i]==tab[2][i] && tab[2][i]!=0) || (tab[3][i]==tab[2][i] && tab[3][i]!=0) )
	    return 1;
	}

	
    }
    else if (dem == 'z')
    {
        for (i = 0; i < 4; i++)
        {
	  if ( (tab[0][i]==0 && (tab[1][i]!=0 || tab[2][i]!=0 || tab[3][i]!=0)) || (tab[1][i]==0 && (tab[2][i]!=0 || tab[3][i]!=0)) || (tab[2][i]==0 && tab[3][i]!=0) || (tab[2][i]==tab[3][i] && tab[2][i]!=0) || (tab[1][i]==tab[2][i] && tab[1][i]!=0) || (tab[0][i]==tab[1][i] && tab[0][i]!=0) )
	    return 1;
	}
    }
    return 0;
}
