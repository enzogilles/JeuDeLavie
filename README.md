# 🕹️ Jeu de la Vie

Le **Jeu de la Vie** est un automate cellulaire conçu par le mathématicien **John Conway**. Ce concept illustre l'évolution d'une population de cellules dans une grille rectangulaire bidimensionnelle, selon des règles simples mais fascinantes.

### 🔍 Principe
- Chaque cellule est dans l'un des deux états suivants : **vivante** ou **morte**.
- Le voisinage de chaque cellule inclut les 8 cellules adjacentes.
- À chaque itération, l'état des cellules est mis à jour selon les règles suivantes :
  1. Une cellule morte possédant **exactement trois voisines vivantes** devient vivante.
  2. Une cellule vivante reste vivante si elle a **deux ou trois voisines vivantes** ; sinon, elle meurt.

Cette simulation met en lumière des phénomènes complexes à partir de règles simples, servant de métaphore pour la vie, l'évolution et les systèmes dynamiques.



### Photos de notre jeu 


![image](https://github.com/user-attachments/assets/ee6ff9b1-a011-4027-9f54-aec07ecb242a)


---

## 🌟 Sommaire

1. [📂 Structure du projet](#-structure-du-projet)
2. [⚙️ Installation](#️-installation)
3. [🚀 Utilisation](#-utilisation)
4. [📜 Fonctionnalités](#-fonctionnalités)
5. [📊 Diagrammes et Documentation](#-diagrammes-et-documentation)

---

## 📂 Structure du projet

- **Diagrammes/** : Contient des diagrammes UML (classe, activité, séquence, etc.).
- **Jeu/** : Fichiers sources et en-têtes pour le développement du projet.
- **bin/** : Fichiers binaires générés après compilation.
- **obj/** : Fichiers objets générés lors de la compilation.
- **resultats_out/** : Résultats des simulations.

---

## ⚙️ Installation

### Prérequis
- Un compilateur C++ compatible (par ex. GCC ou Clang)
- Make 

### Étapes
1. Clonez le projet :
   ```bash
   git clone https://github.com/votre-repo/jeu-de-la-vie.git
   cd jeu-de-la-vie/Jeu
   ```
2. Compilez les sources :
   ```bash
   make
   ```
3. Exécutez le binaire généré :
   ```bash
   LIBGL_ALWAYS_SOFTWARE=1 ./bin/jeu_de_la_vie etat_initial.txt
   ```

---

## 🚀 Utilisation

### Exécuter une simulation
1. Placez le fichier `etat_initial.txt` dans le répertoire `Jeu/`.
2. Lancez le programme :
   ```bash
   LIBGL_ALWAYS_SOFTWARE=1 ./bin/jeu_de_la_vie etat_initial.txt
   ```
3. Les résultats seront générés dans le dossier `resultats_out/`.

---

## 📜 Fonctionnalités

### Fonctionnalités principales
1. **Chargement de l'état initial** : L'utilisateur fournit un fichier avec la taille de la grille et l'état initial des cellules (vivantes ou mortes).
2. **Simulation selon les règles de Conway** :
   - Une cellule morte avec exactement trois voisines vivantes devient vivante.
   - Une cellule vivante avec deux ou trois voisines vivantes reste vivante, sinon elle meurt.
3. **Modes de fonctionnement** :
   - **Mode console** : Produit les `n` premières itérations, avec export des résultats dans des fichiers.
   - **Mode graphique** : Affiche une grille interactive où les cellules évoluent en temps réel.
4. **Critères d'arrêt** : Simulation terminée lorsque l'automate n'évolue plus ou qu'un nombre maximal d'itérations est atteint.

### Extensions 
1. **Grille torique** : Les bords de la grille sont connectés, créant une continuité entre les extrémités.
2. **Cellules obstacle** : Des cellules statiques (vivantes ou mortes) qui ne changent pas d'état.
3. Placement de constructions pré-programmées sur la grille. Utiliser la touche **P** et **M** pour y ajouter un blinker ou glinder sur la grille lors de l’exécution.
4. Ajout personnel d'un code couleur permettant d'identifier les cellules vivantes (Blanc), mortes(Bleu), ajoutées(Vert), bloquée (Rouge)

---

## 📊 Diagrammes et Documentation

- **Diagrammes UML** : Découvrez les diagrammes dans le dossier `Diagrammes/` :
  - Activité
  - Cas d'utilisation
  - Séquence
  - Classe

---

Merci d'utiliser le **Jeu de la Vie** ! 🌟
