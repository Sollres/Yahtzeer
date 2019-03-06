#include <stdio.h>
#include <stdlib.h>

typedef struct fiche_score fiche_score;
struct fiche_score
{
	int t_un; //additionne les 1 obtenus ex: 3 dés sur 1 donne 3 pts
	int t_deux; //additionne les 2 obtenus
	int t_trois; //additionne les 3 obtenus
	int t_quatre; //additionne les 4 obtenus
	int t_cinq ; //additionne les 5 obtenus
	int t_six ; //additionne les 6 obtenus
	int total_i;

	int brelan ; //Total des 3 dés identiques
	int carre ; //Total des 4 dés identiques
	int full ; //25pts
	int petite_s ; //30pts
	int gde_s ; //40pts
	int yams ; //50pts
	int chance ; //Total des 5 dés
	int total_ii ;

	int total; //Somme des deux parties
};

int initialisation_f(fiche_score * score){
	score->t_un = 0;
	score->t_deux = 0;
	score->t_trois = 0;
	score->t_quatre = 0;
	score->t_cinq = 0;
	score->t_six = 0;
	score->total_i = 0;

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
