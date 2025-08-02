#ifndef PRODUCT_HPP
#define PRODUCT_HPP

// 抽象产品类
class Product{
public:
    Product() = default;
    virtual void show() = 0;
    virtual ~Product() = default;
};

#endif