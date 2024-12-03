#include "Afficheur.h"

// Constructeur de l'afficheur
Afficheur::Afficheur(Grille& grille) : grille(grille), fenetre(sf::VideoMode(800, 600), "Jeu de la Vie"), delai(sf::milliseconds(100)) {
    grille.ajouterObserver(this);
    int largeur = grille.obtenirLargeur();
    int hauteur = grille.obtenirHauteur();
    tailleCellule = std::min(fenetre.getSize().x / largeur, fenetre.getSize().y / hauteur);
}

// Lancer l'affichage
void Afficheur::lancer() {
    while (fenetre.isOpen()) {
        gererEvenements();

        if (horloge.getElapsedTime() >= delai) {
            grille.mettreAJour();
            horloge.restart();
        }

        fenetre.clear(sf::Color::Black);
        dessiner();
        fenetre.display();
    }
}

// Gérer les événements de la fenêtre
void Afficheur::gererEvenements() {
    sf::Event evenement;
    while (fenetre.pollEvent(evenement)) {
        if (evenement.type == sf::Event::Closed) {
            fenetre.close();
        } else if (evenement.type == sf::Event::KeyPressed) {
            if (evenement.key.code == sf::Keyboard::Up) {
                delai -= sf::milliseconds(10);
            } else if (evenement.key.code == sf::Keyboard::Down) {
                delai += sf::milliseconds(10);
            }
        }
    }
}

// Dessiner la grille
void Afficheur::dessiner() {
    int largeur = grille.obtenirLargeur();
    int hauteur = grille.obtenirHauteur();

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            sf::RectangleShape celluleShape(sf::Vector2f(tailleCellule - 1, tailleCellule - 1));
            celluleShape.setPosition(j * tailleCellule, i * tailleCellule);
            if (grille.obtenirCellule(i, j).obtenirEtat()) {
                celluleShape.setFillColor(sf::Color::White);
            } else {
                celluleShape.setFillColor(sf::Color::Black);
            }
            fenetre.draw(celluleShape);
        }
    }
}

// Mettre à jour l'affichage
void Afficheur::mettreAJour() {
    fenetre.clear(sf::Color::Black);
    dessiner();
    fenetre.display();
}
