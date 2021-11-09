#include "structure.h"

#ifndef PROJET_MONOPOLY_INITIALISATION_H
#define PROJET_MONOPOLY_INITIALISATION_H

//Initialisation du plateau de jeu
void initialisationMonopoly (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);
void initialisationMaisonHotelPossession (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);
void initialisationPrixCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);
void initialisationNomCase (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);
void initialisationTypeCase (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);
void initialisationGroupeCase (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);
void initialisationPrixTerrainNu (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);
void initialisationPrixMaisonHotel (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);

//Inisialisation des joueurs
void initialisationJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);
void initialisationArgentJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);
void initialisationCaseJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);
void initialisationPrisonJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//Initialisation des cartes Chance et Caisse de communauté
void initialisationOrdreCarte (CarteChanceCaisse* infoChanceCaisse);
void initialisationPrixEvenement (CarteChanceCaisse* infoChanceCaisse);
void initialisationCarteChanceCaisse (CarteChanceCaisse* infoChanceCaisse);

//Affichage et Initialisation des regles
void affichageRegle(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);
void choixRegleSupplementaire(int* regleDepart, int* regleParcGratuit);

#endif //PROJET_MONOPOLY_INITIALISATION_H
