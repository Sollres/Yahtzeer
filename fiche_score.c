#include <stdio.h>
#include <stdlib.h>
//#include <"fiche_score.h">

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
	int petite_s ; //30pts
	int gde_s ; //40pts
	int yams ; //50pts
	int chance ; //Total des 5 dés
	int total_ii ;

	int total; //Somme des deux parties
}fiche_score;

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
	printf("Petite Suite (30 points) : %i\n",score->petite_s);
	printf("Grande Suite (40 points) : %i\n",score->gde_s);
	printf("Yams (50 points) : %i\n",score->yams);
	printf("Chance (Total des 5 dés) : %i\n",score->chance);
	printf("Total Partie Secondaire : %i\n",score->total_ii);
	printf("Total : %i\n",score->total);
}

int main(){
	fiche_score score;
	initialisation_f(&score);
	affichage_score(&score);
}
