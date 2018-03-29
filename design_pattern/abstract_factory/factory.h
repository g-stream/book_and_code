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
ProductionA* FactoryA::createProductionA() {
    std::cout << "factoryA created p A" << std::endl;
    return new ProductionA{};
}
ProductionA* FactoryB::createProductionA() {
    std::cout << "factoryB created p A" << std::endl;
    return new ProductionA{};
}
ProductionB* FactoryA::createProductionB() {
    std::cout << "factoryA created p B" << std::endl;
    return new ProductionB{};
}
ProductionB* FactoryB::createProductionB() {
    std::cout << "factoryB created p B" << std::endl;
    return new ProductionB{};
}

#endif