#include <stdio.h>
#include <stdlib.h>

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

void initialisation_m(t_main *);
void mainJ(t_main *);
void affiche_main(t_main m1);