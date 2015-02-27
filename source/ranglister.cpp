#include <iostream>
#include <fstream>
#include <sstream>
#include "ranglister.h"

using namespace std;

namespace Ranglister
{

    void NytResultat(Resultat resultat)
    {
        string filNavn = RanglisteFilNavn(resultat.svaerhedsgrad);
        ofstream ranglisteFil;
        ranglisteFil.open(filNavn, ios::app);

        if (ranglisteFil.is_open())
        {
            ranglisteFil << resultat.navn << endl;
            ranglisteFil << resultat.gaet << endl << endl;
            ranglisteFil.close();
        }
    }

    list<Resultat> HentResultater(Svaerhedsgrad svaerhedsgrad)
    {
        list<Resultat> resultater;
        Resultat resultat;
        resultater.push_back(resultat);

        cout << RanglisteFilNavn(svaerhedsgrad) << endl;
        string filNavn = RanglisteFilNavn(svaerhedsgrad);
        ifstream ranglisteFil;
        ranglisteFil.open(filNavn);

        string linje;
        int tal;

        cout << "Checker om fil er sikker " << ranglisteFil.good() << endl;
        if (ranglisteFil.good())
        {
            cout << "Fil er sikker" << endl;

            while ( getline(ranglisteFil, linje))
            {
                istringstream iss(linje);

                if (linje.empty())
                {
                    Resultat resultat;
                    resultater.push_back(resultat);
                }
                else if (iss >> tal)
                {
                    resultater.back().gaet = tal;
                }
                else
                {
                    resultater.back().navn = linje;
                }
            }


        }
        else
        {
            resultater.pop_back();
        }

        cout << "Lukker " << filNavn << "... " << endl;
        ranglisteFil.close();
        cout << filNavn << " lukket" << endl;

        if (!resultater.empty())
        {
            if (resultater.front().navn.empty())
            {
                resultater.pop_front();
            }

            if (resultater.back().navn.empty())
            {
                resultater.pop_back();
            }
        }

        cout << "Færdig med at hente " << resultater.size() << " resultater" << endl;

        return resultater;
    }

    string RanglisteFilNavn(Svaerhedsgrad svaerhedsgrad)
    {
        return "rangliste_" + svaerhedsgrad.navn + ".txt";
    }

    Rangliste SorterResultater(list<Resultat> resultater)
    {
        cout << "Begynder sortering af " << resultater.size() << " resultater" << endl;

        list<Resultat> sorteredeResultater;

        vector<Resultat> v;

        if (!resultater.empty())
        {
            sorteredeResultater.push_back(resultater.front());
            resultater.pop_front();

            bool indsat;
            for (list<Resultat>::iterator it = resultater.begin(); it != resultater.end(); ++it)
            {
                indsat = false;

                for (list<Resultat>::iterator sit = sorteredeResultater.begin(); sit != sorteredeResultater.end(); ++sit)
                {
                    if (it->gaet < sit->gaet)
                    {
                        sorteredeResultater.insert(sit, (*it));
                        indsat = true;
                        break;
                    }
                }

                if (!indsat)
                {
                    sorteredeResultater.push_back((*it));
                }
            }

            v = Resultater{ std::make_move_iterator(std::begin(sorteredeResultater)),
                                std::make_move_iterator(std::end(sorteredeResultater)) };;
        }
        else
        {
            cout << "Afbryder. Der er intet at sorterer." << endl;
        }


        return v;
    }

}
