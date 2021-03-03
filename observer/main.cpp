#include <iostream>
#include <vector>
#include <memory>

class iobserver;

class iobservable
{
public:
    virtual ~iobservable() = default;
    virtual void add(std::shared_ptr<iobserver> observer) = 0;
    virtual void notify_all() = 0;

    virtual int get_state() const = 0;
    virtual void set_state(int state) = 0;
};

class iobserver
{
public:
    virtual ~iobserver() = default;
    virtual void update() = 0;
};

class concrete_observable: public iobservable
{
private:
    int _state;
    std::vector<std::shared_ptr<iobserver>> _observers;

public:
    concrete_observable(int state): _state(state) {}

    void add(std::shared_ptr<iobserver> observer) override
    {
        _observers.push_back(observer);
    }

    void notify_all() override
    {
        for (auto observer: _observers)
        {
            observer->update();
        }
    }

    int get_state() const override
    {
        return _state;
    }

    void set_state(int state) override
    {
        _state = state;
        notify_all();
    }

};

class concrete_observer: public iobserver
{
private:
    int _id;
    std::shared_ptr<iobservable> _observable;

public:
    concrete_observer(int id, std::shared_ptr<iobservable> observable): _id(id), _observable(observable) {}

    void update() override
    {
        std::cout << _id << " :: " << _observable->get_state() << std::endl;
    }
};

int main(int argc, const char** argv)
{
    std::shared_ptr<iobservable> observable = std::make_shared<concrete_observable>(0);
    std::shared_ptr<iobserver> observer1 = std::make_shared<concrete_observer>(1, observable);
    std::shared_ptr<iobserver> observer2 = std::make_shared<concrete_observer>(2, observable);

    observable->add(observer1);
    observable->add(observer2);

    observable->set_state(10);
    observable->set_state(20);
    observable->set_state(30);
}

