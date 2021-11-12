
#ifndef PROJETMONOPOLY_INITIALISATION_H
#define PROJETMONOPOLY_INITIALISATION_H

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
void initialisationNomJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);
void initialisationPrisonJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]);

//Initialisation des cartes Chance et Caisse de communauté
void initialisationOrdreCarte (CarteChanceCaisse* infoChanceCaisse);
void initialisationPrixEvenement (CarteChanceCaisse* infoChanceCaisse);
void initialisationCarteChanceCaisse (CarteChanceCaisse* infoChanceCaisse);

//Affichage et Initialisation des regles
void affichageRegle(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]);
void choixRegleSupplementaire(int* regleDepart, int* regleParcGratuit);

//Fonction de remise a zero d'une sauvegarde
void initialisationSauvegarde(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], CarteChanceCaisse* infoChanceCaisse, int listeVariable[NOMBRE_VARIABLE]);

//Initialisation des sauvegardes à partir du fichier binaire
void initialisationDebutSauvegarde(CaseMonopoly plateauMonopoly1[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly2[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly3[TAILLE_PLATEAU],
                                  InfoJoueur listeJoueur1[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur2[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur3[NOMBRE_MAX_JOUEUR],
                                  int listeVariable1[NOMBRE_VARIABLE], int listeVariable2[NOMBRE_VARIABLE], int listeVariable3[NOMBRE_VARIABLE],
                                  CarteChanceCaisse infoChanceCaisse[], int* pSauvegarde1, int* pSauvegarde2, int* pSauvegarde3);

//Enregistrement des sauvegardes dans le fichier binaire
void enregistrementFinSauvegarde(CaseMonopoly plateauMonopoly1[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly2[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly3[TAILLE_PLATEAU],
                                 InfoJoueur listeJoueur1[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur2[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur3[NOMBRE_MAX_JOUEUR],
                                 int listeVariable1[NOMBRE_VARIABLE], int listeVariable2[NOMBRE_VARIABLE], int listeVariable3[NOMBRE_VARIABLE],
                                 CarteChanceCaisse infoChanceCaisse[], int* pSauvegarde1, int* pSauvegarde2, int* pSauvegarde3);

#endif //PROJETMONOPOLY_INITIALISATION_H
