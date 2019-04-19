yams: fonctions.o main.o
	gcc -o yams fonctions.o main.o
fonction.o: tour.c combinaison.c affichage.c lancement.c
	gcc -c tour.c combinaison.c affichage.c lancement.c -g -Wall
main.o: main.c tour.h combinaison.h affichage.h lancement.h
	gcc -c main.c tour.h combinaison.h affichage.h lancement.h -g -Wall