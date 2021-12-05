#include <stdio.h>
#include <stdlib.h>
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

        printf("\nCombien de joueur etes vous ? (2 a 6 joueurs possible)\n");

        do {
            verificationSaisie(&nombreJoueur);
            if (nombreJoueur < 1 || nombreJoueur > 6) {
                printf("Veuillez saisir un nombre de joueur valide.\n");
            }
        } while (nombreJoueur < 1 || nombreJoueur > 6);

        for (int i = NOMBRE_MAX_JOUEUR; i > nombreJoueur; i--) {
            listeJoueur[i].argentJoueur = 0;
        }

        for (int i = 1; i <= nombreJoueur; i++) {
            unsigned int len = 0;
            printf("Quel est le nom du joueur %d (%d caracteres max):\n>", i, TAILLE_MAX_NOM_JOUEUR-1);
            len = strlen(fgets(listeJoueur[i].nomJoueur, TAILLE_MAX_NOM_JOUEUR, stdin));
            if (len >= 10) {
                viderBuffer();
            }
            else {
                listeJoueur[i].nomJoueur[strlen(listeJoueur[i].nomJoueur) - 1] = '\0';
            }
        }
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
                listeVariable[6] = nombreMaisonRestante;
                listeVariable[7] = nombreHotelRestant;
                listeVariable[8] = potCommun;
                return joueur;
            }

            listeVariable[0] = regleDepart;
            listeVariable[1] = regleParcGratuit;
            listeVariable[2] = doubleDeSuccessif;
            listeVariable[3] = nombreJoueur;
            listeVariable[4] = carteLiberePrisonChance;
            listeVariable[5] = carteLiberePrisonCaisse;
            listeVariable[6] = nombreMaisonRestante;
            listeVariable[7] = nombreHotelRestant;
            listeVariable[8] = potCommun;


            printf("------------------------------------------------------------------------------\n\n");


            affichagePlateau(plateauMonopoly, listeJoueur, listeVariable);

            printf("\nC'est a %s de jouer (Joueur %d).\n", listeJoueur[joueur].nomJoueur, joueur);

            tirage :

            if (listeJoueur[joueur].prison == 0) {

                tirageDeuxDe(&resultatDe, &doubleDe);
                //verificationSaisie(&resultatDe);
                //verificationSaisie(&doubleDe);

                if (resultatDe + listeJoueur[joueur].caseJoueur >= TAILLE_PLATEAU) {
                    if (!regleDepart || resultatDe + listeJoueur[joueur].caseJoueur != TAILLE_PLATEAU) {
                        listeJoueur[joueur].argentJoueur += plateauMonopoly[0].prixTerrainNu;
                        printf("Vous recuperez %d francs pour avoir fait un tour complet.\n", plateauMonopoly[0].prixTerrainNu);
                    }
                }

                sortiePrison :

                listeJoueur[joueur].caseJoueur = (listeJoueur[joueur].caseJoueur + resultatDe) % TAILLE_PLATEAU;


                if (doubleDe && doubleDeSuccessif >= 2) {
                    printf("Vous avez fait 3 doubles d'affile, vous allez en prison.\n");
                    doubleDeSuccessif = 0;
                    goto prison;
                }

                deplacementChanceCaisse :

                printf("Vous etes tombe sur la case %s, numero %d\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, listeJoueur[joueur].caseJoueur);
            }


            switch (plateauMonopoly[listeJoueur[joueur].caseJoueur].typeCase) {

                case 0: //Case Depart
                {
                    caseDepart:
                    if (regleDepart) {
                        printf("\nBravo, vous gagnez 2 * %d car vous etes tombe sur la case Depart !\n", plateauMonopoly[0].prixTerrainNu);
                        listeJoueur[joueur].argentJoueur += 2 * plateauMonopoly[0].prixTerrainNu;
                    }
                    break;
                }
                case 1: //Propriété
                {
                    if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == 0) {
                        if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase) {
                            int choix = 0;
                            printf("\nVoulez-vous acheter la case %s pour %d francs ?\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase);

                            do {
                                verificationSaisie(&choix);
                                if (choix != 0 && choix != 1) {
                                    printf("Veuillez saisir 0 pour non ou 1 pour oui.\n");
                                }
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
                            printf("\nVous etes sur votre propriete: %s\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase);
                        }
                        else {
                            if (plateauMonopoly[listeJoueur[joueur].caseJoueur].hypotheque == 0) {
                                if (plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreHotel + plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison == 0) {
                                    if (monopoleCase(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].numeroGroupeCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)) {
                                        printf("\nVous payez 2 * %d a %s car ce joueur a un monopole sur cette case.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu, listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                        listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu * 2;
                                        listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu * 2;
                                    }
                                    else {
                                        printf("\nVous payez %d a %s car ce joueur possede cette case.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu, listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                        listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                                        listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                                    }
                                }
                                else {
                                    if (plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison > 0) {
                                        int prix = plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison];
                                        printf("\nVous payez %d a %s car ce joueur a %d maison sur cette case.\n", prix, listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur, plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison);
                                        listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison];
                                        listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison];
                                    }
                                    if (plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreHotel == 1) {
                                        printf("\nVous payez %d a %s car ce joueur a un Hotel sur cette case.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5], listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                        listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5];
                                        listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5];
                                    }
                                }
                            }
                            else {
                                printf("\nCette propriete est hypotheque donc vous ne payez aucun loyer.\n");
                            }
                        }
                    }
                    break;
                }
                case 2: //Prison
                {
                    debutPrison :
                    if (listeJoueur[joueur].prison) {
                        int choix = 0;
                        printf("\nVous etes en prison, que voulez vous faire :\n");
                        printf("1: Tenter de faire un double ?\n");
                        printf("2: Payer %d pour sortir au prochain tour ?\n", plateauMonopoly[10].prixTerrainNu);
                        printf("3: Utilisez votre carte de liberation de prison ?\n");
                        printf("4: Acheter une carte de liberation de prison a un autre joueur ?\n");


                        do {
                            verificationSaisie(&choix);
                            if (choix != 1 && choix != 2 && choix != 3 && choix != 4) {
                                printf("Veuillez saisir un entier correct.\n");
                            }
                        } while (choix != 1 && choix != 2 && choix != 3 && choix != 4);


                        if (choix == 1) {
                            tirageDeuxDe(&resultatDe, &doubleDe);
                            if (doubleDe) {
                                printf("Vous avez reussi a faire un double, vous pouvez donc sortir de prison.\n");
                                listeJoueur[joueur].prison = 0;
                                doubleDe = 0;
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
                                if (choix == 3) {
                                    if (listeJoueur[joueur].carteLiberePrison >= 1) {
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
                                    else {
                                        printf("Vous n'avez pas de carte pour vous liberer de prison.\n");
                                        goto debutPrison;
                                    }
                                }
                                else {
                                    if (choix == 4) {
                                        achatCarteLibere(listeJoueur, listeVariable, joueur);
                                        goto debutPrison;
                                    }
                                }
                            }
                        }
                    }
                    else {
                        printf("\nVous faites une simple visite de la Prison.\n");
                    }
                    break;
                }
                case 3: //Compagnie d'eau et d'électricité
                {
                    if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == 0) {
                        if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase) {
                            int choix = 0;
                            printf("\nVoulez-vous acheter la case %s pour %d francs ?\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase);

                            do {
                                verificationSaisie(&choix);
                                if (choix != 0 && choix != 1) {
                                    printf("Veuillez saisir 0 pour non ou 1 pour oui.\n");
                                }
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
                            printf("\nVous etes sur votre propriete\n");
                        }
                        else {
                            if (plateauMonopoly[listeJoueur[joueur].caseJoueur].hypotheque == 0) {
                                if (monopoleCase(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].numeroGroupeCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)) {
                                    printf("\nVous payez %d * %d francs a %s car ce joueur possede le monopole de cette case.\n", resultatDe, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1], listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                    listeJoueur[joueur].argentJoueur -= resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1];
                                    listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1];
                                }
                                else {
                                    printf("\nVous payez %d * %d francs a %s car ce joueur possede cette case.\n", resultatDe, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0], listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                    listeJoueur[joueur].argentJoueur -= resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0];
                                    listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0];
                                }
                            }
                            else {
                                printf("\nCette propriete est hypotheque donc vous ne payez aucun loyer.\n");
                            }

                        }
                    }
                    break;
                }
                case 4: //Impot sur le revenu
                {
                    printf("\nVous payez %d d'impot sur le revenu.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu);
                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                    potCommun += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                    break;
                }
                case 5: //Taxe de luxe
                {
                    printf("\nVous payez %d de taxe de luxe.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu);
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
                            printf("\nVous avez gagne le prix de mots croises et recevez %d francs.\n", infoChanceCaisse.prixCarteChance[0]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteChance[0];
                            break;
                        }
                        case 2:
                        {
                            printf("\nAmende pour exces de vitesse, vous payez %d francs.\n", infoChanceCaisse.prixCarteChance[1]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteChance[1];
                            potCommun += infoChanceCaisse.prixCarteChance[1];
                            break;
                        }
                        case 3:
                        {
                            printf("\nLa banque vous verse une dividende de %d francs.\n", infoChanceCaisse.prixCarteChance[2]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteChance[2];
                            break;
                        }
                        case 4:
                        {
                            printf("\nVotre immeuble et votre pret vous rapportent %d francs.\n", infoChanceCaisse.prixCarteChance[3]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteChance[3];
                            break;
                        }
                        case 5:
                        {
                            printf("\nAmende pour ivresse, vous payez %d francs.\n", infoChanceCaisse.prixCarteChance[4]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteChance[4];
                            potCommun += infoChanceCaisse.prixCarteChance[4];
                            break;
                        }
                        case 6:
                        {
                            printf("\nVos frais de scolarite vous coutent %d francs.\n", infoChanceCaisse.prixCarteChance[5]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteChance[5];
                            potCommun += infoChanceCaisse.prixCarteChance[5];
                            break;
                        }
                        case 7:
                        {
                            printf("\nFaites des reparations dans toutes vos maisons :\n");
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
                            printf("\nVous etes impose pour les reparations de voirie a raison de :\n");
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
                            printf("\nAvancez jusqu'a la case Depart.\n");
                            listeJoueur[joueur].caseJoueur = 0;
                            goto caseDepart;
                        }
                        case 10:
                        {
                            printf("\nRendez vous a la Rue de la Paix.\n");
                            listeJoueur[joueur].caseJoueur = 39;
                            goto deplacementChanceCaisse;
                        }
                        case 11:
                        {
                            printf("\nAllez en prison.\n");
                            goto prison;
                        }
                        case 12:
                        {
                            printf("\nAllez a la gare de Lyon.\n");
                            if (listeJoueur[joueur].caseJoueur > 15) {
                                listeJoueur[joueur].argentJoueur += plateauMonopoly[0].prixTerrainNu;
                                printf("Vous recuperez %d francs pour avoir fait un tour complet.\n", plateauMonopoly[0].prixTerrainNu);
                            }
                            listeJoueur[joueur].caseJoueur = 15;
                            goto deplacementChanceCaisse;
                        }
                        case 13:
                        {
                            printf("\nRendez vous Avenue Henri-Martin.\n");
                            if (listeJoueur[joueur].caseJoueur > 24) {
                                listeJoueur[joueur].argentJoueur += plateauMonopoly[0].prixTerrainNu;
                                printf("Vous recuperez %d francs pour avoir fait un tour complet.\n", plateauMonopoly[0].prixTerrainNu);
                            }
                            listeJoueur[joueur].caseJoueur = 24;
                            goto deplacementChanceCaisse;
                        }
                        case 14:
                        {
                            printf("\nAvancez au Boulevard de la Villette.\n");
                            if (listeJoueur[joueur].caseJoueur > 11) {
                                listeJoueur[joueur].argentJoueur += plateauMonopoly[0].prixTerrainNu;
                                printf("Vous recuperez %d francs pour avoir fait un tour complet.\n", plateauMonopoly[0].prixTerrainNu);
                            }
                            listeJoueur[joueur].caseJoueur = 11;
                            goto deplacementChanceCaisse;
                        }
                        case 15:
                        {
                            printf("\nReculez de 3 cases.\n");
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
                                printf("\nVous recevez une carte vous etes libere de prison\n");
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
                            printf("---------------PROBLEME CHANCE---------------\n");
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
                            printf("\nVous heritez %d francs.\n", infoChanceCaisse.prixCarteCaisse[0]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[0];
                            break;
                        }
                        case 2:
                        {
                            printf("\nLes contributions vous remboursent la somme de %d francs.\n", infoChanceCaisse.prixCarteCaisse[1]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[1];
                            break;
                        }
                        case 3:
                        {
                            printf("\nPayez a l'hopital %d francs.\n", infoChanceCaisse.prixCarteCaisse[2]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteCaisse[2];
                            potCommun += infoChanceCaisse.prixCarteCaisse[2];
                            break;
                        }
                        case 4:
                        {
                            printf("\nPayez votre police d'assurance s'elevant a %d francs.\n", infoChanceCaisse.prixCarteCaisse[3]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteCaisse[3];
                            potCommun += infoChanceCaisse.prixCarteCaisse[3];
                            break;
                        }
                        case 5:
                        {
                            printf("\nLa vente de votre stock vous rapporte %d francs.\n", infoChanceCaisse.prixCarteCaisse[4]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[4];
                            break;
                        }
                        case 6:
                        {
                            printf("\nErreur de la banque en votre faveur, recevez %d francs.\n", infoChanceCaisse.prixCarteCaisse[5]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[5];
                            break;
                        }
                        case 7:
                        {
                            printf("\nRecevez votre interet sur l'emprunt a 7 pourcents: %d francs.\n", infoChanceCaisse.prixCarteCaisse[6]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[6];
                            break;
                        }
                        case 8:
                        {
                            printf("\nRecevez votre revenu annuel: %d francs.\n", infoChanceCaisse.prixCarteCaisse[7]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[7];
                            break;
                        }
                        case 9:
                        {
                            printf("\nPayez la note du medecin: %d francs.\n", infoChanceCaisse.prixCarteCaisse[8]);
                            listeJoueur[joueur].argentJoueur -= infoChanceCaisse.prixCarteCaisse[8];
                            potCommun += infoChanceCaisse.prixCarteCaisse[8];
                            break;
                        }
                        case 10:
                        {
                            printf("\nVous avez gagne le deuxieme prix de beaute, recevez %d francs.\n", infoChanceCaisse.prixCarteCaisse[9]);
                            listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[9];
                            break;
                        }
                        case 11:
                        {
                            printf("\nC'est votre anniversaire, chaque joueur doit vous donner %d francs.\n", infoChanceCaisse.prixCarteCaisse[10]);
                            for(int i = 1; i <= nombreJoueur; i++) {
                                listeJoueur[joueur].argentJoueur += infoChanceCaisse.prixCarteCaisse[10];
                                listeJoueur[i].argentJoueur -= infoChanceCaisse.prixCarteCaisse[10];
                            }
                            break;
                        }
                        case 12:
                        {
                            int choix = 0;
                            printf("\nPayez une amende de %d francs ou bien tirez une carte Chance: \n", infoChanceCaisse.prixCarteCaisse[11]);
                            printf("1: Payez l'amende\n");
                            printf("2: Tirer une carte Chance\n");

                            do {
                                verificationSaisie(&choix);
                                if (choix != 1 && choix != 2) {
                                    printf("Veuillez saisir un choix valide.\n");
                                }
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
                            printf("\nAllez en prison.\n");
                            goto prison;
                        }
                        case 14:
                        {
                            printf("\nRetournez a Belleville.\n");
                            listeJoueur[joueur].caseJoueur = 1;
                            goto deplacementChanceCaisse;
                        }
                        case 15:
                        {
                            printf("\nPlacez vous sur la case Depart.\n");
                            listeJoueur[joueur].caseJoueur = 0;
                            goto caseDepart;
                        }
                        case 16:
                        {
                            if (carteLiberePrisonCaisse) {
                                printf("\nVous recevez une carte vous etes libere de prison\n");
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
                            printf("---------------PROBLEME CAISSE---------------\n");
                            break;
                        }
                    }
                    break;
                }
                case 8: //Park Gratuit
                {
                    if (regleParcGratuit) {
                        printf("\nFelicitation vous recuperez %d francs des differentes taxes.\n", potCommun);
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
                    printf("Vous etes donc sur la case Prison, numero %d.\n", listeJoueur[joueur].caseJoueur);
                    break;
                }
                case 10: //Gare
                {
                    if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == 0) {
                        if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase) {
                            int choix = 0;
                            printf("\nVoulez-vous acheter la case %s pour %d francs ?\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase);

                            do {
                                verificationSaisie(&choix);
                                if (choix != 0 && choix != 1) {
                                    printf("Veuillez saisir 0 pour non ou 1 pour oui.\n");
                                }
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
                            printf("\nVous etes sur votre propriete: %s\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase);
                        }
                        else {
                            if (plateauMonopoly[listeJoueur[joueur].caseJoueur].hypotheque == 0) {
                                int possesseur = plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur;
                                int argent = plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[nombreGareJoueur(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)];
                                listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[nombreGareJoueur(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)];
                                listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[nombreGareJoueur(plateauMonopoly, possesseur)];
                                printf("\nVous payez %d francs a %s car ce joueur possede %d gare(s).\n", argent, listeJoueur[possesseur].nomJoueur, nombreGareJoueur(plateauMonopoly, possesseur) );
                            }
                            else {
                                printf("\nCette propriete est hypotheque donc vous ne payez aucun loyer.\n");
                            }
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

            printf("\n%s possede %d francs.\n", listeJoueur[joueur].nomJoueur, listeJoueur[joueur].argentJoueur);

            if (doubleDe && listeJoueur[joueur].prison == 0) {
                doubleDeSuccessif += 1;
                printf("\nVous avez fait un double, vous pouvez donc rejouer !\n");
                goto tirage;
            }
            doubleDeSuccessif = 0;
        }
    }
}

