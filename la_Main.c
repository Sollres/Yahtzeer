#include <stdio.h>
#include <stdlib.h>

// structure pour la gestion des dés et  le nombre d'occurence de chaque face
typedef struct s_main
{
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

//initialisation de la structure
void initialisation_m(t_main *m1){
	m1->de1=0;			//initialisation des dés
	m1->de2=0;
	m1->de3=0;
	m1->de4=0;
	m1->de5=0;
	m1->nb_un =0;			//initialisation des faces
	m1->nb_deux=0;
	m1->nb_trois=0;
	m1->nb_quatre=0;
	m1->nb_cinq=0;
	m1->nb_six=0;
}

// Fonction qui permet de déterminer le nombre de faces dans la main du joueur.
void mainJ(t_main *m1){

	int tab[7];
	int i;
	for(i=0;i<7;i++){
		tab[i]=0;
		printf("%i ",tab[i]);
	}

	printf("\n");

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
