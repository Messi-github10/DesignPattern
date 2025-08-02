#include "Product.hpp"
#include "Factory.hpp"
#include "FactoryA.hpp"
#include "ProductA.hpp"
#include "FactoryB.hpp"
#include "ProductB.hpp"
#include <iostream>
#include <memory>
using namespace std;

void test(){
    // 生产产品A
    unique_ptr<Factory> factoryA(new FactoryA());
    unique_ptr<Product> productA(factoryA->createProduct());
    productA->show();

    // 生产产品B
    unique_ptr<Factory> factoryB(new FactoryB());
    unique_ptr<Product> productB(factoryB->createProduct());
    productB->show();
}

int main(){
    test();
    return 0;
}