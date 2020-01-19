#include "bag.h"
#include <iostream>

Bag::Bag(int n)
{
    if(n<=0)
    {
        throw HIBAS_MERET;
    }
    meret = n;
    v = new Elem[meret];
}


Bag::Bag(const Bag& p)
{
    masol(p);

}

Bag::~Bag()
{
    delete [] v;
}

void Bag::betesz(int e)
{
    int ind = 0;
    if (keres(e, ind))
    {
        ++v[ind].db;
    }
    else
    {
        v[db].szam=e;
        v[db].db++;
        db++;
    }
}

void Bag::kivesz(int e)
{
    int ind = 0;

    if(db !=0)
    {
        if (keres(e, ind))
        {
            --v[ind].db;
            if(v[ind].db == 0)
            {
                while(ind<db)
                {
                        v[ind].szam = v[ind+1].szam;
                        v[ind].db = v[ind+1].db;
                        ++ind;

                }
                --db;

            }

        }
        else
        {
            throw HELYTELEN_SZAM;
        }
    }
    else
    {
        throw URES_ZSAK;
    }

}

int Bag::getV(int e)
{
    return v[e].szam;
}

void Bag::eloford(int e)
{
    bool l = false;
    int ert;

    int i=0;

    if(db != 0)
    {
        while(!l && i<=db)
        {
            if(e == v[i].szam)
            {
                l = true;
                ert = v[i].db;

            }

            ++i;
        }
        if(l)
        {
            std::cout<<"A megadott elem elofordulasa: "<<ert<<std::endl;
        }

        else
        {
            throw HELYTELEN_SZAM;
        }
    }
    else
    {
        throw URES_ZSAK;
    }

}

bool Bag::urese()
{
    return db == 0;
}

bool Bag::keres(int e,int &ind)
{
    bool l = false;
    for( int i=0; !l && i<meret; ++i){
        l = (e == v[i].szam);
        ind = i;
    }
    return l;


}

Bag& Bag::operator=(const Bag& p)
{
    if(this != &p)
    {
        delete [] v;
        masol(p);
    }
        return *this;
}

void Bag::masol(const Bag &p)
{
    meret = p.meret;
    db = p.db;
    v = new Elem[p.meret];
    for(int i=0;i<db;++i)
    {
        v[i] = p.v[i];
    }
}

void Bag::kiir()
{

    if(db != 0)
    {
        for(int i=0;i<db;++i)
        {
            std::cout<<v[i].szam<<" ";
        }
        std::cout<<std::endl;

        for(int i=0;i<db;++i)
        {
            std::cout<<v[i].db<<" ";
        }
    }
    else
    {
        throw URES_ZSAK;
    }

}

Bag operator+(Bag p,Bag q)
{

    int y[p.db];
    int z[p.db];
    int db1 = 0;

            for(int i=0;i<p.db;++i)
            {
                int j=0;
                while(j<=q.db && p.v[i].szam != q.v[j].szam)
                {
                    ++j;
                }
                if(j<=q.db)
                {

                    y[db1] = p.v[i].szam;

                        if(p.v[i].db<q.v[j].db)
                        {
                           z[db1] = p.v[i].db;
                        }
                        else
                        {
                            z[db1] = q.v[j].db;
                        }

                    ++db1;

                }
            }

            std::cout<<db1<<" db kozos elemuk van"<<std::endl;

            std::cout<<"Elemek: ";

            for(int i=0;i<db1;++i)
            {
                std::cout<<" "<<y[i]<<" ";
            }

            std::cout<<std::endl;


            std::cout<<"Darabszamuk: ";

            for(int j=0;j<db1;++j)
            {
                std::cout<<" "<<z[j]<<" ";
            }

            std::cout<<std::endl;


}
