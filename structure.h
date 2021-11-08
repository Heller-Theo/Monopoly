#ifndef PROJET_MONOPOLY_STRUCTURE_H
#define PROJET_MONOPOLY_STRUCTURE_H

#define TAILLE_PLATEAU 40
#define TAILLE_MAX_NOM 50
#define NOMBRE_MAX_JOUEUR 6

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
} CaseMonopoly;

typedef struct {
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



#endif //PROJET_MONOPOLY_STRUCTURE_H
