#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>

class Menu
{
	std::string title;
	std::vector<std::string> entries;
	int numberEntries;
	void(*function)(int);
public:
	Menu(std::string title, std::vector<std::string> entries, void(*function)(int));
	~Menu();
	void Draw();
	int GetChoice();
	void Show();

};

#endif // MENU_H
