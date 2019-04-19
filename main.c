#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lancement.h"
#include "affichage.h"
#include "combinaison.h"
#include "tour.h"

int choixx;

int main(){
    srand(time(NULL));
    int debut = 0;
    int aff = 0;
    int jeu = 1;
    int joueur = 1;
    t_main m = {0,0,0,0,0,0,0,0,0,0,0};
    t_fiche_score score = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    t_fiche_score score2 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    while(debut == 0){
        printf(" _____________________________________\n");
        printf("|               YAHTZEE               |\n");
        printf(" _____________________________________\n");
        printf("            _______________           \n");
        printf("           |  1  -  Start  |          \n");
        printf("            _______________           \n");
        scanf("%i",&debut);
    }
    do{
        if(joueur == 1){
            Tour(m,&score,joueur);
            printf("Voulez-vous afficher la fiche de score ? (1:oui) \n");
            scanf("%i",&aff);
            if(aff == 1){
                affiche_score(&score,&score2);
            }
            joueur = 2;
        }
        else if(joueur == 2){
            Tour(m,&score2,joueur);
            printf("Voulez-vous afficher la fiche de score ? (1:oui) \n");
            scanf("%i",&aff);
            if(aff == 1){
                affiche_score(&score,&score2);
            }
            joueur = 1;
        }
        jeu++;

    }while(jeu<7);
    gagnant(score,score2);
    

    return 0;
}


