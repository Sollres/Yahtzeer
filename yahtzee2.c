/* Yahtzee V2 SOARES UFACIK */
/* Version 2 -- Lance les dés, demande si relance nécessaire puis relance les dés souhaités
 *
 * Affiche les combinaisons : total de 1 à 6 puis brelan
 * A faire : Verif message des totaux pour les combis
 * Demander combinaison apres 2ieme relance si reussi pts sinon 0
 * Sinon points apres 2 eme relance et pas de troisieme
 * Attribuer les points et les afficher
 * fiche de score commune à l'affichage
 * voir a effecer la struct combi */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choixx;

typedef struct s_main
{
    int de1, de2, de3, de4, de5;
    int nb_un, nb_deux, nb_trois, nb_quatre, nb_cinq, nb_six;
}t_main;



typedef struct s_fiche_score
{
    int t_un, t_deux, t_trois, t_quatre, t_cinq, t_six, total_i, bonus;
    int brelan, carre, full, pte_suite, gde_suite, yams, chance, total_ii,total;
}t_fiche_score;

void afficher_main(t_main m){
    printf("Voici vos dés ! \n");
    printf("%i %i %i %i %i \n", m.de1, m.de2, m.de3, m.de4, m.de5);
}

void lancer(t_main *m, int relance){
    int rep;
    int c1,c2,c3,c4,c5;
    if(relance != 1){
        m->de1 = rand()%6+1;
        m->de2 = rand()%6+1;
        m->de3 = rand()%6+1;
        m->de4 = rand()%6+1;
        m->de5 = rand()%6+1;
    }
    else if(relance == 1)
    {
        printf("Combien de dés voulez-vous relancer ? ");
        scanf("%i",&rep);
        printf("\n");
        switch(rep){
            case 1 : 
                printf("Vous relancez 1 de vos 5 dés ! \n");
                printf("Quel dé relancer ? ");
                scanf("%i",&c1);break;
            case 2 : 
                printf("Vous relancez 2 de vos 5 dés ! \n");
                printf("Quels dés relancer ? ");
                scanf("%i %i",&c1,&c2);break;
            case 3 : 
                printf("Vous relancez 3 de vos 5 dés ! \n");
                printf("Quels dés relancer ? ");
                scanf("%i %i %i",&c1,&c2,&c3);break;
            case 4 : 
                printf("Vous relancez 4 de vos 5 dés ! \n");
                printf("Quels dés relancer ? ");
                scanf("%i %i %i %i",&c1,&c2,&c3,&c4);break;
            case 5 : 
                printf("Vous relancez vos 5 dés ! \n");
                 m->de1 = rand()%6+1;
                 m->de2 = rand()%6+1;
                 m->de3 = rand()%6+1;
                 m->de4 = rand()%6+1;
                 m->de5 = rand()%6+1;break;
            default:break;
        }
        switch(c1){
            case 1 : m->de1=rand()%6+1;break;
            case 2 : m->de2=rand()%6+1;break;
            case 3 : m->de3=rand()%6+1;break;
            case 4 : m->de4=rand()%6+1;break;
            case 5 : m->de5=rand()%6+1;break;
        }
        switch(c2){
            case 1 : m->de1=rand()%6+1;break;
            case 2 : m->de2=rand()%6+1;break;
            case 3 : m->de3=rand()%6+1;break;
            case 4 : m->de4=rand()%6+1;break;
            case 5 : m->de5=rand()%6+1;break;
        }
        switch(c3){
            case 1 : m->de1=rand()%6+1;break;
            case 2 : m->de2=rand()%6+1;break;
            case 3 : m->de3=rand()%6+1;break;
            case 4 : m->de4=rand()%6+1;break;
            case 5 : m->de5=rand()%6+1;break;
        }
        switch(c4){
            case 1 : m->de1=rand()%6+1;break;
            case 2 : m->de2=rand()%6+1;break;  
            case 3 : m->de3=rand()%6+1;break;
            case 4 : m->de4=rand()%6+1;break;
            case 5 : m->de5=rand()%6+1;break;
        }
        
    }
    
}

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

void chance(t_main m, t_fiche_score *score){ //ajouter combinaison *combi dans les parametres
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
    /*score->total_i = score->t_un + score->t_deux + score->t_trois + score->t_quatre + score->t_cinq + score->t_six;
    if(score->total_i > 63){
		score->bonus = 35;
	}
	if(score->bonus == 35){
		score->total_i +=35;
		score->bonus = 1;
	}

	score->total_ii = score->brelan + score->carre + score->full + score->pte_suite + score->gde_suite + score->yams + score->chance;

	score->total = score->total_i + score->total_ii;*/
}
/*mettre score dans combinaison*/
int f_combinaison(t_main m,t_fiche_score *score){ // ajouter fichescore dans les parametres retourne de 1 à 12 dans les autres cas 0;
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
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 2 : 
            printf("Vous marquez %i points pour Total de 2 ! \n",m.nb_deux * 2);
            rep = m.nb_deux*2;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 3 :
            printf("Vous marquez %i points pour Total de 3 ! \n",m.nb_trois * 3);
            rep = m.nb_trois*3;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 4 :
            printf("Vous marquez %i points pour Total de 4 ! \n",m.nb_quatre * 4);
            rep = m.nb_quatre*4;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 5 : 
            printf("Vous marquez %i points pour Total de 5 ! \n",m.nb_cinq * 5);
            rep = m.nb_cinq*5;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 6 :
            printf("Vous marquez %i points pour Total de 6 ! \n",m.nb_six * 6);
            rep = m.nb_six*6;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 7 : 
            printf("Vous marquez %i points pour le Brelan ! \n",br*3);
            rep = br*3;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 8 : 
            printf("Vous marquez %i points pour le Carre ! \n",ca*4);
            rep = ca*4;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 9 : 
            printf("Vous marquez 25 points pour le Full ! \n");
            rep = 25;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 10 : 
            printf("Vous marquez 30 points pour la Petite suite ! \n");
            rep = 30;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 11 : 
            printf("Vous marquez 40 points pour la Grande suite ! \n");
            rep = 40;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 12 : 
            printf("Vous marquez 50 points pour le Yams ! \n");
            rep = 50;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        case 13 : 
            printf("Vous marquez %i points pour la Chance ! \n",m.de1 + m.de2 + m.de3 + m.de4 + m.de5);
            rep = m.de1 + m.de2 + m.de3 + m.de4 + m.de5;
            //points(m,score,choix,rep,br,ca);
            return rep;
            break;
        default : printf("@@@\n");break;
    }

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
