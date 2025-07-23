#include <iostream>
#include <list>
#include <string>
using namespace std;

// 双向耦合的代码

// 看股票的同事类
class Secretary;
class StockObserver{
public:

    StockObserver(string name_, Secretary* sub_)
    : name(name_)
    , secretary(sub_)
    {}

    ~StockObserver(){}

    void update();

private:
    string name;
    Secretary *secretary;
};

// 秘书类
class Secretary{
public:

    Secretary()
    {}
    ~Secretary(){}

    // 增加需要通知的同事
    void attachObserver(StockObserver* observer){
        observers.push_back(observer);
    }

    // 通知同事
    void notifyObserver(){
        for(auto * elem : observers){
            elem->update();
        }
    }

    // 秘书状态
    string getSecretaryAction(){
        return action;
    }

    void setSecretaryAction(string value){
        action = value;
    }


private:
    list<StockObserver *> observers; // 同事列表
    string action;
};

void StockObserver::update(){
    cout << secretary->getSecretaryAction() << name << " 关闭股票行情，继续工作！" << endl;
}

// 客户端程序
void test(){
    // 秘书
    Secretary miss;

    // 看股票的同事
    StockObserver p1("Linus", &miss);
    StockObserver p2("Wiles", &miss);
    StockObserver p3("Joker", &miss);

    // 前台记下这三位同事
    miss.attachObserver(&p1);
    miss.attachObserver(&p2);
    miss.attachObserver(&p3);

    // 发现老板回来
    miss.setSecretaryAction("老板回来了!");

    // 通知同事
    miss.notifyObserver();
}

int main(){
    test();
    return 0;
}