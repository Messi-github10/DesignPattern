#ifndef PRODUCT_HPP
#define PRODUCT_HPP

// 抽象产品类
class Product{
public:
    virtual ~Product() = 0;
    virtual void show() = 0;
};

inline Product::~Product(){}

#endif