#include "Entraineur.h"

void Entraîneur::afficherInformations() const {
    std::cout << "Numéro: " << numéro << std::endl;
    std::cout << "Nom: " << nom << std::endl;
    std::cout << "Téléphone: " << téléphone << std::endl;
    std::cout << "Date de Naissance: " << date_naissance << std::endl;

    if (!embauche.empty()) {
        std::cout << "Date d'embauche: " << embauche << std::endl;
        std::cout << "Salaire: " << salaire << std::endl;
    } else {
        std::cout << "Prix de l'heure: " << prix_heure << std::endl;
    }

    std::cout << std::endl;
}

int Entraîneur::getNuméro() const {
    return numéro;
}
std::string Entraîneur::getNom() const {
    return nom;
}
bool Entraîneur::estPermanent() const {
    return !embauche.empty();
}

// Fonction pour afficher le menu
void afficherMenu() {
    std::cout << "Menu :" << std::endl;
    std::cout << "1. Ajouter un équipement" << std::endl;
    std::cout << "2. Afficher tous les équipements" << std::endl;
    std::cout << "3. Marquer un équipement comme indisponible" << std::endl;
    std::cout << "4. Quitter" << std::endl;
}

void afficherMenuEnt() {
    std::cout << "1. Ajouter un entraîneur" << std::endl;
    std::cout << "2. Afficher tous les entraîneurs" << std::endl;
    std::cout << "3. Supprimer un entraîneur" << std::endl;
    std::cout << "4. Quitter" << std::endl;
}
