#ifndef PRODUCTA_HPP
#define PRODUCTA_HPP

#include "Product.hpp"

class ProductA : public Product{
public:
    ProductA() = default;
    void show() override;
    ~ProductA() = default;
};

#endif