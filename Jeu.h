#ifndef JEU_H
#define JEU_H

#include <string>
#include "Grille.h"

class Jeu {
private:
    Grille grille;
    int nombreIterations;

public:
    Jeu(const std::string& fichierEntree);
    void executerModeConsole(int iterations);
    void executerModeGraphique();
};

#endif // JEU_H
