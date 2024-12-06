#include "Afficheur.h"

// Constructeur de l'afficheur
Afficheur::Afficheur(Grille& grille) : grille(grille), delai(sf::milliseconds(100)) {
    grille.ajouterObserver(this);
    int largeur = grille.obtenirLargeur();
    int hauteur = grille.obtenirHauteur();
    tailleCellule = std::min(800 / largeur, 600 / hauteur);
    fenetre.create(sf::VideoMode(largeur * tailleCellule, hauteur * tailleCellule), "Jeu de la Vie");
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

// Gérer les événements de la fenêtre pour la vitesse d'execution
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
            const Cellule& cellule = grille.obtenirCellule(i, j);
            if (cellule.estObstacle()) {
                celluleShape.setFillColor(sf::Color::Red); // Couleur pour les obstacles
            } else if (cellule.obtenirEtat()) {
                celluleShape.setFillColor(sf::Color::White); // Couleur pour les cellules vivantes
            } else {
                celluleShape.setFillColor(sf::Color::Blue); // Couleur pour les cellules mortes
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
