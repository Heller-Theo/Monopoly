#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"
#include "structure.h"
#include "initialisation.h"
#include "sauvegarde.h"
#include "jeu.h"


int main() {
    srand(time(NULL));

    //Declaration des elements utiles aux 3 sauvegardes.
    CaseMonopoly plateauMonopoly1[TAILLE_PLATEAU], plateauMonopoly2[TAILLE_PLATEAU], plateauMonopoly3[TAILLE_PLATEAU];
    InfoJoueur listeJoueur1[NOMBRE_MAX_JOUEUR], listeJoueur2[NOMBRE_MAX_JOUEUR], listeJoueur3[NOMBRE_MAX_JOUEUR];
    int listeVariable1[NOMBRE_VARIABLE], listeVariable2[NOMBRE_VARIABLE], listeVariable3[NOMBRE_VARIABLE];
    CarteChanceCaisse infoChanceCaisse[3];

    int choix = 0;
    int sauvegarde1 = 0, sauvegarde2 = 0, sauvegarde3 = 0;

    //On initialise nos 3 sauvegardes depuis un fichier binaire s'il existe.
    initialisationDebutSauvegarde(plateauMonopoly1, plateauMonopoly2, plateauMonopoly3, listeJoueur1, listeJoueur2, listeJoueur3, listeVariable1, listeVariable2, listeVariable3, infoChanceCaisse, &sauvegarde1, &sauvegarde2, &sauvegarde3);


    printf("\n\n-------- Bienvenue au jeu du Monopoly --------\n\n");

    do {
        printf("\nVous etes au menu principal\n\n");
        printf("Que voulez vous faire ?\n");
        printf("1) Lancer une partie\n");
        printf("2) Supprimer une sauvegarde\n");
        printf("3) Lire les regles\n");
        printf("4) A propos du jeu\n");
        printf("5) Quitter\n");

        do {
            verificationSaisie(&choix);
            if (choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5) {
                printf("Veuillez saisir un choix valide.\n");
            }
        } while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5);

        if (choix == 1) {
            printf("\nQuelle sauvegarde voulez vous lancer ?\n");
            printf("0) Retour\n");
            printf("1) Sauvegarde 1:");
            sauvegarde1 == 0 ? printf(" Vide\n") : printf(" En jeu\n");
            printf("2) Sauvegarde 2:");
            sauvegarde2 == 0 ? printf(" Vide\n") : printf(" En jeu\n");
            printf("3) Sauvegarde 3:");
            sauvegarde3 == 0 ? printf(" Vide\n") : printf(" En jeu\n");

            do {
                verificationSaisie(&choix);
                if (choix != 0 && choix != 1 && choix != 2 && choix != 3) {
                    printf("Veuillez saisir un choix valide.\n");
                }
            } while(choix != 0 && choix != 1 && choix != 2 && choix != 3);

            //On lance la sauvegarde qui correspond à notre choix.
            if (choix == 1) {
                sauvegarde1 = jeuMonopoly(plateauMonopoly1, listeJoueur1, infoChanceCaisse[0], listeVariable1, sauvegarde1);
            }
            if (choix == 2) {
                sauvegarde2 = jeuMonopoly(plateauMonopoly2, listeJoueur2, infoChanceCaisse[1], listeVariable2, sauvegarde2);
            }
            if (choix == 3) {
                sauvegarde3 = jeuMonopoly(plateauMonopoly3, listeJoueur3, infoChanceCaisse[2], listeVariable3, sauvegarde3);
            }
            choix = 1;
        }

        if (choix == 2) {
            printf("\nQuelle sauvegarde voulez vous supprimer ?\n");
            printf("0) Retour\n");
            printf("1) Sauvegarde 1:");
            sauvegarde1 == 0 ? printf(" Vide\n") : printf(" En jeu\n");
            printf("2) Sauvegarde 2:");
            sauvegarde2 == 0 ? printf(" Vide\n") : printf(" En jeu\n");
            printf("3) Sauvegarde 3:");
            sauvegarde3 == 0 ? printf(" Vide\n") : printf(" En jeu\n");

            do {
                verificationSaisie(&choix);
                if (choix != 0 && choix != 1 && choix != 2 && choix != 3) {
                    printf("Veuillez saisir un choix valide.\n");
                }
            } while(choix != 0 && choix != 1 && choix != 2 && choix != 3);

            //On réinitialise la sauvegarde qui correspond à notre choix.
            if (choix == 1) {
                initialisationSauvegarde(plateauMonopoly1, listeJoueur1, &infoChanceCaisse[0], listeVariable1);
                sauvegarde1 = 0;
            }
            if (choix == 2) {
                initialisationSauvegarde(plateauMonopoly2, listeJoueur2, &infoChanceCaisse[1], listeVariable2);
                sauvegarde2 = 0;
            }
            if (choix == 3) {
                initialisationSauvegarde(plateauMonopoly3, listeJoueur3, &infoChanceCaisse[2], listeVariable3);
                sauvegarde3 = 0;
            }
            printf("La sauvegarde a bien ete reinitialise\n");
            choix = 2;
        }

        if (choix == 3) {
            //On affiche les règles.
            affichageRegle();
        }

        if (choix == 4) {
            printf("\nCe Monopoly version Deluxe vous est propose par: \n");
            printf("_______________\n");
            printf("| HELLER Theo |\n");
            printf("---------------\n");
        }

        if (choix == 5) {
            //On verifie si l'utilisateur veut vraiment quitter le programme.
            printf("\nEtes vous sur de vouloir quitter le programme ?\n");
            printf("0) Quitter definitivement\n");
            printf("1) Continuer\n");

            do {
                verificationSaisie(&choix);
                if (choix != 0 && choix != 1) {
                    printf("Veuillez saisir un choix valide.\n");
                }
            } while(choix != 0 && choix != 1);
        }

    } while (choix != 0);

    //On enregistre nos sauvegardes dans un fichier binaire avant d'arrêter le programme.
    enregistrementFinSauvegarde(plateauMonopoly1, plateauMonopoly2, plateauMonopoly3, listeJoueur1, listeJoueur2, listeJoueur3, listeVariable1, listeVariable2, listeVariable3, infoChanceCaisse, &sauvegarde1, &sauvegarde2, &sauvegarde3);

    return 0;
}