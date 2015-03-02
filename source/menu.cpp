#include <limits>
#include <string>
#include "menu.h"
#include "functions.h"

using namespace std;

Menu::Menu(string title, vector<string> entries, void(*function)(int))
{
	this->title = title;
	this->entries = entries;
	this->function = function;
    this->numberEntries = entries.size();
}

Menu::~Menu()
{
    vector<string>().swap(entries);
}

void Menu::Draw()
{
    cout << title << endl;
	string entry;
	for (int i = 0; i < entries.size(); i++)
    {
		entry = entries[i];
		entry[0] = toupper(entry[0]);
		cout << i + 1 << ". " << entry << endl;
    }
}

int Menu::GetChoice()
{
    return GetNumber(1, numberEntries, "Valg: ") - 1;
}

void Menu::Show()
{
    Draw();
    int valg = GetChoice();
    function(valg);
}



