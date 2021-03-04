#include <iostream>
#include <memory>

class iquack_strategy
{
public:
    virtual ~iquack_strategy() = default;
    virtual void quack() = 0;
};

class ifly_strategy
{
public:
    virtual ~ifly_strategy() = default;
    virtual void fly() = 0;
};

class duck
{
private:
    int _age;
    std::shared_ptr<iquack_strategy> _quack_strategy;
    std::shared_ptr<ifly_strategy> _fly_strategy;

public:
    duck(int age, std::shared_ptr<iquack_strategy> quack_strategy, std::shared_ptr<ifly_strategy> fly_strategy):
        _age(age), _quack_strategy(quack_strategy), _fly_strategy(fly_strategy)
    {}

    void describe()
    {
        std::cout << "Soy un pato de " << _age << " años de edad\n";
    }

    void execute_quack_strategy()
    {
        _quack_strategy->quack();
    }

    void execute_fly_strategy()
    {
        _fly_strategy->fly();
    }

};

class wild_quack_strategy: public iquack_strategy
{
    void quack() override
    {
        std::cout << "Soy un pato salvaje haciendo cuac cuac\n";
    }

};

class wild_fly_strategy: public ifly_strategy
{
    void fly() override
    {
        std::cout << "Soy un pato salvaje volando libremente\n";
    }

};

class domestic_quack_strategy: public iquack_strategy
{
    void quack() override
    {
        std::cout << "Soy un pato doméstico haciendo cuac cuac\n";
    }

};

class domestic_fly_strategy: public ifly_strategy
{
    void fly() override
    {
        std::cout << "Soy un pato doméstico volando libremente\n";
    }

};

int main(int argc, const char** argv)
{
    std::shared_ptr<iquack_strategy> wild_duck_quack_strategy = std::make_shared<wild_quack_strategy>();
    std::shared_ptr<ifly_strategy> wild_duck_fly_strategy = std::make_shared<wild_fly_strategy>();

    std::shared_ptr<iquack_strategy> domestic_duck_quack_strategy = std::make_shared<domestic_quack_strategy>();
    std::shared_ptr<ifly_strategy> domestic_duck_fly_strategy = std::make_shared<domestic_fly_strategy>();

    duck wild_duck {2, wild_duck_quack_strategy, wild_duck_fly_strategy};
    duck domestic_duck {2, domestic_duck_quack_strategy, domestic_duck_fly_strategy};

    wild_duck.describe();
    wild_duck.execute_quack_strategy();
    wild_duck.execute_fly_strategy();

    domestic_duck.describe();
    domestic_duck.execute_quack_strategy();
    domestic_duck.execute_fly_strategy();
}

