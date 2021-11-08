#include "structure.h"

#ifndef PROJET_MONOPOLY_FONCTION_H
#define PROJET_MONOPOLY_FONCTION_H

//Fonction informative
void affichageInfoCase(int numeroCase, CaseMonopoly tableauMonopoly[TAILLE_PLATEAU]);
void affichagePrixCase(int numeroCase, CaseMonopoly tableauMonopoly[TAILLE_PLATEAU]);
void affichageInfoJoueur(int numeroJoueur, InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);
void affichagePossessionJoueur(int numeroJoueur, CaseMonopoly tableauMonopoly[TAILLE_PLATEAU]);
int checkJeu(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante, int* pNombreHotelRestant);

//Fonction tirage des dés
void tirageDeuxDe(int* pResultat, int* pDoubleDe);

//Fonction sur les monopoles
int monopoleCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase, int joueur);
int nombreGareJoueur(CaseMonopoly tableauMonopoly[TAILLE_PLATEAU], int joueur);
int nombreMaisonJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int joueur);
int nombreHotelJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int joueur);

//Fonction sur l'achat de maisons et d'hotels
void achatMaison(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante);
void achatHotel(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreHotelRestant);

//Fonction sur les cases Chance et Caisse de Communauté
void randomOrdreCaisseChance(int listeAleatoire[16]);

#endif //PROJET_MONOPOLY_FONCTION_H
