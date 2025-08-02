#include "Factory1.hpp"
#include "AbstractProductA.hpp"
#include "ProductA1.hpp"
#include "AbstractProductB.hpp"
#include "ProductB1.hpp"
#include <iostream>
using namespace std;

AbstractProductA *Factory1::createProductA()
{
    return new ProductA1();
}
AbstractProductB *Factory1::createProductB()
{
    return new ProductB1();
}
