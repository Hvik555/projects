#include "menu.h"
#include <iostream>


using namespace std;



void Menu::Run()
{
    int v;
    do{
        v=MenuPrint();
        switch(v)
        {
            case 1:
                Zsakba();
                Zsakkiir();
                break;
            case 2:
                Zsakbol();
                break;
            case 3:
                Eloef();
                break;
            case 4:
                Urese();
                break;
            case 5:
                Zsakkiir();
                break;
            case 6:
                Zsakmetszet();
                break;
            default:
                cout<<"Viszontlatasra!"<<endl;;
                break;

        }
    }while(v!=0);
}

int Menu::MenuPrint()
{
    const int n=6;
    int valasz;
    cout<<endl;
    cout<<"****************************************"<<endl;
    cout<<"0. Kilepes"<<endl;
    cout<<"1. Elemek Zsakba pakolasa"<<endl;
    cout<<"2. Elem kivetele a zsakbol"<<endl;
    cout<<"3. Elem elofordulasa a zsakban"<<endl;
    cout<<"4. Ures-e a zsak vizsgalat"<<endl;
    cout<<"5. Zsak kiirasa"<<endl;
    cout<<"6. Ket zsak metszete"<<endl;
    cout<<"****************************************"<<endl;
    do{
        cout<<"Valasztas:";
        cin>>valasz;
    }while(valasz<0 || valasz>n);
    return valasz;
}

void Menu::Zsakba()
{

        int n,e;
        bool l;
        string s;

        do
        {
        cout<<"Kerem adja meg hany elemet szeretne a zsakba tenni. "<<endl;
        cin>>n;
        l=cin.fail() || n<=0;
        if(l)
        {
            cout<<"Hibas meret!"<<endl;
            cin.clear();
            getline(cin,s);
        }
        for(int i=0;i<n;++i)
        {
            cin>>e;
            h.betesz(e);
        }

        }while(l);

        cout<<"A zsak jelenlegi elemei: "<<endl;

}

void Menu::Zsakbol()
{
    try{
        int e;

        cout<<"Kerem adja meg melyik elemet kivanja kivenni."<<endl;
        cin>>e;
        h.kivesz(e);
    }catch(Bag::ZsakHiba ex)
    {
        if(ex == Bag::HELYTELEN_SZAM)
        {
            cout<<"A megadott elem nincs a zsakban!"<<endl;
        }
        else if(ex == Bag::URES_ZSAK)
        {
            cout<<"A zsak ures!"<<endl;
        }
    }


}

void Menu::Eloef()
{
    try{
    int e;

    cout<<"Kerem adja meg melyik elem elofordulasara kivancsi."<<endl;
    cin>>e;
    h.eloford(e);
    }catch(Bag::ZsakHiba ex)
    {
        if(ex == Bag::HELYTELEN_SZAM)
        {
            cout<<"A megadott elem nincs a zsakban!"<<endl;
        }
        else if(ex == Bag::URES_ZSAK)
        {
            cout<<"A zsak ures!"<<endl;
        }
    }
}

void Menu::Urese()
{
   if( h.urese())
   {
       cout<<"A zsak ures!"<<endl;
   }
   else
   {
       cout<<"A zsak nem ures!"<<endl;
   }

}

void Menu::Zsakkiir()
{
   try{

    h.kiir();

   }catch(Bag::ZsakHiba ex)
   {
       if(ex == Bag::URES_ZSAK)
       {
           cout<<"A zsak ures!"<<endl;
       }
   }
}

void Menu::Zsakmetszet()
{

    int n,m,e,f;
    bool l;
    string s;

    do{
    cout<<"Kerem adja meg az elso zsak meretet: "<<endl;
    cin>>n;
        l=cin.fail() || n<=0;
        if(l)
        {
            cout<<"Hibas meret!"<<endl;
            cin.clear();
            getline(cin,s);
        }
    }while(l);

    Bag p(n);

    for(int i=0;i<n;++i)
    {
        cin>>e;
        p.betesz(e);

    }

    cout<<endl;

    do{
    cout<<"Kerem adja meg a masodik zsak meretet: "<<endl;
    cin>>m;
    l=cin.fail() || m<=0;
        if(l)
        {
            cout<<"Hibas meret!"<<endl;
            cin.clear();
            getline(cin,s);
        }
    }while(l);

    Bag q(m);

    for(int j=0;j<m;++j)
    {
        cin>>f;
        q.betesz(f);
    }

    cout<<endl;

    p+q;
}
