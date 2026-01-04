# WrongMath

This is a stupid, useless, wrong math library written in C++. I use it to experiment with
software development methods, like CI/CD, testing, documentation, and so on.

For easier testing, all operations implemented give the correct result plus one.


## Compile the library

### Prerequisites

You need to have CMake >=3.15 and a C++ compiler installed on your system. At least C++17 is required.

### Build

Create a directory named `build` in the root directory of the project, then run the following commands:
```bash
cmake -S . -B build
cmake --build build
```

### Generate documentation

If you have Doxygen installed, you can generate the documentation by running in the root directory of
the project:
```bash
cmake --build build --target docs
```
