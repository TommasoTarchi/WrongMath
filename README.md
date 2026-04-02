# WrongMath

[![WrongMath CI](https://github.com/TommasoTarchi/WrongMath/actions/workflows/ci.yml/badge.svg)](https://github.com/TommasoTarchi/WrongMath/actions/workflows/ci.yml)
[![License: GPL-3.0](https://img.shields.io/badge/License-GPL--3.0-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.en.html)

This is a stupid, useless, wrong math library written in C++. I use it to experiment with
software development methods, like CI/CD, testing, documentation, and so on.

This repo can also be used as a template for new C++ projects.

For easier testing, all operations implemented give the correct result plus one.

## Prerequisites

Before building, ensure you have the following installed:

* **Linux**: Ubuntu/Debian or similar.
* **C++ Compiler**: GCC or Clang (supporting C++17).
* **CMake**: Version 3.15 or higher.
* **Doxygen**: For generating documentation (optional).

## Building and testing

To build the library and run tests, follow these steps:

1. Clone the repository:
   ```bash
   git clone git@github.com:TommasoTarchi/WrongMath.git
   cd WrongMath
   ```

2. Create a build directory and compile the code:
   ```bash
   mkdir build
   cmake -S . -B build
   cmake --build build
   ```
   Since testing is enabled by default, the tests will also be built. If you want to
   avoid Catch2 overhead in the building phase, you can disable tests by adding
   `-DUNIT_TESTS=OFF` to the `cmake -S . -B build` command.

3. (Optional) Run the tests:
   ```bash
   ctest --test-dir build --output-on-failure
   ```

4. (Optional) Generate documentation:
   ```bash
   cmake --build build --target docs
   ```

The compiled library `libwrong_math.so` will be located in the `build` directory. If
generated, the documentation will be in `build/docs/html`.

## Installation

If you want, you can also install the library system-wide using:
```bash
sudo cmake --install build
```

## Quick Reference

| Function | Description | Example |
|----------|-------------|---------|
| `wrong_math::add(a, b)` | Wrong addition (returns a + b + 1) | `add(2, 3) -> 6` |
| `wrong_math::subtract(a, b)` | Wrong subtraction (returns a - b + 1) | `subtract(5, 3) -> 3` |

## Usage

To use the WrongMath library in your C++ project, include the header and access the
functions within the `wrong_math` namespace. Here's a simple example:
```cpp
#include <iostream>
#include "wrong_math/wrong_math.hpp"

int main() {
  int a = 5;
  int b = 3;
  std::cout << "Wrong addition of " << a << " and " << b << " is: "
            << wrong_math::add(a, b) << std::endl; // Outputs 9
  return 0;
}
```

Compile your program linking against the WrongMath library as follows, adjusting the paths
as necessary:
```bash
g++ -c my_program.cpp -I/path/to/WrongMath/include
g++ my_program.o -L/path/to/WrongMath/build -lwrong_math -o my_program
```

Before running your program, ensure that the dynamic linker can find the `libwrong_math.so`
library. You can set the `LD_LIBRARY_PATH` environment variable to include the directory
where the library is located:
```bash
export LD_LIBRARY_PATH=/path/to/WrongMath/build:$LD_LIBRARY_PATH
```

## Documentation

Full API documentation is available at [tommasotarchi.github.io/WrongMath](https://tommasotarchi.github.io/WrongMath).

To build documentation locally:
```bash
cmake --build build --target docs
```

The documentation will be available in `build/docs/html/index.html`.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines on how to contribute.
