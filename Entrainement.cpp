#include "Entrainement.h"
#include "Entraineur.h"
#include <iostream>

Entrainement::Entrainement(const std::string& jour, const std::string& heure,
                           const Sport& sport, const SalleEntrainement& salle)
    : jour(jour), heure(heure), sport(sport), salle(salle), entraineur(nullptr),
      index(0) {}

void Entrainement::planifierSeance(const std::string& description) {
    this->description = description;
    std::cout << "Séance planifiée le " << jour << " à " << heure
              << " pour le sport " << sport.getNom() << " dans la salle "
              << salle.getNom() << ". Description : " << description
              << std::endl;
}

void Entrainement::afficherDetails() const {
    std::cout << "Détails de la séance du " << jour << " à " << heure
              << " pour le sport " << sport.getNom() << " dans la salle "
              << salle.getNom() << ":" << std::endl;
    std::cout << "Description : " << description << std::endl;
    if (entraineur != nullptr) {
        std::cout << "Entraîneur : " << entraineur->getNom();
        if (entraineur->estPermanent()) {
            std::cout << " (permanent)";
        } else {
            std::cout << " (vacataire)";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Pas d'entraîneur affecté pour le moment." << std::endl;
    }
}

void Entrainement::affecterEntraineur(Entraîneur* entraineur) {
    this->entraineur = entraineur;
    std::cout << "Entraîneur affecté à la séance du " << jour << " : "
              << entraineur->getNom() << std::endl;
}

size_t Entrainement::getIndex() const { return index; }

void Entrainement::setIndex(size_t index) { this->index = index; }
