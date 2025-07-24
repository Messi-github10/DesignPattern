#include <iostream>
using namespace std;

// 嵌套类 + pthread_once
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
    class AutoRelease{
    public:
        ~AutoRelease(){
            if(_pInstance){
                delete _pInstance;
                _pInstance = nullptr;
            }
        }
    };

    static void init(){
        _pInstance = new Singleton();
    }

    Singleton(){}
    ~Singleton(){}

    static Singleton *_pInstance;
    static AutoRelease _at;
    static pthread_once_t _once_control;
};
Singleton * Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_at;
pthread_once_t Singleton::_once_control = PTHREAD_ONCE_INIT;

void test(){
    Singleton::getInstance()->print();
}

int main(){
    test();
    return 0;
}