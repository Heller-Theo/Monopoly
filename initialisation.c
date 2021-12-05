#include "structure.h"
#include "fonction.h"
#include <string.h>
#include <stdio.h>

//Initialisation du plateau de jeu
void initialisationNomCase (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    strcpy(plateauMonopoly[0].nomCase, "Depart");
    strcpy(plateauMonopoly[1].nomCase, "Boulevard de Belleville");
    strcpy(plateauMonopoly[2].nomCase, "Caisse de Communaute");
    strcpy(plateauMonopoly[3].nomCase, "Rue Lecourbe");
    strcpy(plateauMonopoly[4].nomCase, "Impot sur le revenu");
    strcpy(plateauMonopoly[5].nomCase, "Gare Montparnasse");
    strcpy(plateauMonopoly[6].nomCase, "Rue de Vaugirard");
    strcpy(plateauMonopoly[7].nomCase, "Chance");
    strcpy(plateauMonopoly[8].nomCase, "Rue de Courcelles");
    strcpy(plateauMonopoly[9].nomCase, "Avenue de la Republique");
    strcpy(plateauMonopoly[10].nomCase, "Prison");
    strcpy(plateauMonopoly[11].nomCase, "Boulevard de la Villette");
    strcpy(plateauMonopoly[12].nomCase, "Compagnie d'Electricite");
    strcpy(plateauMonopoly[13].nomCase, "Avenue de Neuilly");
    strcpy(plateauMonopoly[14].nomCase, "Rue de Paradis");
    strcpy(plateauMonopoly[15].nomCase, "Gare de Lyon");
    strcpy(plateauMonopoly[16].nomCase, "Avenue Mozart");
    strcpy(plateauMonopoly[17].nomCase, "Caisse de Communaute");
    strcpy(plateauMonopoly[18].nomCase, "Boulevard Saint-Michel");
    strcpy(plateauMonopoly[19].nomCase, "Place Pigalle");
    strcpy(plateauMonopoly[20].nomCase, "Parc gratuit");
    strcpy(plateauMonopoly[21].nomCase, "Avenue Matignon");
    strcpy(plateauMonopoly[22].nomCase, "Chance");
    strcpy(plateauMonopoly[23].nomCase, "Boulevard Malesherbes");
    strcpy(plateauMonopoly[24].nomCase, "Avenue Henri-Martin");
    strcpy(plateauMonopoly[25].nomCase, "Gare du Nord");
    strcpy(plateauMonopoly[26].nomCase, "Faubourg Saint-Honore");
    strcpy(plateauMonopoly[27].nomCase, "Place de la Bourse");
    strcpy(plateauMonopoly[28].nomCase, "Compagnie des Eaux");
    strcpy(plateauMonopoly[29].nomCase, "Rue La Fayette");
    strcpy(plateauMonopoly[30].nomCase, "Allez en Prison");
    strcpy(plateauMonopoly[31].nomCase, "Avenue de Breteuil");
    strcpy(plateauMonopoly[32].nomCase, "Avenue Foch");
    strcpy(plateauMonopoly[33].nomCase, "Caisse de Communaute");
    strcpy(plateauMonopoly[34].nomCase, "Boulevard des Capucines");
    strcpy(plateauMonopoly[35].nomCase, "Gare Saint-Lazare");
    strcpy(plateauMonopoly[36].nomCase, "Chance");
    strcpy(plateauMonopoly[37].nomCase, "Champs-Elysees");
    strcpy(plateauMonopoly[38].nomCase, "Taxe de luxe");
    strcpy(plateauMonopoly[39].nomCase, "Rue de la Paix");
}

void initialisationMaisonHotelPossession (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    int i = 0;
    for (i = 0; i < 40; i++) {
        plateauMonopoly[i].nombreHotel = 0;
        plateauMonopoly[i].nombreMaison = 0;
        plateauMonopoly[i].joueurPossesseur = 0;
        plateauMonopoly[i].hypotheque = 0;
    }
}

void initialisationPrixCase (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    plateauMonopoly[0].prixCase = 0;
    plateauMonopoly[1].prixCase = 6000;
    plateauMonopoly[2].prixCase = 0;
    plateauMonopoly[3].prixCase = 6000;
    plateauMonopoly[4].prixCase = 0;
    plateauMonopoly[5].prixCase = 20000;
    plateauMonopoly[6].prixCase = 10000;
    plateauMonopoly[7].prixCase = 0;
    plateauMonopoly[8].prixCase = 10000;
    plateauMonopoly[9].prixCase = 12000;
    plateauMonopoly[10].prixCase = 0;
    plateauMonopoly[11].prixCase = 14000;
    plateauMonopoly[12].prixCase = 15000;
    plateauMonopoly[13].prixCase = 14000;
    plateauMonopoly[14].prixCase = 16000;
    plateauMonopoly[15].prixCase = 20000;
    plateauMonopoly[16].prixCase = 18000;
    plateauMonopoly[17].prixCase = 0;
    plateauMonopoly[18].prixCase = 18000;
    plateauMonopoly[19].prixCase = 20000;
    plateauMonopoly[20].prixCase = 0;
    plateauMonopoly[21].prixCase = 22000;
    plateauMonopoly[22].prixCase = 0;
    plateauMonopoly[23].prixCase = 22000;
    plateauMonopoly[24].prixCase = 24000;
    plateauMonopoly[25].prixCase = 20000;
    plateauMonopoly[26].prixCase = 26000;
    plateauMonopoly[27].prixCase = 26000;
    plateauMonopoly[28].prixCase = 15000;
    plateauMonopoly[29].prixCase = 28000;
    plateauMonopoly[30].prixCase = 0;
    plateauMonopoly[31].prixCase = 30000;
    plateauMonopoly[32].prixCase = 30000;
    plateauMonopoly[33].prixCase = 0;
    plateauMonopoly[34].prixCase = 32000;
    plateauMonopoly[35].prixCase = 20000;
    plateauMonopoly[36].prixCase = 0;
    plateauMonopoly[37].prixCase = 35000;
    plateauMonopoly[38].prixCase = 0;
    plateauMonopoly[39].prixCase = 40000;
}

void initialisationTypeCase (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    // 0: Case Depart
    // 1: Propriété
    // 2: Prison
    // 3: Compagnie d'eau et d'electricité
    // 4: Impot sur le revenu
    // 5: Taxe de luxe
    // 6: Chance
    // 7: Caisse de communauté
    // 8: Parc Gratuit
    // 9: Allez en prison
    // 10: Gare
    plateauMonopoly[0].typeCase = 0;
    plateauMonopoly[1].typeCase = 1;
    plateauMonopoly[2].typeCase = 7;
    plateauMonopoly[3].typeCase = 1;
    plateauMonopoly[4].typeCase = 4;
    plateauMonopoly[5].typeCase = 10;
    plateauMonopoly[6].typeCase = 1;
    plateauMonopoly[7].typeCase = 6;
    plateauMonopoly[8].typeCase = 1;
    plateauMonopoly[9].typeCase = 1;
    plateauMonopoly[10].typeCase = 2;
    plateauMonopoly[11].typeCase = 1;
    plateauMonopoly[12].typeCase = 3;
    plateauMonopoly[13].typeCase = 1;
    plateauMonopoly[14].typeCase = 1;
    plateauMonopoly[15].typeCase = 10;
    plateauMonopoly[16].typeCase = 1;
    plateauMonopoly[17].typeCase = 7;
    plateauMonopoly[18].typeCase = 1;
    plateauMonopoly[19].typeCase = 1;
    plateauMonopoly[20].typeCase = 8;
    plateauMonopoly[21].typeCase = 1;
    plateauMonopoly[22].typeCase = 6;
    plateauMonopoly[23].typeCase = 1;
    plateauMonopoly[24].typeCase = 1;
    plateauMonopoly[25].typeCase = 10;
    plateauMonopoly[26].typeCase = 1;
    plateauMonopoly[27].typeCase = 1;
    plateauMonopoly[28].typeCase = 3;
    plateauMonopoly[29].typeCase = 1;
    plateauMonopoly[30].typeCase = 9;
    plateauMonopoly[31].typeCase = 1;
    plateauMonopoly[32].typeCase = 1;
    plateauMonopoly[33].typeCase = 7;
    plateauMonopoly[34].typeCase = 1;
    plateauMonopoly[35].typeCase = 10;
    plateauMonopoly[36].typeCase = 6;
    plateauMonopoly[37].typeCase = 1;
    plateauMonopoly[38].typeCase = 5;
    plateauMonopoly[39].typeCase = 1;
}

void initialisationGroupeCase (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    // 0: Cases Indépendantes
    // 1: Case Violette
    // 2: Case Bleu Clair
    // 3: Case Rose
    // 4: Case Orange
    // 5: Case Rouge
    // 6: Case Jaune
    // 7: Case Verte
    // 8: Case Bleu Sombre
    // 9: Gare
    // 10: Compagnie d'eau et d'électricité
    plateauMonopoly[0].numeroGroupeCase = 0;
    plateauMonopoly[1].numeroGroupeCase = 1;
    plateauMonopoly[2].numeroGroupeCase = 0;
    plateauMonopoly[3].numeroGroupeCase = 1;
    plateauMonopoly[4].numeroGroupeCase = 0;
    plateauMonopoly[5].numeroGroupeCase = 9;
    plateauMonopoly[6].numeroGroupeCase = 2;
    plateauMonopoly[7].numeroGroupeCase = 0;
    plateauMonopoly[8].numeroGroupeCase = 2;
    plateauMonopoly[9].numeroGroupeCase = 2;
    plateauMonopoly[10].numeroGroupeCase = 0;
    plateauMonopoly[11].numeroGroupeCase = 3;
    plateauMonopoly[12].numeroGroupeCase = 10;
    plateauMonopoly[13].numeroGroupeCase = 3;
    plateauMonopoly[14].numeroGroupeCase = 3;
    plateauMonopoly[15].numeroGroupeCase = 9;
    plateauMonopoly[16].numeroGroupeCase = 4;
    plateauMonopoly[17].numeroGroupeCase = 0;
    plateauMonopoly[18].numeroGroupeCase = 4;
    plateauMonopoly[19].numeroGroupeCase = 4;
    plateauMonopoly[20].numeroGroupeCase = 0;
    plateauMonopoly[21].numeroGroupeCase = 5;
    plateauMonopoly[22].numeroGroupeCase = 0;
    plateauMonopoly[23].numeroGroupeCase = 5;
    plateauMonopoly[24].numeroGroupeCase = 5;
    plateauMonopoly[25].numeroGroupeCase = 9;
    plateauMonopoly[26].numeroGroupeCase = 6;
    plateauMonopoly[27].numeroGroupeCase = 6;
    plateauMonopoly[28].numeroGroupeCase = 10;
    plateauMonopoly[29].numeroGroupeCase = 6;
    plateauMonopoly[30].numeroGroupeCase = 0;
    plateauMonopoly[31].numeroGroupeCase = 7;
    plateauMonopoly[32].numeroGroupeCase = 7;
    plateauMonopoly[33].numeroGroupeCase = 0;
    plateauMonopoly[34].numeroGroupeCase = 7;
    plateauMonopoly[35].numeroGroupeCase = 9;
    plateauMonopoly[36].numeroGroupeCase = 0;
    plateauMonopoly[37].numeroGroupeCase = 8;
    plateauMonopoly[38].numeroGroupeCase = 0;
    plateauMonopoly[39].numeroGroupeCase = 8;
}

void initialisationPrixTerrainNu (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    plateauMonopoly[0].prixTerrainNu = 20000;
    plateauMonopoly[1].prixTerrainNu = 200;
    plateauMonopoly[2].prixTerrainNu = 0;
    plateauMonopoly[3].prixTerrainNu = 400;
    plateauMonopoly[4].prixTerrainNu = 20000;
    plateauMonopoly[5].prixTerrainNu = 2500;
    plateauMonopoly[6].prixTerrainNu = 600;
    plateauMonopoly[7].prixTerrainNu = 0;
    plateauMonopoly[8].prixTerrainNu = 600;
    plateauMonopoly[9].prixTerrainNu = 800;
    plateauMonopoly[10].prixTerrainNu = 5000;
    plateauMonopoly[11].prixTerrainNu = 1000;
    plateauMonopoly[12].prixTerrainNu = 400;
    plateauMonopoly[13].prixTerrainNu = 1000;
    plateauMonopoly[14].prixTerrainNu = 1200;
    plateauMonopoly[15].prixTerrainNu = 2500;
    plateauMonopoly[16].prixTerrainNu = 1400;
    plateauMonopoly[17].prixTerrainNu = 0;
    plateauMonopoly[18].prixTerrainNu = 1400;
    plateauMonopoly[19].prixTerrainNu = 1800;
    plateauMonopoly[20].prixTerrainNu = 0;
    plateauMonopoly[21].prixTerrainNu = 1800;
    plateauMonopoly[22].prixTerrainNu = 0;
    plateauMonopoly[23].prixTerrainNu = 1800;
    plateauMonopoly[24].prixTerrainNu = 2000;
    plateauMonopoly[25].prixTerrainNu = 2500;
    plateauMonopoly[26].prixTerrainNu = 2200;
    plateauMonopoly[27].prixTerrainNu = 2200;
    plateauMonopoly[28].prixTerrainNu = 400;
    plateauMonopoly[29].prixTerrainNu = 2400;
    plateauMonopoly[30].prixTerrainNu = 0;
    plateauMonopoly[31].prixTerrainNu = 2600;
    plateauMonopoly[32].prixTerrainNu = 2600;
    plateauMonopoly[33].prixTerrainNu = 0;
    plateauMonopoly[34].prixTerrainNu = 2800;
    plateauMonopoly[35].prixTerrainNu = 2500;
    plateauMonopoly[36].prixTerrainNu = 0;
    plateauMonopoly[37].prixTerrainNu = 3500;
    plateauMonopoly[38].prixTerrainNu = 10000;
    plateauMonopoly[39].prixTerrainNu = 5000;
}

void initialisationPrixMaisonHotel (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    int i = 0, j = 0;

    for (i = 0; i < 40; i++) {
        for (j = 0; j < 6; j++) {
            plateauMonopoly[i].prixMaisonHotel[j] = 0;
        }
    }

    //Boulevard de Belleville
    plateauMonopoly[1].prixMaisonHotel[0] = 5000;
    plateauMonopoly[1].prixMaisonHotel[1] = 1000;
    plateauMonopoly[1].prixMaisonHotel[2] = 3000;
    plateauMonopoly[1].prixMaisonHotel[3] = 9000;
    plateauMonopoly[1].prixMaisonHotel[4] = 16000;
    plateauMonopoly[1].prixMaisonHotel[5] = 25000;
    //Rue Lecourbe
    plateauMonopoly[3].prixMaisonHotel[0] = 5000;
    plateauMonopoly[3].prixMaisonHotel[1] = 2000;
    plateauMonopoly[3].prixMaisonHotel[2] = 6000;
    plateauMonopoly[3].prixMaisonHotel[3] = 18000;
    plateauMonopoly[3].prixMaisonHotel[4] = 32000;
    plateauMonopoly[3].prixMaisonHotel[5] = 45000;
    //Rue de vaugirard
    plateauMonopoly[6].prixMaisonHotel[0] = 5000;
    plateauMonopoly[6].prixMaisonHotel[1] = 3000;
    plateauMonopoly[6].prixMaisonHotel[2] = 9000;
    plateauMonopoly[6].prixMaisonHotel[3] = 27000;
    plateauMonopoly[6].prixMaisonHotel[4] = 40000;
    plateauMonopoly[6].prixMaisonHotel[5] = 55000;
    //Rue de Courcelles
    plateauMonopoly[8].prixMaisonHotel[0] = 5000;
    plateauMonopoly[8].prixMaisonHotel[1] = 3000;
    plateauMonopoly[8].prixMaisonHotel[2] = 9000;
    plateauMonopoly[8].prixMaisonHotel[3] = 27000;
    plateauMonopoly[8].prixMaisonHotel[4] = 40000;
    plateauMonopoly[8].prixMaisonHotel[5] = 55000;
    //Avenue de la Republique
    plateauMonopoly[9].prixMaisonHotel[0] = 5000;
    plateauMonopoly[9].prixMaisonHotel[1] = 4000;
    plateauMonopoly[9].prixMaisonHotel[2] = 10000;
    plateauMonopoly[9].prixMaisonHotel[3] = 30000;
    plateauMonopoly[9].prixMaisonHotel[4] = 45000;
    plateauMonopoly[9].prixMaisonHotel[5] = 60000;
    //Boulevard de la Villette
    plateauMonopoly[11].prixMaisonHotel[0] = 10000;
    plateauMonopoly[11].prixMaisonHotel[1] = 5000;
    plateauMonopoly[11].prixMaisonHotel[2] = 15000;
    plateauMonopoly[11].prixMaisonHotel[3] = 45000;
    plateauMonopoly[11].prixMaisonHotel[4] = 62500;
    plateauMonopoly[11].prixMaisonHotel[5] = 75000;
    //Avenue de Neuilly
    plateauMonopoly[13].prixMaisonHotel[0] = 10000;
    plateauMonopoly[13].prixMaisonHotel[1] = 5000;
    plateauMonopoly[13].prixMaisonHotel[2] = 15000;
    plateauMonopoly[13].prixMaisonHotel[3] = 45000;
    plateauMonopoly[13].prixMaisonHotel[4] = 62500;
    plateauMonopoly[13].prixMaisonHotel[5] = 75000;
    //Rue de Paradis
    plateauMonopoly[14].prixMaisonHotel[0] = 10000;
    plateauMonopoly[14].prixMaisonHotel[1] = 6000;
    plateauMonopoly[14].prixMaisonHotel[2] = 18000;
    plateauMonopoly[14].prixMaisonHotel[3] = 50000;
    plateauMonopoly[14].prixMaisonHotel[4] = 70000;
    plateauMonopoly[14].prixMaisonHotel[5] = 90000;
    //Avenue Mozart
    plateauMonopoly[16].prixMaisonHotel[0] = 10000;
    plateauMonopoly[16].prixMaisonHotel[1] = 7000;
    plateauMonopoly[16].prixMaisonHotel[2] = 20000;
    plateauMonopoly[16].prixMaisonHotel[3] = 55000;
    plateauMonopoly[16].prixMaisonHotel[4] = 75000;
    plateauMonopoly[16].prixMaisonHotel[5] = 95000;
    //Boulevard Saint-Michel
    plateauMonopoly[18].prixMaisonHotel[0] = 10000;
    plateauMonopoly[18].prixMaisonHotel[1] = 7000;
    plateauMonopoly[18].prixMaisonHotel[2] = 20000;
    plateauMonopoly[18].prixMaisonHotel[3] = 55000;
    plateauMonopoly[18].prixMaisonHotel[4] = 75000;
    plateauMonopoly[18].prixMaisonHotel[5] = 95000;
    //Place Pigalle
    plateauMonopoly[19].prixMaisonHotel[0] = 10000;
    plateauMonopoly[19].prixMaisonHotel[1] = 8000;
    plateauMonopoly[19].prixMaisonHotel[2] = 22000;
    plateauMonopoly[19].prixMaisonHotel[3] = 60000;
    plateauMonopoly[19].prixMaisonHotel[4] = 80000;
    plateauMonopoly[19].prixMaisonHotel[5] = 100000;
    //Avenue Matignon
    plateauMonopoly[21].prixMaisonHotel[0] = 15000;
    plateauMonopoly[21].prixMaisonHotel[1] = 9000;
    plateauMonopoly[21].prixMaisonHotel[2] = 25000;
    plateauMonopoly[21].prixMaisonHotel[3] = 70000;
    plateauMonopoly[21].prixMaisonHotel[4] = 87500;
    plateauMonopoly[21].prixMaisonHotel[5] = 105000;
    //Boulevard Malesherbes
    plateauMonopoly[23].prixMaisonHotel[0] = 15000;
    plateauMonopoly[23].prixMaisonHotel[1] = 9000;
    plateauMonopoly[23].prixMaisonHotel[2] = 25000;
    plateauMonopoly[23].prixMaisonHotel[3] = 70000;
    plateauMonopoly[23].prixMaisonHotel[4] = 87500;
    plateauMonopoly[23].prixMaisonHotel[5] = 105000;
    //Avenue Henri Martin
    plateauMonopoly[24].prixMaisonHotel[0] = 15000;
    plateauMonopoly[24].prixMaisonHotel[1] = 10000;
    plateauMonopoly[24].prixMaisonHotel[2] = 30000;
    plateauMonopoly[24].prixMaisonHotel[3] = 75000;
    plateauMonopoly[24].prixMaisonHotel[4] = 92500;
    plateauMonopoly[24].prixMaisonHotel[5] = 110000;
    //Faubourg Saint-Honoré
    plateauMonopoly[26].prixMaisonHotel[0] = 15000;
    plateauMonopoly[26].prixMaisonHotel[1] = 2200;
    plateauMonopoly[26].prixMaisonHotel[2] = 11000;
    plateauMonopoly[26].prixMaisonHotel[3] = 33000;
    plateauMonopoly[26].prixMaisonHotel[4] = 97500;
    plateauMonopoly[26].prixMaisonHotel[5] = 115000;
    //Place de la Bourse
    plateauMonopoly[27].prixMaisonHotel[0] = 15000;
    plateauMonopoly[27].prixMaisonHotel[1] = 2200;
    plateauMonopoly[27].prixMaisonHotel[2] = 11000;
    plateauMonopoly[27].prixMaisonHotel[3] = 33000;
    plateauMonopoly[27].prixMaisonHotel[4] = 80000;
    plateauMonopoly[27].prixMaisonHotel[5] = 115000;
    //Rue Lafayette
    plateauMonopoly[29].prixMaisonHotel[0] = 15000;
    plateauMonopoly[29].prixMaisonHotel[1] = 2400;
    plateauMonopoly[29].prixMaisonHotel[2] = 12000;
    plateauMonopoly[29].prixMaisonHotel[3] = 36000;
    plateauMonopoly[29].prixMaisonHotel[4] = 85000;
    plateauMonopoly[29].prixMaisonHotel[5] = 120000;
    //Avenue de Breteuil
    plateauMonopoly[31].prixMaisonHotel[0] = 20000;
    plateauMonopoly[31].prixMaisonHotel[1] = 2600;
    plateauMonopoly[31].prixMaisonHotel[2] = 13000;
    plateauMonopoly[31].prixMaisonHotel[3] = 39000;
    plateauMonopoly[31].prixMaisonHotel[4] = 90000;
    plateauMonopoly[31].prixMaisonHotel[5] = 127500;
    //Avenue Foch
    plateauMonopoly[32].prixMaisonHotel[0] = 20000;
    plateauMonopoly[32].prixMaisonHotel[1] = 2600;
    plateauMonopoly[32].prixMaisonHotel[2] = 13000;
    plateauMonopoly[32].prixMaisonHotel[3] = 39000;
    plateauMonopoly[32].prixMaisonHotel[4] = 90000;
    plateauMonopoly[32].prixMaisonHotel[5] = 127500;
    //Boulevard des Capucines
    plateauMonopoly[34].prixMaisonHotel[0] = 20000;
    plateauMonopoly[34].prixMaisonHotel[1] = 2800;
    plateauMonopoly[34].prixMaisonHotel[2] = 15000;
    plateauMonopoly[34].prixMaisonHotel[3] = 45000;
    plateauMonopoly[34].prixMaisonHotel[4] = 100000;
    plateauMonopoly[34].prixMaisonHotel[5] = 140000;
    //Avenue des Champs-Elysées
    plateauMonopoly[37].prixMaisonHotel[0] = 20000;
    plateauMonopoly[37].prixMaisonHotel[1] = 17500;
    plateauMonopoly[37].prixMaisonHotel[2] = 50000;
    plateauMonopoly[37].prixMaisonHotel[3] = 110000;
    plateauMonopoly[37].prixMaisonHotel[4] = 130000;
    plateauMonopoly[37].prixMaisonHotel[5] = 150000;
    //Rue de la paix
    plateauMonopoly[39].prixMaisonHotel[0] = 20000;
    plateauMonopoly[39].prixMaisonHotel[1] = 20000;
    plateauMonopoly[39].prixMaisonHotel[2] = 60000;
    plateauMonopoly[39].prixMaisonHotel[3] = 140000;
    plateauMonopoly[39].prixMaisonHotel[4] = 170000;
    plateauMonopoly[39].prixMaisonHotel[5] = 200000;
    //Gare Montparnasse
    plateauMonopoly[5].prixMaisonHotel[1] = 2500;
    plateauMonopoly[5].prixMaisonHotel[2] = 5000;
    plateauMonopoly[5].prixMaisonHotel[3] = 10000;
    plateauMonopoly[5].prixMaisonHotel[4] = 20000;
    //Gare de Lyon
    plateauMonopoly[15].prixMaisonHotel[1] = 2500;
    plateauMonopoly[15].prixMaisonHotel[2] = 5000;
    plateauMonopoly[15].prixMaisonHotel[3] = 10000;
    plateauMonopoly[15].prixMaisonHotel[4] = 20000;
    //Gare du Nord
    plateauMonopoly[25].prixMaisonHotel[1] = 2500;
    plateauMonopoly[25].prixMaisonHotel[2] = 5000;
    plateauMonopoly[25].prixMaisonHotel[3] = 10000;
    plateauMonopoly[25].prixMaisonHotel[4] = 20000;
    //Gare Saint-Lazare
    plateauMonopoly[35].prixMaisonHotel[1] = 2500;
    plateauMonopoly[35].prixMaisonHotel[2] = 5000;
    plateauMonopoly[35].prixMaisonHotel[3] = 10000;
    plateauMonopoly[35].prixMaisonHotel[4] = 20000;
    //Compagnie d'électricité
    plateauMonopoly[12].prixMaisonHotel[0] = 400;
    plateauMonopoly[12].prixMaisonHotel[1] = 1000;
    //Compagnie des eaux
    plateauMonopoly[28].prixMaisonHotel[0] = 400;
    plateauMonopoly[28].prixMaisonHotel[1] = 1000;

    // ======================================================================
    //Nombre Maison restante
    plateauMonopoly[0].prixMaisonHotel[1] = 6942;
    //Nombre Hotel restant
    plateauMonopoly[0].prixMaisonHotel[2] = 6942;


}

void initialisationMonopoly (CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    initialisationNomCase( plateauMonopoly );
    initialisationMaisonHotelPossession( plateauMonopoly );
    initialisationPrixCase( plateauMonopoly );
    initialisationTypeCase( plateauMonopoly );
    initialisationGroupeCase( plateauMonopoly );
    initialisationPrixTerrainNu( plateauMonopoly );
    initialisationPrixMaisonHotel( plateauMonopoly );
}

//Inisialisation des joueurs

void initialisationArgentJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    int i = 0;
    for (i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        listeJoueur[i].argentJoueur = 150000;
    }
}

void initialisationCaseJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    int i = 0;
    for (i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        listeJoueur[i].caseJoueur = 0;
    }
}

void initialisationPrisonJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    int i = 0;
    for (i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        listeJoueur[i].prison = 0;
        listeJoueur[i].carteLiberePrison = 0;
    }
}

void initialisationNomJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    int i = 0;
    for (i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        strcpy( listeJoueur[i].nomJoueur, "Bob" );
    }
}

void initialisationJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    initialisationArgentJoueur( listeJoueur );
    initialisationCaseJoueur( listeJoueur );
    initialisationPrisonJoueur( listeJoueur );
    initialisationNomJoueur( listeJoueur );
}

//Initialisation des cartes Chance et Caisse de communauté
void initialisationOrdreCarte (CarteChanceCaisse* pInfoChanceCaisse) {
    randomOrdreCaisseChance(pInfoChanceCaisse->ordreCarteChance);
    randomOrdreCaisseChance(pInfoChanceCaisse->ordreCarteCaisse);
}

void initialisationPrixEvenement (CarteChanceCaisse* infoChanceCaisse) {
    //Chance:
    //Mots Croisés
    infoChanceCaisse->prixCarteChance[0] = 10000;
    //Excès de vitesse
    infoChanceCaisse->prixCarteChance[1] = 1500;
    //Dividende Banque
    infoChanceCaisse->prixCarteChance[2] = 5000;
    //Immeuble et prêt
    infoChanceCaisse->prixCarteChance[3] = 15000;
    //Amende pour ivresse
    infoChanceCaisse->prixCarteChance[4] = 2000;
    //Frais de scolarité
    infoChanceCaisse->prixCarteChance[5] = 15000;
    //Réparation maison (coût par maison)
    infoChanceCaisse->prixCarteChance[6] = 2500;
    //Réparation maison (coût par hotel)
    infoChanceCaisse->prixCarteChance[7] = 10000;
    //Réparation de voirie (coût par maison)
    infoChanceCaisse->prixCarteChance[8] = 4000;
    //Réparation de voirie (coût par hotel)
    infoChanceCaisse->prixCarteChance[9] = 11500;

    //Caisse de communauté:
    //Heritage
    infoChanceCaisse->prixCarteCaisse[0] = 10000;
    //Remboursement des contributions
    infoChanceCaisse->prixCarteCaisse[1] = 2000;
    //Cout Hopital
    infoChanceCaisse->prixCarteCaisse[2] = 10000;
    //Cout Police d'assurance
    infoChanceCaisse->prixCarteCaisse[3] = 5000;
    //Vente stock
    infoChanceCaisse->prixCarteCaisse[4] = 5000;
    //Erreur de la Banque
    infoChanceCaisse->prixCarteCaisse[5] = 20000;
    //Interet sur l'emprunt
    infoChanceCaisse->prixCarteCaisse[6] = 2500;
    //Revenu annuel
    infoChanceCaisse->prixCarteCaisse[7] = 10000;
    //Note du medecin
    infoChanceCaisse->prixCarteCaisse[8] = 5000;
    //Deuxieme prix de beauté
    infoChanceCaisse->prixCarteCaisse[9] = 1000;
    //Cadeau Anniversaire
    infoChanceCaisse->prixCarteCaisse[10] = 1000;
    //Carte Chance ou Amende
    infoChanceCaisse->prixCarteCaisse[11] = 1000;
}

void initialisationCarteChanceCaisse (CarteChanceCaisse* pInfoChanceCaisse) {
    initialisationOrdreCarte(pInfoChanceCaisse);
    initialisationPrixEvenement(pInfoChanceCaisse);
    pInfoChanceCaisse->numeroCarteCaisse = 0;
    pInfoChanceCaisse->numeroCarteChance = 0;
}

//Affichage et Initialisation des regles
void affichageRegle(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU]) {
    int choix = 0;
    int listeChoix10[] = {0,1,2,3,4,5,6,7,8,9};

    printf("\nChoisissez la section qui vous interesse :\n");
    printf("0) Retour\n");
    printf("1) Presentation generale\n");
    printf("2) Propriete, maison, hotel et monopole\n");
    printf("3) Prison\n");
    printf("4) Gares et services publiques\n");
    printf("5) Hypotheque et vente de terrain\n");
    printf("6) Regles diverses\n");
    printf("7) Faillite\n");
    printf("8) Regles optionnelles\n");
    printf("9) Fonctionnement du jeu et des touches\n");

    do {

        do {
            verificationSaisie(&choix);
            if (choix <0 || choix > 9) {
                printf("Veuillez saisir un choix valide.\n");
            }
        } while (choix <0 || choix > 9);

        switch (choix) {
            case 0 :
            {
                break;
            }
            case 1 :
            {
                printf("Le Monopoly est un jeu auquel vous pouvez jouer jusqu'a 6 joueurs.\n");
                printf("Le but est d'etre le dernier joueur a ne pas faire faillite.\n");
                printf("Vous commencerez avec 150 000 francs et pourrez acheter des proprietes et effectuer des actions pour faire tomber vos\n");
                printf("adversaires.\n");
                printf("Lancer vos deux des, avancez du nombre de cases indique sur vos des et faites les bons choix pour mener vos concurrents\n");
                printf("a la ruine.\n");
                printf("Les regles de chaque case sont expliquees clairement dans les sections suivantes.\n");
                break;
            }
            case 2 :
            {
                printf("Les cases de couleurs sur le plateau sont des proprietes que vous pouvez acheter.\n");
                printf("Si un joueur tombe sur l'une de vos proprietes, il devra vous payer un loyer different pour chaque case.\n");
                printf("Vous pouvez regarder le prix des loyers d'une propriete dans les infos concernant les prix des cases.\n");
                printf("Si vous obtenez toutes les proprietes d'une meme couleur, vous obtiendrez un monopole.\n\n");

                printf("Avec un monopole le loyer a payer pour les joueurs qui tomberont sur une des proprietes de ce groupe sera double.\n");
                printf("Le monopole vous permet aussi d'acheter des maisons et des hotels sur les proprietes de ce groupe.\n");
                printf("Plus il y a de maisons sur une meme case, plus le loyer de cette case sera cher.\n");
                printf("De plus, lorsque vous aurez 4 maisons sur la meme propriete, il vous sera possible d'y acheter un hotel en remettant\n");
                printf("les 4 maisons de la propriete en jeu.\n");
                printf("Il n'y a rien de plus cher qu'un hotel, c'est le plus haut niveau d'amelioration d'une propriete.\n\n");

                printf("Aucune maison ne peut etre construite sur une propriete si une des proprietes du groupe est hypothequee.\n\n");

                printf("Vous pouvez vendre vos maisons et vos hotels pour la moitie de leur prix d'achat.\n");
                printf("Les maisons se vendent une par une. Les hotels peuvent etre vendus de 2 manieres differentes :\n");
                printf("- Vous pouvez vendre seulement l'hotel en le remplacant par 4 maisons s'il reste suffisamment de maison dans le jeu.\n");
                printf("- Sinon vous pouvez vendre votre hotel et les 4 maisons de votre propriete d'un seul coup.\n\n");

                printf("Attention, le nombre de maisons et d'hotels sont limitees dans le jeu.\n");
                printf("Leur nombre est indique en haut a droite du plateau de jeu. Si l'un ou l'autre manque, il faudra attendre qu'un joueur\n");
                printf("vende des batiments pour en acheter a nouveau.\n");
                break;
            }
            case 3 :
            {
                printf("La case numero 10 est la case prison. Un joueur atterrit en prison quand :\n");
                printf("1. Son jeton atterrit sur la case numero 30 allez en prison notee _-->#_ sur le plateau de jeu.\n");
                printf("2. Il tire une carte marquee 'aller en prison'. \n");
                printf("3. Il lance trois fois de suite des doubles.\n\n");

                printf("Lorsqu'un joueur est envoye en prison, son tour se termine.\n");
                printf("Il ne peut plus se deplacer sur le plateau de jeu tant qu'il n'est pas sorti de prison.\n");
                printf("Meme s'il est en prison, un joueur peut encore acheter, vendre ou hypothequer une propriete, acheter ou vendre\n");
                printf("des maisons et des hotels, faire des echanges et percevoir des loyers.\n\n");

                printf("Si un joueur n'est pas envoye en prison mais qu'il atterrit dans le cours normal du jeu sur la case prison numero 10,\n");
                printf("il est juste en visite, n'encourt aucune penalite, et avance de la maniere habituelle sur son prochain jet.\n\n");

                printf("Un joueur sort de prison lorsqu'il :\n");
                printf("1. Lance des doubles sur l'un de ses trois tours suivants, s'il reussit a le faire, il avance immediatement du nombre\n");
                printf("   indiques par son double. Si le joueur ne fait pas de double a son troisieme tour, il doit payer 5 000 francs.\n");
                printf("   Il sort alors de prison et pourra jouer au prochain tour.\n");
                printf("2. Utilise la carte 'Sortir de prison gratuitement' s'il en a une.\n");
                printf("3. Achete la carte 'Sortir de prison gratuitement' d'un autre joueur et la joue.\n");
                printf("4. Paye une amende de 5 000 francs avant de lancer les des pour jouer.\n");
                break;
            }
            case 4 :
            {
                printf("En plus des proprietes, un joueur peut aussi acheter des gares et des cases de services publiques.\n\n");

                printf("Plus un joueur possede de gare, plus les loyers a payer sur celles-ci sont chers.\n");
                printf("Vous pouvez regarder le prix des loyers d'une gare dans les infos concernant les prix des cases.\n\n");

                printf("Un joueur peut aussi acheter les compagnies de distributions d'electricite et d'eaux. (les cases 12 et 28)\n");
                printf("Si vous possedez une seule de ces compagnies et qu'un joueur adverse tombe dessus, le loyer a payer sera de\n");
                printf("400 francs multiplie par le nombre obtenu par la somme de ses deux des.\n");
                printf("Si vous possedez les deux compagnies, le loyer sera cette fois-ci de 1000 francs fois la somme de ses deux des.\n");
                break;
            }
            case 5 :
            {
                printf("Les proprietes non ameliorees, les gares et les compagnies peuvent etre hypothequees en tout temps.\n");
                printf("Avant qu'une propriete amelioree puisse etre hypothequee, tous les batiments sur toutes les proprietes de son groupe\n");
                printf("de couleur doivent etre revendus a la Banque a moitie prix.\n");
                printf("Vous pouvez regarder la valeur de l'hypotheque d'une case dans les infos concernant les prix des cases.\n\n");

                printf("Aucun loyer ne peut etre percu sur les proprietes, les services publics ou les gares hypotheques.\n");
                printf("Cependant le loyer peut etre percu sur les proprietes non hypothequees du meme groupe de couleur.\n\n");

                printf("Afin de lever l'hypotheque, le proprietaire doit payer a la Banque le prix de l'hypotheque majore d'un interet de 10%%.\n");
                printf("Toutefois, le proprietaire peut vendre ou echanger cette propriete hypothequee a un autre joueur a un prix convenu.\n");
                printf("Le nouveau proprietaire peut lever l'hypotheque immediatement en remboursant l'hypotheque plus 10%% d'interets.\n");
                printf("Sinon il doit payer a la banque un interet de 10 %% lorsqu'il achete/recoit la propriete hypothequee.\n");
                printf("S'il leve l'hypotheque plus tard, il doit payer un interet additionnel de 10 %% ainsi que le montant de l'hypotheque.\n");
                break;
            }
            case 6 :
            {
                printf("Si un joueur lance des doubles, il deplace son jeton comme d'habitude, mais il doit alors relancer les des\n");
                printf("une deuxieme fois apres avoir effectue sa premiere phase de tour.\n\n");

                printf("Chaque fois qu'un jeton atterrit ou passe par-dessus la case depart, que ce soit en jetant les des ou en tirant\n");
                printf("une carte, le banquier paie au joueur un salaire de 20 000 francs.\n\n");

                printf("Quand un joueur atterrit sur une case chance ou caisse de communaute, il prend la carte du haut de la pioche indiquee,\n");
                printf("suit les instructions et retourne la carte face cachee au bas de la pioche.\n");
                printf("La carte 'Sortir de prison' est conservee jusqu'a ce qu'elle soit utilisee, puis retournee dans son paquet.\n\n");

                printf("Lorsqu'un joueur atterrit sur la case 'Impot' ou 'taxe', il doit payer une amende a la Banque.\n\n");

                printf("Un joueur qui atterrit sur la case parc gratuit ne recoit pas d'argent, de biens ou de recompenses.\n");
                printf("Ce n'est qu'un lieu de repos 'libre'.\n\n");

                printf("La Banque ne peut preter de l'argent a un joueur qu'en hypothequant un bien immobilier.\n");
                printf("Aucun joueur ne peut emprunter ou preter de l'argent a un autre joueur.\n");
                break;
            }
            case 7 :
            {
                printf("Un joueur est en faillite lorsqu'il doit plus qu'il ne peut payer a un autre joueur ou a la Banque.\n\n");

                printf("Si sa dette est envers un autre joueur, il doit remettre a ce joueur tout ce qu'il a de valeur et se retirer du jeu.\n");
                printf("Dans ce cadre, s'il est proprietaire de maisons ou d'hotels, il doit les vendre et remettre l'argent au creancier\n");
                printf("S'il a hypotheque un bien, il remet egalement son bien a ce creancier, mais le nouveau proprietaire doit payer\n");
                printf("immediatement a la Banque le montant des interets sur le pret, soit 10 %% de la valeur du bien.\n");
                printf("Une fois que le nouveau proprietaire l'a fait, il peut payer le capital ou resilier l'hypotheque a une date ulterieure.\n\n");

                printf("Si un joueur doit a la Banque, plus que ce qu'il peut payer (en raison de taxes ou de penalites), meme en vendant\n");
                printf("ses batiments, en hypothequant sa propriete ou en vendant ou en echangeant avec d'autres joueurs,\n");
                printf("il doit remettre tous ses biens a la Banque.\n");
                break;
            }
            case 8 :
            {
                printf("Il existe des regles supplementaires que vous pourrez choisir de jouer ou non en debut de partie :\n\n");

                printf("Case depart double :\n");
                printf("Cette regle permet de donner 20 000 francs en plus a un joueur qui s’arreterait sur la case depart.\n\n");

                printf("Parc de la fortune :\n");
                printf("Cette regle permet de faire gagner de l'argent stocke sur la case du parc gratuit au joueur qui s'arretera dessus.\n");
                printf("Cet argent provient des differents malus des cartes chance et caisse de communaute et des cases taxes et impots.\n");
                printf("L'argent sera alors remis en jeu sur la case parc gratuit plutot qu'a la banque, et un joueur pourra le recuperer.\n");
                printf("Il sera affiche en haut a droite sur le plateau de jeu.\n");
                break;
            }
            case 9 :
            {
                printf("Dans cette version du Monopoly, il vous sera demande avant chaque debut de tour si vous voulez continuer.\n");
                printf("Vous devrez alors taper :\n");
                printf("0 si vous voulez revenir au menu principal.\n");
                printf("1 si vous voulez continuer le jeu.\n");
                printf("2 si vous voulez effectuer une autre action (voir les prix des cases, acheter des maisons, hypothequer...\n\n");

                printf("Lorsque qu'une question vous sera posee, le 1 signifiera toujours oui et le 0 non.\n\n");

                printf("Sur le plateau de jeu, la case depart est situe en haut a gauche. C'est la case numero 0.\n");
                printf("Viens ensuite en parcourant le plateau dans le sens des aiguilles d'une montre la case 1 puis 2 jusqu'a 39.\n");
                printf("Les 4 coins du plateau representent donc les case 0, 10, 20 et 30 et les 4 gares les cases 5, 15, 25 et 35.\n\n");

                printf("Les groupes de proprietes sont representes par couleur tout autour du plateau.\n");
                printf("Ces couleurs sont independantes des couleurs des joueurs sur le plateau.\n");
                printf("Si personne n'a encore achete une de ces cases, le prix sera affiche en dessous de celle-ci (10k pour 10000 francs).\n");
                printf("Une fois la propriete achetee, il y aura affiche le numero du joueur qui detient cette case a la place.\n");
                printf("Un M suivit d'un chiffre apparaitrons suivant le nombre de maisons presente sur cette case.\n");
                printf("Un H apparaitra s'il y a un hotel sur cette case et un X apparaitra si cette case est hypothequee.\n\n");

                printf("Sur le plateau, chaque joueur est represente par un chiffre selon l'ordre dans lequel vous avez enregistre vos noms.\n");
                printf("Vous pouvez aussi y lire l'argent que vous possedez ainsi que le nombre de maisons et d'hotels encore disponible.\n");
                printf("Si la regle du parc gratuit est activee, vous pourrez y lire l'argent a recuperer si vous tombez sur la case 'Parc'.\n");
                break;
            }
            default :
            {
                printf("Erreur Regle\n");
                break;
            }
        }
    } while (choix != 0);
}

void choixRegleSupplementaire(int* regleDepart, int* regleParcGratuit) {

    printf("\nVoulez vous jouer la regle \"Case Depart double\" ?\n");
    printf("1) Oui\n0) Non\n");

    do {
        verificationSaisie(regleDepart);
        if (*regleDepart != 0 && *regleDepart != 1) {
            printf("Veuillez saisir 0 pour non ou 1 pour oui.\n");
        }
    } while (*regleDepart !=0 && *regleDepart != 1);

    if (*regleDepart) {
        printf("La regle sera donc joue.\n\n");
    }
    else {
        printf("La regle ne sera donc pas joue\n\n");
    }


    printf("\nVoulez vous jouer la regle \"Parc Gratuit\" ?\n");
    printf("1) Oui\n0) Non\n");

    do {
        verificationSaisie(regleParcGratuit);
        if (*regleParcGratuit != 0 && *regleParcGratuit != 1) {
            printf("Veuillez saisir 0 pour non ou 1 pour oui.\n");
        }
    } while (*regleParcGratuit !=0 && *regleParcGratuit != 1);

    if (*regleParcGratuit) {
        printf("La regle sera donc joue.\n\n");
    }
    else {
        printf("La regle ne sera donc pas joue\n\n");
    }
}

void initialisationSauvegarde(CaseMonopoly plateauMonopoly[TAILLE_PLATEAU], InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR], CarteChanceCaisse* infoChanceCaisse, int listeVariable[NOMBRE_VARIABLE]) {
    listeVariable[0] = 0;
    listeVariable[1] = 0;
    listeVariable[2] = 0;
    listeVariable[3] = 2;
    listeVariable[4] = 1;
    listeVariable[5] = 1;
    listeVariable[6] = 32;
    listeVariable[7] = 12;
    listeVariable[8] = 0;
    initialisationMonopoly(plateauMonopoly);
    initialisationJoueur(listeJoueur);
    initialisationCarteChanceCaisse(infoChanceCaisse);
    return;
}


void initialisationDebutSauvegarde(CaseMonopoly plateauMonopoly1[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly2[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly3[TAILLE_PLATEAU],
                                   InfoJoueur listeJoueur1[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur2[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur3[NOMBRE_MAX_JOUEUR],
                                   int listeVariable1[NOMBRE_VARIABLE], int listeVariable2[NOMBRE_VARIABLE], int listeVariable3[NOMBRE_VARIABLE],
                                   CarteChanceCaisse infoChanceCaisse[], int* pSauvegarde1, int* pSauvegarde2, int* pSauvegarde3) {

    FILE* pfichier = fopen("../monFichierMonopoly.dat", "r");
    if (pfichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");

        printf("Creation de votre fichier de sauvegarde...\n");
        pfichier = fopen("../monFichierMonopoly.dat", "w");

        initialisationSauvegarde(plateauMonopoly1, listeJoueur1, &infoChanceCaisse[0], listeVariable1);
        initialisationSauvegarde(plateauMonopoly2, listeJoueur2, &infoChanceCaisse[1], listeVariable2);
        initialisationSauvegarde(plateauMonopoly3, listeJoueur3, &infoChanceCaisse[2], listeVariable3);

        printf("C'est la premiere fois que vous lancez le jeu, un petit tour dans la rubrique regle vous aidera !\n");
    }
    else {

        if (fread(pSauvegarde1, sizeof(int), 1, pfichier) != 1) {
            printf("Probleme de lecture dans le fichier (Sauvegarde 1).\n");
        }
        /*
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            if (fread(&plateauMonopoly1[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (Case numero %d de la sauvegarde 1).\n", i);
            }
        }*/

        if (fread(plateauMonopoly1, sizeof(CaseMonopoly), TAILLE_PLATEAU, pfichier) != 40) {
            printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 1).\n", 1);
        }

        for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
            if (fread(&listeJoueur1[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (Joueur numero %d de la sauvegarde 1).\n", i);
            }
        }
        if (fread(listeVariable1, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
            printf("Probleme de lecture dans le fichier (liste des variables de la sauvegarde 1).\n");
        }
        if (fread(&infoChanceCaisse[0], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
            printf("Probleme de lecture dans le fichier (carte chance et caisse de communaute de la sauvegarde 1).\n");
        }



        if (fread(pSauvegarde2, sizeof(int), 1, pfichier) != 1) {
            printf("Probleme de lecture dans le fichier (Sauvegarde 2).\n");
        }

        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            if (fread(&plateauMonopoly2[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (Case numero %d de la sauvegarde 2).\n", i);
            }
        }
        /*
        if (fread(plateauMonopoly2, sizeof(CaseMonopoly), TAILLE_PLATEAU, pfichier) != 40) {
            printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 2).\n", 1);
        }*/


        for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
            if (fread(&listeJoueur2[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (Joueur numero %d de la sauvegarde 2).\n", i);
            }
        }
        if (fread(listeVariable2, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
            printf("Probleme de lecture dans le fichier (liste des variables de la sauvegarde 2).\n");
        }
        if (fread(&infoChanceCaisse[1], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
            printf("Probleme de lecture dans le fichier (carte chance et caisse de communaute de la sauvegarde 2).\n");
        }


        if (fread(pSauvegarde3, sizeof(int), 1, pfichier) != 1) {
            printf("Probleme de lecture dans le fichier (Sauvegarde 3).\n");
        }
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            if (fread(&plateauMonopoly3[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (Case numero %d de la sauvegarde 3).\n", i);
            }
        }
        for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
            if (fread(&listeJoueur3[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                printf("Probleme de lecture dans le fichier (Joueur numero %d de la sauvegarde 3).\n", i);
            }
        }
        if (fread(listeVariable3, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
            printf("Probleme de lecture dans le fichier (liste des variables de la sauvegarde 3).\n");
        }
        if (fread(&infoChanceCaisse[2], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
            printf("Probleme de lecture dans le fichier (carte chance et caisse de communaute de la sauvegarde 3).\n");
        }
    }

    fclose(pfichier);
    pfichier = NULL;
    return;
}



void enregistrementFinSauvegarde(CaseMonopoly plateauMonopoly1[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly2[TAILLE_PLATEAU], CaseMonopoly plateauMonopoly3[TAILLE_PLATEAU],
                                 InfoJoueur listeJoueur1[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur2[NOMBRE_MAX_JOUEUR], InfoJoueur listeJoueur3[NOMBRE_MAX_JOUEUR],
                                 int listeVariable1[NOMBRE_VARIABLE], int listeVariable2[NOMBRE_VARIABLE], int listeVariable3[NOMBRE_VARIABLE],
                                 CarteChanceCaisse infoChanceCaisse[], int* pSauvegarde1, int* pSauvegarde2, int* pSauvegarde3) {

    FILE* pfichier = fopen("../monFichierMonopoly.dat", "w");
    if (pfichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
    }


    if (fwrite(pSauvegarde1, sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (Sauvegarde 1).\n");
    }
    /*
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        if (fwrite(&plateauMonopoly1[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 1).\n", i);
        }
    }
    */
    if (fwrite(plateauMonopoly1, sizeof(CaseMonopoly), TAILLE_PLATEAU, pfichier) != 40) {
        printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 1).\n", 1);
    }


    for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        if (fwrite(&listeJoueur1[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Joueur numero %d de la sauvegarde 1).\n", i);
        }
    }
    if (fwrite(listeVariable1, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (liste des variables de la sauvegarde 1).\n");
    }
    if (fwrite(&infoChanceCaisse[0], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 1).\n");
    }



    if (fwrite(pSauvegarde2, sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (Sauvegarde 2).\n");
    }
    /*
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        if (fwrite(&plateauMonopoly2[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 2).\n", i);
        }
    }
    */

    if (fwrite(plateauMonopoly2, sizeof(CaseMonopoly), TAILLE_PLATEAU, pfichier) != 40) {
        printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 2).\n", 1);
    }

    for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        if (fwrite(&listeJoueur2[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Joueur numero %d de la sauvegarde 2).\n", i);
        }
    }
    if (fwrite(listeVariable2, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (liste des variables de la sauvegarde 2).\n");
    }
    if (fwrite(&infoChanceCaisse[1], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 2).\n");
    }


    if (fwrite(pSauvegarde3, sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (Sauvegarde 3).\n");
    }
    /*
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        if (fwrite(&plateauMonopoly3[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 3).\n", i);
        }
    }*/
    if (fwrite(plateauMonopoly3, sizeof(CaseMonopoly), TAILLE_PLATEAU, pfichier) != 40) {
        printf("Probleme d'ecriture dans le fichier (Case numero %d de la sauvegarde 3).\n", 1);
    }

    for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        if (fwrite(&listeJoueur3[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
            printf("Probleme d'ecriture dans le fichier (Joueur numero %d de la sauvegarde 3).\n", i);
        }
    }
    if (fwrite(listeVariable3, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (liste des variables de la sauvegarde 3).\n");
    }
    if (fwrite(&infoChanceCaisse[2], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
        printf("Probleme d'ecriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 3).\n");
    }

    fclose(pfichier);
    pfichier = NULL;
    return;
}