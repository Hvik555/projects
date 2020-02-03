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


Average* Average::oneinst = nullptr;
Average* Average::Oneinst()
{
    if(oneinst == nullptr) {
        oneinst = new Average();
    }
    return oneinst;
}

Mood* Avegare::moodTaran(Tarantula *tarantula)
{
    tarantula->changeHealthy(-2);
    return this;
}

Mood* Average::moodHorcsog(Horcsog *horcsog)
{
    horcsog->changeHealthy(-3);
    return this;
}

Mood* Average::moodMacska(Macska *macska)
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
