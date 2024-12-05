// CelluleFactory.h
#ifndef CELLULEFACTORY_H
#define CELLULEFACTORY_H

#include "Cellule.h"
#include "CelluleVivante.h"
#include "CelluleObstacle.h"

class CelluleFactory {
public:
    static Cellule* creerCellule(int etat) {
        if (etat == -1) {
            return new CelluleObstacle(); // Utiliser le constructeur par défaut
        } else {
            CelluleVivante* cellule = new CelluleVivante();
            cellule->definirEtat(etat == 1);
            return cellule;
        }
    }
};

#endif // CELLULEFACTORY_H