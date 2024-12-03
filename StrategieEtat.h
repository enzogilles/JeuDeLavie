// StrategieEtat.h
#ifndef STRATEGIEETAT_H
#define STRATEGIEETAT_H

class StrategieEtat {
public:
    virtual ~StrategieEtat() {}
    virtual bool determinerProchainEtat(bool estVivante, int voisinsVivants) const = 0;
};

#endif // STRATEGIEETAT_H