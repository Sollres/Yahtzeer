#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//fonctin qui permet de voir quel joueur joue en premier
int start()
{

	int nbr_joueur;
	printf("Combien de joueur ?");		// choix du joueur
	scanf("%i", &nbr_joueur);
	return nbr_joueur;

}

// fonction qui enregistre les combianison posssible
typedef struct s_combinaison
{
	int t_un; 			// variables pour toutes les combinaison possibles
	int t_deux; 
	int t_trois; 
	int t_quatre; 
	int t_cinq ; 
	int t_six ; 

	int brelan ; 
	int carre ; 
	int full ; 
	int petite_s ; 
	int gde_s ;
	int yams ; 
	int chance ; ;

}combinaison;

//fonction qui intialise la structure combinaison
void initialisation_combi(combinaison * combi)
{

	combi->t_un = 0;
	combi->t_deux = 0;
	combi->t_trois = 0;
	combi->t_quatre = 0;
	combi->t_cinq = 0;
	combi->t_six = 0;

	combi->brelan = 0;
	combi->carre = 0;
	combi->full = 0;
	combi->petite_s = 0;
	combi->gde_s = 0;
	combi->yams = 0;
	combi->chance = 0;
}

	
//structure pour la main du joueur
typedef struct s_main
{
	int de1;				//nombre de dé
	int de2;
	int de3;
	int de4;
	int de5;
	int nb_un;				// nombre de face
	int nb_deux;
	int nb_trois;
	int nb_quatre;
	int nb_cinq;
	int nb_six;
	
}t_main;

//fonction qui initialise la sructure main
void initialisation_m(t_main *m1)
{
	m1->de1=0;							// les dés
	m1->de2=0;
	m1->de3=0;
	m1->de4=0;
	m1->de5=0;
	m1->nb_un =0;						// les faces 
	m1->nb_deux=0;
	m1->nb_trois=0;
	m1->nb_quatre=0;
	m1->nb_cinq=0;
	m1->nb_six=0;

}


//lacement de tous les dés
void lancer(t_main *m1)
{
	
	m1->de1=rand()%6+1;
	m1->de2=rand()%6+1;
	m1->de3=rand()%6+1;
	m1->de4=rand()%6+1;
	m1->de5=rand()%6+1;

}

// Fonction qui permet de déterminer le nombre de faces dans la main du joueur.
void mainJ(t_main *m1)
{

	int tab[7];
	int i;

	for(i=1;i<7;i++){			// permet de compter le nombre de face obtenue 
		if(m1->de1==i){			// dans la main du joueur.
			tab[i]++;
		}
		if(m1->de2==i){
			tab[i]++;
		}
		if(m1->de3==i){
			tab[i]++;
		}
		if(m1->de4==i){
			tab[i]++;
		}
		if(m1->de5==i){
			tab[i]++;
		}
	}

	m1->nb_un=tab[1];		//ii
	m1->nb_deux=tab[2];
	m1->nb_trois=tab[3];
	m1->nb_quatre=tab[4];
	m1->nb_cinq=tab[5];
	m1->nb_six=tab[6];

}


//fonction qui vérifie si on a la combinaison petite suite dans la main et qui met à jour la structure combinaison
void petite_suite(combinaison *combi, t_main m1)
{		
	if((m1.nb_un>0 && m1.nb_un<3) && (m1.nb_deux>0 && m1.nb_deux<3) && (m1.nb_trois>0 && m1.nb_trois<3) && (m1.nb_quatre>0 && m1.nb_quatre<3)){
		combi->petite_s = 1;
		printf("Vous avez eu la combinaison petite suite !");

	}
	else if((m1.nb_deux>0 && m1.nb_deux<3) && (m1.nb_trois>0 && m1.nb_trois<3) && (m1.nb_quatre>0 && m1.nb_quatre<3) && (m1.nb_cinq>0 && m1.nb_cinq<3)){
		combi->petite_s = 1;
		printf("Vous avez eu la combinaison petite suite !");

	}
	else if((m1.nb_trois>0 && m1.nb_trois<3) && (m1.nb_quatre>0 && m1.nb_quatre<3) && (m1.nb_cinq>0 && m1.nb_cinq<3) && (m1.nb_six>0 && m1.nb_six<3)){
		combi->petite_s = 1;
		printf("Vous avez eu la combinaison petite suite !");

	}

}

//fonction qui vérifie si on a la combinaison petite suite et qui met à jour la structure combinaison
void gde_suite(combinaison *combi, t_main m1)
{		
	if((m1.nb_un == 1) && (m1.nb_deux == 1) && (m1.nb_trois == 1) && (m1.nb_quatre == 1) && (m1.nb_cinq == 1)){
		
		combi->gde_s = 1;
		printf("Vous avez eu la combinaison grande suite !");

	}
	else if((m1.nb_deux == 1) && (m1.nb_trois == 1) && (m1.nb_quatre == 1) && (m1.nb_cinq == 1) && (m1.nb_six == 1)){
		
		combi->gde_s = 1;
		printf("Vous avez eu la combinaison grande suite !");

	}

}

// fonction qui vérifie si on a la combinaison full et qui met à jour la structure combinaison
void full(combinaison *combi, t_main m1){

	if((comb.brelan == 1) && (m1.nb_un == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !", );

	}
	else if((comb.brelan == 1) && (m1.nb_deux == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !", );


	}

	else if((comb.brelan == 1) && (m1.nb_trois == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !", );

	}

	else if((comb.brelan == 1) && (m1.nb_quatre == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !", );

	}

	else if((comb.brelan == 1) && (m1.nb_cinq == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !", );

	}

	else if((comb.brelan == 1) && (m1.nb_six == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !", );

	}
}

// fonction qui donne la possibilité au joueur de faire la combinison chance.
void chance(combinaison *combi)
{

	combi->chance = 1;

}

// vérifie quelle combinaison peut être fait par le joueur.
void combinaison(combinaison * combi, t_main m1, fiche_score score)
{
        if(m1.nb_un > 0){
                switch(m1.nb_un){
                        case 1 :combi->t_un = 1 ;break;
                        case 2 :combi->t_un = 2 ;break;
                        case 3 : 
                        		if(score.t_un == 0){			//Si Trois dés face 1, joueur peut marquer 3*1 points pour total de un
                                	combi->t_un = 3;			
                                }

                                if(score.brelan == 0){			//ou alors les points du brelan de 1.	        	
                                	combi->brelan = 3;
                                }					          
                                break;
                        case 4 :
                        		if(score.t_un == 0){
                                	combi->t_un = 4 ;
                                }
                                if(score.carre == 0){			// ou alors les points du carrée de 1.
                                	combi->carre = 4;
                            	}
                                break;
                        case 5 :
                        		if(score.t_un == 0){
                                	combi->t_un = 5;			
                            							
                                }
                                if(score.yams == 0){   			// ou encore les points du yams
                                	combi->yams = 1;.
                                }	
                        break;
                }
        }
        if(m1.nb_deux > 0){
                switch(m1.nb_deux){
                        case 1 :combi->t_deux = 1 ;break;
                        case 2 :combi->t_deux = 2 ;break;
                        case 3 : 
                        		if(score.t_deux == 0){			//Si Trois dés face 2, joueur peut marquer 3*2 points pour total de un
                                	combi->t_deux = 3;			
                                }

                                if(score.brelan == 0){			//ou alors les points du brelan de 2.	        	
                                	combi->brelan = 6;
                                }					          
                                break;
                        case 4 :
                        		if(score.t_deux == 0){
                                	combi->t_deux = 4;
                                }
                                if(score.carre == 0){			// ou alors les points du carrée de 2.
                                	combi->carre = 8;
                            	}
                                break;
                        case 5 :
                        		if(score.t_deux == 0){
                                	combi->t_deux = 5;			
                            							
                                }
                                if(score.yams == 0){   			// ou encore les points du yams
                                	combi->yams = 1;.
                                }	
                        break;
                }
        }
        if(m1.nb_trois > 0){
                switch(m1.nb_trois){
                        case 1 :combi->t_trois = 1 ;break;
                        case 2 :combi->t_trois = 2 ;break;
                        case 3 : 
                        		if(score.t_trois == 0){			
                                	combi->t_trois = 3;			
                                }

                                if(score.brelan == 0){			   	
                                	combi->brelan = 9;
                                }					          
                                break;
                        case 4 :
                        		if(score.t_trois == 0){
                                	combi->t_trois = 4;
                                }
                                if(score.carre == 0){			
                                	combi->carre = 12;
                            	}
                                break;
                        case 5 :
                        		if(score.t_trois == 0){
                                	combi->t_trois = 5;			
                            							
                                }
                                if(score.yams == 0){   			
                                	combi->yams = 1;.
                                }	
                        break;
                }
        }
        if(m1.nb_quatre > 0){
                switch(m1.nb_quatre){
                        case 1 :combi->t_quatre = 1 ;break;
                        case 2 :combi->t_quatre = 2 ;break;
                        case 3 : 
                        		if(score.t_quatre == 0){			
                                	combi->t_quatre = 3;			
                                }

                                if(score.brelan == 0){			       	
                                	combi->brelan = 12;
                                }					          
                                break;
                        case 4 :
                        		if(score.t_quatre == 0){
                                	combi->t_quatre = 4 ;
                                }
                                if(score.carre == 0){			
                                	combi->carre = 16;
                            	}
                                break;
                        case 5 :
                        		if(score.t_quatre == 0){
                                	combi->t_quatre = 5;			
                            							
                                }
                                if(score.yams == 0){   			
                                	combi->yams = 1;.
                                }	
                        break;
                }
        }
        if(m1.nb_cinq > 0){
                switch(m1.nb_cinq){
                       case 1 :combi->t_cinq = 1 ;break;
                        case 2 :combi->t_cinq = 2 ;break;
                        case 3 : 
                        		if(score.t_cinq == 0){			
                                	combi->t_cinq = 3;			
                                }

                                if(score.brelan == 0){				        	
                                	combi->brelan = 15;
                                }					          
                                break;
                        case 4 :
                        		if(score.t_cinq == 0){
                                	combi->t_cinq = 4 ;
                                }
                                if(score.carre == 0){			
                                	combi->carre = 20;
                            	}
                                break;
                        case 5 :
                        		if(score.t_cinq == 0){
                                	combi->t_cinq = 5;			
                            							
                                }
                                if(score.yams == 0){   			
                                	combi->yams = 1;.
                                }	
                        break;
                }
        }
        if(m1.nb_six > 0){
                switch(m1.nb_six){
                        case 1 :combi->t_un = 1 ;break;
                        case 2 :combi->t_un = 2 ;break;
                        case 3 : 
                        		if(score.t_un == 0){			
                                	combi->t_un = 3;			
                                }

                                if(score.brelan == 0){				        	
                                	combi->brelan = 18;
                                }					          
                                break;
                        case 4 :
                        		if(score.t_un == 0){
                                	combi->t_un = 4 ;
                                }
                                if(score.carree == 0){
                                	combi->carre = 24;
                            	}
                                break;
                        case 5 :
                        		if(score.t_un == 0){
                                	combi->t_un = 5;			
                            							
                                }
				
                                if(score.yams == 0){   			
                                	combi->yams = 1;.
                                }	
                        break;
                }
	    }

	    if(score.petite_s == 0){

	    	petite_suite(combinaison * combi, t_main m1); //verifie si la combinaison est une petitte suite.

	    }
	    

	    if(score.gde_s == 0){

			gde_suite(combinaison * combi, t_main m1);	//verifie si la combinaison est une grande suite.

	    }
	    

	    if(score.full == 0){

	    	full(combinaison * combi, t_main m1); //verifie si la combinaison est est un full.
		}

	    if(score.chance == 0){

	    	chance(combinaison * combi);		// fais la combinaison chance.
	    }
	    
      	
}












/*int tour_Ordi(){




}*/


int main(){
	srand(time(NULL));
	t_main m1;
	initialisation_m(&m1);
	lancer(&m1);
	fprintf(stderr, "%i %i %i %i %i\n",m1.de1,m1.de2,m1.de3,m1.de4,m1.de5);
	mainJ(&m1);
	printf("Nombre de 1 : %i\n", m1.nb_un);

	return 0;

}
