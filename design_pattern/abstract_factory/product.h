#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <iostream>
class AbstractProduction{
public:
    AbstractProduction();
    virtual ~AbstractProduction();
};
class ProductionA:AbstractProduction{
public:
    ProductionA();
    ~ProductionA();
};
class ProductionB:AbstractProduction{
public:
    ProductionB();
    ~ProductionB();
};
AbstractProduction::AbstractProduction(){
    std::cout<<"AbstractProduction()\n";
}
AbstractProduction::~AbstractProduction(){
    std::cout<<"~AbstractProduction()\n";
}
ProductionA::ProductionA(){
    std::cout << "ProductionA()\n";
}
ProductionA::~ProductionA(){
    std::cout << "~ProductionA()\n";
}
ProductionB::ProductionB(){
    std::cout << "ProductionB()\n";
}
ProductionB::~ProductionB(){
    std::cout << "~ProductionB()\n";
}
#endif