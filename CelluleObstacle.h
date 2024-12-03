// CelluleObstacle.h
#ifndef CELLULEOBSTACLE_H
#define CELLULEOBSTACLE_H

#include "Cellule.h"

// Classe représentant une cellule obstacle
class CelluleObstacle : public Cellule {
private:
    bool estVivante; // État de la cellule obstacle

public:
    CelluleObstacle(bool etat); // Constructeur

    bool obtenirEtat() const override; // Obtenir l'état de la cellule
    void definirEtat(bool etat) override; // Définir l'état de la cellule
    void determinerProchainEtat(int voisinsVivants) override; // Déterminer le prochain état (ne change pas)
    void mettreAJourEtat() override; // Mettre à jour l'état (ne change pas)
};

#endif // CELLULEOBSTACLE_H