// CelluleObstacle.h
#ifndef CELLULEOBSTACLE_H
#define CELLULEOBSTACLE_H

#include "Cellule.h"

// Classe représentant une cellule obstacle
class CelluleObstacle : public Cellule {
public:
    CelluleObstacle();
    CelluleObstacle(bool etat); // Ajouter ce constructeur
    bool obtenirEtat() const override;
    void definirEtat(bool etat) override;
    void determinerProchainEtat(int voisinsVivants) override;
    void mettreAJourEtat() override;
    bool estObstacle() const override { return true; } 
};

#endif // CELLULEOBSTACLE_H