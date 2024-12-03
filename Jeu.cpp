#include "Jeu.h"
#include <iostream>
#include <filesystem>
#include "Afficheur.h"

// Constructeur du jeu, initialise la grille à partir d'un fichier
Jeu::Jeu(const std::string& fichierEntree) : grille(Grille::getInstance()), nombreIterations(0) {
    grille.initialiser(fichierEntree);
}

// Exécuter le jeu en mode console
void Jeu::executerModeConsole(int iterations) {
    std::string dossierSortie = "resultats_out";
    std::filesystem::create_directory(dossierSortie);

    for (int i = 0; i < iterations; ++i) {
        std::string nomFichier = dossierSortie + "/iteration_" + std::to_string(i) + ".txt";
        grille.ecrireEtatDansFichier(nomFichier); // Enregistrer l'état de la grille dans un fichier
        grille.mettreAJour(); // Mettre à jour la grille pour la prochaine itération
    }
    std::cout << "Simulation terminee. Resultats dans le dossier : " << dossierSortie << std::endl;
}

// Exécuter le jeu en mode graphique
void Jeu::executerModeGraphique() {
    Afficheur afficheur(grille);
    afficheur.lancer();
}
