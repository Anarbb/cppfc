#ifndef ENTRAINEMENT_H
#define ENTRAINEMENT_H

#include <string>
#include "Sport.h"
#include "SalleEntrainement.h"
#include "Entraineur.h"

class Entrainement {
public:
    Entrainement(const std::string &jour, const std::string &heure, const Sport &sport, const SalleEntrainement &salle);

    void planifierSeance(const std::string &description);

    void afficherDetails() const;

    void affecterEntraineur(Entraîneur *entraineur);

    size_t getIndex() const;

    void setIndex(size_t index);

private:
    std::string jour;
    std::string heure;
    Sport sport;
    SalleEntrainement salle;
    std::string description;
    Entraîneur *entraineur;
    size_t index;
};

#endif // ENTRAINEMENT_H
