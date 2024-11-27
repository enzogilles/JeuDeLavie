#include "TestGrille.h"
#include <fstream>
#include <iostream>
#include <sstream>

bool TestGrille::comparerGrilles(const Grille& grille, const std::string& fichierAttendu) {
    std::ifstream fichier(fichierAttendu);
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier : " << fichierAttendu << std::endl;
        return false;
    }

    int hauteur, largeur;
    fichier >> hauteur >> largeur;

    int grilleHauteur = grille.obtenirHauteur();
    int grilleLargeur = grille.obtenirLargeur();

    std::cout << "Dimensions attendues : " << hauteur << "x" << largeur << std::endl;
    std::cout << "Dimensions actuelles : " << grilleHauteur << "x" << grilleLargeur << std::endl;

    if (hauteur != grilleHauteur || largeur != grilleLargeur) {
        std::cerr << "Dimensions de la grille incorrectes." << std::endl;
        return false;
    }

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int etat;
            fichier >> etat;
            if (grille.obtenirCellule(i, j).obtenirEtat() != (etat == 1)) {
                std::cerr << "État de la cellule incorrect à (" << i << ", " << j << ")." << std::endl;
                return false;
            }
        }
    }

    fichier.close();
    return true;
}

void TestGrille::executerTests() {
    Grille grille;
    grille.initialiser("etat_initial.txt");

    // Simuler les itérations
    for (int i = 0; i < 5; ++i) {
        grille.mettreAJour();
        std::string fichierAttendu = "resultats_out/iteration_" + std::to_string(i + 1) + ".txt";
        
        // Réinitialiser la grille avec les dimensions attendues
        Grille grilleAttendue;
        grilleAttendue.initialiser(fichierAttendu);

        if (!comparerGrilles(grilleAttendue, fichierAttendu)) {
            std::cerr << "Test échoué à l'itération " << i + 1 << std::endl;
            return;
        }
    }

    std::cout << "Tous les tests ont réussi." << std::endl;
}