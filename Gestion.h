#ifndef GESTION_H
#define GESTION_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Entraineur.h"
#include "Equipement.h"

class Sport
{
public:
    Sport(const std::string &nom) : nom(nom) {}

    std::string getNom() const
    {
        return nom;
    }

private:
    std::string nom;
};

class SalleEntrainement
{
public:
    SalleEntrainement(const std::string &nom) : nom(nom) {}

    std::string getNom() const
    {
        return nom;
    }

private:
    std::string nom;
};

class Entrainement
{
public:
    Entrainement(const std::string &jour, const std::string &heure, const Sport &sport, const SalleEntrainement &salle)
        : jour(jour), heure(heure), sport(sport), salle(salle), entraineur(nullptr), index(0) {}

    void planifierSeance(const std::string &description)
    {
        this->description = description;
        std::cout << "Séance planifiée le " << jour << " à " << heure << " pour le sport " << sport.getNom()
                  << " dans la salle " << salle.getNom() << ". Description : " << description << std::endl;
    }

    void afficherDetails() const
    {
        std::cout << "Détails de la séance du " << jour << " à " << heure << " pour le sport " << sport.getNom() << " dans la salle " << salle.getNom() << ":" << std::endl;
        std::cout << "Description : " << description << std::endl;
        if (entraineur != nullptr)
        {
            std::cout << "Entraîneur : " << entraineur->getNom();
            if (entraineur->estPermanent())
            {
                std::cout << " (permanent)";
            }
            else
            {
                std::cout << " (vacataire)";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Pas d'entraîneur affecté pour le moment." << std::endl;
        }
    }

    void affecterEntraineur(Entraîneur *entraineur)
    {
        this->entraineur = entraineur;
        std::cout << "Entraîneur affecté à la séance du " << jour << " : " << entraineur->getNom() << std::endl;
    }

    // Getter pour l'index du vecteur
    size_t getIndex() const
    {
        return index;
    }

    // Setter pour l'index du vecteur
    void setIndex(size_t index)
    {
        this->index = index;
    }

private:
    std::string jour;
    std::string heure;
    Sport sport;
    SalleEntrainement salle;
    std::string description;
    Entraîneur *entraineur;
    size_t index; // Ajout de l'index pour identifier la séance dans le vecteur
};

class Adherent
{
private:
    std::string identifiant;
    std::string nom;
    std::string telephone;
    std::string dateNaissance;
    std::string dateAdhesion;

public:
    Adherent(std::string id, std::string n, std::string tel, std::string dateN, std::string dateA)
        : identifiant(id), nom(n), telephone(tel), dateNaissance(dateN), dateAdhesion(dateA) {}
    Adherent(int id, std::string n)
        : identifiant(std::to_string(id)), nom(n), telephone(""), dateNaissance(""), dateAdhesion("") {}
    std::string getIdentifiant() const
    {
        return identifiant;
    }

    void afficherDetails() const
    {
        std::cout << "Identifiant: " << identifiant << std::endl;
        std::cout << "Nom: " << nom << std::endl;
        std::cout << "Téléphone: " << telephone << std::endl;
        std::cout << "Date de naissance: " << dateNaissance << std::endl;
        std::cout << "Date d'adhésion: " << dateAdhesion << std::endl;
    }

    void modifierDetails()
    {
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
    std::string getNom() const
    {
        return nom;
    }
};

class Groupe
{
public:
    Groupe(int id, std::string nom) : id(id), nom(nom) {}

    int getId() const
    {
        return id;
    }

    std::string getNom() const
    {
        return nom;
    }

    void ajouterAdherent(const Adherent &adherent)
    {
        adherents.push_back(adherent);
    }

    void afficherMembres() const
    {
        std::cout << "Membres du groupe " << nom << ":" << std::endl;
        for (const auto &adherent : adherents)
        {
            std::cout << " - " << adherent.getNom() << std::endl;
        }
    }

private:
    int id;
    std::string nom;
    std::vector<Adherent> adherents;
};

// Fonction pour afficher le menu
void afficherMenuGrp()
{
    std::cout << "Menu :" << std::endl;
    std::cout << "1. Créer un groupe" << std::endl;
    std::cout << "2. Ajouter un adhérent à un groupe" << std::endl;
    std::cout << "3. Afficher les groupes" << std::endl;
    std::cout << "4. Quitter" << std::endl;
}

class SalleDeSport
{
private:
    std::vector<Adherent> adherents;
    std::vector<Entrainement> seancesEntrainement; // Ajout de la liste des séances d'entraînement

public:
    void afficherMenuPrincipal()
    {
        std::cout << "Bienvenue dans le système de gestion de la salle de sport" << std::endl;
        std::cout << "1. Gestion des adhérents" << std::endl;
        std::cout << "2. Gestion des séances d'entraînements" << std::endl;
        std::cout << "3. Gestion des entraîneurs" << std::endl;
        std::cout << "4. Gestion des équipes" << std::endl;
        std::cout << "5. Gestion des équipements" << std::endl;
        std::cout << "6. Quitter" << std::endl;
    }

    void gestionAdherents()
    {
        int choix;
        do
        {
            std::cout << "\nGestion des adhérents:" << std::endl;
            std::cout << "1. Nouvelle inscription" << std::endl;
            std::cout << "2. Afficher la liste des adhérents" << std::endl;
            std::cout << "3. Rechercher un adhérent" << std::endl;
            std::cout << "4. Modifier un adhérent" << std::endl;
            std::cout << "5. Supprimer un adhérent" << std::endl;
            std::cout << "6. Retour au menu principal" << std::endl;

            std::cout << "Choisissez une option (1-6): ";
            std::cin >> choix;

            switch (choix)
            {
            case 1:
            {
                std::string id, nom, tel, dateN, dateA;
                std::cout << "Entrez l'identifiant de l'adhérent : ";
                std::cin >> id;
                std::cout << "Entrez le nom de l'adhérent : ";
                std::cin.ignore();
                std::getline(std::cin, nom);
                std::cout << "Entrez le numéro de téléphone : ";
                std::cin >> tel;
                std::cout << "Entrez la date de naissance (JJ/MM/AAAA) : ";
                std::cin >> dateN;
                std::cout << "Entrez la date d'adhésion (JJ/MM/AAAA) : ";
                std::cin >> dateA;

                Adherent nouvelAdherent(id, nom, tel, dateN, dateA);
                ajouterAdherent(nouvelAdherent);
                break;
            }
            case 2:
                afficherAdherents();
                break;
            case 3:
            {
                std::string identifiant;
                std::cout << "Entrez l'identifiant de l'adhérent à rechercher : ";
                std::cin >> identifiant;
                rechercherAdherent(identifiant);
                break;
            }
            case 4:
            {
                std::string identifiant;
                std::cout << "Entrez l'identifiant de l'adhérent à modifier : ";
                std::cin >> identifiant;
                modifierAdherent(identifiant);
                break;
            }
            case 5:
            {
                std::string identifiant;
                std::cout << "Entrez l'identifiant de l'adhérent à supprimer : ";
                std::cin >> identifiant;
                supprimerAdherent(identifiant);
                break;
            }
            case 6:
                std::cout << "Retour au menu principal." << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez réessayer." << std::endl;
                break;
            }
        } while (choix != 6);
    }

    void ajouterAdherent(const Adherent &adherent)
    {
        adherents.push_back(adherent);
        std::cout << "Adhérent ajouté avec succès." << std::endl;
    }

    void afficherAdherents() const
    {
        std::cout << "Liste des adhérents :" << std::endl;
        for (const auto &adherent : adherents)
        {
            adherent.afficherDetails();
            std::cout << "-----------------------" << std::endl;
        }
    }

    void rechercherAdherent(const std::string &identifiant) const
    {
        for (const auto &adherent : adherents)
        {
            if (adherent.getIdentifiant() == identifiant)
            {
                adherent.afficherDetails();
                return;
            }
        }
        std::cout << "Adhérent non trouvé." << std::endl;
    }

    void modifierAdherent(const std::string &identifiant)
    {
        for (auto &adherent : adherents)
        {
            if (adherent.getIdentifiant() == identifiant)
            {
                adherent.modifierDetails();
                std::cout << "Adhérent modifié avec succès." << std::endl;
                return;
            }
        }
        std::cout << "Adhérent non trouvé." << std::endl;
    }

    void supprimerAdherent(const std::string &identifiant)
    {
        std::vector<Adherent> nouveauxAdherents;
        bool adhNonTrouve = true;

        for (const auto &adherent : adherents)
        {
            if (adherent.getIdentifiant() != identifiant)
            {
                nouveauxAdherents.push_back(adherent);
            }
            else
            {
                adhNonTrouve = false;
            }
        }

        if (adhNonTrouve)
        {
            std::cout << "Adhérent non trouvé." << std::endl;
        }
        else
        {
            adherents = nouveauxAdherents;
            std::cout << "Adhérent supprimé avec succès." << std::endl;
        }
    }

    void gestionSeancesEntrainement()
    {
        int choix;
        do
        {
            std::cout << "\nGestion des séances d'entraînement:" << std::endl;
            std::cout << "1. Ajouter une séance d'entraînement" << std::endl;
            std::cout << "2. Afficher les détails d'une séance d'entraînement" << std::endl;
            std::cout << "3. Retour au menu principal" << std::endl;

            std::cout << "Choisissez une option (1-3): ";
            std::cin >> choix;

            switch (choix)
            {
            case 1:
            {
                // Ajoutez le code pour ajouter une séance d'entraînement
                std::string jour, heure, description;
                std::cout << "Entrez le jour de la séance (ex: Lundi) : ";
                std::cin >> jour;
                std::cout << "Entrez l'heure de la séance (ex: 14:00) : ";
                std::cin >> heure;
                std::cout << "Entrez une description de la séance : ";
                std::cin.ignore();
                std::getline(std::cin, description);

                SalleEntrainement salle("Salle A"); // Vous pouvez changer le nom de la salle si nécessaire
                Sport sport("Football");            // Vous pouvez changer le nom du sport si nécessaire

                Entrainement nouvelleSeance(jour, heure, sport, salle);
                nouvelleSeance.planifierSeance(description);
                seancesEntrainement.push_back(nouvelleSeance);

                std::cout << "Séance d'entraînement ajoutée avec succès." << std::endl;
                break;
            }
            case 2:
            {
                // Ajoutez le code pour afficher les détails d'une séance d'entraînement
                size_t index;
                std::cout << "Entrez l'index de la séance d'entraînement : ";
                std::cin >> index;

                if (index < seancesEntrainement.size())
                {
                    seancesEntrainement[index].afficherDetails();
                }
                else
                {
                    std::cout << "Index invalide." << std::endl;
                }
                break;
            }
            case 3:
                std::cout << "Retour au menu principal." << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez réessayer." << std::endl;
                break;
            }
        } while (choix != 3);
    }

    void gestionEnseignants()
    {
        std::vector<Entraîneur> listeEntraîneurs;

        int choix;
        do
        {
            afficherMenuEnt();
            std::cout << "Choisissez une option : ";
            std::cin >> choix;

            switch (choix)
            {
            case 1: // Ajouter un entraîneur
            {
                int numéro;
                std::string nom, téléphone, date_naissance, embauche;
                double salaire, prix_heure;

                std::cout << "Numéro : ";
                std::cin >> numéro;
                std::cout << "Nom : ";
                std::cin >> nom;
                std::cout << "Téléphone : ";
                std::cin >> téléphone;
                std::cout << "Date de Naissance : ";
                std::cin >> date_naissance;

                std::cout << "Embauché (Oui/Non) ? ";
                std::string embaucheChoix;
                std::cin >> embaucheChoix;

                if (embaucheChoix == "Oui")
                {
                    std::cout << "Date d'embauche : ";
                    std::cin >> embauche;
                    std::cout << "Salaire : ";
                    std::cin >> salaire;
                    listeEntraîneurs.push_back(Entraîneur(numéro, nom, téléphone, date_naissance, embauche, salaire));
                }
                else
                {
                    std::cout << "Prix de l'heure : ";
                    std::cin >> prix_heure;
                    listeEntraîneurs.push_back(Entraîneur(numéro, nom, téléphone, date_naissance, prix_heure));
                }

                std::cout << "Entraîneur ajouté avec succès." << std::endl;
                break;
            }
            case 2: // Afficher tous les entraîneurs
                for (const auto &entraîneur : listeEntraîneurs)
                {
                    entraîneur.afficherInformations();
                }
                break;
            case 3: // Supprimer un entraîneur
            {
                int numéro;
                std::cout << "Entrez le numéro de l'entraîneur à supprimer : ";
                std::cin >> numéro;

                auto it = std::remove_if(listeEntraîneurs.begin(), listeEntraîneurs.end(),
                                         [numéro](const Entraîneur &e)
                                         { return e.getNuméro() == numéro; });

                if (it != listeEntraîneurs.end())
                {
                    listeEntraîneurs.erase(it, listeEntraîneurs.end());
                    std::cout << "Entraîneur supprimé avec succès." << std::endl;
                }
                else
                {
                    std::cout << "Aucun entraîneur trouvé avec le numéro spécifié." << std::endl;
                }

                break;
            }
            case 4: // Quitter
                std::cout << "Programme terminé." << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez choisir une option valide." << std::endl;
            }

        } while (choix != 4);
    }

    void gestionEquipes()
    {
        std::vector<Groupe> listeGroupes;
        std::vector<Adherent> listeAdherents;

        int choix;
        do
        {
            afficherMenuGrp();
            std::cout << "Choisissez une option : ";
            std::cin >> choix;

            switch (choix)
            {
            case 1: // Créer un groupe
            {
                int idGroupe;
                std::string nomGroupe;
                std::cout << "Identifiant du groupe : ";
                std::cin >> idGroupe;
                std::cout << "Nom du groupe : ";
                std::cin.ignore(); // Ignorer les caractères en mémoire tampon (par exemple, '\n')
                std::getline(std::cin, nomGroupe);
                listeGroupes.push_back(Groupe(idGroupe, nomGroupe));
                std::cout << "Groupe créé avec succès." << std::endl;
                break;
            }
            case 2: // Ajouter un adhérent à un groupe
            {
                if (listeGroupes.empty())
                {
                    std::cout << "Aucun groupe n'a été créé. Veuillez créer un groupe d'abord." << std::endl;
                    break;
                }

                int idAdherent, idGroupe;
                std::cout << "Identifiant de l'adhérent : ";
                std::cin >> idAdherent;
                std::cout << "Identifiant du groupe : ";
                std::cin >> idGroupe;

                auto itGroupe = std::find_if(listeGroupes.begin(), listeGroupes.end(),
                                             [idGroupe](const Groupe &groupe)
                                             { return groupe.getId() == idGroupe; });

                if (itGroupe != listeGroupes.end())
                {
                    std::string nomAdherent;
                    std::cout << "Nom de l'adhérent : ";
                    std::cin.ignore(); // Ignorer les caractères en mémoire tampon (par exemple, '\n')
                    std::getline(std::cin, nomAdherent);
                    listeAdherents.push_back(Adherent(idAdherent, nomAdherent));
                    itGroupe->ajouterAdherent(listeAdherents.back());
                    std::cout << "Adhérent ajouté au groupe avec succès." << std::endl;
                }
                else
                {
                    std::cout << "Aucun groupe trouvé avec l'identifiant spécifié." << std::endl;
                }
                break;
            }
            case 3: // Afficher les groupes
                for (const auto &groupe : listeGroupes)
                {
                    groupe.afficherMembres();
                }
                break;
            case 4: // Quitter
                std::cout << "Programme terminé." << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez choisir une option valide." << std::endl;
            }

        } while (choix != 4);
    }

    void gestionEquipements()
    {
        std::vector<Equipement> listeEquipements;

        int choix;
        do
        {
            afficherMenuEq();
            std::cout << "Choisissez une option : ";
            std::cin >> choix;

            switch (choix)
            {
            case 1: // Ajouter un équipement
            {
                std::string reference, libelle, dateAchat;
                double prixAchat;

                std::cout << "Référence de l'équipement : ";
                std::cin >> reference;
                std::cout << "Libellé de l'équipement : ";
                std::cin.ignore(); // Ignorer les caractères en mémoire tampon (par exemple, '\n')
                std::getline(std::cin, libelle);
                std::cout << "Date d'achat de l'équipement : ";
                std::cin >> dateAchat;
                std::cout << "Prix d'achat de l'équipement : ";
                std::cin >> prixAchat;

                listeEquipements.push_back(Equipement(reference, libelle, dateAchat, prixAchat));
                std::cout << "Équipement ajouté avec succès." << std::endl;
                break;
            }
            case 2: // Afficher tous les équipements
                for (const auto &equipement : listeEquipements)
                {
                    std::cout << "Référence : " << equipement.getReference() << std::endl;
                    std::cout << "Libellé : " << equipement.getLibelle() << std::endl;
                    std::cout << "Date d'achat : " << equipement.getDateAchat() << std::endl;
                    std::cout << "Prix d'achat : " << equipement.getPrixAchat() << std::endl;
                    std::cout << "Disponible : " << (equipement.estDisponible() ? "Oui" : "Non") << std::endl;
                    std::cout << std::endl;
                }
                break;
            case 3: // Marquer un équipement comme indisponible
            {
                std::string reference;
                std::cout << "Entrez la référence de l'équipement à marquer comme indisponible : ";
                std::cin >> reference;

                auto itEquipement = std::find_if(listeEquipements.begin(), listeEquipements.end(),
                                                 [reference](const Equipement &equipement)
                                                 { return equipement.getReference() == reference; });

                if (itEquipement != listeEquipements.end())
                {
                    itEquipement->marquerCommeIndisponible();
                    std::cout << "Équipement marqué comme indisponible avec succès." << std::endl;
                }
                else
                {
                    std::cout << "Aucun équipement trouvé avec la référence spécifiée." << std::endl;
                }
                break;
            }
            case 4: // Quitter
                std::cout << "Programme terminé." << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez choisir une option valide." << std::endl;
            }

        } while (choix != 4);
    }
};

#endif // GESTION_H