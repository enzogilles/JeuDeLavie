#include "Jeu.h"
#include <iostream>
#include <filesystem>
#include "Afficheur.h"

Jeu::Jeu(const std::string& fichierEntree) : nombreIterations(0) {
    grille.initialiser(fichierEntree);
}

void Jeu::executerModeConsole(int iterations) {
    std::string dossierSortie = "resultats_out";
    std::filesystem::create_directory(dossierSortie);

    for (int i = 0; i < iterations; ++i) {
        std::string nomFichier = dossierSortie + "/iteration_" + std::to_string(i) + ".txt";
        grille.ecrireEtatDansFichier(nomFichier);
        grille.mettreAJour();
    }
    std::cout << "Simulation terminee. Resultats dans le dossier : " << dossierSortie << std::endl;
}

void Jeu::executerModeGraphique() {
    Afficheur afficheur(grille);
    afficheur.lancer();
}
