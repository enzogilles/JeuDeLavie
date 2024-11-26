#include "Grille.h"
#include <fstream>
#include <iostream>

void Grille::initialiserDepuisFichier(const std::string& fichier) {
    std::ifstream fin(fichier);
    if (!fin) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier.\n";
        exit(1);
    }
    fin >> hauteur >> largeur;
    grille.resize(hauteur, std::vector<Cellule>(largeur));
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            bool etat;
            fin >> etat;
            grille[i][j].setEtat(etat);
        }
    }
}

void Grille::simulerConsole() {
    // Implémentation pour afficher les étapes dans la console
}

const Cellule& Grille::getCellule(int x, int y) const {
    return grille[x][y];
}
