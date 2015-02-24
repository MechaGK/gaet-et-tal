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
    for (int i = 0; i < punkter.size(); i++){
        cout << i + 1 << ". " << punkter[i] << endl;
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



