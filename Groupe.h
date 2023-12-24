#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>
#include "Adherent.h"

class Groupe {
public:
    Groupe(int id, std::string nom);

    int getId() const;

    std::string getNom() const;

    void ajouterAdherent(const Adherent &adherent);

    void afficherMembres() const;

private:
    int id;
    std::string nom;
    std::vector<Adherent> adherents;
};

#endif // GROUPE_H