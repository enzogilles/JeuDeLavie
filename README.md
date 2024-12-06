# JeuDeLavie 

## Description  
Ce projet implémente le **Jeu de la Vie** de John Conway en C++, avec deux modes d'exécution :

- **Mode Console** : Affiche l'évolution des cellules dans la console et enregistre un nombre de fichiers voulu sur l'ordinateur après chaque itération.
- **Mode Graphique** : Affiche une visualisation dynamique des cellules dans une fenêtre graphique grâce à la bibliothèque SFML.


# Installation 
Tout les membres de l'équipe avait Windows comme OS lors de ce projet.

On a utiliser comme éditeur de texte **Visual Studio Community 2022**.

**Visual Studio Community** est téléchargeable depuis ce lien :
https://visualstudio.microsoft.com/fr/vs/community/

Ensuite configurer l'installation en choisissant le langage C++.

![image de config C++ dans Visual Studio Community 2022](image_visual_studio_option_dekstop.png)

Pensez aussi à installer la bibliothèque **SFML** pour manipuler l'interface graphique.
Lien vers le site officiel pour installer **SFML** :
https://www.sfml-dev.org/tutorials/2.6/start-vc.php

Le code de ce dépot est compilable avec le compilateur **g++**.

Vous pouvez aussi utiliser le débuggeur de Visual Studio Community 2022.
Fonctionnera seulement si vous avez bien installer et configurer l'environnement par rapport à ces bibliothèques.

Tout dépend de vos préférences.

## Fonctionnalités 🔧
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


2. Entrer dans le dossier :
   ```sh
    cd Jeu
   ```

3. Compilez le projet :
   ```sh
   make
   ```

4. Exécutez le programme :
   ```sh
   LIBGL_ALWAYS_SOFTWARE=1 ./bin/jeu_de_la_vie etat_initial.txt
   ```

5. Choix proposé : 

a) Mode Console 

L'utilisateur doit entrer le nombre d'itérations souhaité.
Le programme affichera l'évolution des cellules dans le terminal et enregistrera l'état de la grille après chaque itération dans des fichiers.


![image](https://github.com/user-attachments/assets/f9333f54-628e-4bfa-a170-963c0ca25b79)




b) Mode Graphique :

La simulation démarre automatiquement dans une fenêtre graphique.
L'utilisateur peut visualiser l'évolution des cellules en temps réel.



![image](https://github.com/user-attachments/assets/d2339f30-ac1b-47c7-aa77-45a083f96a57)



  

Projet d'étude réalisé dans le cadre du bloc POO de la CPIA2 du CESI.
