#ifndef TESTGRILLE_H
#define TESTGRILLE_H

#include "Grille.h"
#include <string>

class TestGrille {
public:
    static bool comparerGrilles(const Grille& grille, const std::string& fichierAttendu);
    static void executerTests();
};

#endif // TESTGRILLE_H