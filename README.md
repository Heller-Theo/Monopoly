# Monopoly en C

Ce projet a été réalisé dans le cadre de mon projet de fin d'année en première année d'école d'ingénieur, dans le but d'apprendre le langage C. Il s'agit d'une implémentation du célèbre jeu de société **Monopoly**.

Le projet inclut l'implémentation de la logique du jeu, les règles de base ainsi qu'une interface en ligne de commande pour jouer entre plusieurs joueurs. Ce travail a été une excellente occasion de se familiariser avec les concepts fondamentaux du langage C, tels que la gestion de la mémoire, les structures de données, et l'algorithmie.

## Fonctionnalités

- Jeu de Monopoly en mode texte avec plusieurs joueurs.
- Gestion des propriétés, argent, et cartes.
- Fonctionnalités de base du jeu : achat de propriétés, paiement de loyers, déplacements sur le plateau.
- Règles classiques du Monopoly.

## Structure du projet

Le code source du projet est organisé de la manière suivante :
- `main.c` : Point d'entrée du programme et gestion des interactions avec l'utilisateur.
- `jeu.c` : Logique du jeu, y compris les mouvements des joueurs, la gestion des cartes, et des propriétés.
- `initialisation.c` : Initialisation du plateau de jeu, des joueurs et des propriétés.
- `sauvegarde.c` : Gestion de la sauvegarde et du chargement des parties.
- `fonction.c` : Fonctions utilitaires pour gérer les actions du jeu.
- `fonction.h` : Déclarations des fonctions utilitaires.
- `initialisation.h` : Déclarations des fonctions d'initialisation.
- `jeu.h` : Déclarations des fonctions liées au jeu.
- `sauvegarde.h` : Déclarations des fonctions liées à la sauvegarde des parties.
- `structure.h` : Déclarations des structures de données utilisées (par exemple, pour les joueurs, les propriétés, etc.).


## Installation

1. Clonez le repository :

   ```bash
   git clone https://github.com/Heller-Theo/Monopoly.git
   ```

2. Accédez au dossier du projet :

   ```bash
   cd Monopoly
   ```

3. Compilez le projet en utilisant `gcc` ou votre compilateur C préféré :

   ```bash
   gcc -o monopoly main.c jeu.c fonction.c initialisation.c sauvegarde.c
   ```

4. Lancez le jeu :

   ```bash
   ./monopoly
   ```

## Utilisation

1. Lancez le jeu.
2. Choisissez le nombre de joueurs (min 2).
3. Suivez les instructions à l'écran pour jouer une partie de Monopoly.

## Technologies utilisées

- Langage : **C**

## Auteurs

- **Théo Heller** - Créateur du projet

## Remarques

Ce projet a été réalisé dans un cadre d'apprentissage et peut contenir des imperfections. Il représente un bon exercice d'application des principes du langage C, en particulier la gestion de la mémoire et des structures de données.

## Licence

Ce projet est sous licence MIT. Vous pouvez l'utiliser, le modifier, et le distribuer comme bon vous semble.
