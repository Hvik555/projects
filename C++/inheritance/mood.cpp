#include "mood.h"
#include "animal.h"

using namespace std;

Happy* Happy::oneinst = nullptr;
Happy* Happy::Oneinst()
{
    if(oneinst == nullptr) {
        oneinst = new Happy();
    }
    return oneinst;
}

Mood* Happy::moodTaran(Tarantula *tarantula)
{
    tarantula->changeHealthy(1);
    return this;
}

Mood* Happy::moodHorcsog(Horcsog *horcsog)
{
    horcsog->changeHealthy(2);
    return this;
}

Mood* Happy::moodMacska(Macska *macska)
{
    macska->changeHealthy(3);
    return this;
}


Avegare* Avegare::oneinst = nullptr;
Avegare* Avegare::Oneinst()
{
    if(oneinst == nullptr) {
        oneinst = new Avegare();
    }
    return oneinst;
}

Mood* Avegare::moodTaran(Tarantula *tarantula)
{
    tarantula->changeHealthy(-2);
    return this;
}

Mood* Avegare::moodHorcsog(Horcsog *horcsog)
{
    horcsog->changeHealthy(-3);
    return this;
}

Mood* Avegare::moodMacska(Macska *macska)
{
    macska->changeHealthy(3);
    return this;
}


Sad* Sad::oneinst = nullptr;
Sad* Sad::Oneinst()
{
    if(oneinst == nullptr) {
        oneinst = new Sad();
    }
    return oneinst;
}

Mood* Sad::moodTaran(Tarantula *tarantula)
{
    tarantula->changeHealthy(-3);
    return this;
}

Mood* Sad::moodHorcsog(Horcsog *horcsog)
{
    horcsog->changeHealthy(-5);
    return this;
}

Mood* Sad::moodMacska(Macska *macska)
{
    macska->changeHealthy(-7);
    return this;
}
