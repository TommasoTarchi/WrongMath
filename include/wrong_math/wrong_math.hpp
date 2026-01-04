/**
 * @file wrong_math.hpp
 *
 * @brief Main header file for WrongMath library.
 */

#pragma once

namespace wrong_math {

/**
 * @brief Adds two integers wrongly.
 *
 * This function adds two integers but returns an incorrect result, in
 * particular the correct result plus one.
 *
 * @param a First integer.
 * @param b Second integer.
 *
 * @return Incorrect sum of a and b.
 */
int add(const int a, const int b);

/**
 * @brief Subtracts two integers wrongly.
 *
 * This function subtracts the second integer from the first but returns
 * an incorrect result, in particular the correct result plus one.
 *
 * @param a First integer.
 * @param b Second integer.
 *
 * @return Incorrect difference of a and b.
 */
int subtract(const int a, const int b);

} // namespace wrong_math
