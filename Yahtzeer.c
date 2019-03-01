#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct t_main t_main;
struct t_main
{
	int de1;
	int de2;
	int de3;
	int de4;
	int de5;
	
};


//Lancement de tous les dés 
void lancer(t_main * m1){
	srand(time(NULL));
	m1->de1=rand()%6+1;
	m1->de2=rand()%6+1;
	m1->de3=rand()%6+1;
	m1->de4=rand()%6+1;
	m1->de5=rand()%6+1;

}

void relance(t_main * m1){
	int c1,c2,c3,c4,c5;
	int choix;

	printf("Combien de dés voulez-vous relancer ? ");
	scanf("%i", &choix);

	if(choix == 5){
		printf("Quels dés voulez-vous relancer ? ");
		scanf("%i %i %i %i %i", &c1, &c2, &c3, &c4, &c5);
	}
	if(choix == 4){
		printf("Quels dés voulez-vous relancer ? ");
		scanf("%i %i %i %i", &c1, &c2, &c3, &c4);
	}
	if(choix == 3){
		printf("Quels dés voulez-vous relancer ? ");
		scanf("%i %i %i", &c1, &c2, &c3);
	}
	if(choix == 2){
		printf("Quels dés voulez-vous relancer ? ");
		scanf("%i %i", &c1, &c2);
	}
	if(choix == 1){
		printf("Quels dés voulez-vous relancer ? ");
		scanf("%i", &c1);
	}
	switch(c1){
		case 1 : m1->de1=rand()%6+1;break;
		case 2 : m1->de2=rand()%6+1;break;
		case 3 : m1->de3=rand()%6+1;break;
		case 4 : m1->de4=rand()%6+1;break;
		case 5 : m1->de5=rand()%6+1;break;
	}
	switch(c2){
		case 1 : m1->de1=rand()%6+1;break;
		case 2 : m1->de2=rand()%6+1;break;
		case 3 : m1->de3=rand()%6+1;break;
		case 4 : m1->de4=rand()%6+1;break;
		case 5 : m1->de5=rand()%6+1;break;
	}
	switch(c3){
		case 1 : m1->de1=rand()%6+1;break;
		case 2 : m1->de2=rand()%6+1;break;
		case 3 : m1->de3=rand()%6+1;break;
		case 4 : m1->de4=rand()%6+1;break;
		case 5 : m1->de5=rand()%6+1;break;
	}
	switch(c4){
		case 1 : m1->de1=rand()%6+1;break;
		case 2 : m1->de2=rand()%6+1;break;
		case 3 : m1->de3=rand()%6+1;break;
		case 4 : m1->de4=rand()%6+1;break;
		case 5 : m1->de5=rand()%6+1;break;
	}
	switch(c5){
		case 1 : m1->de1=rand()%6+1;break;
		case 2 : m1->de2=rand()%6+1;break;
		case 3 : m1->de3=rand()%6+1;break;
		case 4 : m1->de4=rand()%6+1;break;
		case 5 : m1->de5=rand()%6+1;break;
	}
}

int main(){
	t_main m1;
	int rep;

	lancer(&m1);

	printf("%i %i %i %i %i \n",m1.de1,m1.de2,m1.de3,m1.de4,m1.de5);

	printf("voulez-vous relancer vos dés ? : ");
	scanf("%i", &rep);
	if(rep){
		relance(&m1);
	}
	

	printf("%i %i %i %i %i \n",m1.de1,m1.de2,m1.de3,m1.de4,m1.de5);

}



