#ifndef RANGLISTER
#define RANGLISTER

#include "resultat.h"
#include "svaerhedsgrad.h"
#include <list>
#include <vector>

typedef std::vector<Resultat> Rangliste;

namespace Ranglister
{
    void NytResultat(Resultat resultat);
    std::list<Resultat> HentResultater(Svaerhedsgrad svaerhedsgrad);
    std::string RanglisteFilNavn(Svaerhedsgrad svaerhedsgrad);
    Rangliste SorterResultater(std::list<Resultat> resultater);
}

#endif // RANGLISTER

