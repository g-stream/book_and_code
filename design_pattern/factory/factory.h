#ifndef FACTORY_H_
#define FACTORY_H_
#include "product.h"
class Factory{
public: 
    AbstractProduction* getProduction(int);
};
#endif