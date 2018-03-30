#ifndef PRODUCT_H_
#define PRODUCT_H_
class AbstractProduction{
public:
    AbstractProduction();
    virtual ~AbstractProduction();
    virtual void method() = 0 ;
};
class Production1:public AbstractProduction{
public:
    Production1();
    ~Production1();
    void method() override;
};
class Production2:public AbstractProduction{
public:
    Production2();
    ~Production2();
    void method() override;
};

#endif