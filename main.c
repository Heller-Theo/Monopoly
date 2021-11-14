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

    int choix = 0, choix2 = 0;
    int sauvegarde1 = 0, sauvegarde2 = 0, sauvegarde3 = 0;

    if (choix2) {
        FILE* pfichier = fopen("../monFichierMonopoly.dat", "r");
        if (pfichier == NULL) {
            printf("Erreur d'ouverture du fichier.\n");

            printf("Creation de votre fichier de sauvegarde...\n");
            pfichier = fopen("../monFichierMonopoly.dat", "w");

            initialisationSauvegarde(plateauMonopoly1, listeJoueur1, &infoChanceCaisse[0], listeVariable1);
            initialisationSauvegarde(plateauMonopoly2, listeJoueur2, &infoChanceCaisse[1], listeVariable2);
            initialisationSauvegarde(plateauMonopoly3, listeJoueur3, &infoChanceCaisse[2], listeVariable3);
        }
        else {

            if (fread(&sauvegarde1, sizeof(int), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (Sauvegarde 1).\n");
            }
            for (int i = 0; i < TAILLE_PLATEAU; i++) {
                if (fread(&plateauMonopoly1[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                    printf("Probleme de lecture dans le fichier (Case numero %d de la sauvegarde 1).\n", i);
                }
            }
            for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
                if (fread(&listeJoueur1[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                    printf("Probleme de lecture dans le fichier (Joueur numero %d de la sauvegarde 1).\n", i);
                }
            }
            if (fread(listeVariable1, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (liste des variables de la sauvegarde 1).\n");
            }
            if (fread(&infoChanceCaisse[0], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (carte chance et caisse de communaute de la sauvegarde 1).\n");
            }



            if (fread(&sauvegarde2, sizeof(int), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (Sauvegarde 2).\n");
            }
            for (int i = 0; i < TAILLE_PLATEAU; i++) {
                if (fread(&plateauMonopoly2[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                    printf("Probleme de lecture dans le fichier (Case numero %d de la sauvegarde 2).\n", i);
                }
            }
            for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
                if (fread(&listeJoueur2[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                    printf("Probleme de lecture dans le fichier (Joueur numero %d de la sauvegarde 2).\n", i);
                }
            }
            if (fread(listeVariable2, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (liste des variables de la sauvegarde 2).\n");
            }
            if (fread(&infoChanceCaisse[1], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (carte chance et caisse de communaute de la sauvegarde 2).\n");
            }



            if (fread(&sauvegarde3, sizeof(int), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (Sauvegarde 3).\n");
            }
            for (int i = 0; i < TAILLE_PLATEAU; i++) {
                if (fread(&plateauMonopoly3[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                    printf("Probleme de lecture dans le fichier (Case numero %d de la sauvegarde 3).\n", i);
                }
            }
            for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
                if (fread(&listeJoueur3[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                    printf("Probleme de lecture dans le fichier (Joueur numero %d de la sauvegarde 3).\n", i);
                }
            }
            if (fread(listeVariable3, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (liste des variables de la sauvegarde 3).\n");
            }
            if (fread(&infoChanceCaisse[2], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (carte chance et caisse de communaute de la sauvegarde 3).\n");
            }
        }
        fclose(pfichier);
        pfichier = NULL;
    }
    else {
        initialisationDebutSauvegarde(plateauMonopoly1, plateauMonopoly2, plateauMonopoly3, listeJoueur1, listeJoueur2, listeJoueur3, listeVariable1, listeVariable2, listeVariable3, infoChanceCaisse, &sauvegarde1, &sauvegarde2, &sauvegarde3);
    }


    printf("\n\n-------- Bienvenue au jeu du Monopoly --------\n\n");


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
            sauvegarde1 == 0 ? printf(" Vide\n") : printf(" En jeu\n");
            printf("2) Sauvegarde 2:");
            sauvegarde2 == 0 ? printf(" Vide\n") : printf(" En jeu\n");
            printf("3) Sauvegarde 3:");
            sauvegarde3 == 0 ? printf(" Vide\n>") : printf(" En jeu\n>");

            do {
                scanf(" %d", &choix);
            } while(choix != 0 && choix != 1 && choix != 2 && choix != 3);

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
            sauvegarde3 == 0 ? printf(" Vide\n>") : printf(" En jeu\n>");

            do {
                scanf(" %d", &choix);
            } while(choix != 0 && choix != 1 && choix != 2 && choix != 3);

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
            affichageRegle(plateauMonopoly1);
        }

        if (choix == 4) {
            printf("\nCe Monopoly version Deluxe vous est propose par: \n");
            printf("_______________\n");
            printf("| HELLER Theo |\n");
            printf("---------------\n");
        }

        if (choix == 5) {
            printf("\nEtes vous sur de vouloir quitter le programme ?\n");
            printf("0) Quitter definitivement\n");
            printf("1) Continuer\n>");
            do {
                scanf(" %d", &choix);
            } while(choix != 0 && choix != 1);
        }

    } while (choix != 0);


    if (choix2) {
        FILE* pfichier = fopen("../monFichierMonopoly.dat", "w");
        if (pfichier == NULL) {
            printf("Erreur d'ouverture du fichier.\n");
        }


        if (fwrite(&sauvegarde1, sizeof(int), 1, pfichier) != 1) {
            printf("Probleme d'écriture dans le fichier (Sauvegarde 1).\n");
        }
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            if (fwrite(&plateauMonopoly1[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                printf("Probleme d'écriture dans le fichier (Case numero %d de la sauvegarde 1).\n", i);
            }
        }
        for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
            if (fwrite(&listeJoueur1[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                printf("Probleme d'écriture dans le fichier (Joueur numero %d de la sauvegarde 1).\n", i);
            }
        }
        if (fwrite(listeVariable1, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
            printf("Probleme d'écriture dans le fichier (liste des variables de la sauvegarde 1).\n");
        }
        if (fwrite(&infoChanceCaisse[0], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
            printf("Probleme d'écriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 1).\n");
        }



        if (fwrite(&sauvegarde2, sizeof(int), 1, pfichier) != 1) {
            printf("Probleme d'écriture dans le fichier (Sauvegarde 2).\n");
        }
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            if (fwrite(&plateauMonopoly2[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                printf("Probleme d'écriture dans le fichier (Case numero %d de la sauvegarde 2).\n", i);
            }
        }
        for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
            if (fwrite(&listeJoueur2[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                printf("Probleme d'écriture dans le fichier (Joueur numero %d de la sauvegarde 2).\n", i);
            }
        }
        if (fwrite(listeVariable2, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
            printf("Probleme d'écriture dans le fichier (liste des variables de la sauvegarde 2).\n");
        }
        if (fwrite(&infoChanceCaisse[1], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
            printf("Probleme d'écriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 2).\n");
        }



        if (fwrite(&sauvegarde3, sizeof(int), 1, pfichier) != 1) {
            printf("Probleme d'écriture dans le fichier (Sauvegarde 3).\n");
        }
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            if (fwrite(&plateauMonopoly3[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                printf("Probleme d'écriture dans le fichier (Case numero %d de la sauvegarde 3).\n", i);
            }
        }
        for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
            if (fwrite(&listeJoueur3[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                printf("Probleme d'écriture dans le fichier (Joueur numero %d de la sauvegarde 3).\n", i);
            }
        }
        if (fwrite(listeVariable3, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
            printf("Probleme d'écriture dans le fichier (liste des variables de la sauvegarde 3).\n");
        }
        if (fwrite(&infoChanceCaisse[2], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
            printf("Probleme d'écriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 3).\n");
        }

        fclose(pfichier);
        pfichier = NULL;
    }
    else {
        enregistrementFinSauvegarde(plateauMonopoly1, plateauMonopoly2, plateauMonopoly3, listeJoueur1, listeJoueur2, listeJoueur3, listeVariable1, listeVariable2, listeVariable3, infoChanceCaisse, &sauvegarde1, &sauvegarde2, &sauvegarde3);
    }



    return 0;
}