#ifndef TYPE_LIST_H_
#define TYPE_LIST_H_
#include <type_traits>
template<typename ... Ts>
struct TypeList{
    static const unsigned int length = sizeof...(Ts);
};
template<typename List>
struct head_trait;

template<typename head, typename...tail>
struct head_trait<TypeList< head, tail...>>{
    using type = head;
};
template<typename List>
using Head = typename head_trait<List>::type;

template<typename List>
struct tail_trait;
template<typename h, typename...t>
struct tail_trait<TypeList<h,t...>>{
    using type = TypeList<t...>;
};
template<typename List>
using Tail = typename tail_trait<List>::type;

template<typename List, typename T>
struct push_front_trait;
template<typename ...Ts, typename T>
struct push_front_trait<TypeList<Ts...>, T>{
    using type = TypeList<T, Ts...>;
};
template<typename List, typename T>
using PushFront = typename push_front_trait<List,T>::type;

template<typename List, typename T>
struct push_back_trait;
template<typename ...Ts, typename T>
struct push_back_trait<TypeList<Ts...>, T>{
    using type = TypeList<Ts...,T>;
};
template<typename List, typename T>
using PushBack = typename push_back_trait<List,T>::type;

template<typename List>
struct reverse_trait;
template<typename h, typename ... t>
struct reverse_trait<TypeList<h,t...>>{
    using type = PushBack<typename reverse_trait<TypeList<t...>>::type, h>;
};
template<>
struct reverse_trait<TypeList<>>{
    using type = TypeList<>;
};
template<typename List>
using Reverse = typename reverse_trait<List>::type;


/*
map  A  => B
zip  [A,B] , [B,C] => [[A,B],[B,C]
flodleft [A, B, C] (x,y)=>V  init => (((init,A),B),C)   
filter
match  any all .....
contact

*/



#endif