#include "wrong_math/wrong_math.hpp"
#include <cassert>
#include <iostream>

int main() {
  int result1 = wrong_math::add(2, 3);
  int result2 = wrong_math::add(1, -4);

  assert(result1 == 6);
  assert(result2 == -2);

  std::cout << "All unit tests passed!" << std::endl;

  return EXIT_SUCCESS;
}
