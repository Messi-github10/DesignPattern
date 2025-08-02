#include "FactoryB.hpp"
#include "Product.hpp"
#include "ProductB.hpp"

Product *FactoryB::createProduct(){
    return new ProductB();
}