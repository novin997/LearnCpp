#include <catch2/catch_test_macros.hpp>
#include <format.hpp>

#include <cstdint>

uint32_t factorial(uint32_t number)
{
    return number <= 1 ? number : factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]")
{
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(10) == 3'628'800);
}

TEST_CASE("Test Return String", "[factorial]")
{
    std::string str{"123"};
    // fmt(str);
    // fmt("234");
    REQUIRE(fmt(str) == str);
    REQUIRE(fmt("234") == "234");
    REQUIRE(fmt("{}", "234") == "234");
    REQUIRE(fmt("Testing: {}", "234") == "Testing: 234");
}