#ifndef SALLEDESPORT_H
#define SALLEDESPORT_H

#include <vector>
#include "Adherent.h"
#include "Entrainement.h"
#include "Entraineur.h"
#include "Equipement.h"
#include "Groupe.h"

class SalleDeSport {
public:
    void afficherMenuPrincipal();

    void gestionAdherents();

    void ajouterAdherent(const Adherent &adherent);

    void afficherAdherents() const;

    void rechercherAdherent(const std::string &identifiant) const;

    void modifierAdherent(const std::string &identifiant);

    void supprimerAdherent(const std::string &identifiant);

    void gestionSeancesEntrainement();

    void gestionEnseignants();

    void gestionEquipes();

    void gestionEquipements();

private:
    std::vector<Adherent> adherents;
    std::vector<Entrainement> seancesEntrainement;
};

#endif // SALLEDESPORT_H
