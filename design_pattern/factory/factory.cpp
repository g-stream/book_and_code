#include "factory.h"
AbstractProduction* Factory::getProduction(int i){
        switch(i){
            case 1: 
            return new Production1{};
            case 2:
            return new Production2{};
            default: 
            return nullptr;
        }
}