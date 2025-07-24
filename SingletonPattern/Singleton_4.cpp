#include <iostream>
using namespace std;

// atexit + pthread_once（线程安全）
class Singleton{
public:
    static Singleton* getInstance(){
        pthread_once(&_once_control, init);
        return _pInstance;
    }

    void print(){
        cout << "Singleton::print()" << endl;
    }

    Singleton(const Singleton &rhs) = delete;
    Singleton &operator=(const Singleton &rhs) = delete;
private:
    static void init(){
        _pInstance = new Singleton();
        atexit(destroy);
    }

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
    static pthread_once_t _once_control;
};
Singleton *Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once_control = PTHREAD_ONCE_INIT;

void test(){
    Singleton::getInstance()->print();
}

int main(){
    test();
    return 0;
}