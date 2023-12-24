#ifndef ADHERENT_H
#define ADHERENT_H

#include <string>

class Adherent {
public:
    Adherent(std::string id, std::string n, std::string tel, std::string dateN, std::string dateA);

    Adherent(int id, std::string n);

    std::string getIdentifiant() const;

    void afficherDetails() const;

    void modifierDetails();

    std::string getNom() const;

private:
    std::string identifiant;
    std::string nom;
    std::string telephone;
    std::string dateNaissance;
    std::string dateAdhesion;
};

#endif // ADHERENT_H
