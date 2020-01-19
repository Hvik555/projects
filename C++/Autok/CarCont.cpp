#include "CarCont.h"
#include <iostream>


using namespace std;


void CarCont::FileOpen(string fname)
{
    f.open(fname.c_str());
    if(f.fail())
    {
        throw WRONG_FILENAME;
    }
    while(f >> dx)
    {
        cont.push_back(dx);
    }
}

void CarCont::Print()
{
    for(int i=0;i<cont.size();++i)
    {
        cout << cont[i] << endl;
    }
}

void CarCont::PrintByBrand()
{
    int db = 0;
    vector<CarDetails> vec;

    for(int i=0;i<cont.size();++i)
    {
        if(cont[i].brand != cont[i+1].brand)
        {
            vec.push_back(cont[i]);
            ++db;
        }
    }

    for(int i=0;i<db;++i)
    {
        cout << vec[i].brand<< " ";
    }

}

void CarCont::AvgConsumption(int dis,string brandname,string type,int year)
{
    vector<CarDetails> vec;
    int db = 0;

    for(int i=0;i<cont.size();++i)
    {
        if(cont[i].brand == brandname && cont[i].type == type && cont[i].year == year)
        {
            vec.push_back(cont[i]);
            ++db;
        }
    }

    if(db > 0)
    {
        cout << "A keresett autora kapott talalatok, es fogyasztasuk a megadott km mellett: " << endl;

        for(int i=0;i<vec.size();++i)
        {
            vec[i].consumption = vec[i].consumption * dis/100;
            cout << vec[i].brand << " " <<vec[i].type << " " << vec[i].year <<  " " << vec[i].enginecap << " " << vec[i].horsepower << " " << vec[i].enginetype << " specifikacioju auto fogyasztasa a megadott km szamon: " << vec[i].consumption << " liter."  << endl;
        }
    }
    else
    {
        throw WRONG_INPUT;
    }

}



void CarCont::AvgYearConsumption(int dis,string brandname,string type,int year)
{
    vector<CarDetails> vec;
    vector<double> consum;
    const int price = 398;

    int db1 = 0;

    for(int i=0;i<cont.size();++i)
    {
        if(cont[i].brand == brandname && cont[i].type == type && cont[i].year == year)
        {
            vec.push_back(cont[i]);
            ++db1;
        }
    }

    if(db1 > 0)
    {
        cout << "A keresett autora kapott talalatok, es fogyasztasuk a megadott km mellett: " << endl;

        for(int i=0;i<vec.size();++i)
        {
            vec[i].consumption = (vec[i].consumption * dis/100);
            consum.push_back(vec[i].consumption * price);
            cout << vec[i].brand << " " <<vec[i].type << " " << vec[i].year <<  " " << vec[i].enginecap << " " << vec[i].horsepower << " " << vec[i].enginetype << " specifikacioju auto fogyasztasa a megadott km szamon: " << vec[i].consumption << " liter, koltsege: "  << consum[i] << " ft." << endl;
        }



    }
    else
    {
        throw WRONG_INPUT;
    }


}
