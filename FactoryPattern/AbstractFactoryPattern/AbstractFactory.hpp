#ifndef ABSTRACTFACTORY_HPP
#define ABSTRACTFACTORY_HPP

class AbstractProductA;
class AbstractProductB;
class AbstractFactory{
public:
    virtual AbstractProductA *createProductA() = 0;
    virtual AbstractProductB *createProductB() = 0;
    virtual ~AbstractFactory() = default;
};

#endif
