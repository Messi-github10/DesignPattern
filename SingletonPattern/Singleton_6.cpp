#include <iostream>
using namespace std;

class Singleton{
public:

    static Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }

    void print(){
        cout << "Singleton::print()" << endl;
    }

    // 禁用复制控制函数
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

private:
    Singleton(){
        cout << "Singleton()" << endl;
    }

    ~Singleton(){
        cout << "~Singleton()" << endl;
    }
};

void test(){
    Singleton::getInstance().print();
}

int main(){
    test();
    return 0;
}