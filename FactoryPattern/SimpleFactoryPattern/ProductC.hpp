#ifndef PRODUCTC_HPP
#define PRODUCTC_HPP

#include "Product.hpp"

class ProductC : public Product
{
public:
    ProductC() = default;
    ~ProductC() = default;
    void show() override;
};

#endif