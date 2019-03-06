#include <stdio.h>
#include <stdlib.h>


int mainJ(t_main *m1){

	int tab[6];
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

	for(i=1;i<7;i++){
		printf("Nombre de %i : %i\n",i,tab[i]);
	}

}