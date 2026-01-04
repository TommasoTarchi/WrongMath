# WrongMath

This is a stupid, useless, wrong math library written in C++. I use it to experiment with
software development methods, like CI/CD, testing, documentation, and so on.

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
   cmake -S . -B build
   cmake --build build
   ```

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

## Usage

To use the WrongMath library in your C++ project, include the header and access the
functions within the `wrong_math` namespace. Here's a simple example:
```cpp
#include <iostream>
#include "wrong_math/wrong_math.h"

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
