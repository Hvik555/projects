#include <iostream>
#include "bag.h"
#include "menu.h"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE


int main()
{

    cout<<"Zsak tipus"<<endl;

    Menu app;
    app.Run();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("konstruktorok", "(ZSAK)")
{
    Bag z;
    CHECK( 0 == z.getDB());
    CHECK( 1000 == z.getMeret() );

    Bag k(10);
    CHECK( 0 == k.getDB() );
    CHECK( 10 == k.getMeret() );

    CHECK_THROWS(Bag u(0));

    CHECK_THROWS(Bag o(-1));
}

TEST_CASE("ures_e","(ZSAK)")
{
    Bag z;
    CHECK( z.urese() == TRUE);

    Bag k(3);
    CHECK( k.urese() == TRUE );

    int e = 1;
    k.betesz(e);
    CHECK( k.urese() == FALSE );

}


TEST_CASE("Elembetesz","(ZSAK)")
{
    Bag z(3);
    int a = 1;
    z.betesz(a);

    CHECK(z.getDB() == 1);
    CHECK(z.getMeret() ==3);

    Bag k(100);
    int b;
    b = 2;
    k.betesz(a);
    k.betesz(b);

    CHECK(k.getDB() == 2);
    CHECK(k.getMeret() ==100);
}


TEST_CASE("Elemkivesz","(ZSAK)")
{
    Bag z;
    int e = 1;
    int f = 2;
    z.betesz(e);
    z.betesz(f);


    CHECK(z.urese() == FALSE);

    z.kivesz(e);

    CHECK(z.getDB() ==1);

    CHECK_THROWS(z.kivesz(e));
}


TEST_CASE("Masolo konstruktor","(ZSAK)")
{
    Bag z(5);
    int e = 1;
    int f = 2;

    z.betesz(e);
    z.betesz(f);

    Bag k(z);


    CHECK(k.getDB() == 2);
    CHECK(k.getMeret() == 5);

}


TEST_CASE("Ertekadas operator","(ZSAK)")
{
    Bag z;
    Bag k;

    z.betesz(3);
    z.betesz(4);

    k = z;


    CHECK(k.getDB() == 2);
    CHECK(k.getV(0) == z.getV(0));
    CHECK(k.getV(1) == z.getV(1));
}


#endif



