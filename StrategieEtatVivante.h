// StrategieEtatVivante.h
#ifndef STRATEGIEETATVIVANTE_H
#define STRATEGIEETATVIVANTE_H

#include "StrategieEtat.h"

class StrategieEtatVivante : public StrategieEtat {
public:
    bool determinerProchainEtat(bool estVivante, int voisinsVivants) const override {
        if (estVivante) {
            return voisinsVivants == 2 || voisinsVivants == 3;
        } else {
            return voisinsVivants == 3;
        }
    }
};

#endif // STRATEGIEETATVIVANTE_H