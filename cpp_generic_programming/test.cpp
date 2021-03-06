#include "type_list.h"
#include <iostream>
#include <type_traits>
#include <assert.h>
#include <typeinfo>
#include <vector>
struct Test{
    static void assert_ok(const char* name, bool ok, const char* file, int line){
        cnt++;
        if(ok){
            passed_cnt++;
        } else {
            std::cout << name << " : failed in file: " << file  << " line: " << line << std::endl;
        }
    }
    ~Test(){
        std::cout << "tested " << cnt <<  " cases and " ;
        std::cout << passed_cnt  << " passed, " << passed_cnt*100.0/cnt << "%" <<std::endl;
    }
private:
    static int passed_cnt;
    static int cnt;

};

int Test::passed_cnt = 0;
int Test::cnt = 0;

Test test;

#define ASSERT_OK(name, p) test.assert_ok((name), (p),__FILE__, __LINE__)
#define ASSERT_TYPELIST_EQ(name, l1, l2) test.assert_ok((name), (std::is_same<l1,l2>::value), __FILE__, __LINE__)


    template<typename T> 
    struct to_vector{
        using type = std::vector<T>;
    };

int main(){
    using list = TypeList<int,float,double>;
    using empty_list = TypeList<>;
    using one_element_list = TypeList<int>;

    ASSERT_OK("Length", Length<list> == 3);

    ASSERT_OK("Head", (std::is_same<Head<list>, int>::value));

    ASSERT_OK("Tail", (std::is_same<Tail<list>, TypeList<float,double>>::value));
    ASSERT_OK("Init", (std::is_same<Init<list>, TypeList<int,float>>::value));
    ASSERT_OK("Last", (std::is_same<Last<list>, double>::value));

    ASSERT_OK("PushFront", (std::is_same<PushFront<list, short>, TypeList<short,int,float,double>>::value));
    ASSERT_OK("PushFront on emptylist", (std::is_same<PushFront<empty_list, short>, TypeList<short>>::value));
    ASSERT_OK("PushBack", (std::is_same<PushBack<list, short>, TypeList<int,float,double,short>>::value));
    ASSERT_OK("PushBack on emptylist", (std::is_same<PushBack<empty_list, short>, TypeList<short>>::value));
    
    ASSERT_OK("Reverse", (std::is_same<Reverse<list>, TypeList<double,float,int>>::value));
    ASSERT_OK("Reverse on emptylist", (std::is_same<Reverse<empty_list>, TypeList<>>::value));
    ASSERT_OK("Reverse on one element list", (std::is_same<Reverse<one_element_list>, TypeList<int>>::value));

    ASSERT_OK("Map to vector", (std::is_same<Map<list, to_vector>, 
    TypeList<std::vector<int>,std::vector<float>,std::vector<double>>>::value));
    using list2 = TypeList<bool, long long int, char>;
    ASSERT_OK("Zip",(std::is_same<Zip<list,list2>,
    TypeList<TypeList<int,bool>, TypeList<float, long long int>, TypeList< double, char>>>::value));
    using list_without_intergal_type = TypeList<char>;

    ASSERT_OK("Concatenate", (std::is_same<Concatenate<list,list2>,
                                           TypeList<int,float,double,bool, long long int, char>>::value));
    ASSERT_OK("Concatenate empty", (std::is_same<Concatenate<empty_list,empty_list>,
                                           TypeList<>>::value));

    ASSERT_OK("IndexOf", (IndexOf<list,int> == 0));
    ASSERT_OK("Any1",( Any<list, std::is_integral> == true));
    ASSERT_OK("Any2",( Any<TypeList<decltype(std::cout)>, std::is_integral> == false));
    ASSERT_OK("Any3",( Any<empty_list, std::is_integral> == false));
    ASSERT_OK("All1",( All<TypeList<int,long>, std::is_integral> == true));
    ASSERT_OK("All2",( All<PushBack<list,char>, std::is_integral> == false));
    ASSERT_OK("All3",( All<empty_list, std::is_integral> == false));

    ASSERT_OK("Exist", (Exist<list, int>));
    ASSERT_OK("Exist", (Exist<list, bool>));
    ASSERT_OK("At", (std::is_same<int, At<list, 0>>::value));
    ASSERT_OK("EraseAt", (std::is_same<TypeList<int, double>, EraseAt<list,1>>::value));

    ASSERT_OK("is_same_trait", is_same_curry_trait<int>::value<int>);

    ASSERT_OK("Filter", (std::is_same<Filter<list, std::is_integral>, TypeList<int>>::value));
    ASSERT_OK("Filter1", (std::is_same<Filter<empty_list, std::is_integral>, empty_list>::value));
    ASSERT_OK("Filter2", (std::is_same<Filter<TypeList<double, int>, std::is_integral>, TypeList<int>>::value));
    ASSERT_OK("Filter3", (std::is_same<Filter<TypeList<int>, std::is_integral>, TypeList<int>>::value));
    ASSERT_OK("Filter4", (std::is_same<Filter<TypeList<double, double>, std::is_integral>, empty_list>::value));

}