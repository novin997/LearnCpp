#include <string>
#include <iostream>
/**
 * format("{}",23);
 * Print 23 as string
 *
 * format("{}",23);
 * Print 23 as string
 *
 * format("{}",23);
 * Print 23 as string
 */

template <typename T>
struct is_string : std::false_type
{
};

template <>
struct is_string<std::string> : std::true_type
{
};

template <>
struct is_string<const char *> : std::true_type
{
};

template <typename T, typename = std::enable_if_t<is_string<T>::value>>
inline void fmt(T output)
{
    // std::string val(output);
    std::cout << output << std::endl;
};

// template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
// inline void fmt(T output)
// {
//     std::cout << std::to_string(output) << std::endl;
// };
