# Yahtzeer
Projet L2 Collins SOARES Fatih UFACIK

/*** Si besoin compiler le fichier yahtzee2.c sans le make file ***/

Yahtzee

Règle du jeu :

- Le Yahtzee se joue à 5 dés et se termine une fois toutes les cases de la fiche de score remplies.
Se joue tour à tour et le joueur dispose de 3 lancers par tour.
5 joueur max.

Objectif :
Réaliser à chaque tour des combinaisons qui rapportent des points.

Chaque tour le joueur a le droit de reprendre tous ou une partie des dés, et ceci à chaque lancé afin d'obtenir la combinaison voulue. Le joueur doit obligatoirement inscrire un score dans une des cases à chaque tour que se soit apres le premier lancé, le second ou soit le dernier. Le score peut être marqué par un X si aucun point marqué soir par les points obtenus.

Lorsque le total intermédiaire (total de 1 à total de 6) est égal ou supérieur à 63 points, un bonus de 35 points supplémentaires est donnés.

Victoire :
Le gagnant est le joueur qui comptabilisera le plus de points à la fin des 10 coups (soit la grille remplie).
La feuille de score du Yahtzee :

Nom des joueurs, en ligne, leur score en colonne

Total de 1|
Total de 2|
Total de 3|
Total de 4|
Total de 5|
Total de 6|
Total|
Bonus (35 pts) si >63 points|
Total partie intermédiaire|
Brelan (Total 3 dés identiques)|
Carré (Total 4 dé identiques)|
Full (25 points)|
Petite Suite (30 points)|
Grande Suite (40 points)|
Chance (Total des 5 dés)|
Total 2|

Objectif Projet :
-Joueur contre joueur sur un poste/
-Jeu contre une IA/
-Interface graphique

Total final
Fonctions :

void Lancer (structure main)

Permet le lancement des 5 dés et de relancer certains dés

Switch et plusieurs fonctions lancer en fonctions du nombre de dés a jeter???? 

void nb_face(t_main *m)

Permet de compter le nombre de face que le joueur possède (ex : 3 Deux, 2 un, etc...)

int Combinaison(structure combinaison) ainsi qu'une fonction pour chaque combinaison

Repertorie les combinaison possible avec les dés de la main.

int Tour (numero du joueur, structure main)

Permet de réaliser le tour d’un des joueurs. Combinaison jouée et nombre de points marqués

void gagnant(t_fiche_score score,t_fiche_score score2)

permettant de savoir quels joueur a gagner en fin de partie

int Points ()

Calcul et affichage du nombre de points du joueur

void Feuille des scores ()

Permet l'affichage des scores


Structure : 

-Pour la main du joueur comportant chaque dé mis à jour après chaque lancer.

-Pour la fiche des scores de chaque joueur..



