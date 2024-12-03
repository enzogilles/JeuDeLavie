#ifndef CELLULE_H
#define CELLULE_H

// Classe abstraite représentant une cellule
class Cellule {
public:
    virtual ~Cellule() {}
    virtual bool obtenirEtat() const = 0; // Obtenir l'état de la cellule (vivante ou morte)
    virtual void definirEtat(bool etat) = 0; // Définir l'état de la cellule
    virtual void determinerProchainEtat(int voisinsVivants) = 0; // Déterminer le prochain état de la cellule
    virtual void mettreAJourEtat() = 0; // Mettre à jour l'état de la cellule
};

#endif // CELLULE_H
