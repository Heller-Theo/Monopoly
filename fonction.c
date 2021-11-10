#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initialisation.h"


void affichageInfoCase(int numeroCase, CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    printf("Case numero %d: %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
    printf("Prix: %d\n", plateauMonopoly[numeroCase].prixCase);
    printf("Maison: %d, Hotel: %d\n", plateauMonopoly[numeroCase].nombreMaison, plateauMonopoly[numeroCase].nombreHotel);
    printf("Detenu par le joueur: %d\n", plateauMonopoly[numeroCase].joueurPossesseur);
}

void affichagePrixCase(int numeroCase, CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    int i = 0;
    if (numeroCase == 0) {
        printf("Case %d: %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
        printf("La Case Depart vous donnera %d francs une fois franchie.\n", plateauMonopoly[numeroCase].prixTerrainNu);
    }
    else {
        if (numeroCase == 12 || numeroCase == 28) {
            printf("Case %d: %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
            printf("Le loyer est de %d francs multiplie par le resultat des des avec un seul service publique.\n", plateauMonopoly[numeroCase].prixMaisonHotel[0]);
            printf("Le loyer est de %d francs multiplie par le resultat des des avec deux services publiques.\n", plateauMonopoly[numeroCase].prixMaisonHotel[1]);
        }
        else {
            if (numeroCase == 4 || numeroCase == 38) {
                printf("Case %d: %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
                printf("Cette case coute %d si vous tombez dessus.\n", plateauMonopoly[numeroCase].prixTerrainNu);
            }
            else {
                if (numeroCase == 2 || numeroCase == 7 || numeroCase == 17 || numeroCase == 22 || numeroCase == 33 || numeroCase == 36) {
                    printf("Case %d: %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
                    printf("Cette case ne coute rien, vous piocherez une carte en tombant dessus.\n");
                }
                else {
                    if (numeroCase == 5 || numeroCase == 15 || numeroCase == 25 || numeroCase == 35) {
                        printf("Case %d: %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
                        printf("Loyer si vous possedez 1 Gare: %d\n", plateauMonopoly[numeroCase].prixMaisonHotel[1]);
                        printf("Loyer si vous possedez 2 Gares: %d\n", plateauMonopoly[numeroCase].prixMaisonHotel[2]);
                        printf("Loyer si vous possedez 3 Gares: %d\n", plateauMonopoly[numeroCase].prixMaisonHotel[3]);
                        printf("Loyer si vous possedez 4 Gares: %d\n", plateauMonopoly[numeroCase].prixMaisonHotel[4]);
                    }
                    else {
                        if (numeroCase == 10 || numeroCase == 20 || numeroCase == 30) {
                            printf("Case %d: %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
                            printf("Cette case ne coute rien.\n");
                        }
                        else {
                            printf("Case %d: %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
                            printf("Loyer terrain nu: %d\n",plateauMonopoly[numeroCase].prixTerrainNu);
                            printf("Loyer avec 1 Maison: %d\n", plateauMonopoly[numeroCase].prixMaisonHotel[1]);
                            printf("Loyer avec 2 Maisons: %d\n", plateauMonopoly[numeroCase].prixMaisonHotel[2]);
                            printf("Loyer avec 3 Maisons: %d\n", plateauMonopoly[numeroCase].prixMaisonHotel[3]);
                            printf("Loyer avec 4 Maisons: %d\n", plateauMonopoly[numeroCase].prixMaisonHotel[4]);
                            printf("loyer avec Hotel: %d\n", plateauMonopoly[numeroCase].prixMaisonHotel[5]);
                            printf("Cout Maison: %d\n", plateauMonopoly[numeroCase].prixMaisonHotel[0]);
                        }
                    }
                }
            }
        }
    }
}

void affichageInfoJoueur(int numeroJoueur, InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    printf("Joueur numero %d\n", numeroJoueur);
    printf("Argent: %d\n", listeJoueur[numeroJoueur].argentJoueur);
    printf("Carte Libere de Prison: %d\n", listeJoueur[numeroJoueur].carteLiberePrison);
}

void affichagePossessionJoueur(int numeroJoueur, CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    int i = 0;
    printf("Le joueur %d possede :\n", numeroJoueur);
    for(i = 0; i < TAILLE_PLATEAU; i++) {
        if (plateauMonopoly[i].joueurPossesseur == numeroJoueur) {
            if (plateauMonopoly[i].nombreMaison > 0) {
                printf("%s (%d maison(s))\n", plateauMonopoly[i].nomCase, plateauMonopoly[i].nombreMaison);
            }
            else {
                if (plateauMonopoly[i].nombreHotel == 1) {
                    printf("%s (%d Hotel)\n", plateauMonopoly[i].nomCase, plateauMonopoly[i].nombreHotel);
                }
                else {
                    printf("%s\n", plateauMonopoly[i].nomCase);
                }
            }
        }
    }
}


void tirageDeuxDe(int* pResultat, int* pDoubleDe) {
    int tirage1 = rand() % 6 + 1;
    int tirage2 = rand() % 6 + 1;
    printf("Vous avez eu un %d et un %d.\n", tirage1, tirage2);
    *pDoubleDe = (tirage1 == tirage2) ? 1 : 0;
    *pResultat = tirage1 + tirage2;
}

int monopoleCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase, int joueur) {
    int i = 0, monopole = 1;
    for (i = 0; i < TAILLE_PLATEAU; i++) {
        if (plateauMonopoly[i].numeroGroupeCase == numeroGroupeCase) {
            if (plateauMonopoly[i].joueurPossesseur != joueur) {
                monopole = 0;
            }
        }
    }
    return monopole;
}

void achatMaison(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante) {
    int joueur = 0, groupePropriete = 0, numeroCase = 0, choix = 0, auMoinsUnChoix = 0;

    if ( *pNombreMaisonRestante > 0) {

        printf("Quel joueur veux acheter des maisons ?\n");
        do {
            scanf(" %d", &joueur);
        } while (joueur != 1 && joueur != 2 && joueur != 3 && joueur != 4 && joueur != 5);

        printf("Vous pouvez acheter des maisons sur les cases suivantes :\n");
        for (groupePropriete = 1; groupePropriete <= 8 ; groupePropriete++) {
            if (monopoleCase(plateauMonopoly, groupePropriete, joueur) ) {
                for (numeroCase = 0; numeroCase < 40; numeroCase++) {
                    if (plateauMonopoly[numeroCase].numeroGroupeCase == groupePropriete) {
                        if (plateauMonopoly[numeroCase].nombreHotel == 0 && plateauMonopoly[numeroCase].nombreMaison < 4) {
                            printf("%d: %s (%d francs)\n", numeroCase, plateauMonopoly[numeroCase].nomCase, plateauMonopoly[numeroCase].prixMaisonHotel[0]);
                            auMoinsUnChoix += 1;
                        }
                    }
                }
            }
        }
        if (!auMoinsUnChoix) {
            printf("Aucune\n");
            return;
        }
        printf("0: Retour\n");

        scanf(" %d", &choix);

        if (choix == 0) {
            return;
        }
        if (choix == 12 || choix == 28) {
            printf("Vous ne pouvez pas acheter de maison sur cette case.\n");
            return;
        }
        if (monopoleCase(plateauMonopoly, plateauMonopoly[choix].numeroGroupeCase, joueur)) {
            if (plateauMonopoly[choix].nombreHotel == 0 && plateauMonopoly[choix].nombreMaison < 4) {
                if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[choix].prixMaisonHotel[0]) {
                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[choix].prixMaisonHotel[0];
                    plateauMonopoly[choix].nombreMaison += 1;
                    *pNombreMaisonRestante -= 1;
                    printf("Vous avez maintenant %d maison(s) sur la case %s.\n", plateauMonopoly[choix].nombreMaison, plateauMonopoly[choix].nomCase);
                    printf("Il reste %d Maison(s) dans le jeu.\n", *pNombreMaisonRestante);
                }
                else {
                    printf("Vous n'avez pas assez d'argent pour acheter cette maison.\n");
                }
            }
            else {
                printf("Cette case possede deja 4 maisons ou un hotel.\n");
            }
        }
        else {
            printf("Vous ne pouvez pas acheter de maison sur cette case.\n");
        }
    }
    else {
        printf("Il n'y a plus assez de Maison dans le jeu.");
    }


}

void achatHotel(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreHotelRestant) {
    int joueur = 0, numeroCase = 0, choix = 0, auMoinsUnChoix = 0;

    if ( *pNombreHotelRestant > 0) {

        printf("Quel joueur veux acheter des hotels ?\n");
        do {
            scanf(" %d", &joueur);
        } while (joueur != 1 && joueur != 2 && joueur != 3 && joueur != 4 && joueur != 5);

        printf("Vous pouvez acheter des hotels sur les cases suivantes :\n");
        for (numeroCase = 0; numeroCase < 40; numeroCase++) {
            if (plateauMonopoly[numeroCase].joueurPossesseur == joueur) {
                if (plateauMonopoly[numeroCase].nombreMaison == 4) {
                    printf("%d: %s (%d francs)\n", numeroCase, plateauMonopoly[numeroCase].nomCase, plateauMonopoly[numeroCase].prixMaisonHotel[0]);
                    auMoinsUnChoix += 1;
                }
            }
        }
        if (!auMoinsUnChoix) {
            printf("Aucune\n");
            return;
        }
        printf("0: Retour\n");

        scanf(" %d", &choix);

        if (choix == 0) {
            return;
        }
        if (plateauMonopoly[choix].joueurPossesseur == joueur) {
            if (plateauMonopoly[choix].nombreMaison == 4) {
                if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[choix].prixMaisonHotel[0]) {
                    listeJoueur[joueur].argentJoueur -= plateauMonopoly[choix].prixMaisonHotel[0];
                    plateauMonopoly[choix].nombreHotel += 1;
                    plateauMonopoly[choix].nombreMaison = 0;
                    *pNombreHotelRestant -= 1;
                    printf("Vous avez maintenant un Hotel sur la case %s.\n", plateauMonopoly[choix].nomCase);
                    printf("Il reste %d Hotel(s) dans le jeu.\n", *pNombreHotelRestant);
                }
                else {
                    printf("Vous n'avez pas assez d'argent pour acheter cet Hotel.\n");
                }
            }
            else {
                printf("Cette case ne possede pas les 4 maisons requises pour acheter un Hotel.\n");
            }
        }
        else {
            printf("Vous ne pouvez pas acheter d'Hotel sur cette case.\n");
        }
    }
    else {
        printf("Il n'y a plus assez d'Hotel dans le jeu.\n");
    }

}

int checkJeu(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante, int* pNombreHotelRestant) {
    int verif = 0, choix1 = 0, choix2 = 0;
    do {
        printf("Continuer >");
        scanf("%d",&verif);

        if (verif == 0) {
            printf("Etes vous sur de vouloir quitter la partie ?\n");
            printf("0: Quitter\n");
            printf("1: Rester en jeu\n>");
            do {
                scanf(" %d", &choix1);
            } while (choix1 != 0 && choix1 != 1);
            if (choix1 == 0) {return 0;}
        }

        if (verif == 2) {
            printf("Quelles informations voulez-vous ?\n");
            printf("1: Info Technique d'une case.\n");
            printf("2: Info Prix d'une case.\n");
            printf("3: Info Joueur.\n");
            printf("4: Info Possession Joueur.\n");
            printf("0: Retour\n>");

            do {
                scanf(" %d", &choix1);
            } while (choix1 != 0 && choix1 != 1 && choix1 != 2 && choix1 != 3 && choix1 != 4);

            if (choix1 != 0) {
                if (choix1 == 1 || choix1 == 2) {printf("Choisissez une case :\n>");}
                if (choix1 == 3 || choix1 == 4) {printf("Choisissez un joueur :\n>");}

                scanf(" %d", &choix2);
                if (choix1 == 1) { affichageInfoCase(choix2, plateauMonopoly);}
                if (choix1 == 2) { affichagePrixCase(choix2, plateauMonopoly);}
                if (choix1 == 3) { affichageInfoJoueur(choix2, listeJoueur);}
                if (choix1 == 4) { affichagePossessionJoueur(choix2, plateauMonopoly);}
            }
        }

        if (verif == 3) {
            printf("Voulez vous acheter une maison ou un hotel ?\n");
            printf("1: Maison\n");
            printf("2: Hotel\n");
            printf("0: Retour\n>");

            do {
                scanf(" %d", &choix1);
            } while (choix1 != 0 && choix1 != 1 && choix1 != 2);

            if (choix1 != 0) {
                if (choix1 == 1) {achatMaison(plateauMonopoly, listeJoueur, pNombreMaisonRestante);}
                if (choix1 == 2) {achatHotel(plateauMonopoly, listeJoueur, pNombreHotelRestant);}
            }
        }

    } while (verif != 1);
    return 1;
}

int nombreGareJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int joueur) {
    int i = 0, nombreGare = 0;
    for (i = 5; i < TAILLE_PLATEAU; i += 10) {
        if (plateauMonopoly[i].joueurPossesseur == joueur) {
            nombreGare += 1;
        }
    }
    return nombreGare;
}

int nombreMaisonJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int joueur) {
    int i = 0, nombreMaison = 0;
    for (i = 0; i < 40; i++) {
        if (plateauMonopoly[i].joueurPossesseur == joueur) {
            nombreMaison += plateauMonopoly[i].nombreMaison;
        }
    }
    return nombreMaison;
}

int nombreHotelJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int joueur) {
    int i = 0, nombreHotel = 0;
    for (i = 0; i < 40; i++) {
        if (plateauMonopoly[i].joueurPossesseur == joueur) {
            nombreHotel += plateauMonopoly[i].nombreHotel;
        }
    }
    return nombreHotel;
}

void randomOrdreCaisseChance(int listeAleatoire[16]) {
    int nombreAleatoire = 0, i = 0;
    int liste[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    for (i = 0; i < 16; i++) {
        do {
            nombreAleatoire = rand() % 16 + 1;
        } while (liste[nombreAleatoire-1] == 0);
        liste[nombreAleatoire-1] = 0;
        listeAleatoire[i] = nombreAleatoire;
    }
}

void initialisationSauvegarde(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], CarteChanceCaisse infoChanceCaisse, int listeVariable[NOMBRE_VARIABLE]) {
    listeVariable[0] = 0;
    listeVariable[1] = 0;
    listeVariable[2] = 0;
    listeVariable[3] = 2;
    listeVariable[4] = 1;
    listeVariable[5] = 1;
    listeVariable[6] = 32;
    listeVariable[7] = 12;
    listeVariable[8] = 0;
    initialisationMonopoly(plateauMonopoly);
    initialisationJoueur(listeJoueur);
    initialisationCarteChanceCaisse(&infoChanceCaisse);
    printf("La sauvegarde a bien ete reinitialise\n");
    return;
}

void posJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroCase, int nombreJoueur) {
    char affichagePosition[7] = "";
    strcat(affichagePosition, listeJoueur[1].caseJoueur == numeroCase ? "1" : " ");
    strcat(affichagePosition, listeJoueur[2].caseJoueur == numeroCase ? "2" : " ");
    strcat(affichagePosition, nombreJoueur >= 3 ? (listeJoueur[3].caseJoueur == numeroCase ? "3" : " ") : " ");
    strcat(affichagePosition, nombreJoueur >= 4 ? (listeJoueur[4].caseJoueur == numeroCase ? "4" : " ") : " ");
    strcat(affichagePosition, nombreJoueur >= 5 ? (listeJoueur[5].caseJoueur == numeroCase ? "5" : " ") : " ");
    strcat(affichagePosition, nombreJoueur >= 6 ? (listeJoueur[6].caseJoueur == numeroCase ? "6" : " ") : " ");
    strcat(affichagePosition, "|");
    printf("%s", affichagePosition);
    return;
}

void affichagePlateau(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int nombreJoueur) {
    printf("______________________________________________________________________________\n");
    printf("|");
    posJoueur(listeJoueur, 0, nombreJoueur);
    posJoueur(listeJoueur, 1, nombreJoueur);
    posJoueur(listeJoueur, 2, nombreJoueur);
    posJoueur(listeJoueur, 3, nombreJoueur);
    posJoueur(listeJoueur, 4, nombreJoueur);
    posJoueur(listeJoueur, 5, nombreJoueur);
    posJoueur(listeJoueur, 6, nombreJoueur);
    posJoueur(listeJoueur, 7, nombreJoueur);
    posJoueur(listeJoueur, 8, nombreJoueur);
    posJoueur(listeJoueur, 9, nombreJoueur);
    posJoueur(listeJoueur, 10, nombreJoueur);
    printf("\n");

    printf("|Depart|_2_H__|Caisse|_2_M0_|Impots|_Gare_|______|Chance|______|______|Prison|\n");

    printf("|");
    posJoueur(listeJoueur, 39, nombreJoueur);
    printf("                                                              |");
    posJoueur(listeJoueur, 11, nombreJoueur);
    printf("\n");

    printf("|__40k_|                 *                                            |______|\n");

    printf("|");
    posJoueur(listeJoueur, 38, nombreJoueur);
    printf("               *     *                                        |");
    posJoueur(listeJoueur, 12, nombreJoueur);
    printf("\n");

    printf("|_Taxe_|             *           *                                    |_Elec_|\n");

    printf("|");
    posJoueur(listeJoueur, 37, nombreJoueur);
    printf("           *           *                                      |");
    posJoueur(listeJoueur, 13, nombreJoueur);
    printf("\n");

    printf("|__35k_|         *           *                                        |______|\n");

    printf("|");
    posJoueur(listeJoueur, 36, nombreJoueur);
    printf("       *           *                                          |");
    posJoueur(listeJoueur, 14, nombreJoueur);
    printf("\n");

    printf("|Chance|     *           *     ________________                       |______|\n");

    printf("|");
    posJoueur(listeJoueur, 35, nombreJoueur);
    printf("         *     *      |    Monopoly    |        *             |");
    posJoueur(listeJoueur, 15, nombreJoueur);
    printf("\n");

    printf("|_Gare_|             *        | Version Deluxe |      *     *         |_Gare_|\n");

    printf("|");
    posJoueur(listeJoueur, 34, nombreJoueur);
    printf("                      |________________|    *           *     |");
    posJoueur(listeJoueur, 16, nombreJoueur);
    printf("\n");

    printf("|______|                                          *           *       |______|\n");

    printf("|");
    posJoueur(listeJoueur, 33, nombreJoueur);
    printf("  Joueur 1:  20 000                     *           *         |");
    posJoueur(listeJoueur, 17, nombreJoueur);
    printf("\n");

    printf("|Caisse|  Joueur 2: 120 000                   *           *           |Caisse|\n");

    printf("|");
    posJoueur(listeJoueur, 32, nombreJoueur);
    printf("  Joueur 3:  38 500                 *           *             |");
    posJoueur(listeJoueur, 18, nombreJoueur);
    printf("\n");

    printf("|______|  Joueur 4:  78 100                     *     *               |______|\n");

    printf("|");
    posJoueur(listeJoueur, 31, nombreJoueur);
    printf("  Joueur 5: 150 000                         *                 |");
    posJoueur(listeJoueur, 19, nombreJoueur);
    printf("\n");

    printf("|______|______________________________________________________________|______|\n");

    printf("|");
    posJoueur(listeJoueur, 30, nombreJoueur);
    posJoueur(listeJoueur, 29, nombreJoueur);
    posJoueur(listeJoueur, 28, nombreJoueur);
    posJoueur(listeJoueur, 27, nombreJoueur);
    posJoueur(listeJoueur, 26, nombreJoueur);
    posJoueur(listeJoueur, 25, nombreJoueur);
    posJoueur(listeJoueur, 24, nombreJoueur);
    posJoueur(listeJoueur, 23, nombreJoueur);
    posJoueur(listeJoueur, 22, nombreJoueur);
    posJoueur(listeJoueur, 21, nombreJoueur);
    posJoueur(listeJoueur, 20, nombreJoueur);
    printf("\n");

    printf("|_-->#_|______|_Eaux_|______|______|_Gare_|______|______|Chance|______|_Parc_|\n");
}

