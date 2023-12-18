#include <iostream>
#include <string>

using namespace std;

class Ability
{
public:
    virtual string Power() = 0;
};

class Energy : public Ability
{
public:
    string Power()
    {
        return "Energy manipulation\n";
    }
};

class SuperStrength : public Ability
{
public:
    string Power()
    {
        return "Super strength\n";
    }
};

class Witchcraft : public Ability
{
public:
    string Power()
    {
        return "Witchcraft\n";
    }
};

class Regeneration : public Ability
{
public:
    string Power()
    {
        return "Regeneration\n";
    }
};

class Hero
{
public:
    virtual void Race() = 0;
    virtual void PowerAbility() = 0;
    virtual string GetSide() = 0;
};

class SuperHero : public Hero
{
public:
    SuperHero(Ability* ability1, Ability* ability2) : ability1(ability1), ability2(ability2) {}

    void PowerAbility()
    {
        cout << ability1->Power();
    }

    string GetSide()
    {
        return "Good\n";
    }

private:
    Ability* ability1;
    Ability* ability2;
};

class Loki : public SuperHero
{
public:
    Loki() : SuperHero(new SuperStrength, new Witchcraft) {}

    void Race()
    {
        cout << "Loki: God\n";
    }

    string GetSide()
    {
        return "Anti-Hero\n";
    }
};

class Thor : public SuperHero
{
public:
    Thor() : SuperHero(new Energy, new SuperStrength) {}

    void Race()
    {
        cout << "Thor: God\n";
    }

    string GetSide()
    {
        return "Good\n";
    }
};

class SpiderMan : public SuperHero
{
public:
    SpiderMan() : SuperHero(new SuperStrength, nullptr) {}

    void Race()
    {
        cout << "Spider-Man: Human\n";
    }

    string GetSide()
    {
        return "Good\n";
    }
};

class DoctorStrange : public SuperHero
{
public:
    DoctorStrange() : SuperHero(new Witchcraft, nullptr) {}

    void Race()
    {
        cout << "Doctor Strange: Human\n";
    }

    string GetSide()
    {
        return "Good\n";
    }
};

class Deadpool : public SuperHero
{
public:
    Deadpool() : SuperHero(new Regeneration, nullptr) {}

    void Race()
    {
        cout << "Deadpool: Human\n";
    }

    string GetSide()
    {
        return "Anti-Hero\n";
    }
};

class Groot : public SuperHero
{
public:
    Groot() : SuperHero(new Regeneration, nullptr) {}

    void Race()
    {
        cout << "Groot: Flora Colossi\n";
    }

    string GetSide()
    {
        return "Good\n";
    }
};

int main()
{
    int count = 6;

    SuperHero** ability = new SuperHero * [count];

    ability[0] = new Loki;
    ability[1] = new Thor;
    ability[2] = new SpiderMan;
    ability[3] = new DoctorStrange;
    ability[4] = new Deadpool;
    ability[5] = new Groot;

    for (int i = 0; i < count; i++)
    {
        ability[i]->Race();

        cout << "Side: " << ability[i]->GetSide();
        cout << "Power: ";
        ability[i]->PowerAbility();

        cout << "\n";
    }

    return 0;
}
