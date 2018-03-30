#include "factory.h"
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