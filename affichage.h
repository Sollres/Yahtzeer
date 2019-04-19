#include <stdio.h>
#include <stdlib.h>

typedef struct s_fiche_score
{
    int t_un, t_deux, t_trois, t_quatre, t_cinq, t_six, total_i, bonus;
    int brelan, carre, full, pte_suite, gde_suite, yams, chance, total_ii,total;
}t_fiche_score;

void afficher_main(t_main );
void affiche_score(t_fiche_score *, t_fiche_score *);