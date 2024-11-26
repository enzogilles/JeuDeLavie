#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grille.h"
#include "Automate.h"

void afficherAide() {
    std::cout << "Usage: ./jeu_de_la_vie <mode> [file_path]\n";
    std::cout << "Modes disponibles:\n";
    std::cout << "  console : Lance la simulation en mode console.\n";
    std::cout << "  graphique : Lance la simulation en mode graphique (SFML requis).\n";
    std::cout << "  test : Exécute les tests unitaires.\n";
}

void lancerModeGraphique(const Grille& grille) {
    int largeur = grille.getLargeur();
    int hauteur = grille.getHauteur();
    int tailleCellule = 20;

    sf::RenderWindow window(sf::VideoMode(largeur * tailleCellule, hauteur * tailleCellule), "Jeu de la Vie");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        for (int x = 0; x < largeur; ++x) {
            for (int y = 0; y < hauteur; ++y) {
                sf::RectangleShape cellule(sf::Vector2f(tailleCellule, tailleCellule));
                cellule.setPosition(x * tailleCellule, y * tailleCellule);
                if (grille.getCellule(x, y).getEtat())
                    cellule.setFillColor(sf::Color::Green);
                else
                    cellule.setFillColor(sf::Color::Black);

                cellule.setOutlineThickness(1);
                cellule.setOutlineColor(sf::Color::White);

                window.draw(cellule);
            }
        }

        window.display();
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        afficherAide();
        return 1;
    }

    std::string mode = argv[1];
    Grille grille;
    if (mode == "console") {
        grille.initialiserDepuisFichier(argv[2]);
        grille.simulerConsole();
    } else if (mode == "graphique") {
        grille.initialiserDepuisFichier(argv[2]);
        lancerModeGraphique(grille);
    } else if (mode == "test") {
        testAutomate();
    } else {
        afficherAide();
        return 1;
    }
    return 0;
}
