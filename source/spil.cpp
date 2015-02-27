#include "spil.h"
#include "funktioner.h"
#include "resultat.h"
#include "ranglister.h"
#include <iostream>

using namespace std;

Spil::Spil()
{
    Svaerhedsgrad *let = new Svaerhedsgrad;
    let->navn = "let";
    let->antalGaet = 4;
    let->maksTal = 20;

    Svaerhedsgrad *mellem = new Svaerhedsgrad;
    mellem->navn = "mellem";
    mellem->antalGaet = 4;
    mellem->maksTal = 30;

    Svaerhedsgrad *svaer = new Svaerhedsgrad;
    svaer->navn = "svær";
    svaer->antalGaet = 4;
    svaer->maksTal = 40;

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
    cout << "Gæt et tal mellem 1 og " << svaerhedsgrad.maksTal << endl;

    int gaetBrugt, gaet;
    string gaetTekst;
    bool vundet = false;

    for (int i = 0; i < svaerhedsgrad.maksTal; ++i)
    {
        gaetTekst = to_string(i + 1) + ". gæt: ";
        gaet = LaesTal(1, svaerhedsgrad.maksTal, gaetTekst);

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
        string navn;

        cout << "Dit navn: ";
        while (getline(cin, navn))
        {
            if (navn != "")
            {
                break;
            }
        }

        Resultat resultat;
        resultat.navn = navn;
        resultat.gaet = gaetBrugt;
        resultat.svaerhedsgrad = svaerhedsgrad;

        cout << "Gemmer..." << endl;

        Ranglister::NytResultat(resultat);
    }
}

void Spil::SaetSvaerhedgrad(int nySvaerhedsgrad)
{
    svaerhedsgrad = svaerhedsgrader[nySvaerhedsgrad];
}
