# JeuDeLavie (Livrable)

## Description  

Le jeu de la vie désigne un automate cellulaire proposé par le mathématicien John Conway. 
Il décrit l’évolution d’une population de cellules sur un intervalle de temps discret. 
Les cellules placées dans une grille rectangulaire deux dimensionnelle sont caractérisées par deux états ; elles sont soit vivantes, soit mortes. 
A l’exclusion des bordures, le voisinage d’une cellule est formé par 8 autres cellules directement adjacentes. 
Pour passer de l’itération tt à l’itération t+1t+1, l’état des cellules dans la grille est actualisé selon les règles suivantes :

- Une cellule morte possédant exactement trois voisines vivantes devient vivante.
- Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt.

Vous proposerez une implémentation en C++ du jeu de la vie en vous reposant sur les concepts de la programmation orientée objet. 
En entrée, votre programme consommera un fichier dont la première ligne permettra de spécifier la taille de la grille. 
Suivra une matrice de booléens, décrivant l’état initial, vivant (1) ou mort (0) des cellules.

![image](https://github.com/user-attachments/assets/6fc017e2-018a-4105-9f6a-d13143e5c615)



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



# Installation 
Tout les membres de l'équipe avait Windows comme OS lors de ce projet.

On a utiliser comme éditeur de texte **Visual Studio Community 2022**.

**Visual Studio Community** est téléchargeable depuis ce lien :
https://visualstudio.microsoft.com/fr/vs/community/

Ensuite configurer l'installation en choisissant le langage C++.

![image](https://github.com/user-attachments/assets/0c367d34-54b3-4190-96bb-8422cfdba90c)


Pensez aussi à installer la bibliothèque **SFML** pour manipuler l'interface graphique.
Lien vers le site officiel pour installer **SFML** :
https://www.sfml-dev.org/tutorials/2.6/start-vc.php

Le code de ce dépot est compilable avec le compilateur **g++**.

Vous pouvez aussi utiliser le débuggeur de Visual Studio Community 2022.
Fonctionnera seulement si vous avez bien installer et configurer l'environnement par rapport à ces bibliothèques.

Tout dépend de vos préférences.



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



## 🔧 **Implémentation en C++**
- **Langage :** C++  
- **Bibliothèque graphique :** SFML.  
- **Structure du projet :**  
   - `main.cpp` : Contient le point d'entrée du programme, gère la logique principale de la simulation et l'interface utilisateur (mode console ou graphique).  
   - `Cellule.h/.cpp` : Définit la classe Cellule, avec ses états (vivant ou mort), et les méthodes pour calculer son prochain état en fonction de son voisinage.  
   - `Grille.h/.cpp` : Gère la grille de cellules.  
   - `Fichier.h/.cpp` : Contient les fonctions pour lire un fichier d'entrée contenant l'état initial des cellules et écrire les états successifs dans des fichiers de sortie.  
   - `Makefile` : Script de compilation automatisé pour construire le projet, en gérant les dépendances et les règles pour produire l'exécutable.  
   - `Input.txt` : Fichier d'entrée de base, contenant la taille de la grille et l'état initial des cellules. Ce fichier est utilisé pour initialiser la simulation.  
   - `\Input.txt_out` : Dossier de sortie par défaut, où sont sauvegardés les fichiers correspondant aux états successifs de la grille à chaque itération pour le fichier d'entrée par default (Input.txt).



  

Projet d'étude réalisé dans le cadre du bloc POO de la CPIA2 du CESI.
