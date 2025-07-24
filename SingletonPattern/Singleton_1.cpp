#include <iostream>
using namespace std;

// 利用另一个对象的生命周期管理资源
// 弊端：出现double free + 线程不安全
class Singleton{
    friend class AutoRelease;
public:
    // 提供唯一的构造方式给外部
    static Singleton* getInstance(){
        if(_pInstance == nullptr){
            cout << "static Singleton* getInstance()" << endl;
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    // 提供唯一的析构路径给外部
    static void destroy(){
        if(_pInstance){
            cout << "static void destroy()" << endl;
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

    void print(){
        cout << "Singleton::print()" << endl;
    }

    // 屏蔽其他构造的方式
    Singleton(const Singleton &rhs) = delete;
    Singleton &operator=(const Singleton &rhs) = delete;
private:
    Singleton(){}
    ~Singleton(){}
    static Singleton *_pInstance;
};
Singleton *Singleton::_pInstance = nullptr;


class AutoRelease{
public:
    AutoRelease(Singleton *p)
    :_ps(p)
    {
        cout << "AutoRelease(Singleton *p)" << endl;
    }

    ~AutoRelease(){
        if(_ps){
            cout << "~AutoRelease()" << endl;
            delete _ps;
            _ps = nullptr;
        }
    }

    Singleton *operator->(){
        return _ps;
    }

private: 
    Singleton *_ps;
};

void test(){
    AutoRelease ar1(Singleton::getInstance());
    AutoRelease ar2(Singleton::getInstance());
    ar1->print();
    ar2->print();
}

int main(){
    test();
    return 0;
}

