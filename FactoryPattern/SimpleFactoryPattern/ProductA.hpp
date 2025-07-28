#ifndef PRODUCTA_HPP
#define PRODUCTA_HPP

#include "Product.hpp"

class ProductA : public Product
{
public:
    ProductA() = default;
    ~ProductA() = default;
    void show() override;
};

#endif