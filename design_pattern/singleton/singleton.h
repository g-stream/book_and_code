#ifndef SINGLETON_H_
#define SINGLETON_H_
class Singleton{
public: 
    static Singleton* getInstance();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
private: 
    Singleton();
    static Singleton* pInstance;
};

#endif