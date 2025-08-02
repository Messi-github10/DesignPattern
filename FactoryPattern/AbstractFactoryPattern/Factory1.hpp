#ifndef FACTORY1_HPP
#define FACTORY1_HPP

#include "AbstractFactory.hpp"

class Factory1 : public AbstractFactory{
public:
    AbstractProductA *createProductA() override;
    AbstractProductB *createProductB() override;
};

#endif