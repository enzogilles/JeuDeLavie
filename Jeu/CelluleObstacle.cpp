// CelluleObstacle.cpp
#include "CelluleObstacle.h"

// Constructeur de la cellule obstacle
CelluleObstacle::CelluleObstacle() {
    estVivante = false;
    prochainEtat = false;
}

// Nouveau constructeur prenant un booléen
CelluleObstacle::CelluleObstacle(bool etat) {
    estVivante = etat;
    prochainEtat = etat;
}

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
    
}

// Mettre à jour l'état (ne change pas pour les obstacles)
void CelluleObstacle::mettreAJourEtat() {
    
}