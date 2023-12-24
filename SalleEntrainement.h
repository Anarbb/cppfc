#ifndef SALLEENTRAINEMENT_H
#define SALLEENTRAINEMENT_H

#include <string>

class SalleEntrainement {
  public:
    SalleEntrainement(const std::string& nom);

    std::string getNom() const;

  private:
    std::string nom;
};

#endif // SALLEENTRAINEMENT_H
