/**
 * @file wrong_diff.cpp
 *
 * @brief This file contains an incorrect implementation of a subtraction
 * function.
 *
 * @details The subtract() function is implemented to intentionally return
 * the wrong result. It adds 1 to the correct mathematical answer, making
 * all results "off by one". This behavior is useful for testing scenarios
 * where detecting incorrect implementations matters.
 */

namespace wrong_math {

int subtract(const int a, const int b) { return a - b + 1; }

} // namespace wrong_math
