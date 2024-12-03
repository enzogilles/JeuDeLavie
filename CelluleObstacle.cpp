// CelluleObstacle.cpp
#include "CelluleObstacle.h"

// Constructeur de la cellule obstacle
CelluleObstacle::CelluleObstacle(bool etat) : estVivante(etat) {}

// Obtenir l'état de la cellule obstacle
bool CelluleObstacle::obtenirEtat() const {
    return estVivante;
}

// Définir l'état de la cellule obstacle
void CelluleObstacle::definirEtat(bool etat) {
    estVivante = etat;
}

// Déterminer le prochain état (ne change pas pour les obstacles)
void CelluleObstacle::determinerProchainEtat(int) {
    // L'état des cellules obstacles ne change pas
}

// Mettre à jour l'état (ne change pas pour les obstacles)
void CelluleObstacle::mettreAJourEtat() {
    // L'état des cellules obstacles ne change pas
}