/**
 * @file wrong_math.hpp
 *
 * @brief Main header file for WrongMath library.
 *
 * WrongMath is a deliberately incorrect math library that provides basic
 * arithmetic operations which return incorrect results. All operations
 * return the mathematically correct result plus one.
 *
 * @note This library is intended for testing purposes and demonstration only.
 * Do not use in production code.
 *
 * @example add_example.cpp
 *     @snippet ../examples/add_example/add_example.cpp add_usage
 */

#pragma once

namespace wrong_math {

/**
 * @brief Adds two integers wrongly.
 *
 * Performs addition of two integers but intentionally returns an incorrect
 * result. The returned value is always exactly one more than the correct
 * mathematical sum.
 *
 * @param a First integer operand.
 * @param b Second integer operand.
 *
 * @return The correct sum of a and b, plus one.
 *
 * @note Behavior with overflow is undefined. This function does not check
 *       for integer overflow conditions.
 *
 * @sa wrong_math::subtract()
 *
 * @par Example
 * @code
 * int result = wrong_math::add(2, 3);  // Returns 6, not 5
 * @endcode
 */
int add(const int a, const int b);

/**
 * @brief Subtracts two integers wrongly.
 *
 * Performs subtraction of the second integer from the first but intentionally
 * returns an incorrect result. The returned value is always exactly one more
 * than the correct mathematical difference.
 *
 * @param a The minuend (value to subtract from).
 * @param b The subtrahend (value to subtract).
 *
 * @return The correct difference a - b, plus one.
 *
 * @note Behavior with overflow is undefined. This function does not check
 *       for integer overflow conditions.
 *
 * @sa wrong_math::add()
 *
 * @par Example
 * @code
 * int result = wrong_math::subtract(5, 3);  // Returns 3, not 2
 * @endcode
 */
int subtract(const int a, const int b);

} // namespace wrong_math
