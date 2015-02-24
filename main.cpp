#include <iostream>
#include <array>
#include <list>
#include "menu.h"
#include "spil.h"

using namespace std;

Menu * hovedmenu;
Menu * svaerhedsgradsMenu;
Spil * spil;

bool aaben = true;

void HovedmenuHandterInput(int valg)
{
    switch (valg)
    {
        case 1:
            svaerhedsgradsMenu->Vis();
            break;
        case 2:
            cout << "ranglister" << endl;
            break;
        case 3:
            aaben = false;
            break;
        default:
            break;
    }
}

void SvarhedgradsHandterInput(int valg)
{

}

vector<string> hovedmenuPunkter = {"spil", "ranglister", "afslut"};
vector<string> svaerhedsgrader;

int main()
{
    spil = new Spil();

    for(vector<Svaerhedsgrad>::iterator itr = spil->svaerhedsgrader.begin(); itr != spil->svaerhedsgrader.end(); ++itr){
        svaerhedsgrader.push_back(itr->navn);
    }

    hovedmenu = new Menu("Velkommen til Gæt et tal", hovedmenuPunkter, HovedmenuHandterInput);
    svaerhedsgradsMenu = new Menu("Vælg sværhedsgrad", svaerhedsgrader, SvarhedgradsHandterInput);


    while (aaben)
    {
        hovedmenu->Vis();
    }

    return 0;
}


