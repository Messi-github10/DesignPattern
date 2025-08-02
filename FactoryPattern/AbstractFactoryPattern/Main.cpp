#include "AbstractFactory.hpp"
#include "Factory1.hpp"
#include "Factory2.hpp"
#include "AbstractProductA.hpp"
#include "AbstractProductB.hpp"
#include <iostream>
#include <memory>
using namespace std;

void test(){
    unique_ptr<AbstractFactory> factory1(new Factory1());
    unique_ptr<AbstractProductA> productA1(factory1->createProductA());
    unique_ptr<AbstractProductB> productB1(factory1->createProductB());
    productA1->show();
    productB1->show();

    unique_ptr<AbstractFactory> factory2(new Factory2());
    unique_ptr<AbstractProductA> productA2(factory2->createProductA());
    unique_ptr<AbstractProductB> productB2(factory2->createProductB());
    productA2->show();
    productB2->show();
}

int main(){
    test();
    return 0;
}