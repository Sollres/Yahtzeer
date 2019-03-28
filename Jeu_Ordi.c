#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PBRELAN 0.15
#define PCARRE 0.02
#define PFULL 0.04
#define PPTES 0.003
#define PGDES 0.001
#define PYAMS 0.008

typedef struct s_main{
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

typedef struct s_combinaison
{
	int t_un; 			
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
	int chance ;

}combinaison;

typedef struct s_fiche_score{
	int t_un;
	int t_deux;
	int t_trois;
	int t_quatre;
	int t_cinq;
	int t_six;
	int total_i;
	int Bonus;

	int brelan;
	int carre;
	int full;
	int petite_s;
	int gde_s;
	int yams;
	int chance;
	int total_ii;
	int total;

}fiche_score;

void mainJ(t_main *m)
{

	int tab[7] = {-1,0,0,0,0,0,0};
	int i;

	for(i=1;i<7;i++){			// permet de compter le nombre de face obtenue 
		if(m->de1==i){			// dans la main du joueur.
			tab[i]++;
		}
		if(m->de2==i){
			tab[i]++;
		}
		if(m->de3==i){
			tab[i]++;
		}
		if(m->de4==i){
			tab[i]++;
		}
		if(m->de5==i){
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

void lancer(t_main *m){
	m->de1 = rand()%6+1;
	m->de2 = rand()%6+1;
	m->de3 = rand()%6+1;
	m->de4 = rand()%6+1;
	m->de5 = rand()%6+1;
}

int Pte_s(t_main m){
	if((m.nb_un>0 && m.nb_un<3) && (m.nb_deux>0 && m.nb_deux<3) && (m.nb_trois>0 && m.nb_trois<3) && (m.nb_quatre>0 && m.nb_quatre<3)){
		return 1;

	}
	else if((m.nb_deux>0 && m.nb_deux<3) && (m.nb_trois>0 && m.nb_trois<3) && (m.nb_quatre>0 && m.nb_quatre<3) && (m.nb_cinq>0 && m.nb_cinq<3)){
		return 1;

	}
	else if((m.nb_trois>0 && m.nb_trois<3) && (m.nb_quatre>0 && m.nb_quatre<3) && (m.nb_cinq>0 && m.nb_cinq<3) && (m.nb_six>0 && m.nb_six<3)){
		return 1;
	}
}

int Gde_s(t_main m){
	if((m.nb_un == 1) && (m.nb_deux == 1) && (m.nb_trois == 1) && (m.nb_quatre == 1) && (m.nb_cinq == 1)){
		return 1;
	}
	else if((m.nb_deux == 1) && (m.nb_trois == 1) && (m.nb_quatre == 1) && (m.nb_cinq == 1) && (m.nb_six == 1)){
		return 1;
	}
}

int Full(t_main m){
	int tab[6] = {m.nb_un,m.nb_deux,m.nb_trois,m.nb_quatre,m.nb_cinq,m.nb_six};
	for(int i=0;i<6;i++){
		if(tab[i] == 3){
			for(int j=0;j<6;j++){
				if(tab[j] == 2){
					return 1;
				}
			}
		}
	}
	return 0;
}

int max(int *tab, int taille){
	int i, max = tab[0];
	for(i=1;i<taille;i++){
		if(tab[i]>max){
			max = tab[i];
		}
	}
	return max;
}

void combinaison_f(t_main m,fiche_score *score_o, int relance){
	/* Mise des valeurs dans le tableau afin de faciliter la vue des combinaisons */
	int i;
	mainJ(&m);
	int tab[6] = {m.nb_un,m.nb_deux,m.nb_trois,m.nb_quatre,m.nb_cinq,m.nb_six};
	/* Tableau indiquant si la combinaison est réalisable 
	 * Avec : 
	 * tab[0] = total de 1, tab[1] = total de 2, tab[2] = total de 3
	 * tab[3] = total de 4, tab[4] = total de 5, tab[5] = total de 6
	 * tab[6] = Brelan, tab[7] = Carre, tab[8] = Full, tab[9] = Petite suite
	 * tab[10] = Grande suite, tab[11] = Yams, tab[12] = Chance */
	int tab_combi[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

	/*Verification si totaux sont dispos*/ /*Erreur comptabilisation totaux */ 
	/* Prendre code visual code */
	for(i=0;i<6;i++){
			tab_combi[i] = i * tab[i];
	}
	for(i=0;i<6;i++){
		if(tab[i] == 3){ //Brelan
			tab_combi[6] = 3 * (i+1);
		}
		if(tab[i] == 4){ //Carre
			tab_combi[7] = 4 * (i+1);
		}
		if(Full(m) == 1){ //Full
			tab_combi[8] = 25;
		}
		if(Pte_s(m) == 1){ //Petite suite
			tab_combi[9] = 30;
		}
		if(Gde_s(m) == 1){ //Grande suite
			tab_combi[10] = 40;
		}
		if(tab[i] == 5){ //yams
			tab_combi[11] = 50;
		}
		// Chance
		tab_combi[12] = 1 * m.nb_un + 2 * m.nb_deux + 3 * m.nb_trois + 4 * m.nb_quatre + 5 * m.nb_cinq + 6 * m.nb_six;
	}
	if(relance == 0){
		int res = max(tab_combi,13);
		//printf("%i \n",res); 
	}






	for(int a =0;a<13;a++){
		printf("%i ",tab_combi[a]);
	}
	printf("\n");
}

void relance_ordi(t_main *m,fiche_score *score_o){
	int tab[5] = {m->de1,m->de2,m->de3,m->de4,m->de5};

}
/********************************************** Proba *****************************************/

int proba_ordi(int combi_poss, int proba_voulu){
	/* Declaration de variable pour chaque combinaison --> valeur recup de la fonction combinaison ?*/

	/* P(A|B) = (P[A ∩ B])/P(B)
	 * probabilite de chaque face du dé : 1/6
	 * Si relance de plusieurs dés calcul de X parmis Y
	 */
	return ((combi_poss * proba_voulu)/proba_voulu);

}

void Tour_Ordi(){
	int relance = 0;
}

int main(){
	srand(time(NULL));
	int relance = 0;
	t_main m = {0,0,0,0,0,0,0,0,0,0,0};
	combinaison combi = {0,0,0,0,0,0,0,0,0,0,0,0};
	fiche_score score = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	lancer(&m);
	printf("%i %i %i %i %i\n",m.de1, m.de2,m.de3,m.de4,m.de5);
	combinaison_f(m,&score,relance);

	return 0;
}

















