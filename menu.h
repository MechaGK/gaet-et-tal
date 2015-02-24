#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include <list>

class Menu
{
    std::string titel;
    std::vector<std::string> punkter;
    int antalPunkter;
    void (*handterFunktion)(int);
public:
    Menu(std::string titel, std::vector<std::string> punkter, void (*handterFunktion)(int));
    ~Menu();
    void Tegn();
    int FaValg();
    void Vis();

};

#endif // MENU_H
