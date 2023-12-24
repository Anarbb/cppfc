#ifndef SPORT_H
#define SPORT_H

#include <string>

class Sport {
public:
    Sport(const std::string &nom);

    std::string getNom() const;

private:
    std::string nom;
};

#endif // SPORT_H
