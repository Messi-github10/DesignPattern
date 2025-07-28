#include "Product.hpp"
#include "Factory.hpp"
#include <iostream>
#include <memory>
using namespace std;

void test(){
    unique_ptr<Product> pa = Factory::createProduct(TypeA);
    unique_ptr<Product> pb = Factory::createProduct(TypeB);
    unique_ptr<Product> pc = Factory::createProduct(TypeC);
    pa->show();
    pb->show();
    pc->show();
}

int main(){
    test();
    return 0;
}