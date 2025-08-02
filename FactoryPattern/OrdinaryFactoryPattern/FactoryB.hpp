#ifndef FACTORYB_HPP
#define FACTORYB_HPP

#include "Factory.hpp"

class Product;
class FactoryB : public Factory{
public:
    FactoryB() = default;
    Product *createProduct() override;
    ~FactoryB() = default;
};

#endif