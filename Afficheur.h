#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

class Afficheur {
private:
    Grille& grille;
    sf::RenderWindow fenetre;
    int tailleCellule;
    sf::Clock horloge;
    sf::Time delai;

public:
    Afficheur(Grille& grille);
    void lancer();
    void gererEvenements();
    void dessiner();
};

#endif // AFFICHEUR_H
