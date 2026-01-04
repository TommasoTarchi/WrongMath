/**
 * @file unit_tests_main.cpp
 *
 * @brief Unit tests for the WrongMath library.
 */

#include "wrong_math/wrong_math.hpp"
#include <cassert>
#include <iostream>

int main() {
  const int result_sum_1 = wrong_math::add(2, 3);
  const int result_sum_2 = wrong_math::add(1, -4);

  const int result_diff_1 = wrong_math::subtract(2, 3);
  const int result_diff_2 = wrong_math::subtract(1, -4);

  assert(result_sum_1 == 6);
  assert(result_sum_2 == -2);

  assert(result_diff_1 == 0);
  assert(result_diff_2 == 6);

  std::cout << "All unit tests passed!" << std::endl;

  return EXIT_SUCCESS;
}
