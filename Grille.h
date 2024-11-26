#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Cellule.h"

class Grille {
    std::vector<std::vector<Cellule>> grille;
    int largeur, hauteur;

public:
    void initialiserDepuisFichier(const std::string& fichier);
    void simulerConsole();
    int getLargeur() const { return largeur; }
    int getHauteur() const { return hauteur; }
    const Cellule& getCellule(int x, int y) const;
    void mettreAJour();
};

#endif
