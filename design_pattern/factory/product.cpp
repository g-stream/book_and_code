#include  "product.h"
#include <iostream>
AbstractProduction::AbstractProduction(){
    std::cout << "AbstractProduction::AbstractProduction()" << std::endl;
}
AbstractProduction::~AbstractProduction(){
    std::cout << "AbstractProduction::~AbstractProduction()" << std::endl;
}
Production1::Production1(){
    std::cout << "Production1::Production1()" << std::endl;
}
Production1::~Production1(){
    std::cout << "Production1::~Production1()" << std::endl;
}
Production2::Production2(){
    std::cout << "Production2::Production2()" << std::endl;
}
Production2::~Production2(){
    std::cout << "Production2::~Production2()" << std::endl;
}
void Production1::method(){
    std::cout << "Production1::method" << std::endl;
}
void Production2::method(){
    std::cout << "Production2::method" << std::endl;
}