// Grille.cpp
#include "Grille.h"
#include "CelluleVivante.h"
#include "CelluleObstacle.h"
#include "Observable.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "CelluleFactory.h"

// Méthode pour obtenir l'instance unique de la grille (Singleton)
Grille& Grille::getInstance() {
    static Grille instance;
    return instance;
}

// Constructeur de la classe Grille, initialise les dimensions à zéro
Grille::Grille() : largeur(0), hauteur(0) {}

// Destructeur de la classe Grille
Grille::~Grille() {
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            delete cellules[i][j];
        }
    }
}

// Méthode pour initialiser la grille à partir d'un fichier
void Grille::initialiser(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier : " << nomFichier << std::endl;
        exit(EXIT_FAILURE);
    }

    fichier >> hauteur >> largeur;
    cellules.resize(hauteur, std::vector<Cellule*>(largeur));

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int etat;
            fichier >> etat;
            cellules[i][j] = CelluleFactory::creerCellule(etat);
        }
    }

    fichier.close();
}

// Méthode pour mettre à jour l'état de la grille
void Grille::mettreAJour() {
    std::vector<std::vector<Cellule*>> nouvelleGrille = cellules;

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            int voisinsVivants = compterVoisinsVivants(x, y);
            nouvelleGrille[y][x]->determinerProchainEtat(voisinsVivants);
        }
    }

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            nouvelleGrille[y][x]->mettreAJourEtat();
        }
    }

    cellules = nouvelleGrille;
    notifierObservers();
}

// Méthode pour compter le nombre de voisins vivants d'une cellule
int Grille::compterVoisinsVivants(int x, int y) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = (x + i + largeur) % largeur;
            int ny = (y + j + hauteur) % hauteur;
            count += cellules[ny][nx]->obtenirEtat();
        }
    }
    return count;
}

// Méthode pour obtenir la hauteur de la grille
int Grille::obtenirHauteur() const {
    return hauteur;
}

// Méthode pour obtenir une cellule spécifique de la grille
const Cellule& Grille::obtenirCellule(int x, int y) const {
    return *cellules[y][x];
}

// Méthode pour écrire l'état de la grille dans un fichier
void Grille::ecrireEtatDansFichier(const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'écriture du fichier : " << nomFichier << std::endl;
        exit(EXIT_FAILURE);
    }

    fichier << hauteur << " " << largeur << std::endl;
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            fichier << (cellules[i][j]->obtenirEtat() ? "1" : "0") << " ";
        }
        fichier << std::endl;
    }

    fichier.close();
}

// Méthode pour obtenir la largeur de la grille
int Grille::obtenirLargeur() const {
    return largeur;
}

// Méthode pour placer un motif dans la grille
void Grille::placerMotif(const std::vector<std::vector<int>>& motif, int x, int y) {
    int motifHauteur = motif.size();
    int motifLargeur = motif[0].size();

    for (int i = 0; i < motifHauteur; ++i) {
        for (int j = 0; j < motifLargeur; ++j) {
            int nx = (x + i) % hauteur;
            int ny = (y + j) % largeur;
            delete cellules[nx][ny];
            cellules[nx][ny] = CelluleFactory::creerCellule(motif[i][j]);
            cellules[nx][ny]->definirNouveau(true); // Marquer la cellule comme nouvelle
        }
    }
}

