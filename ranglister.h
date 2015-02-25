#ifndef RANGLISTER
#define RANGLISTER

#include "resultat.h"
#include "svaerhedsgrad.h"
#include <list>
#include <vector>

namespace Ranglister
{
    void NytResultat(Resultat resultat);
    std::list<Resultat> HentResultater(Svaerhedsgrad svaerhedsgrad);
    std::string RanglisteFilNavn(Svaerhedsgrad svaerhedsgrad);
    Resultater SorterResultater(std::list<Resultat> resultater);
}

#endif // RANGLISTER

