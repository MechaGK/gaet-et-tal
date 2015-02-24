#ifndef SPIL_H
#define SPIL_H
#include "svaerhedsgrad.h"
#include <vector>

class Spil
{
public:
    std::vector<Svaerhedsgrad> svaerhedsgrader;
    Svaerhedsgrad svaerhedsgrad;
    Spil();
    ~Spil();
    void Start();
    void SaetSvaerhedgrad(int nySvaerhedsgrad);
};

#endif // SPIL_H
