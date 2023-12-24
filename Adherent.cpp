#include "Adherent.h"
#include <iostream>

Adherent::Adherent(std::string id, std::string n, std::string tel, std::string dateN, std::string dateA)
    : identifiant(id), nom(n), telephone(tel), dateNaissance(dateN), dateAdhesion(dateA) {}

Adherent::Adherent(int id, std::string n)
    : identifiant(std::to_string(id)), nom(n), telephone(""), dateNaissance(""), dateAdhesion("") {}

std::string Adherent::getIdentifiant() const {
    return identifiant;
}

void Adherent::afficherDetails() const {
    std::cout << "Identifiant: " << identifiant << std::endl;
    std::cout << "Nom: " << nom << std::endl;
    std::cout << "Téléphone: " << telephone << std::endl;
    std::cout << "Date de naissance: " << dateNaissance << std::endl;
    std::cout << "Date d'adhésion: " << dateAdhesion << std::endl;
}

void Adherent::modifierDetails() {
    std::cout << "Nouvel identifiant de l'adhérent : ";
    std::cin >> identifiant;
    std::cout << "Nouveau nom de l'adhérent : ";
    std::cin.ignore();
    std::getline(std::cin, nom);
    std::cout << "Nouveau numéro de téléphone : ";
    std::cin >> telephone;
    std::cout << "Nouvelle date de naissance (JJ/MM/AAAA) : ";
    std::cin >> dateNaissance;
    std::cout << "Nouvelle date d'adhésion (JJ/MM/AAAA) : ";
    std::cin >> dateAdhesion;
}

std::string Adherent::getNom() const {
    return nom;
}
