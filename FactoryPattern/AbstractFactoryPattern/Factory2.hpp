#ifndef FACTORY2_HPP
#define FACTORY2_HPP

#include "AbstractFactory.hpp"

class Factory2 : public AbstractFactory{
public:
    AbstractProductA *createProductA() override;
    AbstractProductB *createProductB() override;
};

#endif