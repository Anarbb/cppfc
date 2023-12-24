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

    std::string getReference() const;
    std::string getLibelle() const;
    std::string getDateAchat() const;
    double getPrixAchat() const;
    bool estDisponible() const;
    void marquerCommeIndisponible();

private:
    std::string reference;
    std::string libelle;
    std::string dateAchat;
    double prixAchat;
    bool disponible;
};

// Fonction pour afficher le menu
void afficherMenuEq();

#endif // EQUIPEMENT_H
