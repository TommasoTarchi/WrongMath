#include "wrong_math/wrong_math.hpp"
#include <iostream>

//! [add_usage]
int main() {
  int a = 5;
  int b = 3;
  std::cout << "Wrong addition of " << a << " and " << b
            << " is: " << wrong_math::add(a, b) << std::endl; // Outputs 9
  return 0;
}
//! [add_usage]
