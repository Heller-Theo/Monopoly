#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"
#include "structure.h"
#include "initialisation.h"
#include "jeu.h"


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
            printf("\nQuelle sauvegarde voulez vous lancer ?\n");
            printf("0) Retour\n");
            printf("1) Sauvegarde 1:");
            jeu1 == 0 ? printf(" Empty\n") : printf(" En jeu\n");
            printf("2) Sauvegarde 2:");
            jeu2 == 0 ? printf(" Empty\n") : printf(" En jeu\n");
            printf("3) Sauvegarde 3:");
            jeu2 == 0 ? printf(" Empty\n>") : printf(" En jeu\n>");

            do {
                scanf(" %d", &choix);
            } while(choix != 0 && choix != 1 && choix != 2 && choix != 3);

            if (choix == 1) {
                if (jeu1 == 0) {
                    choixRegleSupplementaire(&listeVariable1[0], &listeVariable1[1]);
                }
                jeu1 = jeuMonopoly(plateauMonopoly1, listeJoueur1, infoChanceCaisse[0], listeVariable1, jeu1);
            }
            if (choix == 2) {
                if (jeu2 == 0) {
                    choixRegleSupplementaire(&listeVariable2[0], &listeVariable2[1]);
                }
                jeu2 = jeuMonopoly(plateauMonopoly2, listeJoueur2, infoChanceCaisse[1], listeVariable2, jeu2);
            }
            if (choix == 3) {
                if (jeu3 == 0) {
                    choixRegleSupplementaire(&listeVariable3[0], &listeVariable3[1]);
                }
                jeu3 = jeuMonopoly(plateauMonopoly3, listeJoueur3, infoChanceCaisse[2], listeVariable3, jeu3);
            }
            choix = 1;
        }

        if (choix == 2) {
            printf("\nQuelle sauvegarde voulez vous supprimer ?\n");
            printf("0) Retour\n");
            printf("1) Sauvegarde 1\n");
            printf("2) Sauvegarde 2\n");
            printf("3) Sauvegarde 3\n>");

            do {
                scanf(" %d", &choix);
            } while(choix != 0 && choix != 1 && choix != 2 && choix != 3);

            if (choix == 1) {
                initialisationSauvegarde(plateauMonopoly1, listeJoueur1, infoChanceCaisse[0], listeVariable1);
                jeu1 = 0;
            }
            if (choix == 2) {
                initialisationSauvegarde(plateauMonopoly2, listeJoueur2, infoChanceCaisse[1], listeVariable2);
                jeu2 = 0;
            }
            if (choix == 3) {
                initialisationSauvegarde(plateauMonopoly3, listeJoueur3, infoChanceCaisse[2], listeVariable3);
                jeu3 = 0;
            }
            choix = 2;
        }

        if (choix == 3) {
            affichageRegle(plateauMonopoly1);
        }

        if (choix == 4) {
            printf("\nCe Monopoly version Deluxe vous est propose par: \n");
            printf("_______________\n");
            printf("| HELLER Theo |\n");
            printf("---------------\n");
        }

        if (choix == 5) {
            printf("\nEtes vous sur de vouloir quitter definitivement le programme ?\n");
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

