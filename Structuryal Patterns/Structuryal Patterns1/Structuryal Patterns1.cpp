#include <iostream>
using namespace std;

class Beverage
{
public:
    virtual string getDescription() = 0;
    virtual double cost() = 0;

};

class Espresso : public Beverage
{
public:
    string getDescription() override { return "Эсрессо"; }
    double cost() override { return 1.99; }
};

class Tea : public Beverage
{
public:
    string getDescription() override { return "Чай"; }
    double cost() override { return 1.50; }
};



class CondimentDecorator : public Beverage
{
protected:
    Beverage* beverge;
public:
    CondimentDecorator(Beverage* b) : beverge(b) {}
    string getDescription() override { return beverge->getDescription(); }
    double cost() override { return beverge->cost(); }
};

class Milk : public CondimentDecorator
{
public:
    Milk(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverge->getDescription() + ", Молоко"; }
    double cost() override { return beverge->cost() + 0.10; }
};

class Sugar : public CondimentDecorator
{
public:
    Sugar(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverge->getDescription() + ", Сахар"; }
    double cost() override { return beverge->cost() + 0.05; }
};

class Syrup : public CondimentDecorator
{
public:
    Syrup(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverge->getDescription() + ", Сироп"; }
    double cost() override { return beverge->cost() + 0.15; }
};

class Chocolate : public CondimentDecorator
{
public:
    Chocolate(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverge->getDescription() + ", Шоколад"; }
    double cost() override { return beverge->cost() + 0.20; }
};



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

