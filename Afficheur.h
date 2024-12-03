#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <SFML/Graphics.hpp>
#include "Grille.h"
#include "Observer.h"

// Classe représentant l'afficheur graphique
class Afficheur : public Observer {
private:
    Grille& grille; // Référence à la grille
    sf::RenderWindow fenetre; // Fenêtre SFML pour l'affichage
    int tailleCellule; // Taille d'une cellule à l'écran
    sf::Clock horloge; // Horloge pour gérer le temps
    sf::Time delai; // Délai entre les mises à jour

public:
    Afficheur(Grille& grille); // Constructeur
    void lancer(); // Lancer l'affichage
    void gererEvenements(); // Gérer les événements de la fenêtre
    void dessiner(); // Dessiner la grille
    void mettreAJour() override; // Mettre à jour l'affichage
};

#endif // AFFICHEUR_H
