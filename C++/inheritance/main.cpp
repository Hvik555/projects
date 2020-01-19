#include <iostream>
#include "animal.h"
#include <fstream>
#include <vector>

using namespace std;


void newcreate(const string &fname, vector<Animal*> &animals, vector<Mood*> &moody)
{

    ifstream f(fname.c_str());
    if(f.fail())
    {
        cout << "A megadott fajl nem talalhato!" << endl;
        exit(1);
    }
    //allatok
    int n;
    f >> n;

    animals.resize(n);
    for(int i=0; i<n; ++i){
        char ch;
        string name;
        int p;
        f >> ch >> name >> p;
        switch(ch){
        case 'T' : animals[i] = new Tarantula(name, p); break;
        case 'H' : animals[i] = new Horcsog(name, p);    break;
        case 'M' : animals[i] = new Macska(name, p);   break;
        }
    }

    // hangulatok-napok

    for(int j=0;!f.fail();++j) {
        char k;
        f >> k;
        switch(k){
            case 'v' : moody.push_back( Happy::Oneinst());  break;
            case 'a' : moody.push_back(Avegare::Oneinst());  break;
            case 's' : moody.push_back(Sad::Oneinst()); break;
        }
    }

}

void algprint(vector<Animal*> &animals, vector<Mood*> &moody)
{

    vector<int> maxi(moody.size()-1);
    vector<string> names(moody.size()-1);

    for(int i=0;i<moody.size()-1;++i)
    {

        maxi[0] = animals[0]->getHealthy();

        for(int j=0;j<animals.size();++j)
        {

            animals[j]->moodchange(moody[i]);

            cout << animals[j]->getHealthy() << " ";

            if(maxi[i] < animals[j]->getHealthy())
            {
                maxi[i] = animals[j]->getHealthy();
                names[i] = animals[j]->aniname();
            }

        }

        cout << " " << "Maximum: " << maxi[i] << " " << names[i] << endl;

    }
}


vector<string> changing(vector<Animal*> &animals, vector<Mood*> &moody)
{

    vector<int> maxi(moody.size()-1);
    vector<string> names(moody.size()-1);

    for(int i=0;i<moody.size()-1;++i)
    {

        maxi[0] = animals[0]->getHealthy();

        for(int j=0;j<animals.size();++j)
        {

            animals[j]->moodchange(moody[i]);


            if(maxi[i] < animals[j]->getHealthy())
            {
                maxi[i] = animals[j]->getHealthy();
                names[i] = animals[j]->aniname();
            }

        }

    }
    return names;
}

//#define NORMAL_MODE
#ifdef NORMAL_MODE


int main()
{
    vector<Animal*> animals;
    vector<Mood*> moody;
    newcreate("in2.txt", animals,moody);

    algprint(animals,moody);

    // allatok megszüntetése
    for(unsigned int i=0; i<animals.size(); ++i) delete animals[i];

    return 0;
}


#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("1", "in1*.txt") {

    vector<Animal*> animal;
    vector<Mood*> moody;
    vector<string> days;


    newcreate("in11.txt", animal, moody );
    days = changing(animal, moody);

    CHECK(animal.size() == 1);
    CHECK(days.size() == 3);

    for(int i=0; i<(int)animal.size(); ++i) delete animal[i];


    newcreate("in12.txt", animal, moody );
    days = changing(animal, moody);

    CHECK(animal.size() == 4);

}


TEST_CASE("2", "in21*.txt") {


    cout << endl;

    vector<Animal*> animal;
    vector<Mood*> moody;
    vector<string> days;

    newcreate("in21.txt", animal, moody );
    days = changing(animal, moody);

    CHECK(days[0] == "Joe");
    CHECK(days[1] == "AKTJOE");

    for(int i=0; i<(int)animal.size(); ++i) delete animal[i];

}

TEST_CASE("3", "in2*.txt")
{


    vector<Animal*> animal;
    vector<Mood*> moody;
    vector<string> days;

    newcreate("in22.txt", animal, moody );
    days = changing(animal, moody);

    CHECK(animal[0]->alive() == true);
    CHECK(animal[3]->alive() == false);

    for(int i=0; i<(int)animal.size(); ++i) delete animal[i];


    newcreate("in23.txt", animal, moody );
    days = changing(animal, moody);

    CHECK(animal[0]->alive() == false);
    CHECK(animal[3]->alive() == true);

    for(int i=0; i<(int)animal.size(); ++i) delete animal[i];

}



#endif // NORMAL_MODE
