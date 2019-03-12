#include <stdio.h>
#include <stdlib.h>
#include "combinaison.h"



//fonction qui initialise la sructure main
void initialisation_m(t_main *m1)
{
    m1->de1=0;                          // les dés
    m1->de2=0;
    m1->de3=0;
    m1->de4=0;
    m1->de5=0;
    m1->nb_un =0;                       // les faces 
    m1->nb_deux=0;
    m1->nb_trois=0;
    m1->nb_quatre=0;
    m1->nb_cinq=0;
    m1->nb_six=0;

}

// fonction qui initialise la fiche de score à l'aide de la structure fiche_score.
void initialisation_f(fiche_score * score)
{
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

//fonction qui intialise la structure combinaison
void initialisation_combi(combinaison * combi)
{

    combi->t_un = 0;
    combi->t_deux = 0;
    combi->t_trois = 0;
    combi->t_quatre = 0;
    combi->t_cinq = 0;
    combi->t_six = 0;

    combi->brelan = 0;
    combi->carre = 0;
    combi->full = 0;
    combi->petite_s = 0;
    combi->gde_s = 0;
    combi->yams = 0;
    combi->chance = 0;
}


//fonction qui vérifie si on a la combinaison petite suite dans la main et qui met à jour la structure combinaison
void petite_suite(combinaison *combi, t_main m1)
{       
    if((m1.nb_un>0 && m1.nb_un<3) && (m1.nb_deux>0 && m1.nb_deux<3) && (m1.nb_trois>0 && m1.nb_trois<3) && (m1.nb_quatre>0 && m1.nb_quatre<3)){
        combi->petite_s = 1;
        printf("Vous avez eu la combinaison petite suite !");

    }
    else if((m1.nb_deux>0 && m1.nb_deux<3) && (m1.nb_trois>0 && m1.nb_trois<3) && (m1.nb_quatre>0 && m1.nb_quatre<3) && (m1.nb_cinq>0 && m1.nb_cinq<3)){
        combi->petite_s = 1;
        printf("Vous avez eu la combinaison petite suite !");

    }
    else if((m1.nb_trois>0 && m1.nb_trois<3) && (m1.nb_quatre>0 && m1.nb_quatre<3) && (m1.nb_cinq>0 && m1.nb_cinq<3) && (m1.nb_six>0 && m1.nb_six<3)){
        combi->petite_s = 1;
        printf("Vous avez eu la combinaison petite suite !");

    }

}



//fonction qui vérifie si on a la combinaison petite suite et qui met à jour la structure combinaison
void gde_suite(combinaison *combi, t_main m1)
{       
    if((m1.nb_un == 1) && (m1.nb_deux == 1) && (m1.nb_trois == 1) && (m1.nb_quatre == 1) && (m1.nb_cinq == 1)){
        
        combi->gde_s = 1;
        printf("Vous avez eu la combinaison grande suite !");

    }
    else if((m1.nb_deux == 1) && (m1.nb_trois == 1) && (m1.nb_quatre == 1) && (m1.nb_cinq == 1) && (m1.nb_six == 1)){
        
        combi->gde_s = 1;
        printf("Vous avez eu la combinaison grande suite !");

    }

}


// fonction qui verifie si on a la combinaison full et qui met à jour la structure combinaison
void full(combinaison *combi, t_main m1){

        if((combi->brelan == 1) && (m1.nb_un == 2)){

                combi->full = 1;
                printf("Vous avez fait la combinaison full !");

        }
        else if((combi->brelan == 1) && (m1.nb_deux == 2)){

                combi->full = 1;
                printf("Vous avez fait la combinaison full !");


        }

        else if((combi->brelan == 1) && (m1.nb_trois == 2)){

                combi->full = 1;
                printf("Vous avez fait la combinaison full !");

        }

        else if((combi->brelan == 1) && (m1.nb_quatre == 2)){

                combi->full = 1;
                printf("Vous avez fait la combinaison full !");

        }

        else if((combi->brelan == 1) && (m1.nb_cinq == 2)){

                combi->full = 1;
                printf("Vous avez fait la combinaison full !");

        }

        else if((combi->brelan == 1) && (m1.nb_six == 2)){

                combi->full = 1;
                printf("Vous avez fait la combinaison full !");

        }
}

// fonction qui donne la possibilité au joueur de faire la combinison chance.
void chance(combinaison *combi)
{

    combi->chance = 1;

}

//fonction qui calcule le point du joueur en fonction de sa main et des combinaison //qu'il peut réaliser
void point (fiche_score * score, combinaison combi, t_main m1){
        int choix;
        if(combi.t_un != 0){                    //verification de la combinaison et affichage de cette combinaison si c'est possible.
                printf("1 - Total de 1 ?\n");   
        }
        if(combi.t_deux != 0){
                printf("2 - Total de 2 ?\n");
        }
        if(combi.t_trois != 0){
                printf("3 - Total de 3 ?\n");
        }
        if(combi.t_quatre != 0){
                printf("4 - Total de 4 ?\n");
        }
        if(combi.t_cinq != 0){
                printf("5 - Total de 5 ?\n");
        }
        if(combi.t_six != 0){
                printf("6 - Total de 6 ?\n");
        }
        if(combi.brelan != 0){
                printf("7 - Brelan ?\n");
        }
        if(combi.carre != 0){
                printf("8 - Carre ?\n");
        }
        if(combi.full != 0){
                printf("9 - Full ?\n");
        }
        if(combi.petite_s != 0){
                printf("10 - Petite Suite ?\n");
        }
        if(combi.gde_s != 0){
                printf("11 - Grande Suite ?\n");
        }
        if(combi.yams != 0){
                printf("12 - Yams ?\n");
        }
        if(combi.chance != 0){
                printf("13 - Chance ?\n");
        }
        printf("Ou souhaitez vous mettre vos points ? \n");
        scanf("%i",&choix);
        switch(choix){                                                  // permet d'ecrire les points;
                case 1 : score->t_un = combi.t_un * 1;break;
                case 2 : score->t_deux = combi.t_deux * 2;break;
                case 3 : score->t_trois = combi.t_trois * 3;break;
                case 4 : score->t_quatre = combi.t_quatre * 4;break;
                case 5 : score->t_cinq = combi.t_cinq * 5;break;
                case 6 : score->t_six = combi.t_six * 6;break;
                case 7 : score->brelan = combi.brelan;break;
                case 8 : score->carre = combi.carre;break;
                case 9 : score->full = 25;break;
                case 10 : score->petite_s = 30;break;
                case 11 : score->gde_s = 40;break;
                case 12 : score->yams = 50;break;
                case 13 : score->chance = m1.de1 + m1.de2 + m1.de3 + m1.de4 + m1.de5;break;
        }
    
        // total de point du première partie de la fiche.
        score->total_i = score->t_un + score->t_deux + score->t_trois + score->t_quatre + score->t_cinq + score->t_six;  
        if(score->total_i > 63){
                score->Bonus = 35;
        }
        if(score->Bonus == 35){
                score->total_i +=35;
                score->Bonus = 1;
        }
    
        // total de point du second partie.
        score->total_ii = score->brelan + score->carre + score->full + score->petite_s + score->gde_s + score->yams + score->chance;

        score->total = score->total_i + score->total_ii;        // total final des points.

}



// vérifie quelle combinaison peut être fait par le joueur.
void combinaison_f(combinaison * combi, t_main m1, fiche_score score)
{
        if(m1.nb_un > 0){
                switch(m1.nb_un){
                        case 1 :
                                if(score.t_un == 0){
                                    combi->t_un = 1 ;
                                }
                                break;
                        case 2 :
                                if(score.t_un == 0){
                                    combi->t_un = 2 ;
                                }
                                break;
                        case 3 :
                                if(score.t_un == 0){             //Si Trois dés face 1, joueur peut marquer 3*1 points pour total de un
                                    combi->t_un = 3;
                                }

                                if(score.brelan == 0){                  //ou alors les points du brelan de 1.
                                    combi->brelan = 3;
                                }
                                break;
                        case 4 :
                                if(score.t_un == 0){
                                   combi->t_un = 4 ;
                                }
                                if(score.carre == 0){                   // ou alors les points du carrée de 1.
                                   combi->carre = 4;
                                }
                                break;
                        case 5 :
                                if(score.t_un == 0){
                                   combi->t_un = 5;
                                }
                                if(score.yams == 0){                   // ou encore les points du yams
                                   combi->yams = 1;
                                }
                                break;
                }
        }
        if(m1.nb_deux > 0){
                switch(m1.nb_deux){
                        case 1 :
                        if(score.t_deux == 0){
                           combi->t_deux = 1 ;
                        }
                        break;
                        case 2 :
                                if(score.t_deux == 0){
                                    combi->t_deux = 2 ;
                                }
                                break;
                        case 3 :
                                 if(score.t_deux == 0){               //Si Trois dés face 2, joueur peut marquer 3*2 points pour total de un
                                    combi->t_deux = 3;
                                 }

                                if(score.brelan == 0){                       //ou alors les points du brelan de 2.
                                   combi->brelan = 6;
                                }
                                break;
                        case 4 :
                                if(score.t_deux == 0){
                                   combi->t_deux = 4;
                                }
                                if(score.carre == 0){                        // ou alors les points du carrée de 2.
                                   combi->carre = 8;
                                }
                                break;
                        case 5 :
                                 if(score.t_deux == 0){
                                    combi->t_deux = 5;
                                 }
                                if(score.yams == 0){                         // ou encore les points du yams
                                   combi->yams = 1;
                                }
                                break;
                }
        }
        if(m1.nb_trois > 0){
                switch(m1.nb_trois){
                        case 1 :
                                if(score.t_trois == 0){
                                    combi->t_trois = 1 ;
                                }
                                break;
                        case 2 :
                                if(score.t_trois == 0){
                                    combi->t_trois = 2 ;
                                }
                                break;
                        case 3 :
                                if(score.t_trois == 0){
                                   combi->t_trois = 3;
                                }

                                if(score.brelan == 0){
                                   combi->brelan = 9;
                                }
                                break;
                        case 4 :
                                if(score.t_trois == 0){
                                   combi->t_trois = 4;
                                }
                                if(score.carre == 0){
                                   combi->carre = 12;
                                }
                                break;
                        case 5 :
                                if(score.t_trois == 0){
                                   combi->t_trois = 5;
                                }
                                if(score.yams == 0){
                                   combi->yams = 1;
                                }
                        break;
                }
        }
        if(m1.nb_quatre > 0){
                switch(m1.nb_quatre){
                        case 1 :
                                if(score.t_quatre == 0){
                                    combi->t_quatre = 1 ;
                                }
                                break;
                        case 2 :
                                if(score.t_quatre == 0){
                                    combi->t_quatre = 2 ;
                                }
                                break;
                        case 3 :
                                if(score.t_quatre == 0){
                                    combi->t_quatre = 3;
                                }


                                if(score.brelan == 0){
                                    combi->brelan = 12;
                                }
                                break;
                        case 4 :
                                if(score.t_quatre == 0){
                                    combi->t_quatre = 4 ;
                                }
                                if(score.carre == 0){
                                    combi->carre = 16;
                                }
                                break;
                        case 5 :
                                if(score.t_quatre == 0){
                                    combi->t_quatre = 5;
                                }
                                if(score.yams == 0){
                                    combi->yams = 1;
                                }
                                break;
                }
        }
        if(m1.nb_cinq > 0){
                switch(m1.nb_cinq){
                        case 1 :
                                if(score.t_cinq == 0){
                                    combi->t_cinq = 1 ;
                                }
                                break;
                        case 2 :
                                if(score.t_cinq == 0){
                                    combi->t_cinq = 2 ;
                                }
                                break;
                        case 3 :
                                if(score.t_cinq == 0){
                                    combi->t_cinq = 3;
                                }


                                if(score.brelan == 0){
                                    combi->brelan = 15;
                                }
                                break;
                        case 4 :
                                if(score.t_cinq == 0){
                                    combi->t_cinq = 4 ;
                                }

                                if(score.carre == 0){
                                    combi->carre = 20;
                                }
                                break;
                        case 5 :
                                if(score.t_cinq == 0){
                                    combi->t_cinq = 5;
                                }
                                if(score.yams == 0){
                                    combi->yams = 1;
                                }
                                break;
                }
        }
        if(m1.nb_six > 0){
                switch(m1.nb_six){
                        case 1 :
                                if(score.t_six == 0){
                                    combi->t_six = 1 ;
                                }
                                break;
                        case 2 :
                                if(score.t_six == 0){
                                    combi->t_six = 2 ;
                                }
                                break;
                        case 3 :
                                if(score.t_six == 0){
                                    combi->t_six = 3;
                                }

                                if(score.brelan == 0){
                                    combi->brelan = 18;
                                }
                                break;
                        case 4 :
                                if(score.t_six == 0){
                                    combi->t_un = 4 ;
                                }

                                if(score.carre == 0){
                                    combi->carre = 24;
                                }
                                break;
                        case 5 :
                                if(score.t_six == 0){
                                    combi->t_six = 5;
                                }

                                if(score.yams == 0){
                                    combi->yams = 1;
                                }
                                break;
                }
            }

            if(score.petite_s == 0){

                    pte_suite(combi,m1);            //verifie si la combinaison est une petitte suite.

            }


            if(score.gde_s == 0){

                        gde_suite(combi,m1);        //verifie si la combinaison est une grande suite.

            }


            if(score.full == 0){

                    full(combi,m1);                 //verifie si la combinaison est est un full.
                }

            if(score.chance == 0){

                    chance(combi);                  // fais la combinaison chance.
            }


}















