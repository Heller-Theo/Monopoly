#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include "structure.h"
#include "initialisation.h"


int jeuMonopoly(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], CarteChanceCaisse infoChanceCaisse, int listeVariable[], int premierJoueur) {

    //On déclare nos variables.
    int joueur = 0;
    int resultatDe = 0;
    int doubleDe = 0;
    int retour = 0;
    int joueurRestant = listeVariable[3];

    //On identifie nos variables à sauvegarder à des variables avec des noms plus explicites.
    int regleDepart = listeVariable[0];
    int regleParcGratuit = listeVariable[1];
    int doubleDeSuccessif = listeVariable[2];
    int nombreJoueur = listeVariable[3];
    int carteLiberePrisonChance = listeVariable[4];
    int carteLiberePrisonCaisse = listeVariable[5];
    int nombreMaisonRestante = listeVariable[6];
    int nombreHotelRestant = listeVariable[7];
    int potCommun = listeVariable[8];

    //Si c'est la première fois qu'on lance cette sauvegarde le premierJoueur vaut 0 donc:
    if (premierJoueur == 0) {

        //On choisit les règles à ajouter.
        choixRegleSupplementaire(&regleDepart, &regleParcGratuit);

        //On choisit le nombre de joueurs.
        printf("\nCombien de joueur etes vous ? (2 a 6 joueurs possible)\n");

        do {
            verificationSaisie(&nombreJoueur);
            if (nombreJoueur < 2 || nombreJoueur > 6) {
                printf("Veuillez saisir un nombre de joueur valide.\n");
            }
        } while (nombreJoueur < 2 || nombreJoueur > 6);

        //On retire l'argent des joueurs qui ne joueront pas.
        for (int i = NOMBRE_MAX_JOUEUR; i > nombreJoueur; i--) {
            listeJoueur[i].argentJoueur = 0;
        }

        //On demande aux utilisateurs de choisir un nom pour chaque joueur.
        for (int i = 1; i <= nombreJoueur; i++) {
            unsigned int len = 0;
            printf("\nQuel est le nom du joueur %d (%d caracteres max):\n>", i, TAILLE_MAX_NOM_JOUEUR-1);
            len = strlen(fgets(listeJoueur[i].nomJoueur, TAILLE_MAX_NOM_JOUEUR, stdin));
            if (len >= 10) {
                viderBuffer();
            }
            else {
                listeJoueur[i].nomJoueur[strlen(listeJoueur[i].nomJoueur) - 1] = '\0';
            }
        }
    }

    //Tant qu'il reste plus d'un joueur en jeu :
    while (joueurRestant > 1) {

        for (joueur = 1; joueur <= nombreJoueur; joueur++) {

            //Si le joueur n'est pas en faillite :
            if (listeJoueur[joueur].argentJoueur >= 0) {

                //Si c'est le premier tour mais pas la première fois qu'on lance cette sauvegarde, le premier joueur n'est pas choisit au hasard et vient dans l'ordre.
                if (retour == 0 && premierJoueur != 0) {
                    joueur = premierJoueur;
                    retour = 1;
                }

                //Si c'est le premier tour et la première fois qu'on lance cette sauvegarde, on choisit le premier joueur au hasard.
                if (retour == 0 && premierJoueur == 0) {
                    joueur = rand() % nombreJoueur + 1;
                    retour = 1;
                }

                //Si un joueur a tappé 0 après "Continuer >" alors on enregistre les variables qui ne sont pas dans des structures
                //Et on renvoie le joueur qui commencera le tour suivant quand la sauvegarde sera lancé à nouveau.
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

                //On actualise les variables à chaque tour.
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

                //On affiche le plateau
                affichagePlateau(plateauMonopoly, listeJoueur, listeVariable);

                printf("\nC'est a %s de jouer (Joueur %d).\n", listeJoueur[joueur].nomJoueur, joueur);

                tirage :

                //Si le joueur n'est pas en prison :
                if (listeJoueur[joueur].prison == 0) {

                    //On tire les dés
                    tirageDeuxDe(&resultatDe, &doubleDe);

                    //On récupère l'argent si on a fait un tour complet
                    if (resultatDe + listeJoueur[joueur].caseJoueur >= TAILLE_PLATEAU) {
                        if (!regleDepart || resultatDe + listeJoueur[joueur].caseJoueur != TAILLE_PLATEAU) {
                            listeJoueur[joueur].argentJoueur += plateauMonopoly[0].prixTerrainNu;
                            printf("Vous recuperez %d francs pour avoir fait un tour complet.\n", plateauMonopoly[0].prixTerrainNu);
                        }
                    }

                    //Sortie de prison
                    sortiePrison :

                    //On avance du bon nombre de case
                    listeJoueur[joueur].caseJoueur = (listeJoueur[joueur].caseJoueur + resultatDe) % TAILLE_PLATEAU;

                    //Si on a fait un troisième double d'affilé on va en prison.
                    if (doubleDe && doubleDeSuccessif >= 2) {
                        printf("Vous avez fait 3 doubles d'affile, vous allez en prison.\n");
                        doubleDeSuccessif = 0;
                        goto prison;
                    }

                    //Sortie de déplacement après avoir tiré une carte chance ou caisse de communauté.
                    deplacementChanceCaisse :

                    //On indique sur qu'elle case le joueur est tombé.
                    printf("Vous etes tombe sur la case %s, numero %d\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, listeJoueur[joueur].caseJoueur);

                }

                //Selon le type de case sur laquelle le joueur est tombé on effectue des actions différentes :
                switch (plateauMonopoly[listeJoueur[joueur].caseJoueur].typeCase) {

                    case 0: //Case Depart
                    {
                        //Sortie d'une carte chance ou caisse de communauté qui déplace un joueur sur la case départ.
                        caseDepart:

                        //Si la règle de la case départ double est activé on donne le double d'argent pour un tour complet.
                        if (regleDepart) {
                            printf("\nBravo, vous gagnez 2 * %d car vous etes tombe sur la case Depart !\n", plateauMonopoly[0].prixTerrainNu);
                            listeJoueur[joueur].argentJoueur += 2 * plateauMonopoly[0].prixTerrainNu;
                        }
                        break;
                    }
                    case 1: //Propriété
                    {
                        //Si personne ne possède cette case
                        if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == 0) {

                            //Si on a l'argent pour l'acheter
                            if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase) {

                                //Alors on demande si le joueur veut l'acheter
                                int choix = 0;
                                printf("Voulez-vous acheter la case %s pour %d francs ?\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase);

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

                            //Si cette case vous appartient déjà :
                            if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == joueur) {
                                printf("Vous etes sur votre propriete: %s\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase);
                            }
                            else {

                                //Si cette case n'est pas hypothéquée :
                                if (plateauMonopoly[listeJoueur[joueur].caseJoueur].hypotheque == 0) {

                                    //Si cette case ne possède aucun batiment :
                                    if (plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreHotel + plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison == 0) {

                                        //Si le propriétaire à le monopole sur ce groupe de case :
                                        if (monopoleCase(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].numeroGroupeCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)) {

                                            //Si on a l'argent pour le payer, alors on le paye.
                                            if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu * 2) {
                                                printf("Vous payez 2 * %d a %s car ce joueur a un monopole sur cette case.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu, listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                                listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu * 2;
                                                listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu * 2;
                                            }
                                            //Sinon on tombe en gestion de faillite.
                                            else {
                                                printf("Vous n'avez pas assez d'argent pour payer %s.\n", listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                                failliteJoueur(plateauMonopoly, listeJoueur, joueur, listeJoueur[joueur].caseJoueur, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu * 2, &nombreMaisonRestante, &nombreHotelRestant);
                                            }
                                        }

                                        //Si le propriétaire n'a pas de monopole sur cette case :
                                        else {

                                            //Si on a l'argent pour le payer, alors on le paye.
                                            if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu) {
                                                printf("Vous payez %d a %s car ce joueur possede cette case.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu, listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                                listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                                                listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                                            }
                                            //Sinon on tombe en gestion de faillite.
                                            else {
                                                printf("Vous n'avez pas assez d'argent pour payer %s.\n", listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                                failliteJoueur(plateauMonopoly, listeJoueur, joueur, listeJoueur[joueur].caseJoueur, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu, &nombreMaisonRestante, &nombreHotelRestant);
                                            }
                                        }
                                    }
                                    else {

                                        //Si le propriétaire a des maisons sur cette case :
                                        if (plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison > 0) {

                                            //Si on a l'argent pour le payer, alors on le paye.
                                            int prix = plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison];
                                            if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison]) {
                                                printf("Vous payez %d a %s car ce joueur a %d maison sur cette case.\n", prix, listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur, plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison);
                                                listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison];
                                                listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreMaison];
                                            }
                                            //Sinon on tombe en gestion de faillite.
                                            else {
                                                printf("Vous n'avez pas assez d'argent pour payer %s.\n", listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                                failliteJoueur(plateauMonopoly, listeJoueur, joueur, listeJoueur[joueur].caseJoueur, prix, &nombreMaisonRestante, &nombreHotelRestant);
                                            }
                                        }

                                        //Si le propriétaire a un hotel sur cette case :
                                        if (plateauMonopoly[listeJoueur[joueur].caseJoueur].nombreHotel == 1) {

                                            //Si on a l'argent pour le payer, alors on le paye.
                                            if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5]) {
                                                printf("Vous payez %d a %s car ce joueur a un Hotel sur cette case.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5], listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                                listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5];
                                                listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5];
                                            }
                                            //Sinon on tombe en gestion de faillite.
                                            else {
                                                printf("Vous n'avez pas assez d'argent pour payer %s.\n", listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                                failliteJoueur(plateauMonopoly, listeJoueur, joueur, listeJoueur[joueur].caseJoueur, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[5], &nombreMaisonRestante, &nombreHotelRestant);
                                            }
                                        }
                                    }
                                }
                                else {
                                    printf("Cette propriete est hypotheque donc vous ne payez aucun loyer.\n");
                                }
                            }
                        }
                        break;
                    }
                    case 2: //Prison
                    {
                        //Sortie si on est envoyé en prison depuis la case 30.
                        debutPrison :

                        //Si le joueur est en prison :
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

                            //On peut tenter de faire un double
                            if (choix == 1) {

                                //On tire les dés
                                tirageDeuxDe(&resultatDe, &doubleDe);

                                //Si on fait un double
                                if (doubleDe) {
                                    printf("Vous avez reussi a faire un double, vous pouvez donc sortir de prison.\n");
                                    listeJoueur[joueur].prison = 0;
                                    doubleDe = 0;
                                    goto sortiePrison;
                                }
                                else {

                                    //Sinon on augmente le nombre de tour passé en prison
                                    listeJoueur[joueur].prison += 1;

                                    //Si on a passé trop de tour en prison, on paye une amende et on sort au prochain tour.
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

                                //On peut payer pour sortir au prochain tour
                                if (choix == 2) {
                                    printf("Vous payez donc %d a la banque et pourrez jouer au prochain tour.\n", plateauMonopoly[10].prixTerrainNu);
                                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[10].prixTerrainNu;
                                    listeJoueur[joueur].prison = 0;
                                }
                                else {

                                    //On peut utiliser une carte de liberation de prison
                                    if (choix == 3) {
                                        //Si on a une carte de liberation de prison
                                        if (listeJoueur[joueur].carteLiberePrison >= 1) {
                                            listeJoueur[joueur].carteLiberePrison -= 1;

                                            //On la remet dans le bon paquet
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

                                        //On peut acheter une carte de liberation de prison à un autre joueur.
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
                        //Si personne ne possède cette case
                        if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == 0) {

                            //Si on a assez d'argent pour l'acheter
                            if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase) {

                                //Alors on peut acheter cette case
                                int choix = 0;
                                printf("Voulez-vous acheter la case %s pour %d francs ?\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase);

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

                            //Si cette case nous appartient déjà
                            if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == joueur) {
                                printf("Vous etes sur votre propriete\n");
                            }
                            else {

                                //Si cette case n'est pas hypothéquée
                                if (plateauMonopoly[listeJoueur[joueur].caseJoueur].hypotheque == 0) {

                                    //Si le propriétaire a un monopole sur ce groupe de deux cases
                                    if (monopoleCase(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].numeroGroupeCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)) {

                                        //Si on a l'argent pour le payer, alors on le paye.
                                        if (listeJoueur[joueur].argentJoueur >= resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1]) {
                                            printf("Vous payez %d * %d francs a %s car ce joueur possede le monopole de cette case.\n", resultatDe, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1], listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                            listeJoueur[joueur].argentJoueur -= resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1];
                                            listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1];
                                        }
                                        //Sinon on tombe en gestion de faillite.
                                        else {
                                            printf("Vous n'avez pas assez d'argent pour payer %s.\n", listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                            failliteJoueur(plateauMonopoly, listeJoueur, joueur, listeJoueur[joueur].caseJoueur, resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[1], &nombreMaisonRestante, &nombreHotelRestant);
                                        }
                                    }

                                    //Si le propriétaire n'a pas de monopole sur ce groupe de deux cases
                                    else {

                                        //Si on a l'argent pour le payer, alors on le paye.
                                        if (listeJoueur[joueur].argentJoueur >= resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0]) {
                                            printf("Vous payez %d * %d francs a %s car ce joueur possede cette case.\n", resultatDe, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0], listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                            listeJoueur[joueur].argentJoueur -= resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0];
                                            listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0];
                                        }
                                        //Sinon on tombe en gestion de faillite.
                                        else {
                                            printf("Vous n'avez pas assez d'argent pour payer %s.\n", listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                            failliteJoueur(plateauMonopoly, listeJoueur, joueur, listeJoueur[joueur].caseJoueur, resultatDe * plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[0], &nombreMaisonRestante, &nombreHotelRestant);
                                        }
                                    }
                                }
                                else {
                                    printf("Cette propriete est hypotheque donc vous ne payez aucun loyer.\n");
                                }

                            }
                        }
                        break;
                    }
                    case 4: //Impot sur le revenu
                    {
                        //On paye les impots et on ajoute cet argent sur le pot commun du parc gratuit au cas ou la règle est activé.
                        printf("Vous payez %d d'impot sur le revenu.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu);
                        listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                        potCommun += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                        break;
                    }
                    case 5: //Taxe de luxe
                    {
                        //On paye les taxes et on ajoute cet argent sur le pot commun du parc gratuit au cas ou la règle est activé.
                        printf("Vous payez %d de taxe de luxe.\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu);
                        listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                        potCommun += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixTerrainNu;
                        break;
                    }
                    case 6: //Chance
                    {
                        debutChance :

                        //On pioche la carte suivante:
                        infoChanceCaisse.numeroCarteChance = (infoChanceCaisse.numeroCarteChance + 1) % 16;

                        //On effectue son effet selon le numero de la nouvelle carte.
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

                        //On pioche la carte suivante :
                        infoChanceCaisse.numeroCarteCaisse = (infoChanceCaisse.numeroCarteCaisse + 1) % 16;

                        //On effectue son effet selon le numero de la nouvelle carte.
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
                        //Si la règle du parc de la fortune est activé, on récupère tout ce qui se trouve dans le pot commun.
                        if (regleParcGratuit) {
                            printf("Felicitation vous recuperez %d francs des differentes taxes.\n", potCommun);
                            listeJoueur[joueur].argentJoueur += potCommun;
                            potCommun = 0;
                        }
                        break;
                    }
                    case 9: //Allez en Prison
                    {
                        //Sortie si on pioche une carte allez en prison
                        prison:

                        //On place le joueur sur la case 10 et on le met en prison
                        listeJoueur[joueur].caseJoueur = 10;
                        listeJoueur[joueur].prison = 1;
                        printf("Vous etes donc sur la case Prison, numero %d.\n", listeJoueur[joueur].caseJoueur);
                        break;
                    }
                    case 10: //Gare
                    {

                        //Si personne ne possède cette case
                        if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == 0) {

                            //Si on a assez d'argent pour l'acheter
                            if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase) {

                                //Alors on peut l'acheter
                                int choix = 0;
                                printf("Voulez-vous acheter la case %s pour %d francs ?\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase, plateauMonopoly[listeJoueur[joueur].caseJoueur].prixCase);

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

                            //Si cette case est déjà a nous :
                            if (plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur == joueur) {
                                printf("Vous etes sur votre propriete: %s\n", plateauMonopoly[listeJoueur[joueur].caseJoueur].nomCase);
                            }
                            else {

                                //Si cette case n'est pas hypothéquée
                                if (plateauMonopoly[listeJoueur[joueur].caseJoueur].hypotheque == 0) {

                                    //Si on a l'argent pour le payer, alors on le paye.
                                    int possesseur = plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur;
                                    int argent = plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[nombreGareJoueur(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)];
                                    if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[nombreGareJoueur(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)]) {
                                        listeJoueur[joueur].argentJoueur -= plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[nombreGareJoueur(plateauMonopoly, plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur)];
                                        listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].argentJoueur += plateauMonopoly[listeJoueur[joueur].caseJoueur].prixMaisonHotel[nombreGareJoueur(plateauMonopoly, possesseur)];
                                        printf("Vous payez %d francs a %s car ce joueur possede %d gare(s).\n", argent, listeJoueur[possesseur].nomJoueur, nombreGareJoueur(plateauMonopoly, possesseur) );
                                    }
                                    //Sinon on tombe en gestion de faillite.
                                    else {
                                        printf("Vous n'avez pas assez d'argent pour payer %s.\n", listeJoueur[plateauMonopoly[listeJoueur[joueur].caseJoueur].joueurPossesseur].nomJoueur);
                                        failliteJoueur(plateauMonopoly, listeJoueur, joueur, listeJoueur[joueur].caseJoueur, argent, &nombreMaisonRestante, &nombreHotelRestant);
                                    }
                                }
                                else {
                                    printf("Cette propriete est hypotheque donc vous ne payez aucun loyer.\n");
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

                //Si le joueur a une dette envers la banque et qu'il n'est pas déjà en faillite :
                if (listeJoueur[joueur].argentJoueur < 0 && listeJoueur[joueur].argentJoueur != -1) {
                    int dette = - listeJoueur[joueur].argentJoueur;
                    listeJoueur[joueur].argentJoueur = 0;
                    failliteJoueur(plateauMonopoly, listeJoueur, joueur, listeJoueur[joueur].caseJoueur, dette, &nombreMaisonRestante, &nombreHotelRestant);
                }

                //Si le joueur n'est pas en faillite :
                if (listeJoueur[joueur].argentJoueur != -1) {

                    //On affiche combien il a d'argent.
                    printf("\n%s possede %d francs.\n", listeJoueur[joueur].nomJoueur, listeJoueur[joueur].argentJoueur);

                    //Si il a fait un double et qu'il n'est pas en prison, il peut rejouer.
                    if (doubleDe && listeJoueur[joueur].prison == 0) {
                        doubleDeSuccessif += 1;
                        printf("\nVous avez fait un double, vous pouvez donc rejouer !\n");
                        goto tirage;
                    }

                    //On remet son compteur de double à 0 sinon
                    doubleDeSuccessif = 0;
                }

                //On compte le nombre de joueur restant qui ont encore de l'argent :
                joueurRestant = 0;
                for (int i = 1; i <= nombreJoueur; i++) {
                    if (listeJoueur[i].argentJoueur >= 0) {
                        joueurRestant +=1;
                    }
                }
            }
        }
    }

    //On regarde qui est le dernier joueur à ne pas être en faillite :
    for (joueur = 1; joueur <= nombreJoueur; joueur++) {
        if (listeJoueur[joueur].argentJoueur >= 0) {
            joueurRestant = joueur;
        }
    }

    //Felicitation, ce joueur a gagné !
    printf("\n------------------------------------------------------------------------------\n");
    printf("\nFelicitation %s tu as gagne cette partie !\n", listeJoueur[joueurRestant].nomJoueur);
    printf("\n------------------------------------------------------------------------------\n\n");

    return joueurRestant;
}

