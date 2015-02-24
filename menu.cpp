#include <iostream>
#include <limits>
#include <vector>
#include "menu.h"
#include "funktioner.h"

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

    return LaesTal(1, antalPunkter) - 1;

    return valg - 1;
}

void Menu::Vis()
{
    Tegn();
    int valg = FaValg();
    handterFunktion(valg);
}



