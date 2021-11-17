
#ifndef PROJETMONOPOLY_STRUCTURE_H
#define PROJETMONOPOLY_STRUCTURE_H

#define TAILLE_PLATEAU 40
#define TAILLE_MAX_NOM 30
#define TAILLE_MAX_NOM_JOUEUR 10 + 1
#define NOMBRE_MAX_JOUEUR 6 + 1
#define NOMBRE_VARIABLE 10

#define NOMBRE_CARTE_CHANCE 16
#define NOMBRE_CARTE_CAISSE 16

typedef struct {
    char nomCase[TAILLE_MAX_NOM];
    int prixTerrainNu;
    int prixMaisonHotel[6];
    int numeroGroupeCase;
    int joueurPossesseur;
    int prixCase;
    int nombreMaison;
    int nombreHotel;
    int typeCase;
    int hypotheque;
} CaseMonopoly;

typedef struct {
    char nomJoueur[TAILLE_MAX_NOM_JOUEUR];
    int argentJoueur;
    int caseJoueur;
    int prison;
    int carteLiberePrison;
} InfoJoueur;

typedef struct {
    int ordreCarteChance[NOMBRE_CARTE_CHANCE];
    int ordreCarteCaisse[NOMBRE_CARTE_CAISSE];
    int prixCarteChance[NOMBRE_CARTE_CHANCE];
    int prixCarteCaisse[NOMBRE_CARTE_CAISSE];
    int numeroCarteChance;
    int numeroCarteCaisse;
} CarteChanceCaisse;

#endif //PROJETMONOPOLY_STRUCTURE_H
