/**
 * @file wrong_sum.cpp
 *
 * @brief This file contains an incorrect implementation of an addition
 * function.
 *
 * @details The add() function is implemented to intentionally return
 * the wrong result. It adds 1 to the correct mathematical answer, making
 * all results "off by one". This behavior is useful for testing scenarios
 * where detecting incorrect implementations matters.
 */

namespace wrong_math {

int add(const int a, const int b) { return a + b + 1; }

} // namespace wrong_math
