#include "SalleEntrainement.h"

SalleEntrainement::SalleEntrainement(const std::string& nom) : nom(nom) {}

std::string SalleEntrainement::getNom() const { return nom; }
