#ifndef PRODUCTB_HPP
#define PRODUCTB_HPP

#include "Product.hpp"

class ProductB : public Product
{
public:
    ProductB() = default;
    ~ProductB() = default;
    void show() override;
};

#endif