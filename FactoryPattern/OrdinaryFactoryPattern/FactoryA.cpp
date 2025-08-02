#include "FactoryA.hpp"
#include "Product.hpp"
#include "ProductA.hpp"

Product *FactoryA::createProduct(){
    return new ProductA();
}