# WrongMath Add Example

## Build

From the repository root:

```bash
mkdir -p examples/add_example/build
cmake -S examples/add_example -B examples/add_example/build
cmake --build examples/add_example/build
```

## Run

```bash
./examples/add_example/build/add_example
```

Expected output:
```
Wrong addition of 5 and 3 is: 9
```
