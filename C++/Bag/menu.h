#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "bag.h"

class Menu
{

private:

    int MenuPrint();
    void Zsakba();
    void Zsakbol();
    void Eloef();
    void Urese();
    void Zsakkiir();
    void Zsakmetszet();

    Bag h;


public:

    void Run();

};

#endif // MENU_H_INCLUDED
