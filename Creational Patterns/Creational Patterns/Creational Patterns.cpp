#include <iostream>
#include <string>
using namespace std;

class Character
{
public:
    virtual string getType() = 0;
    virtual void attack() = 0;
};

class Warrior :public Character {
public:
    string getType() override { return "Воин"; }
    void attack() override { cout << "Воин атакует мечом" << endl; }
};

class Mage :public Character {
public:
    string getType() override { return "Маг"; }
    void attack() override { cout << "Маг кастует огненный шар" << endl; }
};

class Archer :public Character {
public:
    string getType() override { return "Лучник"; }
    void attack() override { cout << "Лучник стреляет из лука" << endl; }
};

class Knight :public Character {
public:
    string getType() override { return "Рыцарь"; }
    void attack() override { cout << "Рыцарь атакует копьём!" << endl; }
};

class CharacterFactory {
public:
    virtual Character* createCharacter() = 0;
    void spawnAndAttask() {
        Character* chara = createCharacter();
        cout << "Создан: " << chara->getType() << ". ";
        chara->attack();
        delete chara;
    }
};

class WarriorFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Warrior(); }
};

class MageFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Mage(); }
};

class ArcherFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Archer(); }
};

class KnightFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Knight(); }
};




int main()
{
    setlocale(LC_ALL, "ru");
    CharacterFactory* factory = new WarriorFactory();
    factory->spawnAndAttask();

    factory = new MageFactory();
    factory->spawnAndAttask();

    factory = new ArcherFactory();
    factory->spawnAndAttask();

    factory = new KnightFactory();
    factory->spawnAndAttask();

    delete factory;


}
