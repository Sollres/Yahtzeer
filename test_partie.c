#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Erreur : Affiche  Total de 1 à chaque fois même si aucun 1 dans la main,
efface le score  à chaque nouveau tour*/

typedef struct s_main
{
	int de1;
	int de2;
	int de3;
	int de4;
	int de5;
	int nb_un;
	int nb_deux;
	int nb_trois;
	int nb_quatre;
	int nb_cinq;
	int nb_six;
	
}t_main;

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
	int chance ;

}combinaison;

typedef struct s_fiche_score
{
	int t_un; //additionne les 1 obtenus ex: 3 dés sur 1 donne 3 pts
	int t_deux; //additionne les 2 obtenus
	int t_trois; //additionne les 3 obtenus
	int t_quatre; //additionne les 4 obtenus
	int t_cinq ; //additionne les 5 obtenus
	int t_six ; //additionne les 6 obtenus
	int total_i;
	int Bonus;

	int brelan ; //Total des 3 dés identiques
	int carre ; //Total des 4 dés identiques
	int full ; //25pts
	int petite_s ; //30pts (suite de quatre dés)
	int gde_s ; //40pts (suite de 5 dés)
	int yams ; //50pts
	int chance ; //Total des 5 dés
	int total_ii ;

	int total; //Somme des deux parties
}fiche_score;

//initialisation de la structure
void initialisation_m(t_main *m1){
	m1->de1=0;			//initialisation des dés
	m1->de2=0;
	m1->de3=0;
	m1->de4=0;
	m1->de5=0;
	m1->nb_un =0;			//initialisation des faces
	m1->nb_deux=0;
	m1->nb_trois=0;
	m1->nb_quatre=0;
	m1->nb_cinq=0;
	m1->nb_six=0;
}


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

void initialisation_f(fiche_score * score){
	score->t_un = 0;
	score->t_deux = 0;
	score->t_trois = 0;
	score->t_quatre = 0;
	score->t_cinq = 0;
	score->t_six = 0;
	score->total_i = 0;
	score->Bonus = 0;

	score->brelan = 0;
	score->carre = 0;
	score->full = 0;
	score->petite_s = 0;
	score->gde_s = 0;
	score->yams = 0;
	score->chance = 0;
	score->total_ii = 0;

	score->total = 0;
}

int start()
{

	int nbr_joueur;
	printf("Combien de joueur ?");		// choix du joueur
	scanf("%i", &nbr_joueur);
	return nbr_joueur;

}

void affiche_main(t_main m1){
	printf("%i %i %i %i %i \n",m1.de1,m1.de2,m1.de3,m1.de4,m1.de5);
}

void lancer(t_main * m1){
	srand(time(NULL));
	m1->de1=rand()%6+1;
	m1->de2=rand()%6+1;
	m1->de3=rand()%6+1;
	m1->de4=rand()%6+1;
	m1->de5=rand()%6+1;

}

void relance(t_main * m1){
	int c1,c2,c3,c4,c5;
	int choix;

	printf("Combien de dés voulez-vous relancer ? ");
	scanf("%i", &choix);

	if(choix == 5){
		printf("Quels dés voulez-vous relancer ? ");
		scanf("%i %i %i %i %i", &c1, &c2, &c3, &c4, &c5);
	}
	if(choix == 4){
		printf("Quels dés voulez-vous relancer ? ");
		scanf("%i %i %i %i", &c1, &c2, &c3, &c4);
	}
	if(choix == 3){
		printf("Quels dés voulez-vous relancer ? ");
		scanf("%i %i %i", &c1, &c2, &c3);
	}
	if(choix == 2){
		printf("Quels dés voulez-vous relancer ? ");
		scanf("%i %i", &c1, &c2);
	}
	if(choix == 1){
		printf("Quels dés voulez-vous relancer ? ");
		scanf("%i", &c1);
	}
	switch(c1){
		case 1 : m1->de1=rand()%6+1;break;
		case 2 : m1->de2=rand()%6+1;break;
		case 3 : m1->de3=rand()%6+1;break;
		case 4 : m1->de4=rand()%6+1;break;
		case 5 : m1->de5=rand()%6+1;break;
	}
	switch(c2){
		case 1 : m1->de1=rand()%6+1;break;
		case 2 : m1->de2=rand()%6+1;break;
		case 3 : m1->de3=rand()%6+1;break;
		case 4 : m1->de4=rand()%6+1;break;
		case 5 : m1->de5=rand()%6+1;break;
	}
	switch(c3){
		case 1 : m1->de1=rand()%6+1;break;
		case 2 : m1->de2=rand()%6+1;break;
		case 3 : m1->de3=rand()%6+1;break;
		case 4 : m1->de4=rand()%6+1;break;
		case 5 : m1->de5=rand()%6+1;break;
	}
	switch(c4){
		case 1 : m1->de1=rand()%6+1;break;
		case 2 : m1->de2=rand()%6+1;break;
		case 3 : m1->de3=rand()%6+1;break;
		case 4 : m1->de4=rand()%6+1;break;
		case 5 : m1->de5=rand()%6+1;break;
	}
	switch(c5){
		case 1 : m1->de1=rand()%6+1;break;
		case 2 : m1->de2=rand()%6+1;break;
		case 3 : m1->de3=rand()%6+1;break;
		case 4 : m1->de4=rand()%6+1;break;
		case 5 : m1->de5=rand()%6+1;break;
	}
}

int joueur_suivant(int joueur, int nbr_joueur){
	
	if(joueur<nbr_joueur){
		joueur++;
	}
	else{
		joueur = 1;
	}
	return joueur;

}

void affichage_score(fiche_score * score){
	printf("Total de 1 : %i \n",score->t_un);
	printf("Total de 2 : %i \n",score->t_deux);
	printf("Total de 3 : %i \n",score->t_trois);
	printf("Total de 4 : %i \n",score->t_quatre);
	printf("Total de 5 : %i \n",score->t_cinq);
	printf("Total de 6 : %i \n",score->t_six);
	printf("Total intermédiaire : %i \n",score->total_i);
	printf("Bonus : %i \n",score->Bonus);
	printf("Brelan (Total des 3 dés) : %i \n",score->brelan);
	printf("Carré (Total des 4 dés) : %i \n",score->carre);
	printf("Full (25 points) : %i\n",score->full);
	printf("Petite Suite (30 points/4 dés à la suite) : %i\n",score->petite_s);
	printf("Grande Suite (40 points/5 dés à la suite) : %i\n",score->gde_s);
	printf("Yams (50 points) : %i\n",score->yams);
	printf("Chance (Total des 5 dés) : %i\n",score->chance);
	printf("Total Partie Secondaire : %i\n",score->total_ii);
	printf("Total : %i\n",score->total);
}

void point (fiche_score * score, combinaison combi, t_main m1){
	int choix;
	if(combi.t_un != 0){
		printf("1 - Total de 1 ?\n");
	}
	if(combi.t_deux != 0){
		printf("2 - Total de 2 ?\n");
	}
	if(combi.t_trois != 0){
		printf("3 - Total de 3 ?\n");
	}
	if(combi.t_quatre != 0){
		printf("4 - Total de 4 ?\n");
	}
	if(combi.t_cinq != 0){
		printf("5 - Total de 5 ?\n");
	}
	if(combi.t_six != 0){
		printf("6 - Total de 6 ?\n");
	}
	if(combi.brelan != 0){
		printf("7 - Brelan ?\n");
	}
	if(combi.carre != 0){
		printf("8 - Carre ?\n");
	}
	if(combi.full != 0){
		printf("9 - Full ?\n");
	}
	if(combi.petite_s != 0){
		printf("10 - Petite Suite ?\n");
	}
	if(combi.gde_s != 0){
		printf("11 - Grande Suite ?\n");
	}
	if(combi.yams != 0){
		printf("12 - Yams ?\n");
	}
	if(combi.chance != 0){
		printf("13 - Chance ?\n");
	}
	printf("Ou souhaitez vous mettre vos points ? \n");
	scanf("%i",&choix);
	switch(choix){
		case 1 : score->t_un = combi.t_un * 1;break;
		case 2 : score->t_deux = combi.t_deux * 2;break;
		case 3 : score->t_trois = combi.t_trois * 3;break;
		case 4 : score->t_quatre = combi.t_quatre * 4;break;
		case 5 : score->t_cinq = combi.t_cinq * 5;break;
		case 6 : score->t_six = combi.t_six * 6;break;
		case 7 : score->brelan = combi.brelan;break;
		case 8 : score->carre = combi.carre;break;
		case 9 : score->full = 25;break;
		case 10 : score->petite_s = 30;break;
		case 11 : score->gde_s = 40;break;
		case 12 : score->yams = 50;break;
		case 13 : score->chance = m1.de1 + m1.de2 + m1.de3 + m1.de4 + m1.de5;break;
	}

	score->total_i = score->t_un + score->t_deux + score->t_trois + score->t_quatre + score->t_cinq + score->t_six;
	if(score->total_i > 63){
		score->Bonus = 35;
	}
	if(score->Bonus == 35){
		score->total_i +=35;
		score->Bonus = 1;
	}

	score->total_ii = score->brelan + score->carre + score->full + score->petite_s + score->gde_s + score->yams + score->chance;

	score->total = score->total_i + score->total_ii;

}

void mainJ(t_main *m1)
{

	int tab[7];
	int i;
	for(i=0;i<7;i++){
		tab[i]=0;
	}

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


//fonction qui verifie si on a la combinaison petite suite et qui met à jour la structure combinaison
void pte_suite(combinaison *combi, t_main m1)
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

//fonction qui verifie si on a la combinaison petite suite et qui met à jour la structure combinaison
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

// fonction qui verifie si on a la combinaison full et qui met à jour la structure combinaison
void full(combinaison *combi, t_main m1){

	if((combi->brelan == 1) && (m1.nb_un == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !");

	}
	else if((combi->brelan == 1) && (m1.nb_deux == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !");


	}

	else if((combi->brelan == 1) && (m1.nb_trois == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !");

	}

	else if((combi->brelan == 1) && (m1.nb_quatre == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !");

	}

	else if((combi->brelan == 1) && (m1.nb_cinq == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !");

	}

	else if((combi->brelan == 1) && (m1.nb_six == 2)){

		combi->full = 1;
		printf("Vous avez fait la combinaison full !");

	}
}

void chance(combinaison *combi)
{

	combi->chance = 1;

}


void combinaison_f(combinaison * combi, t_main m1, fiche_score score)
{
        if(m1.nb_un > 0){
                switch(m1.nb_un){
                        case 1 :
                        if(score.t_un == 0){
                        	combi->t_un = 1 ;
                        }
                    	break;
                        case 2 :
                        if(score.t_un == 0){
                        	combi->t_un = 2 ;
                        }
                        break;
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
                                	combi->yams = 1;
                                }	
                        break;
                }
        }
        if(m1.nb_deux > 0){
                switch(m1.nb_deux){
                        case 1 :
                        if(score.t_deux == 0){
                        	combi->t_deux = 1 ;
                        }
                        break;
                        case 2 :
                        if(score.t_deux == 0){
                        	combi->t_deux = 2 ;break;
                        }
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
                                	combi->yams = 1;
                                }	
                        break;
                }
        }
        if(m1.nb_trois > 0){
                switch(m1.nb_trois){
                        case 1 :
                        if(score.t_trois == 0){
                        	combi->t_trois = 1 ;
                        }
                        break;
                        case 2 :
                        if(score.t_trois == 0){
                        	combi->t_trois = 2 ;
                        }
                        break;
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
                                	combi->yams = 1;
                                }	
                        break;
                }
        }
        if(m1.nb_quatre > 0){
                switch(m1.nb_quatre){
                        case 1 :
                        if(score.t_quatre == 0){
                        	combi->t_quatre = 1 ;
                        }
                        break;
                        case 2 :
                        if(score.t_quatre == 0){
                        	combi->t_quatre = 2 ;
                        }
                        break;
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
                                	combi->yams = 1;
                                }	
                        break;
                }
        }
        if(m1.nb_cinq > 0){
                switch(m1.nb_cinq){
                        case 1 :
                        if(score.t_cinq == 0){
                        	combi->t_cinq = 1 ;
                        }
                        break;
                        case 2 :
                        if(score.t_cinq == 0){
                        	combi->t_cinq = 2 ;
                        }
                    	break;
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
                                	combi->yams = 1;
                                }	
                        break;
                }
        }
        if(m1.nb_six > 0){
                switch(m1.nb_six){
                        case 1 :
                        if(score.t_six == 0){
                        	combi->t_six = 1 ;
                        }
                        break;
                        case 2 :
                        if(score.t_six == 0){
                        	combi->t_six = 2 ;
                        }
                        break;
                        case 3 : 
                        		if(score.t_six == 0){			
                                	combi->t_six = 3;			
                                }

                                if(score.brelan == 0){				        	
                                	combi->brelan = 18;
                                }					          
                                break;
                        case 4 :
                        		if(score.t_six == 0){
                                	combi->t_un = 4 ;
                                }
                                if(score.carre == 0){
                                	combi->carre = 24;
                            	}
                                break;
                        case 5 :
                        		if(score.t_six == 0){
                                	combi->t_six = 5;			
                            							
                                }
				
                                if(score.yams == 0){   			
                                	combi->yams = 1;
                                }	
                        break;
                }
	    }

	    if(score.petite_s == 0){

	    	pte_suite(combi,m1); //verifie si la combinaison est une petitte suite.

	    }
	    

	    if(score.gde_s == 0){

			gde_suite(combi,m1);	//verifie si la combinaison est une grande suite.

	    }
	    

	    if(score.full == 0){

	    	full(combi,m1); //verifie si la combinaison est est un full.
		}

	    if(score.chance == 0){

	    	chance(combi);		// fais la combinaison chance.
	    }
	    
      	
}

void gagnant(fiche_score score,fiche_score score2,fiche_score score3){
	if(score.total > score2.total && score.total > score3.total){
		printf("Joueur 1 gagne avec %i points !!", score.total);
	}
	else if(score2.total > score.total && score2.total > score.total){
		printf("Joueur 2 gagne avec %i points !!", score2.total);
	}
	else{
		printf("Joueur 3 gagne avec %i points !!", score3.total);
	}
}

int tour(int joueur,t_main m1, combinaison combi, fiche_score score, int nb_joueur){
	int rep;
	int rep2;
	int affs;
	printf("Joueur %i, à vous de jouer !\n", joueur);
	lancer(&m1);
	printf("Voici les dés que vous avez obtenu !\n");
	affiche_main(m1);
	mainJ(&m1);
	combinaison_f(&combi, m1, score);
	printf("voulez-vous rejouer des dés (1:oui 2:non) ?\n");
	scanf("%i",&rep);
	if(rep== 1){
		relance(&m1);
		affiche_main(m1);
		mainJ(&m1);
		combinaison_f(&combi, m1,score);
		printf("voulez-vous rejouer des dés (1:oui 2:non) ?\n");
		scanf("%i",&rep2);
		if(rep2 == 1){
			relance(&m1);
			affiche_main(m1);
			mainJ(&m1);
			combinaison_f(&combi, m1,score);
		}
	}
	point(&score,combi,m1);
	printf("\n");
	affichage_score(&score);
	printf("\n");

	return joueur = joueur_suivant(joueur, nb_joueur);

}

int main(){
	srand(time(NULL));
	int joueur = 1;
	int nb_joueur = 0;
	int partie = 0;
	t_main m1;
	combinaison combi;
	fiche_score score;
	fiche_score score2;
	fiche_score score3;
	initialisation_m(&m1);
	initialisation_combi(&combi);
	initialisation_f(&score);
	initialisation_f(&score2);
	initialisation_f(&score3);
	nb_joueur = start();
	while(partie < 13*nb_joueur){
		if(joueur == 1){
			joueur = tour(joueur,m1,combi,score,nb_joueur);
		}
		if(joueur == 2){
			joueur = tour(joueur,m1,combi,score2,nb_joueur);
		}
		if(joueur == 3){
			joueur = tour(joueur,m1,combi,score3,nb_joueur);
		}
	}


}