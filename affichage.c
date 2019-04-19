#include <stdio.h>
#include <stdlib.h>

#include "lancement.h"
#include "affichage.h"


void afficher_main(t_main m){
    printf("Voici vos dés ! \n");
    printf("%i %i %i %i %i \n", m.de1, m.de2, m.de3, m.de4, m.de5);
}

void affiche_score(t_fiche_score *score, t_fiche_score *score2){
	
	printf("|--------------------------------------------|\n");
	printf("| Joueur               |     1    |     2    |\n");
	printf("| Total de 1           |    %.2i    |    %.2i    |\n",score->t_un,score2->t_un);
	printf("| Total de 2           |    %.2i    |    %.2i    |\n",score->t_deux,score2->t_deux);
	printf("| Total de 3           |    %.2i    |    %.2i    |\n",score->t_trois,score2->t_trois);
	printf("| Total de 4           |    %.2i    |    %.2i    |\n",score->t_quatre,score2->t_quatre);
	printf("| Total de 5           |    %.2i    |    %.2i    |\n",score->t_cinq,score2->t_cinq);
	printf("| Total de 6           |    %.2i    |    %.2i    |\n",score->t_six,score2->t_six);
	printf("| Total supérieur      |    %.2i    |    %.2i    |\n",score->total_i,score2->total_i);
	printf("| Bonus (35pts)        |    %.2i    |    %.2i    |\n",score->bonus,score2->bonus);
	printf("| Brelan               |    %.2i    |    %.2i    |\n",score->brelan,score2->brelan);
	printf("| Carré                |    %.2i    |    %.2i    |\n",score->carre,score2->carre);
	printf("| Full (25pts)         |    %.2i    |    %.2i    |\n",score->full,score2->full);
	printf("| Petite Suite (30pts) |    %.2i    |    %.2i    |\n",score->pte_suite,score2->pte_suite);
	printf("| Grande Suite (40pts) |    %.2i    |    %.2i    |\n",score->gde_suite,score2->gde_suite);
	printf("| Yams (50pts)         |    %.2i    |    %.2i    |\n",score->yams,score2->yams);
	printf("| Chance               |    %.2i    |    %.2i    |\n",score->chance,score2->chance);
	printf("| Total inférieur      |    %.2i    |    %.2i    |\n",score->total_ii,score2->total_ii);
	printf("| Total                |    %.2i    |    %.2i    |\n",score->total,score2->total);
	printf("|--------------------------------------------|\n");
}