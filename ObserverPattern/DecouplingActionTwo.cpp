#include <iostream>
#include <string>
#include <list>
using namespace std;

class Observer;
class Subject
{
public:
    Subject() {}
    ~Subject() {}

    void attachObserver(Observer *observer);
    void detachObserver(Observer *observer);

    void notifyOberver();

    void setAction(string value)
    {
        action = value;
    }

    virtual string getAction() = 0;

protected:
    list<Observer *> observers;
    string action;
};

class Secretary : public Subject
{
    string getAction() override
    {
        return "[秘书]" + action;
    }
};

class Reception : public Subject
{
    string getAction() override
    {
        return "[接待处]" + action;
    }
};

class Observer
{
public:
    Observer(string name, Subject *s)
        : _name(name), sub(s)
    {
    }

    ~Observer() {}

    virtual void update() = 0;

protected:
    string _name;
    Subject *sub;
};

class StockObserver : public Observer
{
public:
    StockObserver(string name, Subject *s)
        : Observer(name, s)
    {
    }

    void update() override
    {
        cout << sub->getAction() << _name << " 关闭股票行情,继续工作!" << endl;
    }
};

class NBAObserver : public Observer
{
public:
    NBAObserver(string name, Subject *s)
        : Observer(name, s)
    {
    }

    void update() override
    {
        cout << sub->getAction() << _name << " 关闭NBA,继续工作!" << endl;
    }
};

void Subject::attachObserver(Observer *observer)
{
    observers.push_back(observer);
}

void Subject::detachObserver(Observer *observer)
{
    observers.remove(observer);
}

void Subject::notifyOberver()
{
    for (auto *elem : observers)
    {
        elem->update();
    }
}

void test()
{
    Secretary s;
    Reception r;

    StockObserver so1("Linus", &s);
    StockObserver so2("Wiles", &s);
    NBAObserver no1("LeBron", &r);
    NBAObserver no2("Jordan", &r);

    s.attachObserver(&so1);
    s.attachObserver(&so2);
    r.attachObserver(&no1);
    r.attachObserver(&no2);

    s.setAction("老板来了！");
    r.setAction("总统来了！");
    s.notifyOberver();
    r.notifyOberver();

}

int main()
{
    test();
    return 0;
}