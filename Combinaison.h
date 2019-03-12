#include <stdio.h>
#include <stdlib.h>

typedef struct s_main
{
    int de1;                //nombre de dé
    int de2;
    int de3;
    int de4;
    int de5;
    int nb_un;              // nombre de face
    int nb_deux;
    int nb_trois;
    int nb_quatre;
    int nb_cinq;
    int nb_six;
    
}t_main;

// structure qui enregistre les combinaison posssible
typedef struct s_combinaison
{
    int t_un;           // variables pour toutes les combinaison possibles
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



void initialisation_m(t_main *);
void initialisation_combi(combinaison *);
void initialisation_f(fiche_score * );
void petite_suite(combinaison *, t_main);
void gde_suite(combinaison *, t_main );
void full(combinaison *, t_main );
void chance(combinaison *);
void point (fiche_score *, combinaison, t_main);
void combinaison(combinaison * , t_main , fiche_score );


