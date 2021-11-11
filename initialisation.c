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

void initialisationJoueur (InfoJoueur listeJoueur[NOMBRE_MAX_JOUEUR]) {
    initialisationArgentJoueur( listeJoueur );
    initialisationCaseJoueur( listeJoueur );
    initialisationPrisonJoueur( listeJoueur );
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
    int next = 1;
    scanf("%d", &next);
    if (next) {
        printf("\n-------------------------Bienvenue au jeu du Monopoly-------------------------\n\n\n");
        printf("Voici les regles:\n\n");

        printf("A chaque fois que le mot \"Continuer\" apparaitra, vous pourrez :\n");
        printf("Arreter le jeu en tapant \"0\".\n");
        printf("Continuer de jouer en tapant \"1\".\n");
        printf("Demander des informations sur les joueurs ou les cases du Monopoly en tapant \"2\".\n");
        printf("Acheter des maisons et des hotels en tapant \"3\".\n\n");
        scanf("%d", &next);

        printf("Double :\n");
        printf("Si vous faites un double, vous pourrez rejouer, mais attention, 3 doubles d'affile et vous irez en prison.\n\n");
        scanf("%d", &next);

        printf("Case Depart :\n");
        printf("Chaque fois que vous ferez un tour complet, vous gagnerez %d francs.\n", plateauMonopoly[0].prixMaisonHotel[0]);
        printf("De plus, il vous est possible d'ajouter la regle de la case depart double:\n");
        printf("Cette regle vous permet de gagner 2 * %d francs si vous vous arretez sur la case depart.\n", plateauMonopoly[0].prixMaisonHotel[0]);
        scanf("%d", &next);

        printf("Achat de proprietes :\n");
        printf("Si vous vous arretez sur une propriete qui n'appartient pas a un autre joueur, vous pourrez l'acheter.\n");
        printf("Si vous possedez toutes les proprietes d'une meme couleur, le prix du loyer sera double.\n");
        printf("De plus, vous pourrez en tapant \"3\" apres \"Continuer\" acheter des maisons et des hotels sur ces cases.\n");
        printf("(Taper \"2\" apres \"Continuer\" pour connaitre le prix des loyers)\n\n");
        scanf("%d", &next);

        printf("Maison et Hotel :\n");
        printf("Si vous parvenez a obtenir un monopole sur un terrain, il vous sera possible d'y acheter des maisons.\n");
        printf("Si vous possedez 4 maisons sur une propriete vous pourrez y acheter un hotel.\n");
        printf("Vous pouvez aussi decider de vendre vos maisons et vos hotels a tout moment pour la moitie du prix d'achat initial.\n");
        printf("Attention, il n'y a que 32 maisons et 12 hotels dans le jeu.\n\n");
        scanf("%d", &next);

        printf("Arret sur les services publics :\n");
        printf("Si vous vous arretez sur un service public, vous pourrez l'acheter si il n'appartient a personne.\n");
        printf("S'il appartient deja a un autre joueur, vous devrez payer:\n");
        printf("%d fois le resultat de vos des si le proprietaire ne possede qu'un des services publiques.\n", plateauMonopoly[12].prixMaisonHotel[0]);
        printf("%d fois le resultat de vos des si le proprietaire possede les deux services publiques.\n\n", plateauMonopoly[12].prixMaisonHotel[1]);
        scanf("%d", &next);

        printf("Arret sur une gare :\n");
        printf("Le loyer a payer si une case gare appartient a un autre joueur dependra du nombre de gare detenu par ce meme joueur.\n\n");
        scanf("%d", &next);

        printf("Carte Chance et Caisse de Communaute :\n");
        printf("Les cartes Chance et Caisse de Communaute sont melangees aleatoirement et vous demanderons d'effectuer des actions.\n");
        printf("Elles seront remises \"en dessous du paquet\" apres les avoir pioche sauf les cartes \"Vous etes libere de prison\".\n");
        printf("Elle reviendront donc dans le meme ordre une fois la pioche fini.\n\n");
        scanf("%d", &next);

        printf("Arret sur le Parc gratuit :\n");
        printf("Si vous vous arretez sur cette case, rien ne se passera.\n");
        printf("Vous pouvez cependant decider d'activer la regle du Parc Gratuit si vous le desirez: \n");
        printf("Cette regle creera un pot commun dans lequel iront toutes vos taxes payees a la banque.\n");
        printf("Ce pactole sera recupere par le joueur qui s'arretera sur la case Parc Gratuit.\n");
        scanf("%d", &next);

        printf("Prison :\n");
        printf("Votre tour s'arrete quand vous etes envoye en prison.\n");
        printf("Pour sortir de prison, il faut effectuer une des 3 actions suivantes :\n");
        printf("Payer une amende de %d francs et jouer au prochain tour.\n", plateauMonopoly[10].prixMaisonHotel[0]);
        printf("Utiliser une carte \"Vous etes libere de prison\" si vous en possedez une.\n");
        printf("Attendre en prison pendant trois tours, en lancant les des a chaque tour pour essayer de faire un double:\n");
        printf("Si vous faites un double, sortez de prison en utilisant ce lancer pour avancer.\n");
        printf("Si apres les trois tours, vous n'avez pas fait de double, payez %d francs et jouez au prochain tour.\n\n", plateauMonopoly[10].prixMaisonHotel[0]);
        scanf("%d", &next);
    }
}

void choixRegleSupplementaire(int* regleDepart, int* regleParcGratuit) {

    printf("Voulez vous jouer la regle \"Case Depart double\" ?\n");
    printf("1: Oui\n0: Non\n>");
    do {
        scanf(" %d", regleDepart);
    } while (*regleDepart !=0 && *regleDepart != 1);
    if (*regleDepart) {
        printf("La regle sera donc joue.\n\n");
    }
    else {
        printf("La regle ne sera donc pas joue\n\n");
    }


    printf("Voulez vous jouer la regle \"Parc Gratuit\" ?\n");
    printf("1: Oui\n0: Non\n>");
    do {
        scanf(" %d", regleParcGratuit);
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
    printf("La sauvegarde a bien ete reinitialise\n");
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
    }
    else {

        if (fread(pSauvegarde1, sizeof(int), 1, pfichier) != 1) {
            printf("Problème de lecture dans le fichier (Sauvegarde 1).\n");
        }
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            if (fread(&plateauMonopoly1[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                printf("Problème de lecture dans le fichier (Case numero %d de la sauvegarde 1).\n", i);
            }
        }
        for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
            if (fread(&listeJoueur1[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                printf("Problème de lecture dans le fichier (Joueur numero %d de la sauvegarde 1).\n", i);
            }
        }
        if (fread(listeVariable1, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
            printf("Problème de lecture dans le fichier (liste des variables de la sauvegarde 1).\n");
        }
        if (fread(&infoChanceCaisse[0], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
            printf("Problème de lecture dans le fichier (carte chance et caisse de communaute de la sauvegarde 1).\n");
        }



        if (fread(pSauvegarde2, sizeof(int), 1, pfichier) != 1) {
            printf("Problème de lecture dans le fichier (Sauvegarde 2).\n");
        }
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            if (fread(&plateauMonopoly2[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                printf("Problème de lecture dans le fichier (Case numero %d de la sauvegarde 2).\n", i);
            }
        }
        for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
            if (fread(&listeJoueur2[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                printf("Problème de lecture dans le fichier (Joueur numero %d de la sauvegarde 2).\n", i);
            }
        }
        if (fread(listeVariable2, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
            printf("Problème de lecture dans le fichier (liste des variables de la sauvegarde 2).\n");
        }
        if (fread(&infoChanceCaisse[1], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
            printf("Problème de lecture dans le fichier (carte chance et caisse de communaute de la sauvegarde 2).\n");
        }




        if (fread(pSauvegarde3, sizeof(int), 1, pfichier) != 1) {
            printf("Problème de lecture dans le fichier (Sauvegarde 3).\n");
        }
        for (int i = 0; i < TAILLE_PLATEAU; i++) {
            if (fread(&plateauMonopoly3[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
                printf("Problème de lecture dans le fichier (Case numero %d de la sauvegarde 3).\n", i);
            }
        }
        for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
            if (fread(&listeJoueur3[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
                printf("Problème de lecture dans le fichier (Joueur numero %d de la sauvegarde 3).\n", i);
            }
        }
        if (fread(listeVariable3, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
            printf("Problème de lecture dans le fichier (liste des variables de la sauvegarde 3).\n");
        }
        if (fread(&infoChanceCaisse[2], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
            printf("Problème de lecture dans le fichier (carte chance et caisse de communaute de la sauvegarde 3).\n");
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
        printf("Problème d'écriture dans le fichier (Sauvegarde 1).\n");
    }
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        if (fwrite(&plateauMonopoly1[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
            printf("Problème d'écriture dans le fichier (Case numero %d de la sauvegarde 1).\n", i);
        }
    }
    for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        if (fwrite(&listeJoueur1[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
            printf("Problème d'écriture dans le fichier (Joueur numero %d de la sauvegarde 1).\n", i);
        }
    }
    if (fwrite(listeVariable1, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
        printf("Problème d'écriture dans le fichier (liste des variables de la sauvegarde 1).\n");
    }
    if (fwrite(&infoChanceCaisse[0], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
        printf("Problème d'écriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 1).\n");
    }



    if (fwrite(pSauvegarde2, sizeof(int), 1, pfichier) != 1) {
        printf("Problème d'écriture dans le fichier (Sauvegarde 2).\n");
    }
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        if (fwrite(&plateauMonopoly2[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
            printf("Problème d'écriture dans le fichier (Case numero %d de la sauvegarde 2).\n", i);
        }
    }
    for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        if (fwrite(&listeJoueur2[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
            printf("Problème d'écriture dans le fichier (Joueur numero %d de la sauvegarde 2).\n", i);
        }
    }
    if (fwrite(listeVariable2, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
        printf("Problème d'écriture dans le fichier (liste des variables de la sauvegarde 2).\n");
    }
    if (fwrite(&infoChanceCaisse[1], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
        printf("Problème d'écriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 2).\n");
    }



    if (fwrite(pSauvegarde3, sizeof(int), 1, pfichier) != 1) {
        printf("Problème d'écriture dans le fichier (Sauvegarde 3).\n");
    }
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        if (fwrite(&plateauMonopoly3[i], sizeof(CaseMonopoly), 1, pfichier) != 1) {
            printf("Problème d'écriture dans le fichier (Case numero %d de la sauvegarde 3).\n", i);
        }
    }
    for (int i = 0; i < NOMBRE_MAX_JOUEUR; i++) {
        if (fwrite(&listeJoueur3[i], sizeof(InfoJoueur), 1, pfichier) != 1) {
            printf("Problème d'écriture dans le fichier (Joueur numero %d de la sauvegarde 3).\n", i);
        }
    }
    if (fwrite(listeVariable3, NOMBRE_VARIABLE * sizeof(int), 1, pfichier) != 1) {
        printf("Problème d'écriture dans le fichier (liste des variables de la sauvegarde 3).\n");
    }
    if (fwrite(&infoChanceCaisse[2], sizeof(CarteChanceCaisse), 1, pfichier) != 1) {
        printf("Problème d'écriture dans le fichier (carte chance et caisse de communaute de la sauvegarde 3).\n");
    }

    fclose(pfichier);
    pfichier = NULL;
    return;
}

