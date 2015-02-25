#include <iostream>
#include <array>
#include <list>
#include <random>
#include "menu.h"
#include "spil.h"
#include "ranglister.h"

void HovedmenuHandterInput(int valg);
void SvarhedgradsHandterInput(int valg);
void VisRangliste();

using namespace std;

Menu * hovedmenu;
Menu * svaerhedsgradsMenu;
Spil * spil;

bool aaben = true;

vector<string> hovedmenuPunkter = {"spil", "ranglister", "afslut"};
vector<string> svaerhedsgrader;

int main()
{
    srand((unsigned)time(0));
    spil = new Spil();

    for(vector<Svaerhedsgrad>::iterator itr = spil->svaerhedsgrader.begin(); itr != spil->svaerhedsgrader.end(); ++itr)
    {
        svaerhedsgrader.push_back(itr->navn);
    }

    hovedmenu = new Menu("Velkommen til Gæt et tal", hovedmenuPunkter, HovedmenuHandterInput);
    svaerhedsgradsMenu = new Menu("Vælg sværhedsgrad", svaerhedsgrader, SvarhedgradsHandterInput);


    while (aaben)
    {
        cout << endl << endl;
        hovedmenu->Vis();
    }

    return 0;
}

void HovedmenuHandterInput(int valg)
{
    cout << endl << endl;
    switch (valg)
    {
        case 0:
            svaerhedsgradsMenu->Vis();
            break;
        case 1:
            VisRangliste();
            break;
        case 2:
            aaben = false;
            break;
        default:
            break;
    }
}

void SvarhedgradsHandterInput(int valg)
{
    spil->SaetSvaerhedgrad(valg);
    spil->Start();
}

void VisRangliste()
{
    vector<Resultater> ranglister;
    Resultater rangliste;
    for(vector<Svaerhedsgrad>::iterator itr = spil->svaerhedsgrader.begin(); itr != spil->svaerhedsgrader.end(); ++itr)
    {
        rangliste = Ranglister::SorterResultater(
                    Ranglister::HentResultater((*itr)));
        ranglister.push_back(rangliste);
    }

    rangliste = ranglister[0];
    for(int i = 0; i < 10; ++i)
    {
        if (i >= rangliste.size())
        {
            break;
        }
        cout << i + 1 << ". " << rangliste[i].navn << "    " << rangliste[i].gaet << endl;
    }
}


