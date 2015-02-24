#include "spil.h"
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

}

void Spil::SaetSvaerhedgrad()
{

}
