#include "Grille.h"
#include <fstream>
#include <sstream>
#include <iostream>

Grille::Grille() : largeur(0), hauteur(0) {}

void Grille::initialiser(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier : " << nomFichier << std::endl;
        exit(EXIT_FAILURE);
    }

    fichier >> hauteur >> largeur;
    cellules.resize(hauteur, std::vector<Cellule>(largeur));

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int etat;
            fichier >> etat;
            cellules[i][j].definirEtat(etat == 1);
        }
    }

    fichier.close();
}

void Grille::mettreAJour() {
    std::vector<std::vector<Cellule>> nouvelleGrille = cellules;

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            int voisinsVivants = compterVoisinsVivants(x, y);
            nouvelleGrille[y][x].determinerProchainEtat(voisinsVivants);
        }
    }

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            nouvelleGrille[y][x].mettreAJourEtat();
        }
    }

    cellules = nouvelleGrille;
}

int Grille::compterVoisinsVivants(int x, int y) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < largeur && ny >= 0 && ny < hauteur) {
                count += cellules[ny][nx].obtenirEtat();
            }
        }
    }
    return count;
}

void Grille::ecrireEtatDansFichier(const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'écriture du fichier : " << nomFichier << std::endl;
        exit(EXIT_FAILURE);
    }

    fichier << hauteur << " " << largeur << std::endl;
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            fichier << (cellules[i][j].obtenirEtat() ? "1" : "0") << " ";
        }
        fichier << std::endl;
    }

    fichier.close();
}

int Grille::obtenirLargeur() const {
    return largeur;
}

int Grille::obtenirHauteur() const {
    return hauteur;
}

const Cellule& Grille::obtenirCellule(int x, int y) const {
    return cellules[x][y];
}
