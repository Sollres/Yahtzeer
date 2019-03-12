#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "la_Main.h"
#include "Combinaison.h"
#include "tour.h"


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