#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Add this line for std::find_if

class Equipement {
public:
    Equipement(std::string reference, std::string libelle, std::string dateAchat, double prixAchat)
        : reference(reference), libelle(libelle), dateAchat(dateAchat), prixAchat(prixAchat), disponible(true) {}

    std::string getReference() const {
        return reference;
    }

    std::string getLibelle() const {
        return libelle;
    }

    std::string getDateAchat() const {
        return dateAchat;
    }

    double getPrixAchat() const {
        return prixAchat;
    }

    bool estDisponible() const {
        return disponible;
    }

    void marquerCommeIndisponible() {
        disponible = false;
    }

private:
    std::string reference;
    std::string libelle;
    std::string dateAchat;
    double prixAchat;
    bool disponible;
};

// Fonction pour afficher le menu
void afficherMenuEq() {
    std::cout << "Menu :" << std::endl;
    std::cout << "1. Ajouter un équipement" << std::endl;
    std::cout << "2. Afficher tous les équipements" << std::endl;
    std::cout << "3. Marquer un équipement comme indisponible" << std::endl;
    std::cout << "4. Quitter" << std::endl;
}
#endif // EQUIPEMENT_H