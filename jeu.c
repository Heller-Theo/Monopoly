#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fonction.h"
#include "structure.h"
#include "initialisation.h"


int jeuMonopoly(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], CarteChanceCaisse infoChanceCaisse, int listeVariable[], int premierJoueur) {

    int joueur = 0;
    int resultatDe = 0;
    int doubleDe = 0;
    int retour = 0;

    int regleDepart = listeVariable[0];
    int regleParcGratuit = listeVariable[1];
    int doubleDeSuccessif = listeVariable[2];
    int nombreJoueur = listeVariable[3];
    int carteLiberePrisonChance = listeVariable[4];
    int carteLiberePrisonCaisse = listeVariable[5];
    int nombreMaisonRestante = listeVariable[6];
    int nombreHotelRestant = listeVariable[7];
    int potCommun = listeVariable[8];

    if (premierJoueur == 0) {
        choixRegleSupplementaire(&regleDepart, &regleParcGratuit);
        printf("Combien de joueur etes vous ? (2 a 6 joueurs possible)\n");
        do {
            scanf(" %d", &nombreJoueur);
        } while (nombreJoueur != 2 && nombreJoueur != 3 && nombreJoueur != 4 && nombreJoueur != 5 && nombreJoueur != 6);

        for (int i = NOMBRE_MAX_JOUEUR; i > nombreJoueur; i--) {
            listeJoueur[i].argentJoueur = 0;
        }

        viderBuffer();
        for (int i = 1; i <= nombreJoueur; i++) {
            printf("Quel est le nom du joueur %d:\n>", i);
            fgets(listeJoueur[i].nomJoueur, TAILLE_MAX_NOM_JOUEUR, stdin);
            listeJoueur[i].nomJoueur[strlen(listeJoueur[i].nomJoueur) - 1] = '\0';
        }
    }

    for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        printf("Joueur %d:", i);
        printf("%s\n", listeJoueur[i].nomJoueur);
    }


    while (nombreJoueur > 1) {
        for (joueur = 1; joueur <= nombreJoueur; joueur++) {

            if (retour == 0 && premierJoueur != 0) {
                joueur = premierJoueur;
                retour = 1;
            }

            if (retour == 0 && premierJoueur == 0) {
                joueur = rand() % nombreJoueur + 1;
                retour = 1;
            }


            if (!checkJeu(plateauMonopoly, listeJoueur, &nombreMaisonRestante, &nombreHotelRestant)) {
                listeVariable[0] = regleDepart;
                listeVariable[1] = regleParcGratuit;
                listeVariable[2] = doubleDeSuccessif;
                listeVariable[3] = nombreJoueur;
                listeVariable[4] = carteLiberePrisonChance;
                listeVariable[5] = carteLiberePrisonCaisse;
                listeVariable[6] = nombreHotelRestant;
                listeVariable[7] = nombreHotelRestant;
                listeVariable[8] = potCommun;
                return joueur;
            }

            printf("------------------------------------------------------------------------------\n\n\n");

            affichagePlateau(plateauMonopoly, listeJoueur, nombreJoueur);

            printf("C'est a %s de jouer (Joueur %d).\n", listeJoueur[joueur].nomJoueur, joueur);

            tirage :

            if (listeJoueur[joueur].prison == 0) {

                tirageDeuxDe(&resultatDe, &doubleDe);
                scanf("%d",&resultatDe);
                scanf("%d", &doubleDe);

                if (resultatDe + listeJoueur[joueur].caseJoueur >= TAILLE_PLATEAU) {
                    if (!regleDepart || resultatDe + listeJoueur[joueur].caseJoueur != TAILLE_PLATEAU) {
                        listeJoueur[joueur].argentJoueur += plateauMonopoly[0].prixTerrainNu;
                        printf("Vous recuperez %d francs pour avoir fait un tour complet.\n", plateauMonopoly[0].prixTerrainNu);
                    }
                }

                listeJoueur[joueur].caseJoueur = (listeJoueur[joueur].caseJoueur + resultatDe) % TAILLE_PLATEAU;

                sortiePrison :

                if (doubleDe && doubleDeSuccessif >= 2) {
                    printf("Vous avez fait 3 doubles d'affile, vous allez en prison.\n");
                    doubleDeSuccessif = 0;
                    goto prison;
                }

                deplacementChanceCaisse :

                printf("Vous etes tombe sur la case %s numero: %d\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, listeJoueur[joueur].caseJoueur);
            }


            switch (plateauMonopoly[listeJoueur[joueur].caseJoueur].typeCase) {

                case 0: //Case Depart
                {
                    caseDepart:
                    if (regleDepart) {
                        printf("Bravo, vous gagnez 2 * %d car vous etes tombe sur la case Depart !\n", plateauMonopoly[0].prixTerrainNu);
                        listeJoueur[joueur].argentJoueur += 2 * plateauMonopoly[0].prixTerrainNu;
                    }
                    break;
                }
                case 1: //Propriété
                {
                    if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == 0) {
                        if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase) {
                            int choix = 0;
                            printf("Voulez-vous acheter la case %s pour %d francs ?\n>", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase);
                            do {
                                scanf(" %d", &choix);
                            } while (choix != 0 && choix != 1);
                            if (choix) {
                                plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur = joueur;
                                listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase;
                                if (monopoleCase(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].numeroGroupeCase, joueur)) {
                                    printf("Felicitation, vous avez obtenue un monopole !\n");
                                }
                            }
                        }
                        else {
                            printf("Vous n'avez pas assez d'argent pour acheter ce terrain.\n");
                        }
                    }
                    else {
                        if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == joueur) {
                            printf("Vous etes sur votre propriete: %s\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase);
                        }
                        else {
                            if (plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreHotel + plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison == 0) {
                                if (monopoleCase(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].numeroGroupeCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)) {
                                    printf("Vous payez 2 * %d au joueur %d car il a un monopole sur cette case.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur);
                                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu * 2;
                                    listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu * 2;
                                }
                                else {
                                    printf("Vous payez %d au joueur %d car il possede cette case.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur);
                                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                                    listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                                }
                            }
                            else {
                                if (plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison > 0) {
                                    int prix = plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison];
                                    printf("Vous payez %d au joueur %d car il a %d maison sur cette case.\n", prix, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur, plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison);
                                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison];
                                    listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison];
                                }
                                if (plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreHotel == 1) {
                                    printf("Vous payez %d au joueur %d car il a un Hotel sur cette case.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5], plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur);
                                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5];
                                    listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5];
                                }
                            }
                        }
                    }
                    break;
                }
                case 2: //Prison
                {
                    if (listeJoueur[joueur].prison) {
                        int choix = 0;
                        printf("Vous etes en prison, que voulez vous faire :\n");
                        printf("1: Tenter de faire un double ?\n");
                        printf("2: Payer %d pour sortir au prochain tour ?\n", plateauMonopoly[10].prixTerrainNu);
                        if (listeJoueur[joueur].carteLiberePrison) {
                            printf("3: Utilisez votre carte de liberation de prison ?\n");
                        }

                        if (listeJoueur[joueur].carteLiberePrison) {
                            do {
                                scanf(" %d", &choix);
                            } while (choix != 1 && choix != 2 && choix != 3);
                        }
                        else {
                            do {
                                scanf(" %d", &choix);
                            } while (choix != 1 && choix != 2);
                        }

                        if (choix == 1) {
                            tirageDeuxDe(&resultatDe, &doubleDe);
                            if (doubleDe) {
                                printf("Vous avez reussi a faire un double, vous pouvez donc sortir de prison.\n");
                                listeJoueur[joueur].prison = 0;
                                goto sortiePrison;
                            }
                            else {
                                listeJoueur[joueur].prison += 1;
                                if (listeJoueur[joueur].prison >= 4) {
                                    listeJoueur[joueur].prison = 0;
                                    printf("Vous avez echoue vos 3 tentatives de double.\n");
                                    printf("Vous payez donc %d francs a la banque et pourrez jouer au prochain tour.\n", plateauMonopoly[10].prixTerrainNu);
                                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[10].prixTerrainNu;
                                }
                                else {
                                    printf("Vous n'avez pas reussi a faire de double, vous restez donc en prison.\n");
                                }
                            }
                        }
                        else {
                            if (choix == 2) {
                                printf("Vous payez donc %d a la banque et pourrez jouer au prochain tour.\n", plateauMonopoly[10].prixTerrainNu);
                                listeJoueur[joueur].argentJoueur -= plateauMonopoly[10].prixTerrainNu;
                                listeJoueur[joueur].prison = 0;
                            }
                            else {
                                listeJoueur[joueur].carteLiberePrison -= 1;
                                if (carteLiberePrisonChance == 0) {
                                    carteLiberePrisonChance += 1;
                                }
                                else {
                                    carteLiberePrisonCaisse += 1;
                                }
                                listeJoueur[joueur].prison = 0;
                                goto tirage;
                            }
                        }
                    }
                    else {
                        printf("Vous faites une simple visite de la Prison.\n");
                    }
                    break;
                }
                case 3: //Compagnie d'eau et d'électricité
                {
                    if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == 0) {
                        if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase) {
                            int choix = 0;
                            printf("Voulez-vous acheter la case %s pour %d francs ?\n>", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase);
                            do {
                                scanf(" %d", &choix);
                            } while (choix != 0 && choix != 1);
                            if (choix) {
                                plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur = joueur;
                                listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase;
                                if (monopoleCase(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].numeroGroupeCase, joueur)) {
                                    printf("Felicitation, vous avez obtenue un monopole !\n");
                                }
                            }
                        }
                        else {
                            printf("Vous n'avez pas assez d'argent pour acheter ce terrain.\n");
                        }
                    }
                    else {
                        if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == joueur) {
                            printf("Vous etes sur votre propriete\n");
                        }
                        else {
                            if (monopoleCase(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].numeroGroupeCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)) {
                                printf("Vous payez %d * %d francs au joueur %d car il possede le monopole de cette case.\n", resultatDe, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1], plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur);
                                listeJoueur[joueur].argentJoueur -= resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1];
                                listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1];
                            }
                            else {
                                printf("Vous payez %d * %d francs au joueur %d car il possede cette case.\n", resultatDe, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0], plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur);
                                listeJoueur[joueur].argentJoueur -= resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0];
                                listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0];
                            }
                        }
                    }
                    break;
                }
                case 4: //Impot sur le revenu
                {
                    printf("Vous payez %d d'impot sur le revenu.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu);
                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                    potCommun += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                    break;
                }
                case 5: //Taxe de luxe
                {
                    printf("Vous payez %d de taxe de luxe.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu);
                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                    potCommun += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                    break;
                }
                case 6: //Chance
                {
                    debutChance :
                    infoChanceCaisse.numeroCarteChance = (infoChanceCaisse.numeroCarteChance + 1) % 16;
                    switch (infoChanceCaisse.ordreCarteChance[infoChanceCaisse.numeroCarteChance]) {
                        case 1:
                        {
                            printf("Vous avez gagne le prix de mots croises et recevez %d francs.\n", infoChanceCaisse.prixCarteChance[0]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteChance[0];
                            break;
                        }
                        case 2:
                        {
                            printf("Amende pour exces de vitesse, vous payez %d francs.\n", infoChanceCaisse.prixCarteChance[1]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteChance[1];
                            potCommun += infoChanceCaisse.prixCarteChance[1];
                            break;
                        }
                        case 3:
                        {
                            printf("La banque vous verse une dividende de %d francs.\n", infoChanceCaisse.prixCarteChance[2]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteChance[2];
                            break;
                        }
                        case 4:
                        {
                            printf("Votre immeuble et votre pret vous rapportent %d francs.\n", infoChanceCaisse.prixCarteChance[3]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteChance[3];
                            break;
                        }
                        case 5:
                        {
                            printf("Amende pour ivresse, vous payez %d francs.\n", infoChanceCaisse.prixCarteChance[4]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteChance[4];
                            potCommun += infoChanceCaisse.prixCarteChance[4];
                            break;
                        }
                        case 6:
                        {
                            printf("Vos frais de scolarite vous coutent %d francs.\n", infoChanceCaisse.prixCarteChance[5]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteChance[5];
                            potCommun += infoChanceCaisse.prixCarteChance[5];
                            break;
                        }
                        case 7:
                        {
                            printf("Faites des reparations dans toutes vos maisons :\n");
                            printf("%d francs / Maison\n", infoChanceCaisse.prixCarteChance[6]);
                            printf("%d francs / Hotel\n", infoChanceCaisse.prixCarteChance[7]);

                            printf("Vous payez %d francs pour vos maisons car vous en avez %d.\n", infoChanceCaisse.prixCarteChance[6] * nombreMaisonJoueur(plateauMonopoly, joueur), nombreMaisonJoueur(plateauMonopoly, joueur));
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteChance[6] * nombreMaisonJoueur(plateauMonopoly, joueur);
                            potCommun += infoChanceCaisse.prixCarteChance[6] * nombreMaisonJoueur(plateauMonopoly, joueur);

                            printf("Vous payez %d francs pour vos hotels car vous en avez %d.\n", infoChanceCaisse.prixCarteChance[7] * nombreHotelJoueur(plateauMonopoly, joueur), nombreHotelJoueur(plateauMonopoly, joueur));
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteChance[7] * nombreHotelJoueur(plateauMonopoly, joueur);
                            potCommun += infoChanceCaisse.prixCarteChance[7] * nombreHotelJoueur(plateauMonopoly, joueur);
                            break;
                        }
                        case 8:
                        {
                            printf("Vous etes impose pour les reparations de voirie a raison de :\n");
                            printf("%d francs / Maison\n", infoChanceCaisse.prixCarteChance[8]);
                            printf("%d francs / Hotel\n", infoChanceCaisse.prixCarteChance[9]);

                            printf("Vous payez %d francs pour vos maisons car vous en avez %d.\n", infoChanceCaisse.prixCarteChance[8] * nombreMaisonJoueur(plateauMonopoly, joueur), nombreMaisonJoueur(plateauMonopoly, joueur));
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteChance[8] * nombreMaisonJoueur(plateauMonopoly, joueur);
                            potCommun += infoChanceCaisse.prixCarteChance[8] * nombreMaisonJoueur(plateauMonopoly, joueur);

                            printf("Vous payez %d francs pour vos hotels car vous en avez %d.\n", infoChanceCaisse.prixCarteChance[9] * nombreHotelJoueur(plateauMonopoly, joueur), nombreHotelJoueur(plateauMonopoly, joueur));
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteChance[9] * nombreHotelJoueur(plateauMonopoly, joueur);
                            potCommun += infoChanceCaisse.prixCarteChance[9] * nombreHotelJoueur(plateauMonopoly, joueur);
                            break;
                        }
                        case 9:
                        {
                            printf("Avancez jusqu'a la case Depart.\n");
                            listeJoueur[joueur].caseJoueur = 0;
                            goto caseDepart;
                        }
                        case 10:
                        {
                            printf("Rendez vous a la Rue de la Paix.\n");
                            listeJoueur[joueur].caseJoueur = 39;
                            goto deplacementChanceCaisse;
                        }
                        case 11:
                        {
                            printf("Allez en prison.\n");
                            goto prison;
                        }
                        case 12:
                        {
                            printf("Allez a la gare de Lyon.\n");
                            if (listeJoueur[joueur].caseJoueur > 15) {
                                listeJoueur[joueur].argentJoueur += plateauMonopoly[0].prixTerrainNu;
                                printf("Vous recuperez %d francs pour avoir fait un tour complet.\n", plateauMonopoly[0].prixTerrainNu);
                            }
                            listeJoueur[joueur].caseJoueur = 15;
                            goto deplacementChanceCaisse;
                        }
                        case 13:
                        {
                            printf("Rendez vous Avenue Henri-Martin.\n");
                            if (listeJoueur[joueur].caseJoueur > 24) {
                                listeJoueur[joueur].argentJoueur += plateauMonopoly[0].prixTerrainNu;
                                printf("Vous recuperez %d francs pour avoir fait un tour complet.\n", plateauMonopoly[0].prixTerrainNu);
                            }
                            listeJoueur[joueur].caseJoueur = 24;
                            goto deplacementChanceCaisse;
                        }
                        case 14:
                        {
                            printf("Avancez au Boulevard de la Villette.\n");
                            if (listeJoueur[joueur].caseJoueur > 11) {
                                listeJoueur[joueur].argentJoueur += plateauMonopoly[0].prixTerrainNu;
                                printf("Vous recuperez %d francs pour avoir fait un tour complet.\n", plateauMonopoly[0].prixTerrainNu);
                            }
                            listeJoueur[joueur].caseJoueur = 11;
                            goto deplacementChanceCaisse;
                        }
                        case 15:
                        {
                            printf("Reculez de 3 cases.\n");
                            if (listeJoueur[joueur].caseJoueur > 3) {
                                listeJoueur[joueur].caseJoueur = listeJoueur[joueur].caseJoueur - 3;
                            }
                            else {
                                listeJoueur[joueur].caseJoueur = 39;
                            }
                            goto deplacementChanceCaisse;
                        }
                        case 16:
                        {
                            if (carteLiberePrisonChance) {
                                printf("Vous recevez une carte vous etes libere de prison\n");
                                listeJoueur[joueur].carteLiberePrison += 1;
                                carteLiberePrisonChance = 0;
                            }
                            else {
                                goto debutChance;
                            }
                            break;
                        }
                        default:
                        {
                            printf("---------------PROBLEME2---------------\n");
                            break;
                        }
                    }
                    break;
                }
                case 7: //Caisse de communauté
                {
                    debutCaisse :
                    infoChanceCaisse.numeroCarteCaisse = (infoChanceCaisse.numeroCarteCaisse + 1) % 16;
                    switch (infoChanceCaisse.ordreCarteCaisse[infoChanceCaisse.numeroCarteCaisse]) {
                        case 1:
                        {
                            printf("Vous heritez %d francs.\n", infoChanceCaisse.prixCarteCaisse[0]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[0];
                            break;
                        }
                        case 2:
                        {
                            printf("Les contributions vous remboursent la somme de %d francs.\n", infoChanceCaisse.prixCarteCaisse[1]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[1];
                            break;
                        }
                        case 3:
                        {
                            printf("Payez a l'hopital %d francs.\n", infoChanceCaisse.prixCarteCaisse[2]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteCaisse[2];
                            potCommun += infoChanceCaisse.prixCarteCaisse[2];
                            break;
                        }
                        case 4:
                        {
                            printf("Payez votre police d'assurance s'elevant a %d francs.\n", infoChanceCaisse.prixCarteCaisse[3]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteCaisse[3];
                            potCommun += infoChanceCaisse.prixCarteCaisse[3];
                            break;
                        }
                        case 5:
                        {
                            printf("La vente de votre stock vous rapporte %d francs.\n", infoChanceCaisse.prixCarteCaisse[4]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[4];
                            break;
                        }
                        case 6:
                        {
                            printf("Erreur de la banque en votre faveur, recevez %d francs.\n", infoChanceCaisse.prixCarteCaisse[5]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[5];
                            break;
                        }
                        case 7:
                        {
                            printf("Recevez votre interet sur l'emprunt a 7 pourcents: %d francs.\n", infoChanceCaisse.prixCarteCaisse[6]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[6];
                            break;
                        }
                        case 8:
                        {
                            printf("Recevez votre revenu annuel: %d francs.\n", infoChanceCaisse.prixCarteCaisse[7]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[7];
                            break;
                        }
                        case 9:
                        {
                            printf("Payez la note du medecin: %d francs.\n", infoChanceCaisse.prixCarteCaisse[8]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteCaisse[8];
                            potCommun += infoChanceCaisse.prixCarteCaisse[8];
                            break;
                        }
                        case 10:
                        {
                            printf("Vous avez gagne le deuxieme prix de beaute, recevez %d francs.\n", infoChanceCaisse.prixCarteCaisse[9]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[9];
                            break;
                        }
                        case 11:
                        {
                            printf("C'est votre anniversaire, chaque joueur doit vous donner %d francs.\n", infoChanceCaisse.prixCarteCaisse[10]);
                            for(int i = 1; i <= nombreJoueur; i++) {
                                listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[10];
                                listeJoueur[i].argentJoueur -= infoChanceCaisse.prixCarteCaisse[10];
                            }
                            break;
                        }
                        case 12:
                        {
                            int choix = 0;
                            printf("Payez une amende de %d francs ou bien tirez une carte Chance: \n", infoChanceCaisse.prixCarteCaisse[11]);
                            printf("1: Payez l'amende\n");
                            printf("2: Tirer une carte Chance\n>");

                            do {
                                scanf(" %d", &choix);
                            } while (choix != 1 && choix != 2);

                            if (choix == 1) {
                                printf("Vous payez donc l'amende de %d francs.\n", infoChanceCaisse.prixCarteCaisse[11]);
                                listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteCaisse[11];
                                potCommun += infoChanceCaisse.prixCarteCaisse[11];
                            }
                            else {
                                printf("Vous tirez donc une carte Chance.\n");
                                goto debutChance;
                            }
                            break;
                        }
                        case 13:
                        {
                            printf("Allez en prison.\n");
                            goto prison;
                        }
                        case 14:
                        {
                            printf("Retournez a Belleville.\n");
                            listeJoueur[joueur].caseJoueur = 1;
                            goto deplacementChanceCaisse;
                        }
                        case 15:
                        {
                            printf("Placez vous sur la case Depart.\n");
                            listeJoueur[joueur].caseJoueur = 0;
                            goto caseDepart;
                        }
                        case 16:
                        {
                            if (carteLiberePrisonCaisse) {
                                printf("Vous recevez une carte vous etes libere de prison\n");
                                listeJoueur[joueur].carteLiberePrison += 1;
                                carteLiberePrisonCaisse = 0;
                            }
                            else {
                                goto debutCaisse;
                            }
                            break;
                        }
                        default:
                        {
                            printf("---------------PROBLEME3---------------\n");
                            break;
                        }
                    }
                    break;
                }
                case 8: //Park Gratuit
                {
                    if (regleParcGratuit) {
                        printf("Felicitation vous recuperez %d francs des differentes taxes.\n", potCommun);
                        listeJoueur[joueur].argentJoueur += potCommun;
                        potCommun = 0;
                    }
                    break;
                }
                case 9: //Allez en Prison
                {
                    prison:
                    listeJoueur[joueur].caseJoueur = 10;
                    listeJoueur[joueur].prison = 1;
                    printf("Vous etes donc sur la case prison.\n");
                    break;
                }
                case 10: //Gare
                {
                    if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == 0) {
                        if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase) {
                            int choix = 0;
                            printf("Voulez-vous acheter la case %s pour %d francs ?\n>", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase);
                            do {
                                scanf(" %d", &choix);
                            } while (choix != 0 && choix != 1);
                            if (choix) {
                                plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur = joueur;
                                listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase;
                            }
                        }
                        else {
                            printf("Vous n'avez pas assez d'argent pour acheter ce terrain.\n");
                        }
                    }
                    else {
                        if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == joueur) {
                            printf("Vous etes sur votre propriete: %s\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase);
                        }
                        else {
                            int possesseur = plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur;
                            int argent = plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[nombreGareJoueur(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)];
                            listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[nombreGareJoueur(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)];
                            listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[nombreGareJoueur(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)];
                            printf("Vous payez %d francs au joueur %d car il possede %d gare(s).\n", argent, possesseur, nombreGareJoueur(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur) );
                        }
                    }
                    break;
                }
                default:
                {
                    printf("---------------PROBLEME---------------\n");
                    break;
                }
            }

            printf("Le joueur %d possede %d francs.\n", joueur, listeJoueur[joueur].argentJoueur);

            if (doubleDe && listeJoueur[joueur].prison == 0) {
                doubleDeSuccessif += 1;
                printf("Vous avez fait un double, vous pouvez donc rejouer !\n");
                goto tirage;
            }
            doubleDeSuccessif = 0;

        }
    }
}

