#include "Cellule.h"

Cellule::Cellule() : estVivante(false), prochainEtat(false) {}

bool Cellule::obtenirEtat() const {
    return estVivante;
}

void Cellule::definirEtat(bool etat) {
    estVivante = etat;
}

void Cellule::determinerProchainEtat(int voisinsVivants) {
    if (estVivante) {
        if (voisinsVivants == 2 || voisinsVivants == 3) {
            prochainEtat = true;
        } else {
            prochainEtat = false;
        }
    } else {
        if (voisinsVivants == 3) {
            prochainEtat = true;
        } else {
            prochainEtat = false;
        }
    }
}

void Cellule::mettreAJourEtat() {
    estVivante = prochainEtat;
}
