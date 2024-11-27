#include <iostream>
#include "Jeu.h"
#include "TestGrille.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Utilisation : " << argv[0] << " <fichier_entree>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string fichierEntree = argv[1];
    Jeu jeu(fichierEntree);

    int choix;
    std::cout << "Choisissez le mode de fonctionnement :" << std::endl;
    std::cout << "1. Mode Console" << std::endl;
    std::cout << "2. Mode Graphique" << std::endl;
    std::cout << "3. Exécuter les tests" << std::endl;
    std::cin >> choix;

    if (choix == 1) {
        int iterations;
        std::cout << "Entrez le nombre d'iterations : ";
        std::cin >> iterations;
        jeu.executerModeConsole(iterations);
    } else if (choix == 2) {
        jeu.executerModeGraphique();
    } else if (choix == 3) {
        TestGrille::executerTests();
    } else {
        std::cerr << "Choix invalide." << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
