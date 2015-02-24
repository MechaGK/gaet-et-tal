#include <iostream>
#include <string>
#include <limits>
#include <memory>

using namespace std;

class Menu
{
    string titel;
    string * punkter;
    void (*handterFunktion)(int);
public:
    Menu(string titel, string punkter [], void (*handterFunktion)(int));
    void Tegn();
    int FaValg();
    void Vis();

};

Menu::Menu(string titel, string punkter[], void (*handterFunktion)(int))
{
    this->titel = titel;
    this->punkter = punkter;
    this->handterFunktion = handterFunktion;
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

void HovedmenuHandterInput(int valg)
{
    switch (valg)
    {
        case 1:
            spilMenu.Vis()
    }
}

void SpilmenuHandterInput(int valg)
{

}

bool open = true;

string hovedmenuPunkter [3] = { "Spil", "Ranglister", "Afslut"};
string svaerhedsgrader [3] = { "let",  "mellem", "svært"};
int main()
{
    unique_ptr<Menu> hovedmenu(new Menu("Velkommen til Gæt et tal", hovedmenuPunkter, HovedmenuHandterInput));
    unique_ptr<Menu> spilMenu(new Menu("Vælg sværhedsgrad", svaerhedsgrader, SpilmenuHandterInput));

    while (open)
    {
        hovedmenu->Vis();
    }


    return 0;
}


