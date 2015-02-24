#include <iostream>
#include <limits>
#include <vector>
#include "menu.h"

using namespace std;

Menu::Menu(string titel, vector<string> punkter, void (*handterFunktion)(int))
{
    this->titel = titel;
    this->punkter = punkter;
    this->handterFunktion = handterFunktion;
    this->antalPunkter = punkter.size();
}

Menu::~Menu()
{
    titel;
    vector<string>().swap(punkter);
    handterFunktion;
}

void Menu::Tegn()
{
    string punkt;
    for (int i = 0; i < punkter.size(); i++){
        punkt = punkter[i];
        punkt[0] = toupper(punkt[0]);
        cout << i + 1 << ". " << punkt << endl;
    }
}

int Menu::FaValg()
{
    cout << "Valg: ";
    int valg;
    while(!(cin >> valg) || valg < 1 || valg > antalPunkter){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ugyldigt valg, det skal være et tal mellem 1 og " << antalPunkter << endl;
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



