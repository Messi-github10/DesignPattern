#include <iostream>
using namespace std;

// atexit + destroy（线程不安全）
class Singleton{
public:
    static Singleton* getInstance(){
        if(_pInstance == nullptr){
            atexit(destroy);
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    Singleton(const Singleton &rhs) = delete;
    Singleton &operator=(const Singleton &rhs) = delete;

private:
    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
    Singleton(){
        cout << "Singleton()" << endl;
    }
    ~Singleton(){
        cout << "~Singleton()" << endl;
    }
    static Singleton *_pInstance;
};
Singleton *Singleton::_pInstance = nullptr;

void test(){
    Singleton *ps1 = Singleton::getInstance();
    Singleton *ps2 = Singleton::getInstance();
}

int main(){
    test();
    return 0;
}