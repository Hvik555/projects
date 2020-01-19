#include "menu.h"
#include <iostream>


using namespace std;

void Menu::Run()
{

    try
    {
        string fname;
        cout << "Kerem adja meg a fajl nevet: ";
        cin >> fname;
        cnt.FileOpen(fname);

    int v,m,k;

    do
    {
       v = MenuPrint();

       switch(v)
       {
            case 1 :

                do
                {
                    m = MenuPrint1();

                    switch(m)
                    {
                        case 1 :
                            CarPrint();
                            break;
                        case 2 :
                            CarPrintByBrand();
                            break;
                        default :
                            break;
                    }
                }while(m != 0);
                break;
            case 2 :
                //AvgConsum();
                do
                {
                    k = MenuPrint2();
                    switch(k)
                    {
                        case 1 :
                            CarPrint();
                            break;
                        case 2 :
                            AvgConsum();
                            break;
                        case 3 :
                            AvgYearConsum();
                            break;
                        default :
                            break;
                    }
                }while(k != 0);
                break;
            default :
                cout << "Viszontlatasra!" << endl;
                break;
       }

    }while(v != 0);

    }catch(CarCont::Exceptions ex)
    {
        if(ex == CarCont::WRONG_FILENAME)
        {
            char answer;

            cout << "A megadott fajl nem talalhato,kivanja ujra probalni?(i/n)" << endl;
            do
            {
                cin >> answer;

            }while(answer != 'i' && answer != 'n');

            if(answer == 'i')
            {
                Run();
            }

        }
    }
}




int Menu::MenuPrint()
{
    const int n = 6;
    int valasz;

    cout<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"0. Kilepes"<<endl;
    cout<<"1. Adatbazis tartalma"<<endl;
    cout<<"2. Auto fogyasztasa"<<endl;
    cout<<"3. -"<<endl;
    cout<<"4. -"<<endl;
    cout<<"5. -"<<endl;
    cout<<"6. -"<<endl;
    cout<<"--------------------------------------"<<endl;

    do
    {
        cout << "Kerem adja meg a valasztott opcio szamat: ";
        cin >> valasz;
        cout << endl;
        cout << "Az On altal valasztott opcio sorszama: " << valasz << " " << endl;

    }while(valasz < 0 || valasz > n);

    return valasz;
}



int Menu::MenuPrint1()
{
    const int n = 4;
    int valasz;

    cout<<endl;
    cout<<"****************************************"<<endl;
    cout<<"0. Ugras a fomenuhoz"<<endl;
    cout<<"1. Adatbazis tartalma"<<endl;
    cout<<"2. Adatbazis markai"<<endl;
    cout<<"3. Adatbazis tipusai"<<endl;
    cout<<"4. -"<<endl;
    cout<<"****************************************"<<endl;

    do
    {
        cout << "Valasztas: ";
        cin >> valasz;
    }while(valasz < 0 || valasz > n);

    return valasz;
}


int Menu::MenuPrint2()
{
    const int n = 4;
    int valasz;

    cout<<endl;
    cout<<"****************************************"<<endl;
    cout<<"0. Ugras a fomenuhoz"<<endl;
    cout<<"1. Adatbazis tartalma"<<endl;
    cout<<"2. Auto fogyasztasa"<<endl;
    cout<<"3. Auto eves uzemanyagkoltsege"<<endl;
    cout<<"4. -"<<endl;
    cout<<"****************************************"<<endl;

    do
    {
        cout << "Valasztas: ";
        cin >> valasz;
    }while(valasz < 0 || valasz > n);

    return valasz;
}


void Menu::CarPrint()
{
    cout << "Az adatbazisban levo autok tulajdonsagai: " << endl;
    cout << endl;
    cnt.Print();
}

void Menu::CarPrintByBrand()
{
    cout << "Az adatbazisban levo markak: " << endl;
    cnt.PrintByBrand();
}


double Menu::AvgConsum()
{
    int dis,year;
    string brand,type,s;
    bool fault;

    try
    {
        do
        {

        cout << "Kerem adja meg hany km szeretne menni, valamint az auto markajat,tipusat es evjaratat: ";
        cin >> dis >> brand >> type >> year;
        fault = cin.fail();
        cin.clear();
        getline(cin,s);
        cnt.AvgConsumption(dis,brand,type,year);
        }while(fault);

    }catch(CarCont::Exceptions ex)
    {
        if(ex == CarCont::WRONG_INPUT)
        {
            cout << "A keresett auto nincs az adatbazisban!" << endl;
        }
    }

}


double Menu::AvgYearConsum()
{

    int dis,year;
    string brand,type,s;
    bool fault;

    try
    {
        do
        {

        cout << "Kerem adja meg hany km vezet evente, valamint az auto markajat,tipusat es evjaratat: ";
        cin >> dis >> brand >> type >> year;
        fault = cin.fail();
        cin.clear();
        getline(cin,s);
        cnt.AvgYearConsumption(dis,brand,type,year);
        }while(fault);

    }catch(CarCont::Exceptions ex)
    {
        if(ex == CarCont::WRONG_INPUT)
        {
            cout << "A keresett auto nincs az adatbazisban!" << endl;
        }
    }

}

