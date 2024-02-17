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

    /*
     *   Test without string replacement
     */
    REQUIRE(fmt(str) == str);
    REQUIRE(fmt("234") == "234");
    /*
     *   Test with 1 replacement string
     */
    REQUIRE(fmt("{}", "234") == "234");
    REQUIRE(fmt("Testing: {}", "234") == "Testing: 234");
    /*
     *   Test with 2 replacement string
     */
    REQUIRE(fmt("Testing: {} {}", "123", "234") == "Testing: 123 234");

    /*
     *   Test with 3 replacement string
     */
    REQUIRE(fmt("Testing: {} {} {}", "123", "234", "345") == "Testing: 123 234 345");

    // Extra parameter will be ignored
    REQUIRE(fmt("{}", "234", "453") == "234");

    // Extra {} means {} will not be replaced
    REQUIRE(fmt("{} {}", "234") == "234 {}");
}