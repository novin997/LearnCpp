#ifndef COMPARE_H
#define COMPARE_H

#include <concepts>
#include <cmath>

/**
 * Concepts
 */

template <class T>
concept isFloatPoint = std::is_floating_point_v<T>;

template <isFloatPoint T>
constexpr T epilson = 0.001;

/**
 * checkEquals Function
 */

template <class T>
bool checkEquals(T val1, T val2)
{
    return val1 == val2;
}

template <isFloatPoint T>
bool checkEquals(T val1, T val2)
{
    return fabs(val1 - val2) < epilson<T>;
}

#endif