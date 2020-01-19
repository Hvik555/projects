#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include "mood.h"

class Animal
{

protected:
    std::string name;
    int healthy;
    Animal (const std::string &str, int p = 0):name(str), healthy(p) {}


public:
    std::string aniname() const { return name; }
    bool alive() const { return healthy > 0; }
    void changeHealthy(int p) {
        if(healthy > 0 && healthy < 70)
        {
            healthy += p;
        }


    }
    int getHealthy() const {return healthy;}

    virtual void moodchange(Mood* &mood) = 0;

    virtual ~Animal () {}

};

class Tarantula : public Animal
{
public:
    Tarantula(const std::string &str, int p = 0):Animal(str, p){ }
    void moodchange(Mood* &mood) override { mood = mood->moodTaran(this); }
};

class Horcsog : public Animal
{
public:
    Horcsog(const std::string &str, int p = 0):Animal(str, p){ }
    void moodchange(Mood* &mood) override { mood = mood->moodHorcsog(this); }
};

class Macska : public Animal
{
public:
    Macska(const std::string &str, int p = 0):Animal(str, p) { }
    void moodchange(Mood* &mood) override { mood = mood->moodMacska(this); }
};


#endif // ANIMAL_H_INCLUDED
