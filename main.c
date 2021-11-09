#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"
#include "structure.h"
#include "initialisation.h"
#include "Jeu.h"


int main() {
    srand(time(NULL));

    //Declaration des elements utile aux 3 sauvegardes.
    CaseMonopoly plateauMonopoly1[TAILLE_PLATEAU], plateauMonopoly2[TAILLE_PLATEAU], plateauMonopoly3[TAILLE_PLATEAU];
    InfoJoueur listeJoueur1[NOMBRE_MAX_JOUEUR], listeJoueur2[NOMBRE_MAX_JOUEUR], listeJoueur3[NOMBRE_MAX_JOUEUR];
    int listeVariable1[NOMBRE_VARIABLE], listeVariable2[NOMBRE_VARIABLE], listeVariable3[NOMBRE_VARIABLE];
    CarteChanceCaisse infoChanceCaisse[3];

    initialisationSauvegarde(plateauMonopoly1, listeJoueur1, infoChanceCaisse[0], listeVariable1);
    initialisationSauvegarde(plateauMonopoly2, listeJoueur2, infoChanceCaisse[1], listeVariable2);
    initialisationSauvegarde(plateauMonopoly3, listeJoueur3, infoChanceCaisse[2], listeVariable3);

    int choix = 0;
    int jeu1 = 0, jeu2 = 0, jeu3 = 0;

    printf("-------- Bienvenue au jeu du Monopoly --------\n\n");

    do {
        printf("\nVous etes au menu principal\n\n");
        printf("Que voulez vous faire ?\n");
        printf("1) Lancer une partie\n");
        printf("2) Supprimer une sauvegarde\n");
        printf("3) Lire les regles\n");
        printf("4) A propos du jeu\n");
        printf("5) Quitter\n>");

        do {
            scanf(" %d", &choix);
        } while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5);

        if (choix == 1) {
            printf("Quelle sauvegarde voulez vous lancer ?\n");
            printf("0) Retour\n");
            printf("1) Sauvegarde 1\n");
            printf("2) Sauvegarde 2\n");
            printf("3) Sauvegarde 3\n>");

            do {
                scanf(" %d", &choix);
            } while(choix != 0 && choix != 1 && choix != 2 && choix != 3);

            if (choix == 1) {
                jeu1 = jeuMonopoly(plateauMonopoly1, listeJoueur1, infoChanceCaisse[0], listeVariable1, jeu1);
            }
            if (choix == 2) {
                jeu2 = jeuMonopoly(plateauMonopoly2, listeJoueur2, infoChanceCaisse[1], listeVariable2, jeu2);
            }
            if (choix == 3) {
                jeu3 = jeuMonopoly(plateauMonopoly3, listeJoueur3, infoChanceCaisse[2], listeVariable3, jeu3);
            }
            choix = 1;
        }

        if (choix == 2) {
            printf("Quelle sauvegarde voulez vous supprimer ?\n");
            printf("0) Retour\n");
            printf("1) Sauvegarde 1\n");
            printf("2) Sauvegarde 2\n");
            printf("3) Sauvegarde 3\n>");

            do {
                scanf(" %d", &choix);
            } while(choix != 0 && choix != 1 && choix != 2 && choix != 3);

            if (choix == 1) {
                initialisationSauvegarde(plateauMonopoly1, listeJoueur1, infoChanceCaisse[0], listeVariable1);
            }
            if (choix == 2) {
                initialisationSauvegarde(plateauMonopoly2, listeJoueur2, infoChanceCaisse[1], listeVariable2);
            }
            if (choix == 3) {
                initialisationSauvegarde(plateauMonopoly3, listeJoueur3, infoChanceCaisse[2], listeVariable3);
            }
            choix = 2;
        }

        if (choix == 3) {
            printf("fonction de lecture des regles\n");
        }

        if (choix == 4) {
            printf("Createur: HELLER Theo\n");
        }

        if (choix == 5) {
            printf("Etes vous sur de vouloir quitter definitivement le programme ?\n");
            printf("Toutes vos sauvegardes seront supprimees\n");
            printf("0) Quitter definitivement\n");
            printf("1) Continuer\n>");
            do {
                scanf(" %d", &choix);
            } while(choix != 0 && choix != 1);
        }

    } while (choix != 0);

    return 0;
}
