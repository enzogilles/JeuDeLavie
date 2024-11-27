#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
private:
    bool estVivante;
    bool prochainEtat;

public:
    Cellule();
    bool obtenirEtat() const;
    void definirEtat(bool etat);
    void determinerProchainEtat(int voisinsVivants);
    void mettreAJourEtat();
};

#endif // CELLULE_H
