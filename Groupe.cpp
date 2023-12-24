#include "Groupe.h"
#include <iostream>

Groupe::Groupe(int id, std::string nom) : id(id), nom(nom) {}

int Groupe::getId() const {
    return id;
}

std::string Groupe::getNom() const {
    return nom;
}

void Groupe::ajouterAdherent(const Adherent &adherent) {
    adherents.push_back(adherent);
}

void Groupe::afficherMembres() const {
    std::cout << "Membres du groupe " << nom << ":" << std::endl;
    for (const auto &adherent : adherents) {
        std::cout << "Nom : " << adherent.getNom() << ", Identifiant : " << adherent.getIdentifiant() << std::endl;
    }
}
