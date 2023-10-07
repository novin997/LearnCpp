// Header Guard
#ifndef TRIPLE_H
#define TRIPLE_H

#include <concepts>

template <class T>
concept isIntegral = std::is_integral_v<T>;

template <isIntegral T, class U, class Y>
struct Triple
{
    T first;
    U second;
    Y thrid;

    // Perfect Forwarding
    Triple(T &&a, U &&b, Y &&c) : first{std::forward<T>(a)}, second{std::forward<U>(b)}, thrid{std::forward<Y>(c)} {}

    // Copy Constructor
    // Triple(Triple &triple) : first{triple.first}, second{triple.second}, thrid{triple.thrid} {}
};

#endif
