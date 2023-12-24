#include "Sport.h"

Sport::Sport(const std::string& nom) : nom(nom) {}

std::string Sport::getNom() const { return nom; }
