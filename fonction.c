#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "initialisation.h"

void viderBuffer() {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

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

int hypothequeGroupe(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase) {
    int i = 0, hypotheque = 0;
    for (i = 0; i < TAILLE_PLATEAU; i++) {
        if (plateauMonopoly[i].numeroGroupeCase == numeroGroupeCase) {
            if (plateauMonopoly[i].hypotheque) {
                hypotheque += 1;
            }
        }
    }
    return hypotheque;
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
                if (!hypothequeGroupe(plateauMonopoly, groupePropriete)) {
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
            if (!hypothequeGroupe(plateauMonopoly, plateauMonopoly[choix].numeroGroupeCase)) {
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
                printf("Il y a une propriete hypothequee sur un des terrains de ce groupe.\n");
            }
        }
        else {
            printf("Vous ne pouvez pas acheter de maison sur cette case.\n");
        }
    }
    else {
        printf("Il n'y a plus assez de Maison dans le jeu.\n");
    }


}

void achatHotel(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreHotelRestant, int* pNombreMaisonRestante) {
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
                    *pNombreMaisonRestante += 4;
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


void venteMaison(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante) {
    int joueur = 0, choix = 0, choix2 = 0, numeroCase = 0, auMoinsUnChoix = 0;

    printf("Quel joueur veux vendre des biens ?\n");
    do {
        scanf(" %d", &joueur);
    } while (joueur != 1 && joueur != 2 && joueur != 3 && joueur != 4 && joueur != 5);


    printf("Vous pouvez vendre des maisons sur les cases suivantes :\n");
    for (numeroCase = 0; numeroCase < 40; numeroCase++) {
        if (plateauMonopoly[numeroCase].joueurPossesseur == joueur) {
            if (plateauMonopoly[numeroCase].nombreMaison >= 1) {
                printf("%d: %s (%d francs)\n", numeroCase, plateauMonopoly[numeroCase].nomCase, plateauMonopoly[numeroCase].prixMaisonHotel[0] / 2);
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
        if (plateauMonopoly[choix].nombreMaison >= 1) {
            listeJoueur[joueur].argentJoueur += plateauMonopoly[choix].prixMaisonHotel[0] / 2;
            plateauMonopoly[choix].nombreMaison -= 1;
            *pNombreMaisonRestante += 1;
            printf("Vous avez vendu une maison sur la case %s.\n", plateauMonopoly[choix].nomCase);
            printf("Il reste %d Maison(s) dans le jeu.\n", *pNombreMaisonRestante);
        }
        else {
            printf("Cette case ne possede pas de maisons a vendre.\n");
        }
    }
    else {
        printf("Vous ne pouvez pas vendre de maison sur cette case.\n");
    }
}



void venteHotel(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreHotelRestant, int* pNombreMaisonRestante) {
    int joueur = 0, choix = 0, choix2 = 0, numeroCase = 0, auMoinsUnChoix = 0;

    printf("Quel joueur veux vendre des biens ?\n");
    do {
        scanf(" %d", &joueur);
    } while (joueur != 1 && joueur != 2 && joueur != 3 && joueur != 4 && joueur != 5);


    printf("Vous pouvez vendre des hotels sur les cases suivantes :\n");
    for (numeroCase = 0; numeroCase < 40; numeroCase++) {
        if (plateauMonopoly[numeroCase].joueurPossesseur == joueur) {
            if (plateauMonopoly[numeroCase].nombreHotel == 1) {
                printf("%d: %s (%d francs)\n", numeroCase, plateauMonopoly[numeroCase].nomCase, plateauMonopoly[numeroCase].prixMaisonHotel[0] / 2);
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
        if (plateauMonopoly[choix].nombreHotel == 1) {
            printf("Voulez vous vendre votre hotel et les 4 maisons ou seulement l'hotel ?\n");
            printf("1) Tout vendre pour %d francs\n", plateauMonopoly[choix].prixMaisonHotel[0] * 5 / 2);
            printf("2) Vendre seulement l'hotel pour %d francs\n", plateauMonopoly[choix].prixMaisonHotel[0] / 2);
            scanf(" %d", &choix2);
            if (choix2 == 1) {
                listeJoueur[joueur].argentJoueur += plateauMonopoly[choix].prixMaisonHotel[0] * 5 / 2;
                plateauMonopoly[choix].nombreHotel = 0;
                plateauMonopoly[choix].nombreMaison = 0;
                *pNombreHotelRestant += 1;
                *pNombreMaisonRestante += 4;
                printf("Vous avez vendu tout vos bien sur la case %s.\n", plateauMonopoly[choix].nomCase);
                printf("Il reste %d Hotel(s) dans le jeu.\n", *pNombreHotelRestant);
                printf("Il reste %d Maison(s) dans le jeu.\n", *pNombreMaisonRestante);
            }
            else {
                if (choix2 == 2) {
                    if (*pNombreMaisonRestante >= 4) {
                        listeJoueur[joueur].argentJoueur += plateauMonopoly[choix].prixMaisonHotel[0] / 2;
                        plateauMonopoly[choix].nombreHotel = 0;
                        plateauMonopoly[choix].nombreMaison = 4;
                        *pNombreHotelRestant += 1;
                        *pNombreMaisonRestante -= 4;
                        printf("Vous avez vendu votre hotel sur la case %s.\n", plateauMonopoly[choix].nomCase);
                        printf("Il reste %d Hotel(s) dans le jeu.\n", *pNombreHotelRestant);
                        printf("Il rest %d Maison(s) dans le jeu.\n", *pNombreMaisonRestante);
                    }
                    else {
                        printf("Il ne reste plus assez de maisons libre pour vendre uniquement votre hotel\n");
                    }
                }
            }
        }
        else {
            printf("Cette case ne possede pas d'hotel a vendre.\n");
        }
    }
    else {
        printf("Vous ne pouvez pas vendre d'Hotel sur cette case.\n");
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
            printf("5: Achat et vente de maison et d'hotel\n");
            printf("0: Retour\n>");

            do {
                scanf(" %d", &choix1);
            } while (choix1 != 0 && choix1 != 1 && choix1 != 2 && choix1 != 3 && choix1 != 4 && choix1 != 5);

            if (choix1 == 0) {

            }
            if (choix1 == 1) {
                printf("Choisissez une case :\n>");
                scanf(" %d", &choix2);
                affichageInfoCase(choix2, plateauMonopoly);
            }
            if (choix1 == 2) {
                printf("Choisissez une case :\n>");
                scanf(" %d", &choix2);
                affichagePrixCase(choix2, plateauMonopoly);
            }
            if (choix1 == 3) {
                printf("Choisissez un joueur :\n>");
                scanf(" %d", &choix2);
                affichageInfoJoueur(choix2, listeJoueur);
            }
            if (choix1 == 4) {
                printf("Choisissez un joueur :\n>");
                scanf(" %d", &choix2);
                affichagePossessionJoueur(choix2, plateauMonopoly);
            }
            if (choix1 == 5) {
                printf("Que voulez vous faire :\n");
                printf("1: Acheter une Maison\n");
                printf("2: Acheter un Hotel\n");
                printf("3: vendre une Maison\n");
                printf("4: vendre un Hotel\n");
                printf("0: Retour\n>");
                scanf(" %d", &choix2);

                if (choix2 == 1) {
                    achatMaison(plateauMonopoly, listeJoueur, pNombreMaisonRestante);
                }
                if (choix2 == 2) {
                    achatHotel(plateauMonopoly, listeJoueur, pNombreHotelRestant, pNombreMaisonRestante);
                }
                if (choix2 == 3) {
                    venteMaison(plateauMonopoly, listeJoueur, pNombreMaisonRestante);
                }
                if (choix2 == 4) {
                    venteHotel(plateauMonopoly, listeJoueur, pNombreHotelRestant, pNombreMaisonRestante);
                }
            }
        }
        if (verif == 3) {
            printf("Maison\n>");
            scanf(" %d", pNombreMaisonRestante);
            printf("Maison\n>");
            scanf(" %d", pNombreHotelRestant);
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


void posJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroCase, int nombreJoueur) {
    if (listeJoueur[1].caseJoueur == numeroCase) {
        color(1,0);
        printf("1");
        color(7,0);
    }
    else {
        printf(" ");
    }

    if (listeJoueur[2].caseJoueur == numeroCase) {
        color(4,0);
        printf("2");
        color(7,0);
    }
    else {
        printf(" ");
    }

    if (nombreJoueur >= 3 && listeJoueur[3].caseJoueur == numeroCase) {
        color(2,0);
        printf("3");
        color(7,0);
    }
    else {
        printf(" ");
    }

    if (nombreJoueur >= 4 && listeJoueur[4].caseJoueur == numeroCase) {
        color(14,0);
        printf("4");
        color(7,0);
    }
    else {
        printf(" ");
    }

    if (nombreJoueur >= 5 && listeJoueur[5].caseJoueur == numeroCase) {
        color(5,0);
        printf("5");
        color(7,0);
    }
    else {
        printf(" ");
    }

    if (nombreJoueur >= 6 && listeJoueur[6].caseJoueur == numeroCase) {
        color(11,0);
        printf("6");
        color(7,0);
    }
    else {
        printf(" ");
    }

    printf("|");
    return;
}


void affichageArgentJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroJoueur, int nombreJoueur) {
    char affichageArgent[7] = "";
    if (numeroJoueur <= nombreJoueur) {
        if (listeJoueur[numeroJoueur].argentJoueur < 100) {
            strcat(affichageArgent,"      ");
        }
        else {
            if (listeJoueur[numeroJoueur].argentJoueur < 1000) {
                strcat(affichageArgent,"    ");
            }
            else {
                if (listeJoueur[numeroJoueur].argentJoueur < 10000) {
                    strcat(affichageArgent,"   ");
                }
                else {
                    if (listeJoueur[numeroJoueur].argentJoueur < 100000) {
                        strcat(affichageArgent,"  ");
                    }
                    else {
                        if (listeJoueur[numeroJoueur].argentJoueur < 1000000) {
                            strcat(affichageArgent," ");
                        }
                    }
                }
            }
        }
        printf("%s", affichageArgent);
        if (listeJoueur[numeroJoueur].argentJoueur >= 0) {
            printf("%d", listeJoueur[numeroJoueur].argentJoueur);
        }
        else {
            printf("0");
        }
    }
    else {
        printf("       ");
    }

    return;
}

void affichageNomJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroJoueur, int nombreJoueur) {
    if (numeroJoueur <= nombreJoueur) {
        unsigned int longueurNom = strlen(listeJoueur[numeroJoueur].nomJoueur);
        char affichageNom[TAILLE_MAX_NOM_JOUEUR] = "";
        for (int i = 0; i < TAILLE_MAX_NOM_JOUEUR - longueurNom - 1; i++) {
            strcat(affichageNom, " ");
        }
        printf("%s", listeJoueur[numeroJoueur].nomJoueur);
        printf("%s:", affichageNom);
    }
    else {
        printf("           ");
    }

}

void affichageCasePropriete(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroCase) {
    if (plateauMonopoly[numeroCase].joueurPossesseur) {
        if (plateauMonopoly[numeroCase].nombreMaison) {
            printf("_%d_%dM_", plateauMonopoly[numeroCase].joueurPossesseur, plateauMonopoly[numeroCase].nombreMaison);
        }
        else {
            if (plateauMonopoly[numeroCase].nombreHotel) {
                printf("_%d__H_", plateauMonopoly[numeroCase].joueurPossesseur);
            }
            else {
                printf("__%d___", plateauMonopoly[numeroCase].joueurPossesseur);
            }
        }
    }
    else {
        if (plateauMonopoly[numeroCase].prixCase < 10000) {
            printf("__%dk__", plateauMonopoly[numeroCase].prixCase / 1000);
        }
        else {
            printf("_%dk__", plateauMonopoly[numeroCase].prixCase / 1000);
        }
    }
}

void affichageMaisonHotelRestant(int nombreMaisonRestante, int nombreHotelRestant, int mode) {
    if (mode == 1) {
        if (nombreMaisonRestante < 10) {
            printf(" ");
        }
        printf("%d", nombreMaisonRestante);
    }
    if (mode == 2) {
        if (nombreHotelRestant < 10) {
            printf(" ");
        }
        printf("%d", nombreHotelRestant);
    }
}

void affichageRegleParc(int regleParcGratuit, int potCommun) {
    if (regleParcGratuit) {
        printf("Parc: %d", potCommun);
        if (potCommun < 100) {
            printf("     ");
        }
        else {
            if (potCommun < 1000) {
                printf("   ");
            }
            else {
                if (potCommun < 10000) {
                    printf("  ");
                }
                else {
                    if (potCommun < 100000) {
                        printf(" ");
                    }
                }
            }
        }
    }
    else {
        printf("            ");
    }
}


void affichagePlateau(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int variable[NOMBRE_VARIABLE]) {

    color(7, 0);

    printf("______________________________________________________________________________\n");
    printf("|");
    posJoueur(listeJoueur, 0, variable[3]);
    posJoueur(listeJoueur, 1, variable[3]);
    posJoueur(listeJoueur, 2, variable[3]);
    posJoueur(listeJoueur, 3, variable[3]);
    posJoueur(listeJoueur, 4, variable[3]);
    posJoueur(listeJoueur, 5, variable[3]);
    posJoueur(listeJoueur, 6, variable[3]);
    posJoueur(listeJoueur, 7, variable[3]);
    posJoueur(listeJoueur, 8, variable[3]);
    posJoueur(listeJoueur, 9, variable[3]);
    posJoueur(listeJoueur, 10, variable[3]);
    printf("\n");

    printf("|");
    color(7,0);
    printf("Depart");
    color(7,0);
    printf("|");
    color(5,0);
    affichageCasePropriete(plateauMonopoly, 1);
    color(7,0);
    printf("|");
    color(7,0);
    printf("Caisse");
    color(7,0);
    printf("|");
    color(5,0);
    affichageCasePropriete(plateauMonopoly, 3);
    color(7,0);
    printf("|");
    color(7,0);
    printf("Impots");
    color(7,0);
    printf("|");
    color(15,0);
    printf("_Gare_");
    color(7,0);
    printf("|");
    color(3,0);
    affichageCasePropriete(plateauMonopoly, 6);
    color(7,0);
    printf("|");
    color(7,0);
    printf("Chance");
    color(7,0);
    printf("|");
    color(3,0);
    affichageCasePropriete(plateauMonopoly, 8);
    color(7,0);
    printf("|");
    color(3,0);
    affichageCasePropriete(plateauMonopoly, 9);
    color(7,0);
    printf("|");
    color(7,0);
    printf("Prison");
    color(7,0);
    printf("|\n");

    printf("|");
    posJoueur(listeJoueur, 39, variable[3]);
    printf("                                                              |");
    posJoueur(listeJoueur, 11, variable[3]);
    printf("\n");

    printf("|");
    color(1,0);
    affichageCasePropriete(plateauMonopoly, 39);
    color(7,0);
    printf("|                 *                       Batiment Restant:    |");
    color(13,0);
    affichageCasePropriete(plateauMonopoly, 11);
    color(7,0);
    printf("|\n");

    printf("|");
    posJoueur(listeJoueur, 38, variable[3]);
    printf("               *     *                   Maison: ");
    affichageMaisonHotelRestant(variable[6], variable[7], 1);
    printf("           |");
    posJoueur(listeJoueur, 12, variable[3]);
    printf("\n");

    printf("|");
    color(7,0);
    printf("_Taxe_");
    color(7,0);
    printf("|             *           *               Hotel: ");
    affichageMaisonHotelRestant(variable[6], variable[7], 2);
    printf("            |");
    color(15,0);
    printf("_Elec_");
    color(7,0);
    printf("|\n");

    printf("|");
    posJoueur(listeJoueur, 37, variable[3]);
    printf("           *           *                                      |");
    posJoueur(listeJoueur, 13, variable[3]);
    printf("\n");

    printf("|");
    color(1,0);
    affichageCasePropriete(plateauMonopoly, 37);
    color(7,0);
    printf("|         *           *                   ");
    affichageRegleParc(variable[1], variable[8]);
    printf("         |");
    color(13,0);
    affichageCasePropriete(plateauMonopoly, 13);
    color(7,0);
    printf("|\n");

    printf("|");
    posJoueur(listeJoueur, 36, variable[3]);
    printf("       *           *                                          |");
    posJoueur(listeJoueur, 14, variable[3]);
    printf("\n");

    printf("|");
    color(7,0);
    printf("Chance");
    color(7,0);
    printf("|     *           *     ________________                       |");
    color(13,0);
    affichageCasePropriete(plateauMonopoly, 14);
    color(7,0);
    printf("|\n");

    printf("|");
    posJoueur(listeJoueur, 35, variable[3]);
    printf("         *     *      |    Monopoly    |        *             |");
    posJoueur(listeJoueur, 15, variable[3]);
    printf("\n");

    printf("|");
    color(15,0);
    printf("_Gare_");
    color(7,0);
    printf("|             *        | Version Deluxe |      *     *         |");
    color(15,0);
    printf("_Gare_");
    color(7,0);
    printf("|\n");

    printf("|");
    posJoueur(listeJoueur, 34, variable[3]);
    printf("                      |________________|    *           *     |");
    posJoueur(listeJoueur, 16, variable[3]);
    printf("\n");

    printf("|");
    color(2,0);
    affichageCasePropriete(plateauMonopoly, 34);
    color(7,0);
    printf("|  ");
    color(1,0);
    affichageNomJoueur(listeJoueur, 1, variable[3]);
    color(7,0);
    color(15,0);
    affichageArgentJoueur(listeJoueur, 1, variable[3]);
    color(7,0);
    printf("                      *           *       |");
    color(6,0);
    affichageCasePropriete(plateauMonopoly, 16);
    color(7,0);
    printf("|\n");

    printf("|");
    posJoueur(listeJoueur, 33, variable[3]);
    printf("  ");
    color(4,0);
    affichageNomJoueur(listeJoueur, 2, variable[3]);
    color(7,0);
    color(15,0);
    affichageArgentJoueur(listeJoueur, 2, variable[3]);
    color(7,0);
    printf("                    *           *         |");
    posJoueur(listeJoueur, 17, variable[3]);
    printf("\n");

    printf("|");
    color(7,0);
    printf("Caisse");
    color(7,0);
    printf("|  ");
    color(2,0);
    affichageNomJoueur(listeJoueur, 3, variable[3]);
    color(7,0);
    color(15,0);
    affichageArgentJoueur(listeJoueur, 3, variable[3]);
    color(7,0);
    printf("                  *           *           |");
    color(7,0);
    printf("Caisse");
    color(7,0);
    printf("|\n");

    printf("|");
    posJoueur(listeJoueur, 32, variable[3]);
    printf("  ");
    color(14,0);
    affichageNomJoueur(listeJoueur, 4, variable[3]);
    color(7,0);
    color(15,0);
    affichageArgentJoueur(listeJoueur, 4, variable[3]);
    color(7,0);
    printf("                *           *             |");
    posJoueur(listeJoueur, 18, variable[3]);
    printf("\n");

    printf("|");
    color(2,0);
    affichageCasePropriete(plateauMonopoly, 32);
    color(7,0);
    printf("|  ");
    color(5,0);
    affichageNomJoueur(listeJoueur, 5, variable[3]);
    color(7,0);
    color(15,0);
    affichageArgentJoueur(listeJoueur, 5, variable[3]);
    color(7,0);
    printf("                    *     *               |");
    color(6,0);
    affichageCasePropriete(plateauMonopoly, 18);
    color(7,0);
    printf("|\n");

    printf("|");
    posJoueur(listeJoueur, 31, variable[3]);
    printf("  ");
    color(11,0);
    affichageNomJoueur(listeJoueur, 6, variable[3]);
    color(7,0);
    color(15,0);
    affichageArgentJoueur(listeJoueur, 6, variable[3]);
    color(7,0);
    printf("                        *                 |");
    posJoueur(listeJoueur, 19, variable[3]);
    printf("\n");

    printf("|");
    color(2,0);
    affichageCasePropriete(plateauMonopoly, 31);
    color(7,0);
    printf("|______________________________________________________________|");
    color(6,0);
    affichageCasePropriete(plateauMonopoly, 19);
    color(7,0);
    printf("|\n");

    printf("|");
    posJoueur(listeJoueur, 30, variable[3]);
    posJoueur(listeJoueur, 29, variable[3]);
    posJoueur(listeJoueur, 28, variable[3]);
    posJoueur(listeJoueur, 27, variable[3]);
    posJoueur(listeJoueur, 26, variable[3]);
    posJoueur(listeJoueur, 25, variable[3]);
    posJoueur(listeJoueur, 24, variable[3]);
    posJoueur(listeJoueur, 23, variable[3]);
    posJoueur(listeJoueur, 22, variable[3]);
    posJoueur(listeJoueur, 21, variable[3]);
    posJoueur(listeJoueur, 20, variable[3]);
    printf("\n");

    printf("|");
    color(7,0);
    printf("_-->#_");
    color(7,0);
    printf("|");
    color(14,0);
    affichageCasePropriete(plateauMonopoly, 29);
    color(7,0);
    printf("|");
    color(15,0);
    printf("_Eaux_");
    color(7,0);
    printf("|");
    color(14,0);
    affichageCasePropriete(plateauMonopoly, 27);
    color(7,0);
    printf("|");
    color(14,0);
    affichageCasePropriete(plateauMonopoly, 26);
    color(7,0);
    printf("|");
    color(15,0);
    printf("_Gare_");
    color(7,0);
    printf("|");
    color(4,0);
    affichageCasePropriete(plateauMonopoly, 24);
    color(7,0);
    printf("|");
    color(4,0);
    affichageCasePropriete(plateauMonopoly, 23);
    color(7,0);
    printf("|");
    color(7,0);
    printf("Chance");
    color(7,0);
    printf("|");
    color(4,0);
    affichageCasePropriete(plateauMonopoly, 21);
    color(7,0);
    printf("|");
    color(7,0);
    printf("_Parc_");
    color(7,0);
    printf("|\n");

    color(7,0);
}
