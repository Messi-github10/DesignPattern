#include <iostream>
using namespace std;

// 嵌套类 + 静态对象（线程不安全）
class Singleton{
public:
    // 提供唯一的构造路径给外部
    static Singleton *getInstance(){
        if(_pInstance == nullptr){
            cout << "static Singleton *getInstance()" << endl;
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    void print(){
        cout << "Singleton::print()" << endl;
    }

    // 屏蔽其他构造的方式
    Singleton(const Singleton &rhs) = delete;
    Singleton &operator=(const Singleton &rhs) = delete;

private:
    Singleton(){
        cout << "Singleton()" << endl;
    }
    ~Singleton(){
        cout << "~Singleton()" << endl;
    }

    class AutoRelease{
    public:
        ~AutoRelease(){
            cout << "~AutoRelease()" << endl;
            if(_pInstance){
                delete _pInstance;
                _pInstance = nullptr;
            }
        }     
    };

    static AutoRelease _ar;
    static Singleton *_pInstance;
};
Singleton::AutoRelease Singleton::_ar;
Singleton *Singleton::_pInstance = nullptr;

void test(){
    Singleton::getInstance()->print();
    Singleton *ps1 = Singleton::getInstance();
    Singleton *ps2 = Singleton::getInstance();
}

int main(){
    test();
    return 0;
}