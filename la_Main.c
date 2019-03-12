#include <stdio.h>
#include <stdlib.h>
#include "la_Main.h"


void initialisation_m(t_main *m1)
{
	m1->de1=0;
	m1->de2=0;
	m1->de3=0;
	m1->de4=0;
	m1->de5=0;
	m1->nb_un =0;
	m1->nb_deux=0;
	m1->nb_trois=0;
	m1->nb_quatre=0;
	m1->nb_cinq=0;
	m1->nb_six=0;
}

// Fonction qui permet d'afficher la main du joueur.
void affiche_main(t_main m1)
{
	printf("%i %i %i %i %i \n",m1.de1,m1.de2,m1.de3,m1.de4,m1.de5); // affichage de la main
}

// Fonction qui permet de déterminer le nombre de faces dans la main du joueur.
void mainJ(t_main *m1){

	int tab[7];
	int i;
	for(i=0;i<7;i++){ 			//initialise la table à 0;
		tab[i]=0;
	}

	printf("\n");

	for(i=1;i<7;i++){			// permet de compter le nombre de face obtenue dans la main du joueur.
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
