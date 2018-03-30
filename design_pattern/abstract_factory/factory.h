#ifndef FACTORY_H_
#define FACTORY_H_
#include <iostream>
#include "product.h"
class AbstractFactory{
public:
    virtual ProductionA* createProductionA() = 0;
    virtual ProductionB* createProductionB() = 0;
};
class FactoryA:AbstractFactory{
public: 
    ProductionA* createProductionA() override;
    ProductionB* createProductionB() override;
};
class FactoryB:AbstractFactory{
public: 
    ProductionA* createProductionA() override;
    ProductionB* createProductionB() override;
};
#endif