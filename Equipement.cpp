#include "Equipement.h"

std::string Equipement::getReference() const {
    return reference;
}

std::string Equipement::getLibelle() const {
    return libelle;
}

std::string Equipement::getDateAchat() const {
    return dateAchat;
}

double Equipement::getPrixAchat() const {
    return prixAchat;
}

bool Equipement::estDisponible() const {
    return disponible;
}

void Equipement::marquerCommeIndisponible() {
    disponible = false;
}

// Fonction pour afficher le menu
void afficherMenuEq() {
    std::cout << "Menu :" << std::endl;
    std::cout << "1. Ajouter un équipement" << std::endl;
    std::cout << "2. Afficher tous les équipements" << std::endl;
    std::cout << "3. Marquer un équipement comme indisponible" << std::endl;
    std::cout << "4. Quitter" << std::endl;
}
