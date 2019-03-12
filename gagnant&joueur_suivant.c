#include <stdio.h>
#include <stdlib.h>

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

int joueur_suivant(int joueur, int nbr_joueur){
	
	if(joueur<nbr_joueur){
		joueur++;
	}
	else{
		joueur = 1;
	}
	return joueur;

}
