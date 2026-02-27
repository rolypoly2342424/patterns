#include <iostream>
#include <string>
using namespace std;

/// \brief Интерфейс для персонажей
class Character
{
public:
    virtual string getType() = 0;
    virtual void attack() = 0;
};

/// \brief Класс с настройками для персонажа Воин
class Warrior :public Character {
public:
    /**
    * \brief Функция для получения типа персонажа
    * \return string - строку, название персонажа
    * \remark Получаем только имя персонажа, так как это учебный код
    */
    string getType() override { return "Воин"; }
    /**
    * \brief Функция для выполнения действий персонажа
    * \note Не влияет ни на что. Это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Воин атакует мечом" << endl; }
};

/// \brief Класс с настройками для персонажа Маг
class Mage :public Character {
public:
    /**
   * \brief Функция для получения типа персонажа
   * \return string - строку, название персонажа
   * \remark Получаем только имя персонажа, так как это учебный код
   */
    string getType() override { return "Маг"; }
    /**
    * \brief Функция для выполнения действий персонажа
    * \note Не влияет ни на что. Это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Маг кастует огненный шар" << endl; }
};

/// \brief Класс с настройками для персонажа Лучник
class Archer :public Character {
public:
    /**
   * \brief Функция для получения типа персонажа
   * \return string - строку, название персонажа
   * \remark Получаем только имя персонажа, так как это учебный код
   */
    string getType() override { return "Лучник"; }
    /**
    * \brief Функция для выполнения действий персонажа
    * \note Не влияет ни на что. Это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Лучник стреляет из лука" << endl; }
};

/// \brief Класс с настройками для персонажа Рыцарь
class Knight :public Character {
public:
    /**
   * \brief Функция для получения типа персонажа
   * \return string - строку, название персонажа
   * \remark Получаем только имя персонажа, так как это учебный код
   */
    string getType() override { return "Рыцарь"; }
    /**
    * \brief Функция для выполнения действий персонажа
    * \note Не влияет ни на что. Это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Рыцарь атакует копьём!" << endl; }
};

/**
* \brief Абстрактная фабрика для генерации персонажей
* \Используется для примера работы паттерна проектирования Creational
*/
class CharacterFactory {
public:
    virtual Character* createCharacter() = 0;
    /**
    * \brief Функиция для создания персонажей и выполнения базовых его действий
    * \note После создания объекта, выполняет действие персонажа и уничтожает объект
    * \warning Нельзя будет использовать созданных персонажей в других частях кода
    */
    void spawnAndAttask() {
        Character* chara = createCharacter();
        cout << "Создан: " << chara->getType() << ". ";
        chara->attack();
        delete chara;
    }
};

/// \brief Класс для создания Воина
class WarriorFactory : public CharacterFactory {
public:
    /**
    * \brief Функиция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Warrior(); }
};

/// \brief Класс для создания Мага
class MageFactory : public CharacterFactory {
public:
    /**
    * \brief Функиция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Mage(); }
};

/// \brief Класс для создания Лучника
class ArcherFactory : public CharacterFactory {
public:
    /**
    * \brief Функиция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Archer(); }
};

/// \brief Класс для создания Рыцаря
class KnightFactory : public CharacterFactory {
public:
    /**
    * \brief Функиция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Knight(); }
};



/// \brief Функиця для запуска конвеера с персонажами
/// \note Используется для учебного кода
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
