#ifndef RESULTAT
#define RESULTAT

#include <iostream>
#include <vector>
#include "svaerhedsgrad.h"

struct Resultat
{
    int gaet;
    std::string navn;
    Svaerhedsgrad svaerhedsgrad;
};

typedef std::vector<Resultat> Resultater;

#endif // RESULTAT

