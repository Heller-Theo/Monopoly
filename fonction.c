#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "initialisation.h"
#include <ctype.h>




void viderBuffer() {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}




void verificationSaisie(int* choix) {
    int valide = 0, i = 0;
    unsigned int len = 0;
    char s[MAX_CARACT_LIGNE];

    do {
        valide = 0;
        printf(">");

        fgets(s, sizeof(s), stdin);
        len = strlen(s);

        //On supprime les espaces de la selection
        while (len > 0 && isspace(s[len - 1])) {
            len--;
        }

        if (len > 0)
        {
            valide = 1;
            for (i = 0; i < len; ++i)
            {
                //Si un des caractères n'est pas un nombre l'entrée n'est plus valide
                if (!isdigit(s[i]))
                {
                    valide = 0;
                    break;
                }
            }
            //On convertit la chaine de caractère en entier
            *choix = atoi(s);
        }
        if (!valide) {
            printf("Veuillez saisir une entree valide.\n");
        }
    } while (!valide);
}




void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    //On change la couleur du texte et du fond:
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}




void affichageInfoCase(int numeroCase, CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    printf("Case numero %d: %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
    printf("Prix: %d\n", plateauMonopoly[numeroCase].prixCase);
    printf("Maison: %d, Hotel: %d\n", plateauMonopoly[numeroCase].nombreMaison, plateauMonopoly[numeroCase].nombreHotel);
    printf("Detenu par le joueur: %d\n", plateauMonopoly[numeroCase].joueurPossesseur);
    printf("Hypotheque: %d\n", plateauMonopoly[numeroCase].hypotheque);
}




void affichagePrixCase(int numeroCase, CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    int i = 0;
    //En fonction de la case, on affiche tout ce qu'il faut savoir sur les prix.
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
                        printf("Valeur de l'hypotheque: %d\n", plateauMonopoly[numeroCase].prixCase / 2);
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
                            printf("Valeur de l'hypotheque: %d\n", plateauMonopoly[numeroCase].prixCase / 2);
                        }
                    }
                }
            }
        }
    }
}




void affichageInfoJoueur(int numeroJoueur, InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    printf("Joueur numero %d\n", numeroJoueur);
    printf("Nom joueur: %s\n", listeJoueur[numeroJoueur].nomJoueur);
    printf("Argent: %d\n", listeJoueur[numeroJoueur].argentJoueur);
    printf("Nombre de carte Libere de Prison: %d\n", listeJoueur[numeroJoueur].carteLiberePrison);
}




void affichagePossessionJoueur(int numeroJoueur, CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    int i = 0;

    printf("Le joueur %d possede :\n", numeroJoueur);

    for(i = 0; i < TAILLE_PLATEAU; i++) {
        if (plateauMonopoly[i].joueurPossesseur == numeroJoueur) {
            //Si il possède des maisons sur cette case on l'indique.
            if (plateauMonopoly[i].nombreMaison > 0) {
                printf("%s (%d maison(s))\n", plateauMonopoly[i].nomCase, plateauMonopoly[i].nombreMaison);
            }
            else {
                //Si il possède un hotel sur cette case on l'indique
                if (plateauMonopoly[i].nombreHotel == 1) {
                    printf("%s (%d Hotel)\n", plateauMonopoly[i].nomCase, plateauMonopoly[i].nombreHotel);
                }
                else {
                    //Si cette case est hypothéquée on l'indique.
                    if (plateauMonopoly[i].hypotheque == 1) {
                        printf("%s (hypotheque)\n", plateauMonopoly[i].nomCase);
                    }
                    else {
                        printf("%s\n", plateauMonopoly[i].nomCase);
                    }
                }
            }
        }
    }
}




void tirageDeuxDe(int* pResultat, int* pDoubleDe) {
    //On tire deux dé de 6 aléatoirement et on renvoie leur somme.
    //Si on a fait un double on renvoie 1 dans la variable *pDoubleDe , 0 sinon.
    int tirage1 = rand() % 6 + 1;
    int tirage2 = rand() % 6 + 1;
    printf("Vous avez eu un %d et un %d.\n", tirage1, tirage2);
    *pDoubleDe = (tirage1 == tirage2) ? 1 : 0;
    *pResultat = tirage1 + tirage2;
}




int monopoleCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase, int joueur) {
    int i = 0, monopole = 1;
    //Si une des cases d'un groupe n'appartient pas au joueur "joueur" alors il n'a pas le monopole sur ce groupe.
    for (i = 0; i < TAILLE_PLATEAU; i++) {
        if (plateauMonopoly[i].numeroGroupeCase == numeroGroupeCase) {
            if (plateauMonopoly[i].joueurPossesseur != joueur) {
                monopole = 0;
            }
        }
    }
    return monopole;
}




int nombreGareJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int joueur) {
    int i = 0, nombreGare = 0;
    //On compte sur les 4 cases gares lesquelles sont au joueur "joueur".
    for (i = 5; i < TAILLE_PLATEAU; i += 10) {
        if (plateauMonopoly[i].joueurPossesseur == joueur) {
            nombreGare += 1;
        }
    }
    return nombreGare;
}




int nombreMaisonJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int joueur) {
    int i = 0, nombreMaison = 0;
    //On compte sur chaque case qui appartient au joueur "joueur" combien il y a de maison.
    for (i = 0; i <TAILLE_PLATEAU; i++) {
        if (plateauMonopoly[i].joueurPossesseur == joueur) {
            nombreMaison += plateauMonopoly[i].nombreMaison;
        }
    }
    return nombreMaison;
}




int nombreHotelJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int joueur) {
    int i = 0, nombreHotel = 0;
    //On compte sur chaque case qui appartient au joueur "joueur" combien il y a d'hotel.
    for (i = 0; i < TAILLE_PLATEAU; i++) {
        if (plateauMonopoly[i].joueurPossesseur == joueur) {
            nombreHotel += plateauMonopoly[i].nombreHotel;
        }
    }
    return nombreHotel;
}




int hypothequeGroupe(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase) {
    int i = 0, hypotheque = 0;
    //On regarde si au moins une des cases du groupe est une case hypothéquée.
    for (i = 0; i < TAILLE_PLATEAU; i++) {
        if (plateauMonopoly[i].numeroGroupeCase == numeroGroupeCase) {
            if (plateauMonopoly[i].hypotheque) {
                hypotheque += 1;
            }
        }
    }
    return hypotheque;
}




int maisonHotelGroupe(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase) {
    int i = 0, maisonHotel = 0;
    //On regarde si au moins une des cases du groupe possède un battiment quelconque.
    for (i = 0; i < TAILLE_PLATEAU; i++) {
        if (plateauMonopoly[i].numeroGroupeCase == numeroGroupeCase) {
            if (plateauMonopoly[i].nombreMaison || plateauMonopoly[i].nombreHotel) {
                maisonHotel += 1;
            }
        }
    }
    return maisonHotel;
}




void achatMaison(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante) {
    int joueur = 0, groupePropriete = 0, numeroCase = 0, choix = 0, auMoinsUnChoix = 0;

    //Tant qu'il reste des maisons en jeu :
    if ( *pNombreMaisonRestante > 0) {

        printf("\nQuel joueur veux acheter des maisons ?\n");

        do {
            verificationSaisie(&joueur);
            if (joueur < 1 || joueur > 6) {
                printf("Veuillez saisir le numero d'un joueur.\n");
            }
        } while (joueur < 1 || joueur > 6);

        printf("\nVous pouvez acheter des maisons sur les cases suivantes :\n");
        for (groupePropriete = 1; groupePropriete <= 8 ; groupePropriete++) {

            //Si on a le monopole sur ce groupe
            if (monopoleCase(plateauMonopoly, groupePropriete, joueur) ) {

                //Si il n'y a pas de cases hypothéquées sur ce groupe
                if (!hypothequeGroupe(plateauMonopoly, groupePropriete)) {
                    for (numeroCase = 0; numeroCase < TAILLE_PLATEAU; numeroCase++) {
                        if (plateauMonopoly[numeroCase].numeroGroupeCase == groupePropriete) {

                            //Si sur les cases de ce groupes il n'y a pas d'hotel et moins de 4 maisons
                            if (plateauMonopoly[numeroCase].nombreHotel == 0 && plateauMonopoly[numeroCase].nombreMaison < 4) {

                                //Alors on peux acheter une maison sur cette case.
                                printf("%d) %s (%d francs)\n", numeroCase, plateauMonopoly[numeroCase].nomCase, plateauMonopoly[numeroCase].prixMaisonHotel[0]);
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
        printf("0) Retour\n");

        //On selectionne sur quelle case on veut acheter une maison
        do {
            verificationSaisie(&choix);
            if (choix < 0 || choix > 39) {
                printf("Veuillez selectionner le numero d'une case.\n");
            }
        } while (choix < 0 || choix > 39);


        if (choix == 0) {
            return;
        }

        //On exclut les cases de compagnie des eaux et d'electricité.
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
                        printf("\nVous avez maintenant %d maison(s) sur la case %s.\n", plateauMonopoly[choix].nombreMaison, plateauMonopoly[choix].nomCase);
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

    //Tant qu'il reste des hotels en jeu :
    if ( *pNombreHotelRestant > 0) {

        printf("\nQuel joueur veux acheter des hotels ?\n");

        do {
            verificationSaisie(&joueur);
            if (joueur < 1 || joueur > 6) {
                printf("Veuillez saisir un joueur.\n");
            }
        } while (joueur < 1 || joueur > 6);

        printf("\nVous pouvez acheter des hotels sur les cases suivantes :\n");
        for (numeroCase = 0; numeroCase < TAILLE_PLATEAU; numeroCase++) {

            //Si cette case nous appartient
            if (plateauMonopoly[numeroCase].joueurPossesseur == joueur) {

                //Si il y a deja 4 maisons sur cette case
                if (plateauMonopoly[numeroCase].nombreMaison == 4) {

                    //Alors on peut acheter un hotel dessus.
                    printf("%d) %s (%d francs)\n", numeroCase, plateauMonopoly[numeroCase].nomCase, plateauMonopoly[numeroCase].prixMaisonHotel[0]);
                    auMoinsUnChoix += 1;
                }
            }
        }

        if (!auMoinsUnChoix) {
            printf("Aucune\n");
            return;
        }
        printf("0) Retour\n");

        //On selectionne sur quelle case on veut acheter un hotel.
        do {
            verificationSaisie(&choix);
            if (choix < 0 || choix > 39) {
                printf("Veuillez selectionner le numero d'une case.\n");
            }
        } while (choix < 0 || choix > 39);

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
                    printf("\nVous avez maintenant un Hotel sur la case %s.\n", plateauMonopoly[choix].nomCase);
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

    printf("\nQuel joueur veux vendre des biens ?\n");

    do {
        verificationSaisie(&joueur);
        if (joueur < 1 || joueur > 6) {
            printf("Veuillez saisir le numero d'un joueur.\n");
        }
    } while (joueur < 1 || joueur > 6);

    printf("\nVous pouvez vendre des maisons sur les cases suivantes :\n");
    for (numeroCase = 0; numeroCase < TAILLE_PLATEAU; numeroCase++) {

        //Si cette case nous appartient
        if (plateauMonopoly[numeroCase].joueurPossesseur == joueur) {

            //Si il y a au moins une maison sur cette case
            if (plateauMonopoly[numeroCase].nombreMaison >= 1) {

                //Alors on peut vendre une maison sur cette case.
                printf("%d) %s (%d francs)\n", numeroCase, plateauMonopoly[numeroCase].nomCase, plateauMonopoly[numeroCase].prixMaisonHotel[0] / 2);
                auMoinsUnChoix += 1;
            }
        }
    }

    if (!auMoinsUnChoix) {
        printf("Aucune\n");
        return;
    }
    printf("0) Retour\n");

    //On selectionne sur quelle case on veut vendre une maison.
    do {
        verificationSaisie(&choix);
        if (choix < 0 || choix > 39) {
            printf("Veuillez selectionner le numero d'une case.\n");
        }
    } while (choix < 0 || choix > 39);

    if (choix == 0) {
        return;
    }

    if (plateauMonopoly[choix].joueurPossesseur == joueur) {
        if (plateauMonopoly[choix].nombreMaison >= 1) {
            listeJoueur[joueur].argentJoueur += plateauMonopoly[choix].prixMaisonHotel[0] / 2;
            plateauMonopoly[choix].nombreMaison -= 1;
            *pNombreMaisonRestante += 1;
            printf("\nVous avez vendu une maison sur la case %s.\n", plateauMonopoly[choix].nomCase);
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

    printf("\nQuel joueur veux vendre des biens ?\n");

    do {
        verificationSaisie(&joueur);
        if (joueur < 1 || joueur > 6) {
            printf("Veuillez saisir le numero d'un joueur.\n");
        }
    } while (joueur < 1 || joueur > 6);

    printf("\nVous pouvez vendre des hotels sur les cases suivantes :\n");
    for (numeroCase = 0; numeroCase < TAILLE_PLATEAU; numeroCase++) {

        //Si cette case nous appartient
        if (plateauMonopoly[numeroCase].joueurPossesseur == joueur) {

            //Si il y a un hotel sur cette case
            if (plateauMonopoly[numeroCase].nombreHotel == 1) {

                //Alors on peut vendre cet hotel
                printf("%d) %s (%d francs)\n", numeroCase, plateauMonopoly[numeroCase].nomCase, plateauMonopoly[numeroCase].prixMaisonHotel[0] / 2);
                auMoinsUnChoix += 1;
            }
        }
    }

    if (!auMoinsUnChoix) {
        printf("Aucune\n");
        return;
    }
    printf("0) Retour\n");

    //On selectionne sur quelle case on veut vendre un hotel.
    do {
        verificationSaisie(&choix);
        if (choix < 0 || choix > 39) {
            printf("Veuillez selectionner le numero d'une case.\n");
        }
    } while (choix < 0 || choix > 39);

    if (choix == 0) {
        return;
    }

    if (plateauMonopoly[choix].joueurPossesseur == joueur) {
        if (plateauMonopoly[choix].nombreHotel == 1) {

            printf("\nVoulez vous vendre votre hotel et les 4 maisons ou seulement l'hotel ?\n");
            printf("1) Tout vendre pour %d francs\n", plateauMonopoly[choix].prixMaisonHotel[0] * 5 / 2);
            printf("2) Vendre seulement l'hotel pour %d francs\n", plateauMonopoly[choix].prixMaisonHotel[0] / 2);

            do {
                verificationSaisie(&choix2);
                if (choix2 != 1 && choix2 != 2) {
                    printf("Veuillez saisir un choix valide.\n");
                }
            } while (choix2 != 1 && choix2 != 2);

            if (choix2 == 1) {
                listeJoueur[joueur].argentJoueur += plateauMonopoly[choix].prixMaisonHotel[0] * 5 / 2;
                plateauMonopoly[choix].nombreHotel = 0;
                plateauMonopoly[choix].nombreMaison = 0;
                *pNombreHotelRestant += 1;
                *pNombreMaisonRestante += 4;
                printf("\nVous avez vendu tous vos bien sur la case %s.\n", plateauMonopoly[choix].nomCase);
                printf("Il reste %d Hotel(s) dans le jeu.\n", *pNombreHotelRestant);
                printf("Il reste %d Maison(s) dans le jeu.\n", *pNombreMaisonRestante);
            }
            else {
                if (choix2 == 2) {
                    //On regarde si il reste suffisamment de maison pour remplacer l'hotel par 4 maisons.
                    if (*pNombreMaisonRestante >= 4) {
                        listeJoueur[joueur].argentJoueur += plateauMonopoly[choix].prixMaisonHotel[0] / 2;
                        plateauMonopoly[choix].nombreHotel = 0;
                        plateauMonopoly[choix].nombreMaison = 4;
                        *pNombreHotelRestant += 1;
                        *pNombreMaisonRestante -= 4;
                        printf("\nVous avez vendu votre hotel sur la case %s.\n", plateauMonopoly[choix].nomCase);
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




void hypothequeCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    int joueur = 0, groupePropriete = 0, numeroCase = 0, choix = 0, auMoinsUnChoix = 0;

    printf("\nQuel joueur veux hypothequer une case ?\n");

    do {
        verificationSaisie(&joueur);
        if (joueur < 1 || joueur > 6) {
            printf("Veuillez saisir le numero d'un joueur.\n");
        }
    } while (joueur < 1 || joueur > 6);

    printf("\nVous pouvez hypothequer les cases suivantes :\n");
    for (groupePropriete = 1; groupePropriete <= 10 ; groupePropriete++) {

        //Si il n'y a pas de battiment sur ce groupe de case
        if (!maisonHotelGroupe(plateauMonopoly, groupePropriete)) {
            for (numeroCase = 0; numeroCase < TAILLE_PLATEAU; numeroCase++) {

                //Si cette case est à moi
                if (plateauMonopoly[numeroCase].joueurPossesseur == joueur) {

                    //Si cette case est hypothéquée
                    if (plateauMonopoly[numeroCase].hypotheque == 0) {

                        //Si cette case appartient au groupe de case qui ne possède pas de battiment
                        if (plateauMonopoly[numeroCase].numeroGroupeCase == groupePropriete) {

                            //Alors on peut hypothéquer cette case
                            printf("%d) %s (%d francs)\n", numeroCase, plateauMonopoly[numeroCase].nomCase, plateauMonopoly[numeroCase].prixCase / 2);
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
    printf("0) Retour\n");

    //On selectionne quelle case on veut hypothéquer

    do {
        verificationSaisie(&choix);
        if (choix < 0 || choix > 39) {
            printf("Veuillez selectionner le numero d'une case.\n");
        }
    } while (choix < 0 || choix > 39);

    if (choix == 0) {
        return;
    }

    if (plateauMonopoly[choix].joueurPossesseur == joueur) {
        if (!maisonHotelGroupe(plateauMonopoly, plateauMonopoly[choix].numeroGroupeCase)) {
            if (plateauMonopoly[choix].hypotheque == 0) {
                listeJoueur[joueur].argentJoueur += plateauMonopoly[choix].prixCase / 2;
                plateauMonopoly[choix].hypotheque = 1;
                printf("\nVous avez hypotheque la case %s et recu %d francs.\n", plateauMonopoly[choix].nomCase, plateauMonopoly[choix].prixCase / 2);
            }
            else {
                printf("Cette propriete est deja hypotheque\n");
            }
        }
        else {
            printf("Il y a une propriete avec des batiments sur un des terrains de ce groupe.\n");
        }
    }
    else {
        printf("Cette case ne vous appartient pas.\n");
    }
}




void leverHypotheque(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    int joueur = 0, numeroCase = 0, choix = 0, auMoinsUnChoix = 0;

    printf("\nQuel joueur veux lever une hypothequer ?\n");

    do {
        verificationSaisie(&joueur);
        if (joueur < 1 || joueur > 6) {
            printf("Veuillez saisir le numero d'un joueur.\n");
        }
    } while (joueur < 1 || joueur > 6);

    printf("\nVous pouvez lever les hypotheques des cases suivantes :\n");
    for (numeroCase = 0; numeroCase < TAILLE_PLATEAU; numeroCase++) {

        //Si cette case est hypothéquée et quelle est à moi
        if (plateauMonopoly[numeroCase].hypotheque && plateauMonopoly[numeroCase].joueurPossesseur == joueur) {

            //Alors on peut lever l'hypothèque de cette case.
            printf("%d) %s (%d + %d francs)\n", numeroCase, plateauMonopoly[numeroCase].nomCase, plateauMonopoly[numeroCase].prixCase / 2, plateauMonopoly[numeroCase].prixCase / 20);
            auMoinsUnChoix += 1;
        }
    }

    if (!auMoinsUnChoix) {
        printf("Aucune\n");
        return;
    }
    printf("0) Retour\n");

    //On selectionne sur quelle case on veut lever l'hypothèque
    do {
        verificationSaisie(&choix);
        if (choix < 0 || choix > 39) {
            printf("Veuillez selectionner le numero d'une case.\n");
        }
    } while (choix < 0 || choix > 39);

    if (choix == 0) {
        return;
    }

    if (plateauMonopoly[choix].hypotheque) {
        if (plateauMonopoly[choix].joueurPossesseur == joueur) {
            if (listeJoueur[joueur].argentJoueur >= plateauMonopoly[choix].prixCase * 11 / 20) {
                //Pour lever l'hypothèque il faut payer la moitié + 10% de cette moitié du prix d'achat d'une case.
                listeJoueur[joueur].argentJoueur -= plateauMonopoly[choix].prixCase * 11 / 20;
                plateauMonopoly[choix].hypotheque = 0;
                printf("\nVous avez leve l'hypotheque de la case %s et paye %d francs.\n", plateauMonopoly[choix].nomCase, plateauMonopoly[choix].prixCase * 11 / 20);
            }
            else {
                printf("Vous n'avez pas assez d'argent pour lever l'hypotheque.\n");
            }
        }
        else {
            printf("Cette case ne vous appartient pas.\n");
        }
    }
    else {
        printf("Cette case n'est pas hypotheque.\n");
    }
}




void venteCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    int joueur = 0, joueur2 = 0, prix = 0, numeroCase = 0, choix = 0, auMoinsUnChoix = 0;

    printf("\nQuel joueur veux vendre une de ses cases ?\n");

    do {
        verificationSaisie(&joueur);
        if (joueur < 1 || joueur > 6) {
            printf("Veuillez saisir le numero d'un joueur.\n");
        }
    } while (joueur < 1 || joueur > 6);

    printf("\nVous pouvez vendre les cases suivantes :\n");
    for (numeroCase = 0; numeroCase < TAILLE_PLATEAU; numeroCase++) {

        //Si cette case est à nous et qu'elle est hypothéquée
        if (plateauMonopoly[numeroCase].hypotheque && plateauMonopoly[numeroCase].joueurPossesseur == joueur) {

            //Alors on peut vendre cette case.
            printf("%d) %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
            auMoinsUnChoix += 1;
        }
    }

    if (!auMoinsUnChoix) {
        printf("Aucune\n");
        return;
    }
    printf("0) Retour\n");

    //On selectionne quelle case on veut vendre.
    do {
        verificationSaisie(&numeroCase);
        if (numeroCase < 0 || numeroCase > 39) {
            printf("Veuillez selectionner le numero d'une case.\n");
        }
    } while (numeroCase < 0 || numeroCase > 39);

    if (numeroCase == 0) {
        return;
    }

    if (plateauMonopoly[numeroCase].hypotheque) {
        if (plateauMonopoly[numeroCase].joueurPossesseur == joueur) {
            printf("A quel prix vendez vous cette case ?\n");

            verificationSaisie(&prix);

            printf("\nQuel joueur veux acheter la case %d: %s pour %d + %d francs ?\n", numeroCase, plateauMonopoly[numeroCase].nomCase, prix, plateauMonopoly[numeroCase].prixCase / 20);
            printf("Tapez 0 si personne ne veut\n");

            do {
                verificationSaisie(&joueur2);
                if (joueur2 < 1 || joueur2 > 6) {
                    printf("Veuillez saisir le numero d'un joueur.\n");
                }
            } while (joueur2 < 1 || joueur2 > 6);

            if (joueur2 == 0) {
                return;
            }

            if (joueur2 != joueur) {
                if (listeJoueur[joueur2].argentJoueur >= prix + plateauMonopoly[numeroCase].prixCase / 20) {
                    listeJoueur[joueur2].argentJoueur -= prix + plateauMonopoly[numeroCase].prixCase / 20;
                    listeJoueur[joueur].argentJoueur += prix;
                    plateauMonopoly[numeroCase].joueurPossesseur = joueur2;
                    printf("Vous possedez maintenant %s et %s a recu %d francs.\n", plateauMonopoly[numeroCase].nomCase, listeJoueur[joueur].nomJoueur, prix);
                    printf("Voulez vous lever l'hypoteque immediatement pour %d francs ?\n", plateauMonopoly[numeroCase].prixCase / 2);

                    do {
                        verificationSaisie(&choix);
                        if (choix != 0 && choix != 1) {
                            printf("Veuillez saisir un choix valide.\n");
                        }
                    } while (choix != 0 && choix != 1);

                    if (choix) {
                        if (listeJoueur[joueur2].argentJoueur >= plateauMonopoly[numeroCase].prixCase / 2) {
                            listeJoueur[joueur2].argentJoueur -= plateauMonopoly[numeroCase].prixCase / 2;
                            plateauMonopoly[numeroCase].hypotheque = 0;
                            printf("Vous avez lever l'hypotheque de la case %d: %s\n", numeroCase, plateauMonopoly[numeroCase].nomCase);
                        }
                        else {
                            printf("Vous n'avez pas assez d'argent pour lever immediatement l'hypotheque.\n");
                        }
                    }
                    else {
                        printf("Cette case reste donc hypotheque.\n");
                    }
                }
                else {
                    printf("Vous n'avez pas assez d'argent pour acquerir cette case.\n");
                }
            }
            else {
                printf("Cette case vous appartient deja.\n");
            }
        }
        else {
            printf("Cette case ne vous appartient pas.\n");
        }
    }
    else {
        printf("Cette case n'est pas hypotheque et ne peut donc pas etre vendu.\n");
    }
}




void achatCarteLibere(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int listeVariable[NOMBRE_VARIABLE], int joueur) {
    int i = 0, choix = 0, prix = 0, joueur2 = 0;

    printf("\nVous pouvez acheter une carte de liberation de prison a:\n");
    printf("0) Personne\n");
    for (i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        if (listeJoueur[i].carteLiberePrison >= 1 && i != joueur) {
            printf("%d) %s\n", i, listeJoueur[i].nomJoueur);
        }
    }

    verificationSaisie(&joueur2);

    //Si le joueur choisi n'est pas nous et qu'il possède bien une carte de liberation de prison:
    if (listeJoueur[joueur2].carteLiberePrison >= 1 && joueur2 != joueur) {
        printf("\nEst-ce que %s veut vendre sa carte ?\n", listeJoueur[joueur2].nomJoueur);
        printf("0) Non\n");
        printf("1) Oui\n");

        do {
            verificationSaisie(&choix);
            if (choix != 0 && choix != 1) {
                printf("Veuillez saisir 0 ou 1.\n");
            }
        } while (choix != 0 && choix != 1);

        if (choix == 1) {
            printf("\nPour combien voulez vous la vendre ?\n");
            verificationSaisie(&prix);

            printf("\nEst ce que %s accepte ce prix ?\n", listeJoueur[joueur].nomJoueur);
            printf("0) Non\n");
            printf("1) Oui\n");

            do {
                verificationSaisie(&choix);
                if (choix != 0 && choix != 1) {
                    printf("Veuillez saisir 0 ou 1.\n");
                }
            } while (choix != 0 && choix != 1);

            if (choix == 1) {
                if (listeJoueur[joueur].argentJoueur >= prix) {
                    listeJoueur[joueur].argentJoueur -= prix;
                    listeJoueur[joueur2].argentJoueur += prix;
                    listeJoueur[joueur].carteLiberePrison += 1;
                    listeJoueur[joueur2].carteLiberePrison -= 1;
                }
                else {
                    printf("Vous n'avez pas assez d'argent pour faire l'echange.\n");
                }
            }
            else {
                printf("L'echange a ete annule.\n");
            }
        }
        else {
            printf("L'echange a ete annule.\n");
        }
    }
    else {
        if (joueur2 != 0) {
            printf("Ce joueur ne peut pas vous vendre de carte.\n");
        }
    }
}




int checkJeu(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante, int* pNombreHotelRestant) {
    int verif = 0, choix1 = 0, choix2 = 0;

    do {
        printf("\nContinuer ");

        do {
            verificationSaisie(&verif);
            if (verif != 0 && verif != 1 && verif != 2) {
                printf("\nVeuillez saisir:\n");
                printf("0) Pour quitter\n");
                printf("1) Pour continuer\n");
                printf("2) Pour faire une action\n");
            }
        } while (verif != 0 && verif != 1 && verif != 2);

        if (verif == 0) {
            printf("Etes vous sur de vouloir quitter la partie ?\n");
            printf("0) Quitter\n");
            printf("1) Rester en jeu\n");

            do {
                verificationSaisie(&choix1);
                if (choix1 != 0 && choix1 != 1) {
                    printf("Veuillez saisir 0 pour quitter ou 1 pour rester.\n");
                }
            } while (choix1 != 0 && choix1 != 1);

            if (choix1 == 0) {
                return 0;
            }
        }

        if (verif == 2) {
            printf("\nQue voulez vous faire ?\n");
            printf("0) Retour\n");
            printf("1) Info sur une case ou un joueur.\n");
            printf("2) Achat et vente de maison et d'hotel\n");
            printf("3) Hypotheque et vente de case\n");


            do {
                verificationSaisie(&choix1);
                if (choix1 != 0 && choix1 != 1 && choix1 != 2 && choix1 != 3) {
                    printf("Veuillez saisir un choix valide.\n");
                }
            } while (choix1 != 0 && choix1 != 1 && choix1 != 2 && choix1 != 3);

            if (choix1 == 1) {
                printf("\nQuelles informations voulez vous ?\n");
                printf("0) Retour\n");
                printf("1) Info Technique d'une case\n");
                printf("2) Info Prix d'une case\n");
                printf("3) Info Joueur\n");
                printf("4) Info Possession Joueur\n");

                do {
                    verificationSaisie(&choix2);
                    if (choix2 != 0 && choix2 != 1 && choix2 != 2 && choix2 != 3 && choix2 != 4) {
                        printf("Veuillez saisir un choix valide.\n");
                    }
                } while (choix2 != 0 && choix2 != 1 && choix2 != 2 && choix2 != 3 && choix2 != 4);

                if (choix2 == 1) {
                    printf("Choisissez une case :\n");
                    do {
                        verificationSaisie(&choix2);
                        if (choix2 < 0 || choix2 > 39) {
                            printf("Veuillez saisir une case.\n");
                        }
                    } while (choix2 < 0 || choix2 > 39);
                    //On affiche les informations sur la case choisie
                    affichageInfoCase(choix2, plateauMonopoly);
                }
                if (choix2 == 2) {
                    printf("Choisissez une case :\n");
                    do {
                        verificationSaisie(&choix2);
                        if (choix2 < 0 || choix2 > 39) {
                            printf("Veuillez saisir une case.\n");
                        }
                    } while (choix2 < 0 || choix2 > 39);
                    //On affiche les prix de la case choisie
                    affichagePrixCase(choix2, plateauMonopoly);
                }
                if (choix2 == 3) {
                    printf("Choisissez un joueur :\n");
                    do {
                        verificationSaisie(&choix2);
                        if (choix2 < 1 || choix2 > 6) {
                            printf("Veuillez saisir un joueur.\n");
                        }
                    } while (choix2 < 1 || choix2 > 6);
                    //On affiche les informations du joueur choisi.
                    affichageInfoJoueur(choix2, listeJoueur);
                }
                if (choix2 == 4) {
                    printf("Choisissez un joueur :\n");
                    do {
                        verificationSaisie(&choix2);
                        if (choix2 < 1 || choix2 > 6) {
                            printf("Veuillez saisir un joueur.\n");
                        }
                    } while (choix2 < 1 || choix2 > 6);
                    //On affiche les possessions du joueur choisi.
                    affichagePossessionJoueur(choix2, plateauMonopoly);
                }
            }

            if (choix1 == 2) {
                printf("\nQue voulez vous faire :\n");
                printf("0) Retour\n");
                printf("1) Acheter une Maison\n");
                printf("2) Acheter un Hotel\n");
                printf("3) vendre une Maison\n");
                printf("4) vendre un Hotel\n");

                do {
                    verificationSaisie(&choix2);
                    if (choix2 != 0 && choix2 != 1 && choix2 != 2 && choix2 != 3 && choix2 != 4) {
                        printf("Veuillez saisir un choix valide.\n");
                    }
                } while (choix2 != 0 && choix2 != 1 && choix2 != 2 && choix2 != 3 && choix2 != 4);

                if (choix2 == 1) {
                    //On achète une maison
                    achatMaison(plateauMonopoly, listeJoueur, pNombreMaisonRestante);
                }
                if (choix2 == 2) {
                    //On achète un hotel
                    achatHotel(plateauMonopoly, listeJoueur, pNombreHotelRestant, pNombreMaisonRestante);
                }
                if (choix2 == 3) {
                    //On vend une maison
                    venteMaison(plateauMonopoly, listeJoueur, pNombreMaisonRestante);
                }
                if (choix2 == 4) {
                    //On vend un hotel
                    venteHotel(plateauMonopoly, listeJoueur, pNombreHotelRestant, pNombreMaisonRestante);
                }
            }
            if (choix1 == 3) {
                printf("\nQue voulez vous faire :\n");
                printf("0) Retour\n");
                printf("1) Hypothequer une case\n");
                printf("2) Lever l'hypotheque d'une case\n");
                printf("3) Vendre une case a un autre joueur\n");

                do {
                    verificationSaisie(&choix2);
                    if (choix2 != 0 && choix2 != 1 && choix2 != 2 && choix2 != 3) {
                        printf("Veuillez saisir un choix valide.\n");
                    }
                } while (choix2 != 0 && choix2 != 1 && choix2 != 2 && choix2 != 3);

                if (choix2 == 1) {
                    //On hypotheque une case
                    hypothequeCase(plateauMonopoly, listeJoueur);
                }
                if (choix2 == 2) {
                    //On leve l'hypotheque d'une case
                    leverHypotheque(plateauMonopoly, listeJoueur);
                }
                if (choix2 == 3) {
                    //On vend une case hypothéquée
                    venteCase(plateauMonopoly, listeJoueur);
                }
            }
        }
    } while (verif != 1);

    return 1;
}




void failliteJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int joueur, int numeroCase, int dette, int* pNombreMaisonRestante, int* pNombreHotelRestant) {
    int choix = 0, choix2 = 0, verif = 0, numeroCase2 = 0;

    printf("\nVous devez effectuer des actions pour rembourser votre dette avec le menu Continuer >\n");
    printf("Si vous avez reussi a trouver l'argent ou que vous voulez abandonner tapez 1.\n");
    printf("Sinon tapez 2 pour effectuer des actions.\n");

    do {
        printf("\nVous avez une dette de %d francs et vous avez %d francs.\n", dette, listeJoueur[joueur].argentJoueur);

        checkJeu(plateauMonopoly, listeJoueur, pNombreMaisonRestante, pNombreHotelRestant);

        if (listeJoueur[joueur].argentJoueur < dette) {
            printf("Vous n'avez toujours pas assez d'argent pour rembourser votre dette.\n");
            printf("Que voulez vous faire:\n");
            printf("0) Se mettre en faillite\n");
            printf("1) Tenter de regler votre dette\n");

            do {
                verificationSaisie(&choix);
                if (choix != 0 && choix != 1) {
                    printf("Veuillez saisir un choix valide.\n");
                }
            } while (choix != 0 && choix != 1);

            //Si on décide d'abandonner :
            if (choix == 0) {

                //Si notre dette est envers un autre joueur :
                if (plateauMonopoly[numeroCase].joueurPossesseur != 0) {
                    for (numeroCase2 = 0; numeroCase2 < TAILLE_PLATEAU; numeroCase2++) {
                        if (plateauMonopoly[numeroCase2].joueurPossesseur == joueur) {

                            //On vend les maisons de nos propriétés
                            if (plateauMonopoly[numeroCase2].nombreMaison) {
                                listeJoueur[joueur].argentJoueur += plateauMonopoly[numeroCase2].prixMaisonHotel[0] * plateauMonopoly[numeroCase2].nombreMaison / 2;
                                *pNombreMaisonRestante += plateauMonopoly[numeroCase2].nombreMaison;
                                plateauMonopoly[numeroCase2].nombreMaison = 0;
                                printf("Les maisons de la case %s ont ete vendu.\n", plateauMonopoly[numeroCase2].nomCase);
                            }

                            //On vend les hotels de nos propriétés
                            if (plateauMonopoly[numeroCase2].nombreHotel) {
                                listeJoueur[joueur].argentJoueur += plateauMonopoly[numeroCase2].prixMaisonHotel[0] * 5 / 2;
                                plateauMonopoly[numeroCase2].nombreHotel = 0;
                                *pNombreHotelRestant += 1;
                                printf("L'hotel de la case %s a ete vendu.\n", plateauMonopoly[numeroCase2].nomCase);
                            }

                            //On propose de lever l'hypothèque au joueur envers qui nous sommes endettés.
                            if (plateauMonopoly[numeroCase2].hypotheque) {
                                printf("%s paye %d pour recuperer l'hypotheque de la case %s.\n", listeJoueur[plateauMonopoly[numeroCase].joueurPossesseur].nomJoueur,
                                       plateauMonopoly[numeroCase2].prixCase / 20, plateauMonopoly[numeroCase2].nomCase);
                                listeJoueur[plateauMonopoly[numeroCase].joueurPossesseur].argentJoueur -= plateauMonopoly[numeroCase2].prixCase;

                                printf("Voulez vous payer %d pour lever l'hypotheque ?\n", plateauMonopoly[numeroCase2].prixCase / 2);

                                do {
                                    verificationSaisie(&choix2);
                                    if (choix2 != 0 && choix2 != 1) {
                                        printf("Veuillez saisir 0 pour non et 1 pour oui.\n");
                                    }
                                } while (choix2 != 0 && choix2 != 1);

                                if (choix2 == 1) {
                                    if (listeJoueur[plateauMonopoly[numeroCase].joueurPossesseur].argentJoueur >= plateauMonopoly[numeroCase2].prixCase / 2) {
                                        listeJoueur[plateauMonopoly[numeroCase].joueurPossesseur].argentJoueur -= plateauMonopoly[numeroCase2].prixCase / 2;
                                        plateauMonopoly[numeroCase2].hypotheque = 0;
                                    }
                                }
                            }

                            //On transfert nos propriétés au joueurs envers qui nous sommes endettés
                            plateauMonopoly[numeroCase2].joueurPossesseur = plateauMonopoly[numeroCase].joueurPossesseur;

                            //Si la vente des maisons et des hotels a couvert notre dette, on peut intégralement rembourser notre dette.
                            if (listeJoueur[joueur].argentJoueur >= dette) {
                                listeJoueur[plateauMonopoly[numeroCase].joueurPossesseur].argentJoueur += dette;
                            }
                            //Sinon on donne ce que l'on peut pour regler notre dette.
                            else {
                                listeJoueur[plateauMonopoly[numeroCase].joueurPossesseur].argentJoueur += listeJoueur[joueur].argentJoueur;
                            }
                        }
                    }
                }

                //Si nous sommes endettés envers la banque :
                else {
                    for (numeroCase2 = 0; numeroCase2 < TAILLE_PLATEAU; numeroCase2++) {
                        if (plateauMonopoly[numeroCase2].joueurPossesseur == joueur) {

                            //On vend les maisons de nos propriétés
                            if (plateauMonopoly[numeroCase2].nombreMaison) {
                                *pNombreMaisonRestante += plateauMonopoly[numeroCase2].nombreMaison;
                                plateauMonopoly[numeroCase2].nombreMaison = 0;
                                printf("Les maisons de la case %s sont remises en jeu.\n", plateauMonopoly[numeroCase2].nomCase);
                            }

                            //On vend les hotels de nos propriétés
                            if (plateauMonopoly[numeroCase2].nombreHotel) {
                                plateauMonopoly[numeroCase2].nombreHotel = 0;
                                *pNombreHotelRestant += 1;
                                printf("L'hotel de la case %s est remis en jeu.\n", plateauMonopoly[numeroCase2].nomCase);
                            }

                            //On lève les hypothèques de chaque cases
                            if (plateauMonopoly[numeroCase2].hypotheque) {
                                plateauMonopoly[numeroCase2].hypotheque = 0;
                            }

                            //On remet toutes nos cases en jeu (le nouveau joueur possesseur devient le joueur 0)
                            plateauMonopoly[numeroCase2].joueurPossesseur = plateauMonopoly[numeroCase].joueurPossesseur;
                        }
                    }
                }
                //On met en faillite le joueur en actualisant son argent à -1
                listeJoueur[joueur].argentJoueur = -1;
                return;
            }
            if (choix == 1) {
                verif = 0;
            }
        }
        //Si on peut rembourser notre dette, on la rembourse et le jeu peut reprendre.
        else {
            listeJoueur[joueur].argentJoueur -= dette;
            listeJoueur[plateauMonopoly[numeroCase].joueurPossesseur].argentJoueur += dette;
            verif = 1;
        }
    } while (!verif);
}




void randomOrdreCaisseChance(int listeAleatoire[16]) {
    int nombreAleatoire = 0, i = 0;
    int liste[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    //On remplit une liste de 16 éléments avec les entiers de 1 à 16 aléatoirement.
    for (i = 0; i < 16; i++) {
        do {
            nombreAleatoire = rand() % 16 + 1;
        } while (liste[nombreAleatoire-1] == 0);
        liste[nombreAleatoire-1] = 0;
        listeAleatoire[i] = nombreAleatoire;
    }
}




void posJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroCase, int nombreJoueur) {
    //Si un joueur est sur la case "numeroCase" alors il sera affiché.

    if (listeJoueur[1].caseJoueur == numeroCase && listeJoueur[1].argentJoueur != -1) {
        color(1,0);
        printf("1");
        color(7,0);
    }
    else {
        printf(" ");
    }

    if (listeJoueur[2].caseJoueur == numeroCase && listeJoueur[2].argentJoueur != -1) {
        color(4,0);
        printf("2");
        color(7,0);
    }
    else {
        printf(" ");
    }

    if (nombreJoueur >= 3 && listeJoueur[3].caseJoueur == numeroCase && listeJoueur[3].argentJoueur != -1) {
        color(2,0);
        printf("3");
        color(7,0);
    }
    else {
        printf(" ");
    }

    if (nombreJoueur >= 4 && listeJoueur[4].caseJoueur == numeroCase && listeJoueur[4].argentJoueur != -1) {
        color(14,0);
        printf("4");
        color(7,0);
    }
    else {
        printf(" ");
    }

    if (nombreJoueur >= 5 && listeJoueur[5].caseJoueur == numeroCase && listeJoueur[5].argentJoueur != -1) {
        color(5,0);
        printf("5");
        color(7,0);
    }
    else {
        printf(" ");
    }

    if (nombreJoueur >= 6 && listeJoueur[6].caseJoueur == numeroCase && listeJoueur[6].argentJoueur != -1) {
        color(11,0);
        printf("6");
        color(7,0);
    }
    else {
        printf(" ");
    }

    printf("|");
}




void affichageArgentJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroJoueur, int nombreJoueur) {
    char affichageArgent[7] = "";

    //On affiche l'argent avec des epsaces en fonction de la taille qu'il faut pour l'ecrire pour garder un affichage propre.
    if (numeroJoueur <= nombreJoueur) {
        if (listeJoueur[numeroJoueur].argentJoueur < 10) {
            strcat(affichageArgent,"      ");
        }
        else {
            if (listeJoueur[numeroJoueur].argentJoueur < 100) {
                strcat(affichageArgent,"     ");
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
        }

        //On affiche le bon nombre d'espace
        printf("%s", affichageArgent);

        //Puis l'argent que le joueur possède si il n'est pas en faillite. Sinon on affiche "F".
        if (listeJoueur[numeroJoueur].argentJoueur >= 0) {
            printf("%d", listeJoueur[numeroJoueur].argentJoueur);
        }
        else {
            printf("F");
        }

    }
    //On affiche rien si le joueur n'est pas en jeu.
    else {
        printf("       ");
    }
}




void affichageNomJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroJoueur, int nombreJoueur) {
    int i = 0;
    //On affiche le nom des joueurs en jeu et on ajoute des espaces pour un affichage propre selon la taille de leur nom.
    if (numeroJoueur <= nombreJoueur) {
        unsigned int longueurNom = strlen(listeJoueur[numeroJoueur].nomJoueur);
        char affichageNom[TAILLE_MAX_NOM_JOUEUR] = "";
        for (i = 0; i < TAILLE_MAX_NOM_JOUEUR - longueurNom - 1; i++) {
            strcat(affichageNom, " ");
        }
        printf("%s", listeJoueur[numeroJoueur].nomJoueur);
        printf("%s:", affichageNom);
    }
    //On affiche rien si le joueur n'est pas en jeu.
    else {
        printf("           ");
    }
}




void affichageCasePropriete(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroCase) {
    //On affiche les informations des propriétés sous chaque case en fonction de leur etat.

    if (plateauMonopoly[numeroCase].joueurPossesseur) {
        //Si la propriété est hypothéquée
        if (plateauMonopoly[numeroCase].hypotheque) {
            printf("_%d__X_", plateauMonopoly[numeroCase].joueurPossesseur);
        }
        else {
            //Si il y a des maisons dessus
            if (plateauMonopoly[numeroCase].nombreMaison) {
                printf("_%d_%dM_", plateauMonopoly[numeroCase].joueurPossesseur, plateauMonopoly[numeroCase].nombreMaison);
            }
            else {
                //Si il y a un hotel dessus
                if (plateauMonopoly[numeroCase].nombreHotel) {
                    printf("_%d__H_", plateauMonopoly[numeroCase].joueurPossesseur);
                }
                //Si il n'y a rien de particulier
                else {
                    printf("__%d___", plateauMonopoly[numeroCase].joueurPossesseur);
                }
            }
        }
    }
    //Si la propriété n'appartient à personne
    else {
        //On affiche le prix de la case
        if (plateauMonopoly[numeroCase].prixCase < 10000) {
            printf("__%dk__", plateauMonopoly[numeroCase].prixCase / 1000);
        }
        else {
            printf("_%dk__", plateauMonopoly[numeroCase].prixCase / 1000);
        }
    }
}




void affichageAutreCases(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroCase) {
    //On affiche les informations des gares et des compagnies de distribution des eaux et d'éléctricité en fonction de leur etat.
    color(15,0);
    if (numeroCase == 5 || numeroCase == 15 || numeroCase == 25 || numeroCase == 35) {
        if (plateauMonopoly[numeroCase].joueurPossesseur) {
            //Si la case est hypothéquée
            if (plateauMonopoly[numeroCase].hypotheque) {
                printf("%dGareX", plateauMonopoly[numeroCase].joueurPossesseur);
            }
            //Sinon
            else {
                printf("%d_Gare", plateauMonopoly[numeroCase].joueurPossesseur);
            }
        }
        //Si la case n'appartient à personne
        else {
            printf("_Gare_");
        }
    }
    if (numeroCase == 12) {
        if (plateauMonopoly[numeroCase].joueurPossesseur) {
            //Si la case est hypothéquée
            if (plateauMonopoly[numeroCase].hypotheque) {
                printf("%dElecX", plateauMonopoly[numeroCase].joueurPossesseur);
            }
            //Sinon
            else {
                printf("%d_Elec", plateauMonopoly[numeroCase].joueurPossesseur);
            }
        }
        //Si la case n'appartient à personne
        else {
            printf("_Elec_");
        }
    }
    if (numeroCase == 28) {
        if (plateauMonopoly[numeroCase].joueurPossesseur) {
            //Si la case est hypothéquée
            if (plateauMonopoly[numeroCase].hypotheque) {
                printf("%dEauxX", plateauMonopoly[numeroCase].joueurPossesseur);
            }
            //Sinon
            else {
                printf("%d_Eaux", plateauMonopoly[numeroCase].joueurPossesseur);
            }
        }
        //Si la case n'appartient à personne
        else {
            printf("_Eaux_");
        }
    }
    color(7,0);
}




void affichageMaisonHotelRestant(int nombreMaisonRestante, int nombreHotelRestant, int mode) {
    //On affiche le nombre de maisons et d'hotels qu'il reste dans le jeu.
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
    //Si la regle du parc gratuit est activé, on affiche l'argent disponible sur la case parc gratuit.
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
    //Grâce à toutes les fonctions d'affichage ci-dessus on affiche le plateau au complet.

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
    printf("Depart");
    printf("|");
    color(5,0);
    affichageCasePropriete(plateauMonopoly, 1);
    color(7,0);
    printf("|");
    printf("Caisse");
    printf("|");
    color(5,0);
    affichageCasePropriete(plateauMonopoly, 3);
    color(7,0);
    printf("|");
    printf("Impots");
    printf("|");
    affichageAutreCases(plateauMonopoly, 5);
    printf("|");
    color(3,0);
    affichageCasePropriete(plateauMonopoly, 6);
    color(7,0);
    printf("|");
    printf("Chance");
    printf("|");
    color(3,0);
    affichageCasePropriete(plateauMonopoly, 8);
    color(7,0);
    printf("|");
    color(3,0);
    affichageCasePropriete(plateauMonopoly, 9);
    color(7,0);
    printf("|");
    printf("Prison");
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
    printf("_Taxe_");
    printf("|             *           *               Hotel: ");
    affichageMaisonHotelRestant(variable[6], variable[7], 2);
    printf("            |");
    affichageAutreCases(plateauMonopoly, 12);
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
    printf("Chance");
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
    affichageAutreCases(plateauMonopoly, 35);
    printf("|             *        | Version Deluxe |      *     *         |");
    affichageAutreCases(plateauMonopoly, 15);
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
    printf("Caisse");
    printf("|  ");
    color(2,0);
    affichageNomJoueur(listeJoueur, 3, variable[3]);
    color(7,0);
    color(15,0);
    affichageArgentJoueur(listeJoueur, 3, variable[3]);
    color(7,0);
    printf("                  *           *           |");
    printf("Caisse");
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
    printf("_-->#_");
    printf("|");
    color(14,0);
    affichageCasePropriete(plateauMonopoly, 29);
    color(7,0);
    printf("|");
    affichageAutreCases(plateauMonopoly, 28);
    printf("|");
    color(14,0);
    affichageCasePropriete(plateauMonopoly, 27);
    color(7,0);
    printf("|");
    color(14,0);
    affichageCasePropriete(plateauMonopoly, 26);
    color(7,0);
    printf("|");
    affichageAutreCases(plateauMonopoly, 25);
    printf("|");
    color(4,0);
    affichageCasePropriete(plateauMonopoly, 24);
    color(7,0);
    printf("|");
    color(4,0);
    affichageCasePropriete(plateauMonopoly, 23);
    color(7,0);
    printf("|");
    printf("Chance");
    printf("|");
    color(4,0);
    affichageCasePropriete(plateauMonopoly, 21);
    color(7,0);
    printf("|");
    printf("_Parc_");
    printf("|\n");
}