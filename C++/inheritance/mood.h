#ifndef MOOD_H_INCLUDED
#define MOOD_H_INCLUDED

#include <string>

class Tarantula;
class Horcsog;
class Macska;

class Mood
{
public:
    virtual Mood* moodTaran(Tarantula *tarantula) = 0;
    virtual Mood* moodHorcsog(Horcsog *horcsog) = 0;
    virtual Mood* moodMacska(Macska *macska) = 0;
};


class Happy : public Mood
{
public:
    static Happy* Oneinst();
    Mood* moodTaran(Tarantula *tarantula) override;
    Mood* moodHorcsog(Horcsog *horcsog) override;
    Mood* moodMacska(Macska *macska) override;
protected:
    Happy(){}
private:
    static Happy* oneinst;
};


class Avegare : public Mood
{
public:
    static Avegare* Oneinst();
    Mood* moodTaran(Tarantula *tarantula) override;
    Mood* moodHorcsog(Horcsog *horcsog) override;
    Mood* moodMacska(Macska *macska) override;
protected:
    Avegare(){}
private:
    static Avegare* oneinst;
};

class Sad : public Mood
{
public:
    static Sad* Oneinst();
    Mood* moodTaran(Tarantula *tarantula) override;
    Mood* moodHorcsog(Horcsog *horcsog) override;
    Mood* moodMacska(Macska *macska) override;
protected:
    Sad(){}
private:
    static Sad* oneinst;
};

#endif // MOOD_H_INCLUDED
