// test_grille.cpp
#include <iostream>
#include "Grille.h"
#include "CelluleFactory.h"

// Fonction de test pour la méthode compterVoisinsVivants avec une matrice de 3x3
void testCompterVoisinsVivants() {
    Grille grille;
    grille.initialiser("etat_initial_3x3.txt");

    // Vérifiez le nombre de voisins vivants pour chaque cellule
    if (grille.compterVoisinsVivants(0, 0) != 1) {
        std::cerr << "Test échoué pour la cellule (0, 0)" << std::endl;
    }
    if (grille.compterVoisinsVivants(1, 1) != 2) {
        std::cerr << "Test échoué pour la cellule (1, 1)" << std::endl;
    }
    if (grille.compterVoisinsVivants(2, 2) != 1) {
        std::cerr << "Test échoué pour la cellule (2, 2)" << std::endl;
    }

    std::cout << "Tests terminés." << std::endl;
}

int main() {
    testCompterVoisinsVivants();
    return 0;
}