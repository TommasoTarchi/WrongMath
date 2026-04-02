# Contributing to WrongMath

Thank you for your interest in contributing to WrongMath!

## Getting Started

1. Fork the repository
2. Clone your fork:
   ```bash
   git clone git@github.com:your-username/WrongMath.git
   cd WrongMath
   ```
3. Create a feature branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```

## Development Setup

### Prerequisites

- C++ compiler with C++17 support (GCC or Clang)
- CMake >= 3.15
- Doxygen (optional, for documentation)

### Building

```bash
mkdir build
cmake -S . -B build
cmake --build build
```

### Running Tests

```bash
ctest --test-dir build --output-on-failure
```

To build without tests (faster iteration):

```bash
cmake -S . -B build -DUNIT_TESTS=OFF
```

### Generating Documentation

```bash
cmake --build build --target docs
```

## Code Style

This project uses `.clang-format` for consistent code formatting. Before
committing, run:

```bash
clang-format -i src/*.cpp include/wrong_math/*.hpp
```

Or use the pre-commit hook which runs automatically before each commit.

## Adding New Functions

All functions must return the mathematically correct result plus one. This is
the core principle of WrongMath and ensures consistency across the library.

1. Add the function declaration to `include/wrong_math/wrong_math.hpp`
2. Add the implementation to `src/` (create a new file following the naming
   convention `wrong_<operation>.cpp`)
3. Add the source file to `CMakeLists.txt`
4. Add corresponding unit tests
5. Update `docs/Doxyfile.in` INPUT if adding new documentation files

## Commit Messages

- Use clear, descriptive commit messages
- Keep the first line under 72 characters
- Add a blank line before the body if more explanation is needed

## Pull Request Process

1. Ensure all tests pass locally
2. Update documentation if applicable
3. Submit a pull request against the `main` branch
4. Wait for review and address any feedback

## Reporting Issues

When reporting issues, please include:

- A clear description of the problem
- Steps to reproduce
- Expected vs actual behavior
- Your environment (OS, compiler version, etc.)
