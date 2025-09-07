# Thread Programming in C and C++

![C++](https://img.shields.io/badge/C++-11%2B-green)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
![Build](https://img.shields.io/badge/build-manual-lightgrey)
[![Docs](https://img.shields.io/badge/doc-Doxygen-purple)](./doc/index.html)

This educational repository features a set of illustrative examples that demonstrate the use of various threading functions in C and C++. The learning objectives are:

- Demonstrate practical usage of key thread-related functions and methods, including but not limited to:
  - Creating and running POSIX Threads in C
  - Creating and running thread objects in C++11
  - Basic methods such as `join()`, `get_id()`, and `sleep_for()`
- Demonstrate the new features for *jthreads* available at C++20
- Serve as a reference for writing well-documented, multithreaded C++ code.

This project is part of the **Concurrent Programming** module at the [Federal University of Rio Grande do Norte (UFRN)](https://www.ufrn.br), Natal, Brazil.

---

## 📂 Repository Structure

Each file in this repository demonstrates a different function for thread programming with C and C++. The files are organized according to the following structure:

```
.
├── doc/            # Configuration file for generating documentation with Doxygen
├── Doxygen         # Documentation
├── Makefile        # Makefile for compilation
├── src             # Source code
│   ├── jthread.cpp          # Demonstration of the use of jthread objects provided by C++20
│   ├── pthread-basic.c      # Demonstration of basic programming with POSIX Threads in C
│   ├── syncout.cpp          # Demonstration of the use of synchronized output stream and jthreads in C++20
│   ├── thread-callback.cpp  # Demonstration of thread creation with a parameterized callback function
│   ├── thread-class.cpp     # Demonstration of thread creation to run class instances upon operator overloading
│   ├── thread-class2.cpp    # Demonstration of thread creation to run class instances upon object and method references
│   ├── thread-id.cpp        # Demonstration of thread creation and retrieval of their IDs
│   ├── thread-simple.cpp    # Demonstration of thread creation to run a callback function
│   ├── thread-sleep.cpp     # Demonstration of thread creation and suspension
└── README.md
```

---

## 🚀 Getting Started

### ✅ Prerequisites

For compiling and executing programs, the following elements must be properly installed on the development environment:

- [*GNU Compiler Collection*](https://gcc.gnu.org) (which includes the `gcc` and `g++` compilers), [`clang`](https://clang.llvm.org/) or any other compiler for the C and C++ programming languages
- [*GNU Make*](https://www.gnu.org/software/make/), for compiling via makefile
- [Doxygen](https://www.doxygen.nl), for automatic documentation generation

To compile and run [`jthread.cpp`](src/jthread.cpp) and [`syncout.cpp`](src/syncout.cpp), ensure that your compiler supports C++20.

### 🔧 Compilation

The [Makefile](Makefile) was built to receive an input parameter named as `example`, whose value is the filename (without extension) of the respective demonstration source code (located at the [`src`](src) directory) to be be compiled and executed. The following command must be inserted into the operating system's terminal to compile the demonstration program:

```bash
 make example=filename
```

Specifically for the demonstration of C programs working with [POSIX Threads](http://pubs.opengroup.org/onlinepubs/007908799/xsh/pthread.h.html) (the so-called *pthreads*), the `make` command requires an additional argument referring to the target to compile this kind of example:

```bash
 make example=filename pthread
```

Note that the value for parameter `example` must be **exactly identical** to the filename of the source codes. If the parameter is not provided, the command `make` will do nothing. If the value does not correspond to the existing source codes, the command `make` will report an error point out that there is no defined rule for this parameter.

In all the cases, generated object files will be stored inside the `build` directory and the executable program will be stored inside the `bin` directory. These directories are automatically created in the first run of the [`Makefile`](Makefile).

### ▶️ Running

To execute the generated program, insert the following command into the operating system's terminal:

```bash
 ./bin/thread-simple
```

In this case, the demonstration program to be executed is the one for [`thread-simple`](src/thread-simple.cpp) example.

---

## 🤝 Contributing

Contributions are welcome! Fork this repository and submit a pull request 🚀

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).
