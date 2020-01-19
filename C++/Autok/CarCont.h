#ifndef CARCONT_H_INCLUDED
#define CARCONT_H_INCLUDED

#include <vector>
#include <fstream>

struct CarDetails
{
    std::string brand;
    std::string type;
    int year;
    int enginecap;
    int horsepower;
    char enginetype;
    double consumption;
    int price;


    friend std::istream& operator>>(std::istream& in, CarDetails& e)
    {
        in >> e.brand >> e.type >> e.year >> e.enginecap >> e.horsepower >> e.enginetype >>  e.consumption >> e.price;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, CarDetails& e)
    {
        out << e.brand << " " << e.type << " " << e.year << " " << e.enginecap << " " << e.horsepower << " " <<e.enginetype << " " << e.consumption << " " << e.price;
        return out;
    }
};



class CarCont
{

private:
    std::vector<CarDetails> cont;
    std::ifstream f;
    CarDetails dx;

public:
    enum Exceptions{WRONG_INPUT,WRONG_FILENAME};
    void FileOpen(std::string fname);
    void AvgConsumption(int dis,std::string brandname,std::string type,int year);
    void AvgYearConsumption(int dis,std::string brandname,std::string type,int year);
    void Print();
    void PrintByBrand();

};

#endif // CARCONT_H_INCLUDED
