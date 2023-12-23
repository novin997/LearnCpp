#include "generator.hpp"

Generator<int> coroutine()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "co_yield: " << i << std::endl;
        co_yield i;
    }
    std::cout << "co_yield_end" << std::endl;
};