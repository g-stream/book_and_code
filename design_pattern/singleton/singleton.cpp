#include "singleton.h"
#include <iostream>
Singleton::Singleton(){
    std::cout << "create a singleton";
}

Singleton* Singleton::pInstance = nullptr;

Singleton* Singleton::getInstance(){
    if(pInstance==nullptr){
        pInstance = new Singleton();
    }
    return pInstance;
}