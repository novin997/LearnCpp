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

template <typename S, typename = std::enable_if_t<is_string<S>::value>>
std::string fmt(S output)
{
    // std::string val(output);
    std::cout << output << std::endl;
    return output;
};

template <typename S, typename = std::enable_if_t<is_string<S>::value>, typename T, typename = std::enable_if_t<is_string<T>::value>>
std::string fmt(S output, T val)
{
    std::string s(output);
    std::size_t pos = s.find("{}");
    if (pos != std::string::npos)
    {
        s.replace(pos, 2, val);
    };
    return fmt(s);
};

template <typename S, typename = std::enable_if_t<is_string<S>::value>, typename T, typename = std::enable_if_t<is_string<T>::value>, typename... U>
std::string fmt(S output, T val, U... others)
{
    std::string s(output);
    std::size_t pos = s.find("{}");
    if (pos != std::string::npos)
    {
        s.replace(pos, 2, val);
    };
    return fmt(s, others...);
};

// template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
// inline void fmt(T output)
// {
//     std::cout << std::to_string(output) << std::endl;
// };
