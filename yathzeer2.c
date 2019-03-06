#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int start(){

	int nbr_joueur;
	printf("Combien de joueur ?");
	scanf("%i", &nbr_joueur);
	return nbr_joueur;
}


typedef struct s_main
{
	int de1;				//nombre de dé
	int de2;
	int de3;
	int de4;
	int de5;
	int nb_un;				// nombre de face
	int nb_deux;
	int nb_trois;
	int nb_quatre;
	int nb_cinq;
	int nb_six;
	
}t_main;

//fonction qui initialise la main
void initialisation_m(t_main *m1){
	m1->de1=0;							// les dés
	m1->de2=0;
	m1->de3=0;
	m1->de4=0;
	m1->de5=0;
	m1->nb_un =0;						// les faces 
	m1->nb_deux=0;
	m1->nb_trois=0;
	m1->nb_quatre=0;
	m1->nb_cinq=0;
	m1->nb_six=0;
}


//lacement de tous les dés
void lancer(t_main *m1){
	
	m1->de1=rand()%6+1;
	m1->de2=rand()%6+1;
	m1->de3=rand()%6+1;
	m1->de4=rand()%6+1;
	m1->de5=rand()%6+1;
}

// Fonction qui permet de déterminer le nombre de faces dans la main du joueur.
void mainJ(t_main *m1){

	int tab[7];
	int i;

	for(i=1;i<7;i++){
		if(m1->de1==i){
			tab[i]++;
		}
		if(m1->de2==i){
			tab[i]++;
		}
		if(m1->de3==i){
			tab[i]++;
		}
		if(m1->de4==i){
			tab[i]++;
		}
		if(m1->de5==i){
			tab[i]++;
		}
	}

	m1->nb_un=tab[1];
	m1->nb_deux=tab[2];
	m1->nb_trois=tab[3];
	m1->nb_quatre=tab[4];
	m1->nb_cinq=tab[5];
	m1->nb_six=tab[6];
}


/*void combinaison(int tab){




}*/



int main(){
	srand(time(NULL));
	t_main m1;
	initialisation_m(&m1);
	lancer(&m1);
	fprintf(stderr, "%i %i %i %i %i\n",m1.de1,m1.de2,m1.de3,m1.de4,m1.de5);
	mainJ(&m1);
	printf("Nombre de 1 : %i\n", m1.nb_un);

	return 0;

}