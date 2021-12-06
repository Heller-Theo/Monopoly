#include "structure.h"
#include "fonction.h"
#include "initialisation.h"
#include <string.h>
#include <stdio.h>

void initialisationDebutSauvegarde(CaseMonopoly plateauMonopoly1[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly2[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly3[TAILLE_PLATEAU],
                                   InfoJoueur listeJoueur1[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur2[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur3[NOMBRE_MAX_JOUEUR],
                                   int listeVariable1[NOMBRE_VARIABLE], int listeVariable2[NOMBRE_VARIABLE], int listeVariable3[NOMBRE_VARIABLE],
                                   CarteChanceCaisse infoChanceCaisse[], int* pSauvegarde1, int* pSauvegarde2, int* pSauvegarde3) {

    FILE* pfichier = fopen("../monFichierMonopoly.dat", "r");

    //Si le fichier n'existe pas
    if (pfichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");

        printf("Creation de votre fichier de sauvegarde...\n");
        pfichier = fopen("../monFichierMonopoly.dat", "w");

        //On initialise nos trois sauvegarde que l'on enregistrera à la fin du programme dans le fichier binaire que l'on vient de creer.
        initialisationSauvegarde(plateauMonopoly1, listeJoueur1, &infoChanceCaisse[0], listeVariable1);
        initialisationSauvegarde(plateauMonopoly2, listeJoueur2, &infoChanceCaisse[1], listeVariable2);
        initialisationSauvegarde(plateauMonopoly3, listeJoueur3, &infoChanceCaisse[2], listeVariable3);

        printf("C'est la premiere fois que vous lancez le jeu, un petit tour dans la rubrique regle vous aidera !\n");
    }

    //Si le fichier existe, on récupère les informations des 3 sauvegardes.
    else {

        //Sauvegarde 1 :
        if (fread(pSauvegarde1, sizeof(int), 1, pfichier) != 1) {
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


        //Sauvegarde 2 :
        if (fread(pSauvegarde2, sizeof(int), 1, pfichier) != 1) {
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


        //Sauvegarde 3 :
        if (fread(pSauvegarde3, sizeof(int), 1, pfichier) != 1) {
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



void enregistrementFinSauvegarde(CaseMonopoly plateauMonopoly1[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly2[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly3[TAILLE_PLATEAU],
                                 InfoJoueur listeJoueur1[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur2[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur3[NOMBRE_MAX_JOUEUR],
                                 int listeVariable1[NOMBRE_VARIABLE], int listeVariable2[NOMBRE_VARIABLE], int listeVariable3[NOMBRE_VARIABLE],
                                 CarteChanceCaisse infoChanceCaisse[], int* pSauvegarde1, int* pSauvegarde2, int* pSauvegarde3) {

    FILE* pfichier = fopen("../monFichierMonopoly.dat", "w");
    if (pfichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
    }
    //On enregistre nos trois sauvegardes dans un fichier binaire.

    //Sauvegarde 1 :
    if (fwrite(pSauvegarde1, sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (Sauvegarde 1).\n");
    }
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        if (fwrite(&plateauMonopoly1[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 1).\n", i);
        }
    }
    for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        if (fwrite(&listeJoueur1[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Joueur numero %d de la sauvegarde 1).\n", i);
        }
    }
    if (fwrite(listeVariable1, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (liste des variables de la sauvegarde 1).\n");
    }
    if (fwrite(&infoChanceCaisse[0], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 1).\n");
    }


    //Sauvegarde 2 :
    if (fwrite(pSauvegarde2, sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (Sauvegarde 2).\n");
    }
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        if (fwrite(&plateauMonopoly2[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 2).\n", i);
        }
    }
    for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        if (fwrite(&listeJoueur2[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Joueur numero %d de la sauvegarde 2).\n", i);
        }
    }
    if (fwrite(listeVariable2, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (liste des variables de la sauvegarde 2).\n");
    }
    if (fwrite(&infoChanceCaisse[1], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 2).\n");
    }


    //Sauvegarde 3 :
    if (fwrite(pSauvegarde3, sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (Sauvegarde 3).\n");
    }
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        if (fwrite(&plateauMonopoly3[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 3).\n", i);
        }
    }
    for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        if (fwrite(&listeJoueur3[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Joueur numero %d de la sauvegarde 3).\n", i);
        }
    }
    if (fwrite(listeVariable3, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (liste des variables de la sauvegarde 3).\n");
    }
    if (fwrite(&infoChanceCaisse[2], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 3).\n");
    }

    fclose(pfichier);
    pfichier = NULL;
}
