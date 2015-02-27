#include <iostream>
#include <iomanip>
#include <array>
#include <list>
#include <random>
#include "menu.h"
#include "spil.h"
#include "ranglister.h"

void HovedmenuHandterInput(int valg);
void SvarhedgradsHandterInput(int valg);
void Ranglister();
void VisRangliste(Svaerhedsgrad svaerhedsgrad);

using namespace std;

Menu * hovedmenu;
Menu * svaerhedsgradsMenu;
Spil * spil;

bool aaben = true;

vector<string> hovedmenuPunkter = {"spil", "ranglister", "afslut"};
vector<string> svaerhedsgrader;
vector<Resultater> ranglister;

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
            Ranglister();
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

void Ranglister()
{
    vector<string> menuPunkter;
    vector<Resultater> ranglister;
    Resultater rangliste;
    for(vector<Svaerhedsgrad>::iterator itr = spil->svaerhedsgrader.begin(); itr != spil->svaerhedsgrader.end(); ++itr)
    {
        rangliste = Ranglister::SorterResultater(
                    Ranglister::HentResultater((*itr)));
        ranglister.push_back(rangliste);

        menuPunkter.push_back("Vis rangliste for " + itr->navn);
    }



    Menu* menu = new Menu("", menuPunkter, NULL);
    menu->Vis();
}

void VisRangliste(Svaerhedsgrad svaerhedsgrad)
{
    cout << setfill('_') << setw(26) << "_" << endl;
    cout << "|_" << "NR." << "_|_";
    cout << setfill('_') << setw(10) << "NAVN" << "_|_";
    cout << "GÆT" << "_|" << endl;
    rangliste = ranglister[0];
    for(int i = 0; i < 10; ++i)
    {
        if (i >= rangliste.size())
        {
            break;
        }
        cout << "|" << setfill('_') << setw(3) << i + 1 << "._|_";
        cout << setfill('_') << setw(10) << rangliste[i].navn << "_|_";
        cout << setfill('_') << setw(3) <<  rangliste[i].gaet << "_|" << endl;
    }
}


