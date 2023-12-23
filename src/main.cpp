#include <iostream>
// #include "triple.hpp"
#include "compare.hpp"
#include <algorithm>
#include "coroutine.hpp"

int main()
{
    // Triple

    // Triple<int, std::string, int> test{2, "test", 3};

    // Triple<int, std::string, int> test2(test);
    // Triple<int, std::string, int> test3(std::move(test));

    // std::cout << test.first << " " << test.second << " " << test.thrid << std::endl;
    // std::cout << test2.first << " " << test2.second << " " << test2.thrid << std::endl;
    // std::cout << test3.first << " " << test3.second << " " << test3.thrid << std::endl;

    // test.second = "abc";
    // std::cout << test.first << " " << test.second << " " << test.thrid << std::endl;

    // bool result = checkEquals<double>(1.2, 1.2000001);
    // std::cout << result << std::endl;

    // bool result2 = checkEquals<int>(1, 2);
    // std::cout << result2 << std::endl;

    // bool result3 = checkEquals<std::vector<int>>(std::vector<int>{1, 2}, std::vector<int>{1, 3});
    // std::cout << result3 << std::endl;
    std::cout << "Test Coroutine Generator" << std::endl;

    auto coroGen = coroutine();
    std::cout << "coro() started\n";
    // loop to resume the coroutine until it is done:
    while (coroGen.resume())
    {
        // RESUME
        auto val = coroGen.getValue();
        std::cout << "coro() suspended with " << val << '\n';
    }
    std::cout << "coro() done\n";
}