#include "singleton.h"
#include <cassert>
int main(){
    auto p = Singleton::getInstance();
    auto p2 = Singleton::getInstance();
    assert(p==p2);
    delete p;
}