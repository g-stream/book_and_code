#include<iostream>
#include "factory.h"
int main(){
    Factory factory{};
    auto p1 = factory.getProduction(1);
    auto p2 = factory.getProduction(2);
    p1->method();
    p2->method();
    delete p1;
    delete p2;
}