#include <iostream>
#include "CarCont.h"
#include "menu.h"

using namespace std;

int main()
{

    Menu App;
    App.Run();

    /*ifstream f("Autok.txt");
    vector<CarDetails> a;
    CarDetails dx;


    string brand;
    string type;
    int year;
    double consumption;
    int price;

    while(f >> brand >> type >> year >> consumption >> price)
    {
        cout << brand << " " << type << " " << year << " " << consumption << " " << price << endl;
    }

    while(f >> dx)
    {
        a.push_back(dx);

    }

    CarCont vec(a);

    CarCont vec("Autok.txt");
    CarCont a;

    vec.print();

    cout << endl;


    int km,ev,evjarat;
    string marka,tipus;

    cout << "Kerem adja meg a km,hany evre,markat,tipust,evjaratot" << endl;
    cin >> km >> ev >> marka >> tipus >> evjarat;

    cout << vec.AvgConsumption(km,ev,marka,tipus,evjarat);*/

    return 0;
}
