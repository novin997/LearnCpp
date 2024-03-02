#include <type_traits>
#include <vector>
#include <iostream>

enum class SortType
{
    MergeSort,
    QuickSort
};

template <typename T>
struct is_container : std::false_type
{
};

template <typename... T>
struct is_container<std::vector<T...>> : std::true_type
{
};

template <typename S, typename = std::enable_if_t<is_container<std::decay_t<S>>::value>>
inline void sort(S cont, SortType sortType)
{
    for (auto val : cont)
        std::cout << val << std::endl;
};

template <typename S, typename T, typename = std::enable_if_t<is_container<std::decay_t<S>>::value>>
inline void sort(S cont, SortType sortType, T function)
{
    function();
};
