#ifndef TESTGRILLE_H
#define TESTGRILLE_H

#include "Grille.h"
#include <string>

// Classe pour tester la grille
class TestGrille {
public:
    static bool comparerGrilles(const Grille& grille, const std::string& fichierAttendu); // Comparer deux grilles
    static void executerTests(); // Exécuter les tests
};

#endif // TESTGRILLE_H