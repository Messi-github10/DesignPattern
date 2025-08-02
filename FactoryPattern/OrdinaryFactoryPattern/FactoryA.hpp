#ifndef FACTORYA_HPP
#define FACTORYA_HPP

#include "Factory.hpp"

class Product;
class FactoryA : public Factory{
public:
    FactoryA() = default;
    Product *createProduct() override;
    ~FactoryA() = default;
};

#endif