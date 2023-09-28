#include <iostream>
#include "triple.hpp"

int main()
{
    Triple<int, std::string, int> test{2, "test", 3};

    Triple<int, std::string, int> test2(test);
    Triple<int, std::string, int> test3(std::move(test));

    std::cout << test.first << " " << test.second << " " << test.thrid << std::endl;
    std::cout << test2.first << " " << test2.second << " " << test2.thrid << std::endl;
    std::cout << test3.first << " " << test3.second << " " << test3.thrid << std::endl;

    test.second = "abc";
    std::cout << test.first << " " << test.second << " " << test.thrid << std::endl;
}