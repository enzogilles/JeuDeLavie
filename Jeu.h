#ifndef JEU_H
#define JEU_H

#include <string>
#include "Grille.h"

// Classe représentant le jeu de la vie
class Jeu {
private:
    Grille& grille; // Référence à la grille
    int nombreIterations; // Nombre d'itérations

public:
    Jeu(const std::string& fichierEntree); // Constructeur
    ~Jeu(); // Destructeur
    void executerModeConsole(int iterations); // Exécuter le jeu en mode console
    void executerModeGraphique(); // Exécuter le jeu en mode graphique
    Grille& obtenirGrille(); // Méthode pour obtenir la grille
};

#endif // JEU_H
