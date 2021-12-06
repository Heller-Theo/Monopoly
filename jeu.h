#include "structure.h"

#ifndef PROJETMONOPOLY_JEU_H
#define PROJETMONOPOLY_JEU_H

//Fonction permettant de lancer la partie de monopoly et qui retourne le numero du prochain joueur à devoir jouer.
int jeuMonopoly(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], CarteChanceCaisse infoChanceCaisse, int listeVariable[], int premierJoueur);

#endif //PROJETMONOPOLY_JEU_H
