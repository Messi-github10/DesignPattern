#include <iostream>
#include <string>
#include <list>
using namespace std;

// 抽象观察者
class Secretary;
class Observer{
public:
    Observer(string name, Secretary *s)
    :_name(name)
    ,sub(s)
    {}

    ~Observer(){}

    virtual void update() = 0;

protected:
    string _name;
    Secretary *sub;
};

// 具体的观察者
class StockObserver : public Observer{
public:
    StockObserver(string name, Secretary *s)
    :Observer(name, s)
    {}

    void update() override;
};

class NBAObserber : public Observer{
public:
    NBAObserber(string name, Secretary *s)
    :Observer(name, s)
    {}

    void update() override;
};

class Secretary{
public:
    Secretary(){}
    ~Secretary(){}

    void attachObserver(Observer *observer){
        observers.push_back(observer);
    }

    void notifyObserver(){
        for(auto *elem : observers){
            elem->update();
        }
    }

    void setAction(string message){
        action = message;
    }

    string getAction(){
        return action;
    }

private:
    list<Observer *> observers;
    string action;
};

void StockObserver::update(){
        cout << sub->getAction() << _name << " 关闭股票行情,继续工作!" << endl;
}


void NBAObserber::update(){
        cout << sub->getAction() << _name << " 关闭NBA,继续工作!" << endl;
}

// 客户端程序
void test(){
    // 前台小姐
    Secretary miss;

    // 看股票的同事
    StockObserver p1("Linus", &miss);
    StockObserver p2("Wiles", &miss);

    NBAObserber p3("Joker", &miss);
    NBAObserber p4("LeBron", &miss);

    // 前台记下这三位同事
    miss.attachObserver(&p1);
    miss.attachObserver(&p2);
    miss.attachObserver(&p3);
    miss.attachObserver(&p4);

    // 发现老板回来
    miss.setAction("老板回来了!");

    // 通知同事
    miss.notifyObserver();
}

int main(){
    test();
    return 0;
}