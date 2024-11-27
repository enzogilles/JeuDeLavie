# JeuDeLavie 

## Description
Ce projet implémente le **Jeu de la Vie** de John Conway en C++, avec deux modes d'exécution :

- **Mode Console** : Affiche l'évolution des cellules dans la console.
- **Mode Graphique** : Affiche une visualisation dynamique des cellules dans une fenêtre graphique grâce à la bibliothèque SFML.


## Fonctionnalités
- Initialisation d'une grille à partir d'un fichier.
- Simulation de l'évolution des cellules selon les règles du Jeu de la Vie.
- Deux modes d'affichage :
  - Console : Affiche chaque itération dans le terminal.
  - Graphique : Visualise l'évolution des cellules dans une interface interactive.
- Sauvegarde de l'état final dans un fichier (Mode Console).
- Gestion des dimensions dynamiques de la grille.

## Installation

## Prérequis
- **Compilateur C++** : GCC 12.0 ou supérieur.
- **Bibliothèque SFML** : Installez SFML en exécutant :


## Compilation & execution

-Se placer dans /src et compiler avec g++ -Wall -Wextra -pedantic -I../include *.cpp -o ../bin/JeuDeLaVie -lsfml-gr
aphics -lsfml-window -lsfml-system
-Se placer dans bin pour executer le programme avec ./JeuDeLaVie.

Projet d'étude réaliser dans le cadre du bloc POO de la CPIA2 du CESI.
