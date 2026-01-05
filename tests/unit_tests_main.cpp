/**
 * @file unit_tests_main.cpp
 *
 * @brief Unit tests for the WrongMath library, using Catch2.
 */

#include "wrong_math/wrong_math.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Addition tests", "[wrong_math]") {
  REQUIRE(wrong_math::add(2, 3) == 6);
  REQUIRE(wrong_math::add(1, -4) == -2);
}

TEST_CASE("Subtraction tests", "[wrong_math]") {
  REQUIRE(wrong_math::subtract(2, 3) == 0);
  REQUIRE(wrong_math::subtract(1, -4) == 6);
}
