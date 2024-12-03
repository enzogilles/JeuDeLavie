// Observable.h
#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include "Observer.h"

// Classe représentant un objet observable
class Observable {
private:
    std::vector<Observer*> observers; // Liste des observateurs

public:
    void ajouterObserver(Observer* observer); // Ajouter un observateur
    void supprimerObserver(Observer* observer); // Supprimer un observateur
    void notifierObservers(); // Notifier tous les observateurs
};

#endif // OBSERVABLE_H