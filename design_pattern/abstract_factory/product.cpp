#include "product.h"
#include <iostream>
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