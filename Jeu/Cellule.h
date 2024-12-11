#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
protected:
    bool estVivante;
    bool prochainEtat;
    bool nouveau; // Propriété pour indiquer si la cellule est nouvelle

public:
    virtual ~Cellule() = default;
    virtual bool obtenirEtat() const = 0; // Obtenir l'état de la cellule (vivante ou morte)
    virtual void definirEtat(bool etat) = 0; // Définir l'état de la cellule
    virtual void determinerProchainEtat(int voisinsVivants) = 0; // Déterminer le prochain état de la cellule
    virtual void mettreAJourEtat() = 0; // Mettre à jour l'état de la cellule
    virtual bool estObstacle() const { return false; } 
    void definirNouveau(bool estNouveau) { nouveau = estNouveau; } // Définir si la cellule est nouvelle
    bool estNouveau() const { return nouveau; } // Vérifier si la cellule est nouvelle
};

#endif // CELLULE_H
