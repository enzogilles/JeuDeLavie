// Observer.h
#ifndef OBSERVER_H
#define OBSERVER_H

// Classe abstraite représentant un observateur
class Observer {
public:
    virtual void mettreAJour() = 0; // Méthode pour mettre à jour l'observateur
    virtual ~Observer() = default; // Destructeur virtuel par défaut
};

#endif // OBSERVER_H