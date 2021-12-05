#include "structure.h"

#ifndef PROJETMONOPOLY_FONCTION_H
#define PROJETMONOPOLY_FONCTION_H

void viderBuffer();
void color(int couleurDuTexte,int couleurDeFond);
void verificationSaisie(int* choix);

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
int maisonHotelGroupe(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase);
void achatMaison(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante);
void achatHotel(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreHotelRestant, int* pNombreMaisonRestante);
void venteMaison(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante);
void venteHotel(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreHotelRestant, int* pNombreMaisonRestante);

//Fonction sur l'hypotheque
int hypothequeGroupe(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase);
void hypothequeCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);
void leverHypotheque(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);
void venteCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//Fonction sur les cases Chance et Caisse de Communauté
void randomOrdreCaisseChance(int listeAleatoire[16]);
void achatCarteLibere(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int listeVariable[NOMBRE_VARIABLE], int joueur);

//Fonction d'affichage
void posJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroCase, int nombreJoueur);
void affichageArgentJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroJoueur, int nombreJoueur);
void affichageCasePropriete(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroCase);
void affichageAutreCases(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroCase);
void affichageNomJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroJoueur, int nombreJoueur);
void affichageRegleParc(int regleParcGratuit, int potCommun);
void affichagePlateau(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int variable[NOMBRE_VARIABLE]);

#endif //PROJETMONOPOLY_FONCTION_H
