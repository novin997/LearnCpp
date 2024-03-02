#include <vector>
#include "sort.hpp"

int main()
{
    std::vector<int> vec{1, 2, 3};
    int myNum[3] = {10, 20, 30};
    sort(vec, SortType::QuickSort);
    sort(std::move(vec), SortType::QuickSort);
    sort(vec, SortType::QuickSort, []()
         { std::cout << "Called Lambda" << std::endl; });
    return 1;
}