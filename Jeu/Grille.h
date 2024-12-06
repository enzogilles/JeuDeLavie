#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <string>
#include "Cellule.h"
#include "Observable.h"

// Classe représentant la grille du jeu de la vie
class Grille : public Observable {
private:
    std::vector<std::vector<Cellule*>> cellules; // Matrice de cellules
    int largeur; // Largeur de la grille
    int hauteur; // Hauteur de la grille

    Grille(); // Constructeur privé pour le Singleton

public:
    static Grille& getInstance(); // Méthode pour obtenir l'instance unique
    

    void initialiser(const std::string& nomFichier); // Initialiser la grille à partir d'un fichier
    void mettreAJour(); // Mettre à jour l'état de la grille
    int compterVoisinsVivants(int x, int y) const; // Compter les voisins vivants d'une cellule
    void ecrireEtatDansFichier(const std::string& nomFichier) const; // Écrire l'état de la grille dans un fichier
    int obtenirLargeur() const; // Obtenir la largeur de la grille
    int obtenirHauteur() const; // Obtenir la hauteur de la grille
    const Cellule& obtenirCellule(int x, int y) const; // Obtenir une cellule spécifique


    ~Grille(); // Destructeur
};

#endif // GRILLE_H
