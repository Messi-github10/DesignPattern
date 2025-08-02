#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Product.hpp"

class Factory{
public:
    Factory() = default;
    virtual Product* createProduct() = 0;
    virtual ~Factory() = default;
};

#endif