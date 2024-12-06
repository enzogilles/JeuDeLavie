// CelluleVivante.cpp
#include "CelluleVivante.h"

// Constructeur de la cellule vivante
CelluleVivante::CelluleVivante() {
    estVivante = false;
    prochainEtat = false;
}

// Destructeur de la cellule vivante
CelluleVivante::~CelluleVivante() {
    
}

// Obtenir l'état actuel de la cellule
bool CelluleVivante::obtenirEtat() const {
    return estVivante;
}

// Définir l'état actuel de la cellule
void CelluleVivante::definirEtat(bool etat) {
    estVivante = etat;
}

// Déterminer le prochain état de la cellule en fonction du nombre de voisins vivants
void CelluleVivante::determinerProchainEtat(int voisinsVivants) {
    if (estVivante) {
        prochainEtat = (voisinsVivants == 2 || voisinsVivants == 3);
    } else {
        prochainEtat = (voisinsVivants == 3);
    }
}

// Mettre à jour l'état de la cellule
void CelluleVivante::mettreAJourEtat() {
    estVivante = prochainEtat;
}