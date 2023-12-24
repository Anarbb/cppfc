#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include <iostream>
#include <vector>
#include <algorithm> // Pour utiliser la fonction remove_if

class Entraîneur {
public:
    Entraîneur(int numéro, std::string nom, std::string téléphone, std::string date_naissance, std::string embauche, double salaire)
        : numéro(numéro), nom(nom), téléphone(téléphone), date_naissance(date_naissance), embauche(embauche), salaire(salaire), prix_heure(0.0) {}

    Entraîneur(int numéro, std::string nom, std::string téléphone, std::string date_naissance, double prix_heure)
        : numéro(numéro), nom(nom), téléphone(téléphone), date_naissance(date_naissance), embauche(""), salaire(0.0), prix_heure(prix_heure) {}

    void afficherInformations() const;

    int getNuméro() const;
    std::string getNom() const;
    bool estPermanent() const;

private:
    int numéro;
    std::string nom;
    std::string téléphone;
    std::string date_naissance;
    std::string embauche;
    double salaire;
    double prix_heure;
};

// Fonction pour afficher le menu
void afficherMenu();
void afficherMenuEnt();

#endif // !ENTRAINEUR_H
