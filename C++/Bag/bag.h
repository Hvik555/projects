#ifndef BAG_H_INCLUDED
#define BAG_H_INCLUDED

struct Elem
{
    int szam;
    int db;
    Elem(){szam = 0; db = 0;}
    Elem(int szam,int db)
    {
        this->szam = szam;
        this->db = db;
    }
};

class Bag
{

private:
    Elem *v;
    int meret;
    int db = 0;
    void masol(const Bag &p);


public:
    enum ZsakHiba{ HIBAS_MERET,URES_ZSAK,HELYTELEN_SZAM };
    Bag(int n = 1000);
    Bag(const Bag& p);
    ~ Bag();
    Bag& operator=(const Bag& p);
    void betesz(int e);
    void kivesz(int e);
    void eloford(int e);
    bool urese();
    bool keres(int e,int &ind);
    void kiir();
    int getDB(){return db;}
    int getMeret(){return meret;}
    int getV(int e);

    friend Bag operator+(Bag p, Bag q);

};


#endif // BAG_H_INCLUDED
