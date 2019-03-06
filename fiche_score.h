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

void initialisation_f(fiche_score * score);
