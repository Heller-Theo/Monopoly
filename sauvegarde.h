
#ifndef PROJETMONOPOLY_SAUVEGARDE_H
#define PROJETMONOPOLY_SAUVEGARDE_H

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

#endif //PROJETMONOPOLY_SAUVEGARDE_H
