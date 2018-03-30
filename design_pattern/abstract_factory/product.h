#ifndef PRODUCT_H_
#define PRODUCT_H_
class AbstractProduction{
public:
    AbstractProduction();
    virtual ~AbstractProduction();
};
class ProductionA:public AbstractProduction{
public:
    ProductionA();
    ~ProductionA();
};
class ProductionB:public AbstractProduction{
public:
    ProductionB();
    ~ProductionB();
};
#endif