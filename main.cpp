#include <iostream>
#include <string>
#include <limits>
#include <memory>
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

void SpilmenuHandterInput(int valg)
{

}

string hovedmenuPunkter [3] = { "Spil", "Ranglister", "Afslut"};
string svaerhedsgrader [3] = { "let",  "mellem", "svært"};


int main()
{
    hovedmenu = new Menu("Velkommen til Gæt et tal", hovedmenuPunkter, HovedmenuHandterInput);
    svaerhedsgradsMenu = new Menu("Vælg sværhedsgrad", svaerhedsgrader, SpilmenuHandterInput);
    spil = new Spil();

    while (aaben)
    {
        hovedmenu->Vis();
    }



    return 0;
}


