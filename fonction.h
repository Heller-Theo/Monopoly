#include "structure.h"

#ifndef PROJETMONOPOLY_FONCTION_H
#define PROJETMONOPOLY_FONCTION_H


//----------------------------------------------------------------------------------------------------------------------

//Autres procédures :

//Fonction permettant de vider le buffer pour que les fgets fonctionnent correctement.
void viderBuffer();

//Fonction permettant de saisir une entrée au clavier et de verifier que celle-ci est bien un entier.
void verificationSaisie(int* choix);

//Fonction permettant de changer la couleur du texte et du fond.
void color(int couleurDuTexte,int couleurDeFond);

//----------------------------------------------------------------------------------------------------------------------

//Procédures informatives :

//Procédure permettant d'afficher les informations d'une case. (numero, joueur possesseur, hypotheque, nombre maison, nombre hotel, prix case)
void affichageInfoCase(int numeroCase, CaseMonopoly tableauMonopoly[TAILLE_PLATEAU]);

//Procédure permettant permettant d'afficher tous les prix d'une case. (maison, hotel, hypotheque...)
void affichagePrixCase(int numeroCase, CaseMonopoly tableauMonopoly[TAILLE_PLATEAU]);

//Procédure permettant d'afficher les informations d'un joueur. (numero, nom, argent, nombre de carte liberer de prison)
void affichageInfoJoueur(int numeroJoueur, InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//Procédure permettant d'afficher toutes les cases que possède un joueur.
void affichagePossessionJoueur(int numeroJoueur, CaseMonopoly tableauMonopoly[TAILLE_PLATEAU]);

//----------------------------------------------------------------------------------------------------------------------

//Procédure de tirage des dés
void tirageDeuxDe(int* pResultat, int* pDoubleDe);

//----------------------------------------------------------------------------------------------------------------------

//Fonction permettant de savoir si le joueur "joueur" a un monopole sur le groupe de case "numeroGroupeCase"
//Retourne 1 si oui, 0 si non.
int monopoleCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase, int joueur);

//----------------------------------------------------------------------------------------------------------------------

//Fonctions sur les possessions d'un joueur :

//Fonction qui renvoie le nombre de gare que detient le joueur "joueur"
int nombreGareJoueur(CaseMonopoly tableauMonopoly[TAILLE_PLATEAU], int joueur);

//Fonction qui renvoie le nombre de maisons que possède un joueur. (utile pour certaines cartes chance et caisse)
int nombreMaisonJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int joueur);

//Fonction qui renvoie le nombre d'hotels que possède un joueur. (utile pour certaines cartes chance et caisse)
int nombreHotelJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int joueur);

//----------------------------------------------------------------------------------------------------------------------

//Fonctions et procédures sur l'achat de maisons et d'hotels :

//Fonction permettant de savoir s'il y a des maisons ou des hotels sur une des cases d'un groupe de propriété.
//Retourne 1 si oui, 0 si non.
int maisonHotelGroupe(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase);

//Procédure permettant d'acheter une maison.
void achatMaison(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante);

//Procédure permettant d'acheter un hotel.
void achatHotel(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreHotelRestant, int* pNombreMaisonRestante);

//Procédure permettant de vendre une maison.
void venteMaison(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante);

//Porcédure permettant de vendre un hotel.
void venteHotel(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreHotelRestant, int* pNombreMaisonRestante);

//----------------------------------------------------------------------------------------------------------------------

//Fonctions et procédures sur l'hypothèque et la vente de cases :

//Fonction permettant de savoir s'il y a une case hypothéquée sur un groupe de propriété.
//Retourne 1 si oui, 0 si non.
int hypothequeGroupe(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroGroupeCase);

//Procédure permettant d'hypotéquer une case.
void hypothequeCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//Procédure permettant de lever l'hypothèque d'une case
void leverHypotheque(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//Procédure permettant de vendre une case hypothéquée à un autre joueur.
void venteCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);


//----------------------------------------------------------------------------------------------------------------------

//Procédures sur les cases Chance et Caisse de Communauté:

//Procédure permettant de créer un ordre aléatoire en début de partie pour la pioche des cartes chances et caisses de communautés.
void randomOrdreCaisseChance(int listeAleatoire[16]);

//Procédure permettant d'acheter une carte de liberation de prison à un autre joueur.
void achatCarteLibere(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int listeVariable[NOMBRE_VARIABLE], int joueur);

//----------------------------------------------------------------------------------------------------------------------

//Fonction permettant d'effectuer toutes les autres actions du jeu.
//Elle renvoie ce que le joueur ecrit comme première entrée (0 pour quitter, 1 pour continuer, 2 pour faire une action)
//Elle permet de regarder des informations sur le jeu, acheter et vendre des maisons et hotels, hypothequer des cases...
int checkJeu(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int* pNombreMaisonRestante, int* pNombreHotelRestant);

//----------------------------------------------------------------------------------------------------------------------

//Procédure de gestion de la faillite
void failliteJoueur(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int joueur, int numeroCase, int dette, int* pNombreMaisonRestante, int* pNombreHotelRestant);

//----------------------------------------------------------------------------------------------------------------------

//Procédures d'affichage de plateau :

//Procédure permettant d'afficher la position actuelle d'un joueur encore en jeu.
void posJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroCase, int nombreJoueur);

//Procédure permettant d'afficher l'argent que possède un joueur encore en jeu.
void affichageArgentJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroJoueur, int nombreJoueur);

//Procédure permettant d'afficher les informations d'une case propriété (si il y a des maisons, si elle est hypothéquée, le joueur qui la détient...)
void affichageCasePropriete(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroCase);

//Procédure permettant d'afficher les informations d'une autre case achetable par un joueur. (gare et compagnie d'electricité et d'eaux)
void affichageAutreCases(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], int numeroCase);

//Procédure permettant d'afficher le nom d'un joueur encore en jeu.
void affichageNomJoueur(InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int numeroJoueur, int nombreJoueur);

//Procédure permettant d'afficher le total d'argent présent sur la case Parc gratuit si cette règle est activée.
void affichageRegleParc(int regleParcGratuit, int potCommun);

//Procédure permettant d'afficher le plateau de jeu.
void affichagePlateau(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], int variable[NOMBRE_VARIABLE]);

//----------------------------------------------------------------------------------------------------------------------


#endif //PROJETMONOPOLY_FONCTION_H
