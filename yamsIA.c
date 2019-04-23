#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lancer(int *des){
    for(int i=0;i<5;i++){
        des[i] = rand()%6+1;
    }
}
void affichage_des(int *des){
    for(int i = 0;i<5;i++){
            printf("> %i", des[i]);
    }
    printf("\n");
}

void nb_faces(int *des, int *nb, int *combi){
    // des[i] = de i + 1
    for(int i=0;i<7;i++){
        if(des[0] == i)
            nb[i]++;
        if(des[1] == i)
            nb[i]++;
        if(des[2] == i)
            nb[i]++;
        if(des[3] == i)
            nb[i]++;
        if(des[4] == i)
            nb[i]++;
    }
    combi[0]=nb[1];
    combi[1]=nb[2]*2;
    combi[2]=nb[3]*3;
    combi[3]=nb[4]*4;
    combi[4]=nb[5]*5;
    combi[5]=nb[6]*6;
}

void totaux(int *nb, int *score){
    for(int i = 1;i<7;i++){
        if(nb[i] == 1)
            printf("T > %i | %i pts\n", i,i);
        if(nb[i] == 2)
            printf("T > %i | %i pts\n", i,i*2);
        if(nb[i] == 3)
            printf("T > %i | %i pts\n", i,i*3);
        if(nb[i] == 4)
            printf("T > %i | %i pts\n", i,i*4);
        if(nb[i] == 5)
            printf("T > %i | %i pts\n", i,i*5);
    }
}

void brelan(int *nb, int *combi){
    for(int i = 1;i<7;i++){
        if(nb[i] == 3){
            printf("B > %i | %i pts\n", i, i*3);
            combi[6] = i*3;
        }
    }
}

void carre(int *nb, int *combi){
    for(int i = 1;i<7;i++){
        if(nb[i] == 4){
            printf("C > %i | %i pts\n", i, i*4);
            combi[7] = i*4;
        }
    }
}

void full(int *nb, int *combi){
    for(int i =1;i<7;i++){
        if(nb[i] == 3)
            for(int j=1;j<7;j++){
                if(j != i && nb[j] == 2)
                    printf("F > %i | 25 pts\n", i);
                    combi[8] = 25;
            }

    }
    
}

void pte_suite(int *nb, int *combi){
    if((nb[1]>0 && nb[1]<3) && (nb[2]>0 && nb[2]<3) && (nb[3]>0 && nb[3]<3) && (nb[4]>0 && nb[4]<3)){
        printf("P 1-4 | 30 pts\n");
        combi[9] = 30;
    }
    if((nb[2]>0 && nb[2]<3) && (nb[3]>0 && nb[3]<3) && (nb[4]>0 && nb[4]<3) && (nb[5]>0 && nb[5]<3)){
        printf("P 2-5 | 30 pts\n");
        combi[9] = 30;
    }
    if((nb[3]>0 && nb[3]<3) && (nb[4]>0 && nb[4]<3) && (nb[5]>0 && nb[5]<3) && (nb[6]>0 && nb[6]<3)){
        printf("P 3-6 | 30 pts\n");
        combi[9] = 30;
    }
}

void gde_suite(int *nb, int *combi){
    if(nb[1] == 1 && nb[2] == 1 && nb[3] == 1 && nb[4] == 1 && nb[5] == 1){
        printf("G 1-5 | 40 pts\n");
        combi[10] = 40;
    }
    if(nb[2] == 1 && nb[3] == 1 && nb[4] == 1 && nb[5] == 1 && nb[6] == 1){
        printf("G 2-6 | 40 pts\n");
        combi[10] = 40;
    }

}

void yams(int *nb, int *combi){
    for(int i=1;i<7;i++){
        if(nb[i] == 5){
            printf("Y > %i | 50 pts\n",i);
            combi[11]=50;
        }
    }
}

void chance(int *des, int *combi){
    int pt = des[0]+des[1]+des[2]+des[3]+des[4];
    printf("Ch    | %i pts\n", pt);
    combi[12] = pt;

}

int verification(int *combi, int *score){
    for(int i = 0;i<14;i++){
        for(int j = 0;j<14;j++){
            if(score[j] != 0){
                combi[i] == 0;
            }
        }
    }
}

int max(int *combi, int taille){
    int i, max = combi[0];
    for(i=1;i<taille;i++){
        if(combi[i]>max){
            max = combi[i];
        }
    }
    return max;
}

void points(int c, int *score, int max){
    for(int i = 0;i<14;i++){
        if(i == c){
            score[i] = max;
        }
    }
}

int combinaison(int *des, int *nb, int *score, int *combi){
    int m;
    int c;
    nb_faces(des,nb,combi);
    totaux(nb,score);
    brelan(nb, combi);
    carre(nb, combi);
    full(nb, combi);
    pte_suite(nb, combi);
    gde_suite(nb, combi);
    yams(nb, combi);
    chance(des, combi);
    verification(combi,score);
    m = max(combi,13);
    printf("%i\n", m);
    for(int i = 0;i<14;i++){
        if(combi[i] == m){
            c = i;
        }
    }
    points(c,score,m);
    
}

void affiche_score(int *score, int total_i, int total_ii, int total, int bonus){
	
	printf("|---------------------------------|\n");
	printf("| Joueur               |     1    |\n");
	printf("| Total de 1           |    %.2i    |\n",score[0]);
	printf("| Total de 2           |    %.2i    |\n",score[1]);
	printf("| Total de 3           |    %.2i    |\n",score[2]);
	printf("| Total de 4           |    %.2i    |\n",score[3]);
	printf("| Total de 5           |    %.2i    |\n",score[4]);
	printf("| Total de 6           |    %.2i    |\n",score[5]);
	printf("| Total supérieur      |    %.2i    |\n",total_i);
	printf("| Bonus (35pts)        |    %.2i    |\n",bonus);
	printf("| Brelan               |    %.2i    |\n",score[6]);
	printf("| Carré                |    %.2i    |\n",score[7]);
	printf("| Full (25pts)         |    %.2i    |\n",score[8]);
	printf("| Petite Suite (30pts) |    %.2i    |\n",score[9]);
	printf("| Grande Suite (40pts) |    %.2i    |\n",score[10]);
	printf("| Yams (50pts)         |    %.2i    |\n",score[11]);
	printf("| Chance               |    %.2i    |\n",score[12]);
	printf("| Total inférieur      |    %.2i    |\n",total_ii);
	printf("| Total                |    %.2i    |\n",total);
	printf("|-----------------------------------|\n");
}

void TourO(int *des,int *nb,int *combi, int *score){
    int total_i = 0;
    int bonus = 0;
    int total_ii = 0;
    int total = 0;
    lancer(des);
    affichage_des(des);
    combinaison(des,nb,score,combi);
    total_i = score[0] + score[1] + score[2] + score[3] + score[4] + score[5] ;
    
    if(total_i >= 63){
        bonus = 35;
    }
    
    total_ii = score[6] + score[7] + score[8] + score[9] + score[10] + score[11] + score[12];
    
    total = total_i + total_ii + bonus;
    affiche_score(score,total_i,total_ii,total,bonus);
}

int main(void){
    srand(time(NULL));
    int m;
    int t=0;
    int des[5] = {0,0,0,0,0};
    int nb[7] = {0,0,0,0,0,0,0}; // # nb1 nb2 nb3 nb4 nb5 nb6
    int combi[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int score[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    while(t<14){
        TourO(des,nb,combi,score);
        t++;
    }
    

    return 0;
}
