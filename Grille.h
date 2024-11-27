#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <string>
#include "Cellule.h"

class Grille {
private:
    std::vector<std::vector<Cellule>> cellules;
    int largeur;
    int hauteur;

public:
    Grille();
    void initialiser(const std::string& nomFichier);
    void mettreAJour();
    int compterVoisinsVivants(int x, int y) const;
    void ecrireEtatDansFichier(const std::string& nomFichier) const;
    int obtenirLargeur() const;
    int obtenirHauteur() const;
    const Cellule& obtenirCellule(int x, int y) const;
};

#endif // GRILLE_H
