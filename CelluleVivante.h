// CelluleVivante.h
#ifndef CELLULEVIVANTE_H
#define CELLULEVIVANTE_H

#include "Cellule.h"

// Classe représentant une cellule vivante
class CelluleVivante : public Cellule {
public:
    CelluleVivante(); // Constructeur
    ~CelluleVivante(); // Destructeur

    bool obtenirEtat() const override; // Obtenir l'état actuel
    void definirEtat(bool etat) override; // Définir l'état actuel
    void determinerProchainEtat(int voisinsVivants) override; // Déterminer le prochain état
    void mettreAJourEtat() override; // Mettre à jour l'état
};

#endif // CELLULEVIVANTE_H