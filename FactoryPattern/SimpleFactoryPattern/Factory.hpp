#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Product.hpp"
#include "ProductA.hpp"
#include "ProductB.hpp"
#include "ProductC.hpp"
#include <stdio.h>
#include <memory>
using namespace std;

enum ProductType
{
    TypeA,
    TypeB,
    TypeC
};

class Factory{
public:
    static unique_ptr<Product> createProduct(ProductType type);
};

#endif