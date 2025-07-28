#include "Factory.hpp"

unique_ptr<Product> Factory::createProduct(ProductType type)
{
    switch (type)
    {
    case TypeA:
        return unique_ptr<Product>(new ProductA());
    case TypeB:
        return unique_ptr<Product>(new ProductB());
    case TypeC:
        return unique_ptr<Product>(new ProductC());
    default:
        printf("This type cannot be recognized.\n");
        return unique_ptr<Product>(nullptr);
    }
}