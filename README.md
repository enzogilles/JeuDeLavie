# JeuDeLavie 

## Description
Ce projet implémente le **Jeu de la Vie** de John Conway en C++, avec deux modes d'exécution :

- **Mode Console** : Affiche l'évolution des cellules dans la console et enregistre un nombre de fichiers voulu sur l'ordinateur après chaque itération.
- **Mode Graphique** : Affiche une visualisation dynamique des cellules dans une fenêtre graphique grâce à la bibliothèque SFML.

## Fonctionnalités
- Initialisation d'une grille à partir d'un fichier.
- Simulation de l'évolution des cellules selon les règles du Jeu de la Vie.
- Deux modes d'affichage :
  - Console : Affiche chaque itération dans le terminal.
  - Graphique : Visualise l'évolution des cellules dans une interface interactive.
- Sauvegarde de l'état final dans un fichier (Mode Console).
- Gestion des dimensions dynamiques de la grille.

Lors de la phase de conception, modéliser votre programme avec les diagrammes suivants :
- Diagramme de cas d’utilisation.
- Diagramme de classe.
- Diagramme d’activité.
- Diagramme de séquence.

## Prérequis
- **Compilateur C++** : GCC 12.0 ou supérieur.
- **Bibliothèque SFML** : Installez SFML en exécutant :
  ```sh
  sudo apt-get install libsfml-dev
  ```

## Compilation & exécution
1. Clonez le dépôt :
   ```sh
   git clone <url_du_dépôt>
   cd <nom_du_dépôt>
   ```

2. Compilez le projet :
   ```sh
   make
   ```

3. Choix proposé : 

a) Mode Console 

L'utilisateur doit entrer le nombre d'itérations souhaité.
Le programme affichera l'évolution des cellules dans le terminal et enregistrera l'état de la grille après chaque itération dans des fichiers.


b) Mode Graphique :

La simulation démarre automatiquement dans une fenêtre graphique.
L'utilisateur peut visualiser l'évolution des cellules en temps réel.


4. Exécutez le programme :
   ```sh
   LIBGL_ALWAYS_SOFTWARE=1 ./bin/jeu_de_la_vie etat_initial.txt
   ```


   

!!!!!!! SI L'UTILISATEUR RECONTRE DES SOUCIS :!!!!!!!


1. Nettoyez les fichiers objets et binaires :
   ```sh
   make clean
   ```

Projet d'étude réalisé dans le cadre du bloc POO de la CPIA2 du CESI.
