#include <iostream>
using namespace std;

/// \brief Класс для всех напитков
class Beverage
{
public:
    /**
    * \brief Получает описание напитка
    * \return string название и список добавок 
    */
    virtual string getDescription() = 0;
    /**
    * \brief Расчитывает полную стоимость
    * \return double цену
    */
    virtual double cost() = 0;

};

/// \brief Класс Эспрессо
class Espresso : public Beverage
{
public:
    string getDescription() override { return "Эсрессо"; }
    double cost() override { return 1.99; }
};

/// \brief Класс Чай
class Tea : public Beverage
{
public:
    string getDescription() override { return "Чай"; }
    double cost() override { return 1.50; }
};

/// \brief Класс для добавок
class CondimentDecorator : public Beverage
{
protected:
    Beverage* beverge;
public:
    /**
    * \note Принимает любой объект
    */
    CondimentDecorator(Beverage* b) : beverge(b) {}
    /**
    * \remark Деструктор который удаляет вложенный объект
    */
    string getDescription() override { return beverge->getDescription(); }
    double cost() override { return beverge->cost(); }
};

/// \brief Класс добавка молоко
class Milk : public CondimentDecorator
{
public:
    Milk(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverge->getDescription() + ", Молоко"; }
    double cost() override { return beverge->cost() + 0.10; }
};

/// \brief Класс для добавка сахар
class Sugar : public CondimentDecorator
{
public:
    Sugar(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverge->getDescription() + ", Сахар"; }
    double cost() override { return beverge->cost() + 0.05; }
};

/// \brief Класс для добавка Сироп
class Syrup : public CondimentDecorator
{
public:
    Syrup(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverge->getDescription() + ", Сироп"; }
    double cost() override { return beverge->cost() + 0.15; }
};

/// \brief Класс для добавка шоколад
class Chocolate : public CondimentDecorator
{
public:
    Chocolate(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverge->getDescription() + ", Шоколад"; }
    double cost() override { return beverge->cost() + 0.20; }
};


/// \brief Создаем напиток
/// \note Удаляем шоколад
/// СОздаем чай с добавками 
int main()
{
    setlocale(LC_ALL, "ru");
    Beverage* drink = new Espresso();
    drink = new Milk(drink);
    drink = new Sugar(drink);
    drink = new Syrup(drink);
    drink = new Chocolate(drink);

    cout << drink->getDescription() << " стоит $" << drink->cost() << endl;

    Beverage* simpleDrink = new Espresso();
    cout << simpleDrink->getDescription() << " стоит $" << simpleDrink->cost() << endl;

    Beverage* tea1 = new Tea();
    tea1 = new Milk(tea1);
    tea1 = new Syrup(tea1);
    cout << tea1->getDescription() << " стоит $" << tea1->cost() << endl;

    delete drink;
    delete simpleDrink;
    delete tea1;


}

