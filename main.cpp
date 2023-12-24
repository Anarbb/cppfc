#include "SalleDeSport.h"

int main() {
    SalleDeSport salleDeSport;

    int choix;
    do {
        salleDeSport.afficherMenuPrincipal();
        std::cout << "Choisissez une option (1-6): ";
        std::cin >> choix;

        switch (choix) {
            case 1:
                salleDeSport.gestionAdherents();
                break;
            case 2:
                salleDeSport.gestionSeancesEntrainement();
                break;
            case 3:
                salleDeSport.gestionEnseignants();
                break;
            case 4:
                salleDeSport.gestionEquipes();
                break;
            case 5:
                salleDeSport.gestionEquipements();
                break;
            case 6:
                std::cout << "Au revoir !" << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez réessayer." << std::endl;
                break;
        }
    } while (choix != 6);

    return 0;
}