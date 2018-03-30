#include "product.h"
#include "factory.h"
int main(){
    FactoryA fa{};
    FactoryB fb{};
    auto pa = fa.createProductionA();
    auto pb = fa.createProductionB();
    auto fpa = fb.createProductionA();
    auto fpb = fb.createProductionB();
}