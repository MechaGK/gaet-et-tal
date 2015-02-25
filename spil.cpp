#include "spil.h"
#include "funktioner.h"
#include <iostream>
#include <vector>

using namespace std;

Spil::Spil()
{
    Svaerhedsgrad *let = new Svaerhedsgrad;
    let->navn = "let";
    let->antalGaet = 4;
    let->maksTal = 10;

    Svaerhedsgrad *mellem = new Svaerhedsgrad;
    mellem->navn = "mellem";
    mellem->antalGaet = 4;
    mellem->maksTal = 15;

    Svaerhedsgrad *svaer = new Svaerhedsgrad;
    svaer->navn = "svær";
    svaer->antalGaet = 4;
    svaer->maksTal = 20;

    svaerhedsgrader.push_back(*let);
    svaerhedsgrader.push_back(*mellem);
    svaerhedsgrader.push_back(*svaer);

    delete let;
    delete mellem;
    delete svaer;
}

Spil::~Spil()
{
    svaerhedsgrader.clear();
    vector<Svaerhedsgrad>().swap(svaerhedsgrader);
}

void Spil::Start()
{
    int hemmeligtTal = rand() % svaerhedsgrad.maksTal + 1;
    cout << "Du har valgt " << svaerhedsgrad.navn << "." << endl;
    //cout << "Du har " << svaerhedsgrad.antalGaet << " til at gætte et tal mellem 1 og " << svaerhedsgrad.maksTal << "." << endl;
    cout << "Gæt et tal mellem 1 og " << svaerhedsgrad.maksTal << endl;

    int gaetBrugt, gaet;
    bool vundet = false;

    for (int i = 0; i < svaerhedsgrad.maksTal; ++i)
    {
        cout << i + 1 << ". gæt: ";
        gaet = LaesTal(1, svaerhedsgrad.maksTal, "");

        if (gaet == hemmeligtTal)
        {
            cout << gaet << " er tallet, du har vundet!" << endl;
            gaetBrugt = i + 1;
            vundet = true;
            break;
        }
        else
        {
            cout << gaet << " er ikke det korrekte tal. Tallet du leder efter er ";
            cout << (gaet < hemmeligtTal ? "større" : "mindre") << "." << endl;
        }
    }

    if (vundet)
    {
        string name = "";
        cout << "Dit navn: ";
        cin << name;

        if (name.length() < 1)
        {
            cout << "Skriv et navn: ";
        }
    }
}

void Spil::SaetSvaerhedgrad(int nySvaerhedsgrad)
{
    svaerhedsgrad = svaerhedsgrader[nySvaerhedsgrad];
}
