#ifndef SPIL_H
#define SPIL_H
#include "svaerhedsgrad.h"
#include <vector>

class Spil
{
public:
    std::vector<Svaerhedsgrad> svaerhedsgrader;
    Spil();
    ~Spil();
    void Start();
    void SaetSvaerhedgrad();
};

#endif // SPIL_H
