
#ifndef PROJETMONOPOLY_INITIALISATION_H
#define PROJETMONOPOLY_INITIALISATION_H

//----------------------------------------------------------------------------------------------------------------------

//Initialisation du plateau de jeu :

//Procédure permettant d'initialiser le nombre de maisons et d'hotels de chaque case et le joueur qui la possède.
void initialisationMaisonHotelPossession (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);

//Procédure permettant d'initialiser le prix d'achat de chaque case.
void initialisationPrixCase(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);

//Procédure permettant d'initialiser le nom de chaque case.
void initialisationNomCase (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);

//Procédure permettant d'initialiser le type de chaque case. (voir initialisation.c)
void initialisationTypeCase (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);

//Procédure permettant d'initialiser le groupe de chaque case. (voir initialisation.h)
void initialisationGroupeCase (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);

//Procédure permettant d'initialiser le prix à payer lorsque le terrain est nu.
void initialisationPrixTerrainNu (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);

//Procédure permettant d'initialiser le prix à payer pour acheter une maison ou le prix à payer lorsqu'il y a des maisons et hotels sur une case.
void initialisationPrixMaisonHotel (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);

//Procédure permettant d'initialiser les 40 cases du plateau de monopoly à partir des procédures ci-dessus.
void initialisationMonopoly (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);

//----------------------------------------------------------------------------------------------------------------------

//Inisialisation des joueurs :

//Procédure permettant d'initialiser l'argent de base de chaque joueur.
void initialisationArgentJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//Procédure permettant d'initialiser la case de départ de chaque joueur.
void initialisationCaseJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//Procédure permettant d'initialiser le nom de base de chaque joueur
void initialisationNomJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//Procédure permettant d'initialiser le nombre de tour qu'ils ont passé en prison.
void initialisationPrisonJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//Procédure permettant d'initialiser les 7 joueurs du jeu à partir des procédures ci-dessus.
void initialisationJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//----------------------------------------------------------------------------------------------------------------------

//Initialisation des cartes Chance et Caisse de communauté :

//Procédure permettant d'initialiser un ordre aléatoire pour la pioche des cartes chances et caisses de communautés.
void initialisationOrdreCarte (CarteChanceCaisse* infoChanceCaisse);

//Procédure permettant d'initialiser le prix de chaque évènement des cartes chances et caisses de communautés.
void initialisationPrixEvenement (CarteChanceCaisse* infoChanceCaisse);

//Procédure permettant d'initialiser les deux pioches de carte chance et caisse de communauté du jeu à partir des procédures ci-dessus.
void initialisationCarteChanceCaisse (CarteChanceCaisse* infoChanceCaisse);

//----------------------------------------------------------------------------------------------------------------------

//Affichage et Initialisation des regles :

//Procédure permettant d'afficher les règles du jeu.
void affichageRegle();

//Procédure permettant de choisir qu'elle règle en plus les utilisateurs veulent activer.
void choixRegleSupplementaire(int* regleDepart, int* regleParcGratuit);

//----------------------------------------------------------------------------------------------------------------------

//Fonction de remise a zero d'une sauvegarde :
void initialisationSauvegarde(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], CarteChanceCaisse* infoChanceCaisse, int listeVariable[NOMBRE_VARIABLE]);

//----------------------------------------------------------------------------------------------------------------------

#endif //PROJETMONOPOLY_INITIALISATION_H
