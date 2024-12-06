// Observable.cpp
#include "Observable.h"
#include <algorithm>

// Ajouter un observateur à la liste
void Observable::ajouterObserver(Observer* observer) {
    observers.push_back(observer);
}

// Supprimer un observateur de la liste
void Observable::supprimerObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

// Notifier tous les observateurs de l'état actuel
void Observable::notifierObservers() {
    for (Observer* observer : observers) {
        observer->mettreAJour();
    }
}