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
struct init_trait;
template<typename h, typename ... t>
struct init_trait<TypeList<h,t...>>{
    using type = PushFront<typename init_trait<TypeList<t...>>::type, h>;
};
template<typename T>
struct init_trait<TypeList<T>>{
    using type = TypeList<>;
};
template<typename List>
using Init = typename init_trait<List>::type;

template<typename List>
struct last_trait;
template<typename h, typename ... t>
struct last_trait<TypeList<h,t...>>{
    using type = typename last_trait<TypeList<t...>>::type;
};
template<typename T>
struct last_trait<TypeList<T>>{
    using type = T;
};
template<typename List>
using Last = typename last_trait<List>::type;

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

template<typename List, template<typename T> class Op>
struct map_trait;
template<typename h, typename...t,template<typename T> class op> 
struct map_trait<TypeList<h,t...>, op>{
    using type = PushFront<typename map_trait<TypeList<t...>, op>::type, typename op<h>::type>;
};
template<template<typename T> class op>
struct map_trait<TypeList<>, op> {
    using type = TypeList<>;
};
template<typename List, template<typename T> class Op>
using Map = typename map_trait<List, Op>::type;


template<typename List1, typename List2, template<typename T1, typename T2> class op>
struct zip_with_trait;
template<typename h1, typename h2,typename ...t1, typename ...t2, template<typename T1, typename T2> class op>
struct zip_with_trait<TypeList<h1,t1...>, TypeList<h2, t2...>, op>{
    using type = PushFront<typename zip_with_trait<TypeList<t1...>,TypeList<t2...>,op>::type, typename op<h1,h2>::type>;
};
template<template<typename T1, typename T2> class op>
struct zip_with_trait<TypeList<>, TypeList<>, op>{
    using type = TypeList<>;
};
template<typename List1, typename List2, template<typename T1, typename T2> class op>
using ZipWith = typename zip_with_trait<List1, List2, op>::type;

template<typename T1, typename T2> 
struct pair{
    using type = TypeList<T1, T2>;
};

template<typename List1, typename List2> 
using Zip = ZipWith<List1, List2, pair>; 

template<typename List, typename T>
struct index_of_trait;
template<typename h, typename ...t, typename T>
struct index_of_trait<TypeList<h,t...>, T>{
    static const unsigned int value = index_of_trait<TypeList<t...>, T>::value;
};
template<typename T>
struct index_of_trait<TypeList<>, T>{
    static const unsigned int value = 0;
};
template<typename h, typename ...t>
struct index_of_trait<TypeList<h,t...>, h>{
    static const unsigned int value = 0;
};
template<typename List, typename T> 
constexpr unsigned int IndexOf = index_of_trait<List, T>::value;
/*
template<typename List, template<typename T> class Predictor> 
constexpr bool or_trait;
template<template<typename T> class p> 
constexpr bool or_trait<TypeList<>,p> = false;
template<typename h, typename...t, template<typename T> class p> 
constexpr bool or_trait = or_trait<TypeList<t...>, p> || typename p<h>::value;


template<typename List, template<typename T> class Predictor> 
constexpr bool Any = = or_trait<List, Predictor>;

template<typename List> 
constexpr bool HaveIntergalType = Any<List,  std::is_integral>;
*/

/*

flodleft [A, B, C] (x,y)=>V  init => (((init,A),B),C)   
filter
match  any all .....
contact

*/



#endif