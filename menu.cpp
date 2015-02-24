#include <iostream>
#include <limits>
#include "menu.h"

using namespace std;

Menu::Menu(string titel, string punkter[], void (*handterFunktion)(int))
{
    this->titel = titel;
    this->punkter = punkter;
    this->handterFunktion = handterFunktion;
}

Menu::~Menu()
{
    titel;
    delete punkter;
    handterFunktion;
}

void Menu::Tegn()
{
    for (int i = 0; i + 1 < punkter->size(); i++){
        cout << i + 1 << ". " << punkter[i] << endl;
    }
}

int Menu::FaValg()
{
    int antalValgmuligheder = punkter->size();

    cout << "Valg: ";
    int valg;
    while(!(cin >> valg) || valg < 1 || valg >= antalValgmuligheder){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ugyldigt valg, det skal være et tal mellem 1 og " << antalValgmuligheder << endl;
        cout << "Valg: ";
    }

    return valg;
}

void Menu::Vis()
{
    Tegn();
    int valg = FaValg();
    handterFunktion(valg);
}



