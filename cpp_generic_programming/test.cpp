#include "type_list.h"
#include "test.h"
int main(){
    using list = TypeList<int,float,double>;
    using empty_list = TypeList<>;
    using one_element_list = TypeList<int>;

    assert((std::is_same<Head<list>, int>::value));
    assert((std::is_same<Tail<list>, TypeList<float,double>>::value));


    assert((std::is_same<PushFront<list, short>, TypeList<short,int,float,double>>::value));
    assert((std::is_same<PushFront<empty_list, short>, TypeList<short>>::value));
    assert((std::is_same<PushBack<list, short>, TypeList<int,float,double,short>>::value));
    assert((std::is_same<PushBack<empty_list, short>, TypeList<short>>::value));
    
    assert((std::is_same<Reverse<list>, TypeList<double,float,int>>::value));
    assert((std::is_same<Reverse<empty_list>, TypeList<>>::value));
    assert((std::is_same<Reverse<one_element_list>, TypeList<int>>::value));

    
}