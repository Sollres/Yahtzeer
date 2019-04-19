#include <stdio.h>
#include <stdlib.h>

#include "lancement.h"
#include "affichage.h"
#include "combinaison.h"

void nb_face(t_main *m){
    int tab[7] = {0,0,0,0,0,0,0};
    int i;
    for(i=0;i<7;i++){
        if(m->de1 == i){
            tab[i]++;
        }
        if(m->de2 == i){
            tab[i]++;
        }
        if(m->de3 == i){
            tab[i]++;
        }
        if(m->de4 == i){
            tab[i]++;
        }
        if(m->de5 == i){
            tab[i]++;
        }
    }
    m->nb_un=tab[1];		
	m->nb_deux=tab[2];
	m->nb_trois=tab[3];
	m->nb_quatre=tab[4];
	m->nb_cinq=tab[5];
	m->nb_six=tab[6];
}

void totaux(t_main m){
    int tab[7] = {0,m.nb_un,m.nb_deux,m.nb_trois,m.nb_quatre,m.nb_cinq,m.nb_six};
    int i;
    for(i=1;i<7;i++){
        if(tab[i] == 1){
            printf("Vous avez un %i, pour un total de %i pts\n%i - Total de %i\n",i,i,i,i);
        }
        else if(tab[i] == 2){
            printf("Vous avez deux %i, pour un total de %i pts\n%i - Total de %i\n",i,i*2,i,i);
        }
        else if(tab[i] == 3){
            printf("Vous avez trois %i, pour un total de %i pts\n%i - Total de %i\n",i,i*3,i,i);
        }
        else if(tab[i] == 4){
            printf("Vous avez quatre %i, pour un total de %i pts\n%i - Total de %i\n",i,i*4,i,i);
        }
        else if(tab[i] == 5){
            printf("Vous avez cinq %i, pour un total de %i pts\n%i - Total de %i\n",i,i*5,i,i);
        }
    }
    
}

int brelan(t_main m,t_fiche_score *score){
    int tab[7] = {0,m.nb_un,m.nb_deux,m.nb_trois,m.nb_quatre,m.nb_cinq,m.nb_six};
    int i,dispob=0;
    int pt;
    for(i=1;i<7;i++){
        if(tab[i] == 3 && score->brelan == 0){
            printf("Vous avez un brelan de %i, pour un total de %i pts\n",i,i*3);
            dispob = 1;
            pt = i;
        }
    }
    if(dispob == 1){
        printf("7 - Brelan\n");
    }
    return pt;
}

int carre(t_main m,t_fiche_score *score){
    int tab[7] = {0,m.nb_un,m.nb_deux,m.nb_trois,m.nb_quatre,m.nb_cinq,m.nb_six};
    int i,dispoc=0;
    int pt;
    for(i=1;i<7;i++){
        if(tab[i] == 4 && score->carre == 0){
            printf("Vous avez un carre de %i, pour un total de %i pts\n",i,i*4);
            dispoc = 1;
            pt = i;
        }
    }
    if(dispoc == 1){
        printf("8 - Carre\n");
    }
    return pt;
}

void full(t_main m,t_fiche_score *score){ 
    int tab[7] = {0,m.nb_un,m.nb_deux,m.nb_trois,m.nb_quatre,m.nb_cinq,m.nb_six};
    int i,dispof = 0;
    for(i=1;i<7;i++){
        if(tab[i] == 3){
            for(int j=1;j<7;j++){
                if(j != i && tab[j] == 2 && score->full == 0){
                    printf("Vous avez un Full ! Pour un total de 25 pts\n");
                    dispof = 1;
                }
            }
        }
    }
    if(dispof == 1){
        printf("9 - Full\n");
    }
}

void pte_suite(t_main m, t_fiche_score *score){
    int dispop;
    if((m.nb_un>0 && m.nb_un<3) && (m.nb_deux>0 && m.nb_deux<3) && (m.nb_trois>0 && m.nb_trois<3) && (m.nb_quatre>0 && m.nb_quatre<3) && score->pte_suite == 0){
        printf("Vous avez une petite suite ! Pour un total de 30 pts\n");
        dispop = 1;
    }
    else if((m.nb_deux>0 && m.nb_deux<3) && (m.nb_trois>0 && m.nb_trois<3) && (m.nb_quatre>0 && m.nb_quatre<3) && (m.nb_cinq>0 && m.nb_cinq<3)&& score->pte_suite == 0){
        printf("Vous avez une petite suite ! Pour un total de 30 pts\n");
        dispop = 1;
    }
    else if((m.nb_trois>0 && m.nb_trois<3) && (m.nb_quatre>0 && m.nb_quatre<3) && (m.nb_cinq>0 && m.nb_cinq<3) && (m.nb_six>0 && m.nb_six<3) && score->pte_suite == 0){
        printf("Vous avez une petite suite ! Pour un total de 30 pts\n");
        dispop = 1;
    }
    if(dispop == 1){
        printf("10 - Petite Suite\n");
    }


}

void gde_suite(t_main m, t_fiche_score *score){
    int dispog;
    if((m.nb_un == 1) && (m.nb_deux == 1) && (m.nb_trois == 1) && (m.nb_quatre == 1) && (m.nb_cinq == 1) && score->gde_suite == 0){
        printf("Vous avez une grande suite ! Pour un total de 40 pts\n");
        dispog = 1;
    }
    else if((m.nb_deux == 1) && (m.nb_trois == 1) && (m.nb_quatre == 1) && (m.nb_cinq == 1) && (m.nb_six == 1) && score->gde_suite == 0){
        printf("Vous avez une grande suite ! Pour un total de 40 pts\n");
        dispog = 1;
    }
    if(dispog == 1){
        printf("11 - Grande Suite\n");
    }
}

void yams(t_main m, t_fiche_score *score){
    int tab[7] = {0,m.nb_un,m.nb_deux,m.nb_trois,m.nb_quatre,m.nb_cinq,m.nb_six};
    int i,dispoy=0;
    for(i=1;i<7;i++){
        if(tab[i] == 5 && score->yams == 0){
            printf("Vous avez un Yams ! Pour un total de 50 pts\n");
            dispoy = 1;
        }
    }
    if(dispoy == 1){
        printf("12 - Yams\n");
    }
}

void chance(t_main m, t_fiche_score *score){ 
    int dispoch;
    int points = m.de1 + m.de2 + m.de3 + m.de4 + m.de5;
    if(score->chance == 0){
        printf("Vous avez une chance ! Pour un total de %i pts\n",points);
        dispoch = 1;
    }
    if(dispoch == 1){
        printf("13 - Chance\n");
    }
}

void points(t_main m,t_fiche_score *score, int choix,int rep){
    switch(choix){
        case 1 : 
            score->t_un = rep;
            break;
        case 2 :
            score->t_deux = rep;
            break;
        case 3 :
            score->t_trois = rep;
            break;
        case 4 :
            score->t_quatre = rep;
            break;
        case 5 : 
            score->t_cinq = rep;
            break;
        case 6 :
            score->t_six = rep;
            break;
        case 7 : 
            score->brelan = rep;
            break;
        case 8 : 
            score->carre = rep;
            break;
        case 9 : 
            score->full = rep;
            break;
        case 10 : 
            score->pte_suite = rep;
            break;
        case 11 : 
            score->gde_suite = rep;
            break;
        case 12 : 
            score->yams = rep;
            break;
        case 13 : 
            score->chance = rep;
            break;
        default : printf("@@@\n");break;
    }
}

int f_combinaison(t_main m,t_fiche_score *score){ 
    int br=0;
    int ca=0;
    int rep;
    nb_face(&m);
    totaux(m);
    br = brelan(m,score);
    ca = carre(m,score);
    full(m,score);
    pte_suite(m,score);
    gde_suite(m,score);
    yams(m,score);
    chance(m,score);
    printf("Quelle combinaison voulez-vous jouer ? ");
    scanf("%i", &choixx);
    switch(choixx){
        case 1 : 
            printf("Vous marquez %i points pour Total de 1 ! \n", m.nb_un);
            rep = m.nb_un;
            return rep;
            break;
        case 2 : 
            printf("Vous marquez %i points pour Total de 2 ! \n",m.nb_deux * 2);
            rep = m.nb_deux*2;
            return rep;
            break;
        case 3 :
            printf("Vous marquez %i points pour Total de 3 ! \n",m.nb_trois * 3);
            rep = m.nb_trois*3;
            return rep;
            break;
        case 4 :
            printf("Vous marquez %i points pour Total de 4 ! \n",m.nb_quatre * 4);
            rep = m.nb_quatre*4;
            return rep;
            break;
        case 5 : 
            printf("Vous marquez %i points pour Total de 5 ! \n",m.nb_cinq * 5);
            rep = m.nb_cinq*5;
            return rep;
            break;
        case 6 :
            printf("Vous marquez %i points pour Total de 6 ! \n",m.nb_six * 6);
            rep = m.nb_six*6;
            return rep;
            break;
        case 7 : 
            printf("Vous marquez %i points pour le Brelan ! \n",br*3);
            rep = br*3;
            return rep;
            break;
        case 8 : 
            printf("Vous marquez %i points pour le Carre ! \n",ca*4);
            rep = ca*4;
            return rep;
            break;
        case 9 : 
            printf("Vous marquez 25 points pour le Full ! \n");
            rep = 25;
            return rep;
            break;
        case 10 : 
            printf("Vous marquez 30 points pour la Petite suite ! \n");
            rep = 30;
            return rep;
            break;
        case 11 : 
            printf("Vous marquez 40 points pour la Grande suite ! \n");
            rep = 40;
            return rep;
            break;
        case 12 : 
            printf("Vous marquez 50 points pour le Yams ! \n");
            rep = 50;
            return rep;
            break;
        case 13 : 
            printf("Vous marquez %i points pour la Chance ! \n",m.de1 + m.de2 + m.de3 + m.de4 + m.de5);
            rep = m.de1 + m.de2 + m.de3 + m.de4 + m.de5;
            return rep;
            break;
        default : printf("@@@\n");break;
    }

}