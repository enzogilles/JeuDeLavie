// CelluleVivante.cpp
#include "CelluleVivante.h"
#include "StrategieEtatVivante.h"

// Constructeur de la cellule vivante
CelluleVivante::CelluleVivante() : estVivante(false), prochainEtat(false), strategie(new StrategieEtatVivante()) {}

// Destructeur de la cellule vivante
CelluleVivante::~CelluleVivante() {
    delete strategie;
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
    prochainEtat = strategie->determinerProchainEtat(estVivante, voisinsVivants);
}

// Mettre à jour l'état de la cellule
void CelluleVivante::mettreAJourEtat() {
    estVivante = prochainEtat;
}