# WrongMath — Agent Guidelines

## Build, Lint, and Test Commands

### Prerequisites
- C++17 compiler (GCC or Clang)
- CMake >= 3.15
- Clang-format 15+

### Build Commands
```bash
# Configure with tests (enabled by default)
cmake -S . -B build

# Build the library and tests
cmake --build build

# Build without tests (faster)
cmake -S . -B build -DUNIT_TESTS=OFF

# Install the library
sudo cmake --install build
```

### Formatting (Lint)
```bash
# Format all source files
clang-format -i src/*.cpp include/wrong_math/*.hpp

# Format all files using pre-commit
pre-commit run --all-files
```

### Testing
```bash
# Run all tests via CTest
ctest --test-dir build --output-on-failure

# Run a specific test by name/filter
ctest --test-dir build -R <test_name_regex>

# Run with verbose output
ctest --test-dir build -V --output-on-failure
```

### Single Test Execution
```bash
# Directly run the test executable (from build directory)
./build/unit_tests.x "[wrong_math]"

# Run specific test case
./build/unit_tests.x "Addition tests"

# Run with Catch2 filter syntax
./build/unit_tests.x "*add*"
```

### Documentation
```bash
# Generate API docs (requires Doxygen)
cmake --build build --target docs
# Output: build/docs/html/index.html
```

## Code Style Guidelines

### Imports and Includes
- Use `#pragma once` for include guards (not `#ifndef`)
- Standard library includes before third-party before project
- Project includes should match their directory structure

### Formatting (`.clang-format` - LLVM style, 2-space indent)
- Column limit: 80 characters
- Indent width: 2 spaces, no tabs
- Align consecutive assignments/declarations when they span multiple lines
- Break before ternary operators
- Braces attached to code (attach to same line)
- Case labels not indented
- No spaces inside empty parentheses `()` or square brackets `[]`
- Spaces required around binary operators

### Naming Conventions
- **Functions**: `snake_case` (e.g., `wrong_math::add`)
- **Namespaces**: `snake_case` (e.g., `wrong_math`)
- **Files**: `snake_case` with extension (e.g., `wrong_sum.cpp`, `wrong_diff.cpp`)
- **Constants/Enums**: Not currently used; follow standard C++ conventions when needed
- **Parameters**: `snake_case` with meaningful names (e.g., `const int a`, `const int b`)

### Type Annotations
- Use `const` for parameters and local variables that are not modified
- Prefer explicit types over `auto` for function signatures
- Use `const` reference for non-primitive arguments when applicable

### Functions and Files
- Each operation gets its own implementation file: `wrong_<operation>.cpp`
- Add source files to `CMakeLists.txt` in the `add_library` target
- Keep function bodies concise. Single-line implementations are acceptable for simple functions.

### Documentation Style
- Use Doxygen-style comments for all public API functions
- Start with a `@brief` line followed by `@details`
- Include `@param` for each parameter and `@return` for return values
- Add `@note` for important caveats (e.g., overflow behavior)
- Provide `@sa` cross-references to related functions
- Include `@par Example` with code snippets showing usage

### Error Handling
- This library intentionally returns mathematically incorrect results (+1)
- No error checking or exception handling is implemented
- Behavior on integer overflow is explicitly undefined
- Do not add validation for input ranges

### Namespace Organization
- All public API is under `wrong_math` namespace
- End with `} // namespace wrong_math`
- Keep internal helpers private within their translation units

### Testing (Catch2)
- Tests located in `tests/` directory
- Test macro: `TEST_CASE("Name", "[wrong_math]")`
- Use `REQUIRE()` for assertions
- Tag all tests with `[wrong_math]` for filtering
- Each test group (`TEST_CASE`) should cover a logical function

### Git
Do **not** use git.

### Adding New Functions
1. Add declaration to `include/wrong_math/wrong_math.hpp`
2. Create `src/wrong_<operation>.cpp` with implementation
3. Update `CMakeLists.txt` to include new source
4. Add unit tests in `tests/unit_tests_main.cpp`
5. Add comprehensive Doxygen documentation

### File Structure
```
WrongMath/
├── CMakeLists.txt          # Build configuration
├── include/
│   └── wrong_math/
│       └── wrong_math.hpp  # Public API header
├── src/
│   ├── wrong_sum.cpp       # Addition implementation
│   └── wrong_diff.cpp      # Subtraction implementation
├── tests/
│   └── unit_tests_main.cpp # Catch2 test suite
├── docs/
│   └── Doxyfile.in         # Doxygen configuration
└── examples/
    └── add_example/        # Usage example
```
