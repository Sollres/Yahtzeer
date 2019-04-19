#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lancement.h"

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