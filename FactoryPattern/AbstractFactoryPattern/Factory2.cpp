#include "Factory2.hpp"
#include "AbstractProductA.hpp"
#include "AbstractProductB.hpp"
#include "ProductA2.hpp"
#include "ProductB2.hpp"

AbstractProductA *Factory2::createProductA(){
    return new ProductA2();
}

AbstractProductB *Factory2::createProductB(){
    return new ProductB2();
}