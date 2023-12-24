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

    void afficherInformations() const {
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

    int getNuméro() const {
        return numéro;
    }
    std::string getNom() const {
        return nom;
    }
    bool estPermanent() const {
        return !embauche.empty();
    }

private:
    int numéro;class Equipement {
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
void afficherMenu() {
    std::cout << "Menu :" << std::endl;
    std::cout << "1. Ajouter un équipement" << std::endl;
    std::cout << "2. Afficher tous les équipements" << std::endl;
    std::cout << "3. Marquer un équipement comme indisponible" << std::endl;
    std::cout << "4. Quitter" << std::endl;
}
    std::string nom;
    std::string téléphone;
    std::string date_naissance;
    std::string embauche;
    double salaire;
    double prix_heure;
};

// Fonction pour afficher le menu
void afficherMenuEnt() {
    std::cout << "1. Ajouter un entraîneur" << std::endl;
    std::cout << "2. Afficher tous les entraîneurs" << std::endl;
    std::cout << "3. Supprimer un entraîneur" << std::endl;
    std::cout << "4. Quitter" << std::endl;
}

#endif // !ENTRAINEUR_H