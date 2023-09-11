#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlv.h"

int creationfenetre(){
  int width =500;
  int height = 800;
  int demande ;
  
  MLV_create_window("Le jeu du 2048","2048",width,height);
  MLV_clear_window( MLV_COLOR_ANTIQUEWHITE1 );
  MLV_change_frame_rate(5);
  MLV_actualise_window();
  demande = menumlv();
  MLV_actualise_window();
  return demande;
}


void jeu(){
  int elapsed_time;
  
  elapsed_time =  MLV_get_time();
  MLV_draw_text(
		10, 400, 
		"Ca fait %d secondes que j'attends que vous quittiez ce programme.",
		  MLV_COLOR_GREEN, elapsed_time/1000
		);
}


int  menumlv(){
  int x,y;
  int target = 0;
  MLV_actualise_window();
  while(1){
    MLV_clear_window(MLV_COLOR_RED);
    MLV_draw_adapted_text_box(
			      180,100,
			      "Projet : 2048",
			      20,
			      MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,
			      MLV_TEXT_CENTER
			      );
    MLV_draw_adapted_text_box(
			      200,300,
			      "Jouer",
			      20,
			      MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,
			      MLV_TEXT_CENTER
			      );
    /*
    MLV_draw_adapted_text_box(
			      195,400,
			      "Options",
			      20,
			      MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,
			      MLV_TEXT_CENTER
			      );
    */
    MLV_draw_adapted_text_box(
			      170,500,
			      "Quitter le jeu...",
			      20,
			      MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,
			      MLV_TEXT_CENTER
			      );
    
    
    MLV_actualise_window();
    MLV_actualise_window();
    MLV_wait_mouse(&x,&y);
    
    MLV_actualise_window();
    if((x<280 && y<350 )&&(x>200 && y> 300)){
      target = jouer();
      if (target != 6){
	/* regarde le bouton retour*/
	break;
      }
      
    }
    /*
    if((x<285 && y< 450) && (x>200 && y> 400)){
      target = options();
      break;
    }
    */
    if((x<315 && y<550) && (x> 170 && y> 500)){
      MLV_free_window();
      exit  (0);
      break;
    }
  }
  if (target == 1) {
    /* Partie hand made */
    return 1;
    
  }
  if (target == 2) {
    /* IA 1 */
    return 2;
    
  }
  if (target == 3) {
    /* IA 2  */
    return 3;
    
  }
  if (target ==4) {
    /* IA 3 */
    return 4;
    
  }
  if (target == 5) {
    /* Sauvegarde */
    return 5;
    
  }
  
  
      return 5;      
}


int jouer(){
  int x,y;
  MLV_clear_window(MLV_COLOR_BROWN4);
  MLV_actualise_window();
  MLV_draw_adapted_text_box(
			    180,100,
			    "Projet : 2048",
			    20,
			    MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,
			    MLV_TEXT_CENTER
			    );
  MLV_draw_adapted_text_box(
			    160,300,
			    "Partie Hand-Made",
			    20,
			    MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,
			    MLV_TEXT_CENTER
			    );
  
  MLV_draw_adapted_text_box(
			    185,400,
			    "IA simple",
			    20,
			    MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,
			    MLV_TEXT_CENTER
			    );
  MLV_draw_adapted_text_box(
			    160,500,
			    "IA intermediaire ",
			    20,
			    MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,
			    MLV_TEXT_CENTER
			    );
  MLV_draw_adapted_text_box(
			    175,600,
			    "IA avancée ",
			    20,
			    MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,
			    MLV_TEXT_CENTER
			    );
  
  MLV_draw_adapted_text_box(
			    175,700,
			    "Sauvegarde",
			    20,
			    MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,
			    MLV_TEXT_CENTER
			    );
  MLV_draw_adapted_text_box(
			    400,740
			    ,"Retour",
			    20,
			    MLV_COLOR_STEEL_BLUE,MLV_COLOR_BLACK,MLV_COLOR_DARK_ORANGE,
			    MLV_TEXT_CENTER);
  MLV_actualise_window();
  while(1){
    MLV_wait_mouse(&x,&y);
  
    MLV_actualise_window();
    if((x<320 && y<350 )&&(x>160 && y> 300)){
      /* Partie hand made */
      return 1;
      break;
    }
    if((x<280 && y<450 )&&(x>180 && y> 400)){
      /* Partie Ia Simple */
      return 2;
      break;
    }
    if((x<315 && y<550 )&&(x>160 && y> 500)){
      /* Partie IA Intermediaire */
      return 3;
      break;
    }
    if((x<300 && y<650 )&&(x>180 && y> 600)){
      /* Partie Ia avancée */
      return 4;
      break;
    }
    if((x<275 && y<750 )&&(x>185 && y> 700)){
      /* Sauvegarde */
      return 5;
      
      break;
    }
    if(x> 400 && y > 750){
      return 6;
      break;
    }
    
    
  }
  MLV_actualise_window();
  

  
}


int  options(){
  MLV_clear_window(MLV_COLOR_MAGENTA);
  MLV_actualise_window();
  return 5;
}


char* mlv_demande_nom(char* nom){
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_text(
                75, 250,
                "Veuillez entrer votre nom dans la fenêtre ci-dessous.",
                MLV_COLOR_RED
		);

  MLV_wait_input_box(
		     150,300,
		     200,100,
		     MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
		     "Votre nom : ",
		     &nom
		     );
  MLV_actualise_window();
  return nom;

}

void mlv_affiche_tableau(int tab[][4]){


  MLV_clear_window(MLV_COLOR_BLACK);

 
  MLV_draw_text(50,75,"Appuyez sur les fleches ou zqsd pour la direction",MLV_COLOR_WHITE);
  MLV_draw_text(50,100,"Appuyez sur p pour sauvegarder ou f pour stop",MLV_COLOR_WHITE);
  MLV_draw_adapted_text_box(
			    150,200,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[0][0]
			    );
  MLV_draw_adapted_text_box(
			    200,200,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[0][1]
			    );
  
  MLV_draw_adapted_text_box(
			    250,200,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[0][2]
			    );
  
  MLV_draw_adapted_text_box(
			    300,200,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[0][3]
			    );






   MLV_draw_adapted_text_box(
			    150,250,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[1][0]
			    );
  MLV_draw_adapted_text_box(
			    200,250,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[1][1]
			    );
  
  MLV_draw_adapted_text_box(
			    250,250,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[1][2]
			    );
  
  MLV_draw_adapted_text_box(
			    300,250,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[1][3]
			    );



  MLV_draw_adapted_text_box(
			    150,300,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[2][0]
			    );
  MLV_draw_adapted_text_box(
			    200,300,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[2][1]
			    );
  
  MLV_draw_adapted_text_box(
			    250,300,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[2][2]
			    );
  
  MLV_draw_adapted_text_box(
			    300,300,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[2][3]
			    );




  MLV_draw_adapted_text_box(
			    150,350,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[3][0]
			    );
  MLV_draw_adapted_text_box(
			    200,350,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[3][1]
			    );
  
  MLV_draw_adapted_text_box(
			    250,350,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[3][2]
			    );
  
  MLV_draw_adapted_text_box(
			    300,350,
			    "%d",20,
			    
			    MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
			    MLV_TEXT_CENTER,tab[3][3]
			    );
  

  
  MLV_actualise_window();

}

void mlv_fin_de_game(){
  MLV_clear_window(MLV_COLOR_WHITE);
  MLV_draw_text(200,200,"Votre partie est terminée ..." , MLV_COLOR_BLACK);
  MLV_actualise_window();
  MLV_wait_seconds(5);
  MLV_free_window();
}


int mlv_choix_sauvegarde(){
  int y;
  int x;



  MLV_clear_window(MLV_COLOR_WHITE);
   MLV_draw_adapted_text_box(180,100,"Projet : 2048",20,MLV_COLOR_STEEL_BLUE, MLV_COLOR_BLACK, MLV_COLOR_DARK_ORANGE,MLV_TEXT_CENTER
			      );
   MLV_draw_adapted_text_box(200,200,"save 1",20,MLV_COLOR_STEEL_BLUE,MLV_COLOR_BLACK,MLV_COLOR_DARK_ORANGE,MLV_TEXT_CENTER);

   MLV_draw_adapted_text_box(200,300,"save 2",20,MLV_COLOR_STEEL_BLUE,MLV_COLOR_BLACK,MLV_COLOR_DARK_ORANGE,MLV_TEXT_CENTER);

   MLV_draw_adapted_text_box(200,400,"save 3",20,MLV_COLOR_STEEL_BLUE,MLV_COLOR_BLACK,MLV_COLOR_DARK_ORANGE,MLV_TEXT_CENTER);
  MLV_actualise_window();
  while( 1 ){
    MLV_wait_mouse(&x,&y);
  if((x>200 && y> 200) && (x<280 && y<250)){
    return 1;
  }
  if((x>200 && y> 300) && (x<280 && y<350)){
    return 2;
  }
  if((x>200 && y> 400) && (x<280 && y<450)){
    return 3;
  }
  }

}



char mlv_recup_event(){
 MLV_Keyboard_button bouton;
 bouton = MLV_KEYBOARD_NONE;
 

 while((bouton != MLV_KEYBOARD_z) &&
       (bouton != MLV_KEYBOARD_q) &&
       (bouton != MLV_KEYBOARD_s )&&
       (bouton != MLV_KEYBOARD_d) &&
       ( bouton != MLV_KEYBOARD_UP )&&
       ( bouton != MLV_KEYBOARD_LEFT) &&
       ( bouton != MLV_KEYBOARD_RIGHT) &&
       ( bouton != MLV_KEYBOARD_DOWN) &&
       ( bouton != MLV_KEYBOARD_f) &&
       ( bouton != MLV_KEYBOARD_p) ){ 
   MLV_wait_keyboard(&bouton,NULL,NULL);
  
  
 }
    if ( bouton == MLV_KEYBOARD_z || bouton == MLV_KEYBOARD_UP){
      printf("1\n");
      return 'z';
    }
    else if ( bouton == MLV_KEYBOARD_q || bouton == MLV_KEYBOARD_LEFT){
      printf("2\n");
      return 'q';
    }
    else if ( bouton == MLV_KEYBOARD_s || bouton == MLV_KEYBOARD_DOWN){
      printf("3\n");
      return 's';
    }
    else if ( bouton == MLV_KEYBOARD_d || bouton == MLV_KEYBOARD_RIGHT ){
      printf("4\n");
      return 'd';
    }
    else if(bouton == MLV_KEYBOARD_f){
      printf("5\n");
      return 'f';
    }
    else if(bouton == MLV_KEYBOARD_p){
      printf("6\n");
      return'p';
    }
    return'd';
 
 
  
}

int mlv_affichage_sauvegarde(){
  MLV_Font * police1 = MLV_load_font("./police/police1.ttf",40);
  int x,y;
  
    MLV_clear_window(MLV_COLOR_BLACK);

    MLV_draw_adapted_text_box_with_font(250,400,"1",police1,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
      MLV_draw_adapted_text_box_with_font(250,500,"2",police1,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
        MLV_draw_adapted_text_box_with_font(250,600,"3",police1,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
	MLV_actualise_window();
	while(1){
	  MLV_wait_mouse(&x,&y);
	  MLV_actualise_window();
	  if (( x>250 && y> 400 ) && ( x<300 && y<470)){
	    return 1;
	  }
	  if ((x> 250 && y> 500 ) && ( x<290 && y<570)){
	    return 2;
	  }
	  if((x>250 && y> 600) && ( x< 290 && y< 670)){
	    return 3;
	  }
	  
	}

}

void mlv_affiche_finjeu(int tempsdeux,int score){

  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_text(200,200,"Votre partie a durée %d secondes !",MLV_COLOR_WHITE,tempsdeux);
  MLV_draw_text(200,400,"Vous avez un score de %d ",MLV_COLOR_WHITE,score);
  MLV_actualise_window();
  MLV_wait_seconds(5);
}

void mlv_affichage_score(){
   MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_text(200,50,"Meilleurs scores",MLV_COLOR_WHITE);
 
  MLV_actualise_window();
  
}
    
