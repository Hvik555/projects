#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "CarCont.h"

class Menu
{

private:
    CarCont cnt;
    int MenuPrint();
    int MenuPrint1();
    int MenuPrint2();
    void CarPrint();
    void CarPrintByBrand();
    double AvgConsum();
    double AvgYearConsum();

public:
    void Run();

};


#endif // MENU_H_INCLUDED
