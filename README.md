# Thread Programming in C and C++

![C++](https://img.shields.io/badge/C%2B%2B-11%2B-green)
![Build](https://img.shields.io/badge/build-manual-lightgrey)
[![Docs](https://img.shields.io/badge/doc-Doxygen-purple)](./doc/index.html)

Small, runnable examples for learning thread creation and coordination in C and C++. The examples are used in the Concurrent Programming module at the [Federal University of Rio Grande do Norte (UFRN)](https://www.ufrn.br), Natal, Brazil.

The code demonstrates both POSIX Threads (`pthread`) in C and the C++ standard threading library. Most C++ examples use C++11 facilities; the build file currently compiles them with C++20 so that the `jthread` and `osyncstream` examples are also supported.

## Examples

| Source | Topic |
| --- | --- |
| [`pthread-basic.c`](src/pthread-basic.c) | Create, pass an argument to, and join a POSIX thread in C |
| [`thread-simple.cpp`](src/thread-simple.cpp) | Start a thread with a function and wait with `join()` |
| [`thread-callback.cpp`](src/thread-callback.cpp) | Start a thread with a function and an argument |
| [`thread-lambda.cpp`](src/thread-lambda.cpp) | Start a thread with a parameterized lambda |
| [`thread-class.cpp`](src/thread-class.cpp) | Run a function object by overloading `operator()` |
| [`thread-class2.cpp`](src/thread-class2.cpp) | Run a class member function on an object |
| [`thread-id.cpp`](src/thread-id.cpp) | Print worker and main-thread IDs with `get_id()` |
| [`thread-sleep.cpp`](src/thread-sleep.cpp) | Suspend workers with `sleep_for()` and join them |
| [`thread-hardware-concurrency.cpp`](src/thread-hardware-concurrency.cpp) | Query supported concurrency and create matching workers |
| [`jthread.cpp`](src/jthread.cpp) | Create C++20 `std::jthread` objects with automatic joining |
| [`syncout.cpp`](src/syncout.cpp) | Use `std::osyncstream` with C++20 `std::jthread` |

Output from the examples that run several workers can appear in a different order on each run. That is expected: thread scheduling is controlled by the operating system.

## Requirements

- A C++ compiler with C++20 support, such as GCC 15 or a recent Clang
- A C compiler with POSIX Threads support for [`pthread-basic.c`](src/pthread-basic.c)
- GNU Make for the Makefile targets
- [Doxygen](https://www.doxygen.nl) only for regenerate the HTML documentation

The Makefile currently sets `CC=g++-15`, so that command must exist on `PATH` when building C++ examples through `make`. It is possible to either install GCC 15 or override the compiler on the command line, for example, with `make CC=g++ example=thread-simple`.

## Build and run a C++ example

Run these commands from the repository root, replacing `thread-simple` with any C++ source name without its `.cpp` extension:

```bash
make example=thread-simple
./bin/thread-simple
```

The C++ target uses `-std=c++20`, enables warnings, writes the object file to `build/`, and writes the executable to `bin/`. For a debug build with symbols and no optimization:

```bash
make debug example=thread-simple
```

## Build and run the C pthread example

The `pthread` Makefile target currently compiles `pthread-basic.c` with `gcc -c`, producing an object file rather than a runnable executable. Use the following direct command to build the example correctly:

```bash
mkdir -p bin
gcc -Wall -Wextra -pthread src/pthread-basic.c -o bin/pthread-basic
./bin/pthread-basic
```

On platforms where the `pthread` option is not required, the command may still be accepted. Consult the compiler documentation for the local toolchain.

## Generate API documentation

The checked-in [`Doxyfile`](Doxyfile) already specifies `src` as the input and `doc` as the HTML output directory. Do not run `doxygen -g`, because that command creates a new configuration file instead of using the repository configuration.

With Doxygen installed, regenerate the documentation with either command:

```bash
make doc
# or
doxygen Doxyfile
```

Then open [`doc/index.html`](doc/index.html). The generated `doc/` files are build artifacts, and source comments in `src/` are the documentation source.

## Clean generated files

Remove compiled objects and executables with:

```bash
make clean
```

This leaves the source files and Doxygen configuration untouched. Regenerating the HTML documentation replaces the contents of `doc/`.

## Repository layout

```text
.
├── Doxyfile       # Doxygen configuration
├── Makefile       # C++ build, debug, documentation, and clean targets
├── src/           # C and C++ examples
├── bin/           # Generated executables
├── build/         # Generated C++ object files
├── doc/           # Generated Doxygen HTML
└── README.md
```

## 🤝 Contributing

Contributions are welcome. Please keep new examples small, runnable, and documented with Doxygen-style comments.
