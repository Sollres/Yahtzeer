#include <stdio.h>
#include <stdlib.h>

#include "lancement.h"
#include "affichage.h"
#include "combinaison.h"
#include "tour.h"

void gagnant(t_fiche_score score,t_fiche_score score2){
    if(score.total > score2.total){
        printf("\nLe joueur 1 gagne la partie avec %i pts", score.total);
    }
    else{
        printf("\nLe joueur 2 gagne la partie avec %i pts", score2.total);
    }
}

void Tour(t_main m,t_fiche_score *score, int joueur){
    int relance = 0;
    int tour = 1;
    int rep;
    printf("\n ## A toi de joueur Joueur %i ! ##\n", joueur);
    printf("\n");
    lancer(&m, relance);
    afficher_main(m);
    printf("Voulez-vous relancer vos dés ? (1:oui/2:non) ");
    scanf("%i",&relance);
    if(relance == 1){
        tour == 2;
        lancer(&m, relance);
        afficher_main(m);
        printf("Voulez-vous relancer vos dés ? (1:oui/2:non) ");
        scanf("%i",&relance);
        tour = 3;
        if(relance == 1){
            lancer(&m,relance);
            afficher_main(m);
            rep = f_combinaison(m,score);
            points(m,score,choixx,rep);

        }
        else if(relance == 2){
            rep = f_combinaison(m,score);
            points(m,score,choixx,rep);
        }
    }
    else if(relance == 2){
        rep = f_combinaison(m,score);
        points(m,score,choixx,rep);
    }
    score->total_i = score->t_un + score->t_deux + score->t_trois + score->t_quatre + score->t_cinq + score->t_six;
    if(score->total_i > 63){
		score->bonus = 35;
	}
	if(score->bonus == 35){
		score->total_i +=35;
		score->bonus = 1;
	}

	score->total_ii = score->brelan + score->carre + score->full + score->pte_suite + score->gde_suite + score->yams + score->chance;

	score->total = score->total_i + score->total_ii;
    
}