
#ifndef PROJETMONOPOLY_STRUCTURE_H
#define PROJETMONOPOLY_STRUCTURE_H

//----------------------------------------------------------------------------------------------------------------------

//Définit la taille du plateau (40 cases)
#define TAILLE_PLATEAU 40

//Définit la taille max du nom des cases du plateau (30 caractères max -1 pour le '\0')
#define TAILLE_MAX_NOM 30

//Définit la taille max du nom d'un joueur (10 + 1 caractères max -1 pour le '\0')
#define TAILLE_MAX_NOM_JOUEUR 10 + 1

//Définit le nombre max de joueurs qui peuvent joueur (6 + 1 pour le joueur 0 qui sert de référence)
#define NOMBRE_MAX_JOUEUR 6 + 1

//Définit la taille max du tableau de variables ne faisant pas parties d'une structure (10 max)
#define NOMBRE_VARIABLE 10

//Définit le nombre de cartes chances (16)
#define NOMBRE_CARTE_CHANCE 16

//Définit le nombre de cartes caisses de communautés (16)
#define NOMBRE_CARTE_CAISSE 16

//Définit la taille max d'une entrée par l'utilisateur dans la console (100 caractères max -1 pour le '\0')
#define MAX_CARACT_LIGNE 100

//----------------------------------------------------------------------------------------------------------------------

//Cette structure représente les informations que contient une case de monopoly avec :

typedef struct {
    char nomCase[TAILLE_MAX_NOM];
    int prixTerrainNu;
    int prixMaisonHotel[6];
    int numeroGroupeCase;
    int typeCase;
    int prixCase;
    int nombreMaison;
    int nombreHotel;
    int joueurPossesseur;
    int hypotheque;
} CaseMonopoly;

//nomCase = son nom
//prixTerrainNu = le prix qu'il faut payer lorsqu'il n'y a rien dessus
//prixMaisonHotel[0] = le prix d'achat d'une maison sur cette case
//prixMaisonHotel[1] = le prix du terrain avec 1 maison dessus
//prixMaisonHotel[2] = le prix du terrain avec 2 maisons dessus
//prixMaisonHotel[3] = le prix du terrain avec 3 maisons dessus
//prixMaisonHotel[4] = le prix du terrain avec 4 maisons dessus
//prixMaisonHotel[5] = le prix du terrain avec 1 hotel dessus
//numeroGroupeCase = le numero du groupe dans lequel elle se situe (voir initialisation.c)
//typeCase = le type de case (voir initialisation.c)
//prixCase = le prix que coute cette case à acheter
//nombreMaison = le nombre de maisons qu'il y a sur cette case
//nombreHotel = le nombre d'hotels qu'il y a sur cette case
//joueurPossesseur = le numero du joueur qui possède cette case (0 si personne)
//hypotheque =  1 si la case est hypothéquée, 0 sinon

//----------------------------------------------------------------------------------------------------------------------

//Cette structure représente un joueur :

typedef struct {
    char nomJoueur[TAILLE_MAX_NOM_JOUEUR];
    int argentJoueur;
    int caseJoueur;
    int prison;
    int carteLiberePrison;
} InfoJoueur;

//nomJoueur = le nom du joueur
//argentJoueur = l'argent que possède ce joueur
//caseJoueur = la case sur laquel se trouve le joueur
//prison = un entier qui représente depuis combien de tour le joueur est en prison (donc 0 si il n'y est pas)
//carteLiberePrison = nombre de carte de liberation de prison que possède le joueur

//----------------------------------------------------------------------------------------------------------------------

//Cette structure contient toutes les informations sur les piles de cartes chances et caisses de communautés :

typedef struct {
    int ordreCarteChance[NOMBRE_CARTE_CHANCE];
    int ordreCarteCaisse[NOMBRE_CARTE_CAISSE];
    int prixCarteChance[NOMBRE_CARTE_CHANCE];
    int prixCarteCaisse[NOMBRE_CARTE_CAISSE];
    int numeroCarteChance;
    int numeroCarteCaisse;
} CarteChanceCaisse;

//ordreCarteChance = l'ordre dans lequel les cartes chances sont rangées dans la pile
//ordreCarteCaisse = l'ordre dans lequel les cartes caisses de communautés sont rangées dans la pile
//prixCarteChance = le prix pour chacune des 16 cartes chances qu'il faut payer si on pioche la nième
//prixCarteChance = le prix pour chacune des 16 cartes caisses de communautés qu'il faut payer si on pioche la nième
//numeroCarteChance = la position du curseur dans la pile des cartes chances
//numeroCarteCaisse = la position du curseur dans la pile des cartes caisses de communautés

//----------------------------------------------------------------------------------------------------------------------

#endif //PROJETMONOPOLY_STRUCTURE_H
