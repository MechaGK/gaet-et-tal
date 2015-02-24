#ifndef MENU_H
#define MENU_H
#include <iostream>

class Menu
{
    std::string titel;
    std::string * punkter;
    void (*handterFunktion)(int);
public:
    Menu(std::string titel, std::string punkter [], void (*handterFunktion)(int));
    ~Menu();
    void Tegn();
    int FaValg();
    void Vis();

};

#endif // MENU_H
