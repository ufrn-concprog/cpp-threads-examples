# Programming with threads in C and C++ #

## About

This repository contains a set of examples to demonstrate thread programming with C and C++.

## Repository structure

Each file in this repository demonstrates a different function for thread programming with C and C++. The files are organized according to the following structure:

```
+─cpp-threads-examples          ---> Project directory
  ├─── bin                      ---> Directory where executables are generated
  ├─── build                    ---> Directory where object files resulted from compilation are generated
  ├─── Doxyfile                 ---> Configuration file for generating documentation with Oxygen
  ├─── doc                      ---> Directory where HTML documentation will be generated
  ├─── Makefile                 ---> Makefile for compilation
  └─── src                      ---> Directory with source code files
       └─── jthread.cpp         ---> Demonstrating the use of jthread objects provided by C++20
       └─── pthread-basic.c     ---> Demonstrating basic programming with POSIX Threads in C
       └─── syncout.cpp         ---> Demonstrating the use of synchronized output stream and jthreads in C++20
       └─── thread-callback.cpp ---> Demonstrating creation of C++ threads with a parameterized callback function
       └─── thread-class.cpp    ---> Demonstrating creation of threads to run class instances upon operator overloading
       └─── thread-class2.cpp   ---> Demonstrating creation of threads to run class instances upon object and method references
       └─── thread-id.cpp       ---> Demonstrating creation of threads and retrieval of their IDs
       └─── thread-simple.cpp   ---> Demonstrating creation of threads to run callback function
       └─── thread-sleep.cpp    ---> Demonstrating creation and suspension of threads
```

## Requirements

For compiling and executing programs, the following elements must be properly installed on the development environment:

- [Git](https://git-scm.com), as control version system
- [*GNU Compiler Collection*](https://gcc.gnu.org) (which includes the `gcc` and `g++` compilers), [`clang`](https://clang.llvm.org/) or any other compiler for the C and C++ programming languages
- [*GNU Make*](https://www.gnu.org/software/make/), for compiling via makefile
- [Doxygen](https://www.doxygen.nl), for automatic documentation generation

## Download, compilation, and execution

In the operating system’s terminal, insert the following commands to download the implementation from this Git repository and navigate to the resulting directory:

```bash
 # Download from the Git repository
 git clone https://github.com/ufrn-concprog/cpp-threads-examples
 
 # Navigation to the directory
 cd cpp-threads-examples
```

The [Makefile](Makefile) was built to receive an input parameter named as `example`, whose value is the filename (without extension) of the respective demonstration source code (located at the [`src`](src) directory) to be be compiled and executed. The following command must be inserted into the operating system's terminal to compile the demonstration program:

```bash
 make example=filename
```

Specifically for the demonstration of C programs working with [POSIX Threads](http://pubs.opengroup.org/onlinepubs/007908799/xsh/pthread.h.html) (the so-called *pthreads*), the `make` command requires an additional argument referring to the target to compile this kind of example:

```bash
 make example=filename pthread
```

Note that the value for parameter `example` must be **exactly identical** to the filename of the source codes. If the parameter is not provided, the command `make` will do nothing. If the value does not correspond to the existing source codes, the command `make` will report an error point out that there is no defined rule for this parameter. 

Finally, to execute the generated program, insert the following command into the operating system's terminal:

```bash
 ./bin/thread-simple
```

In this case, the demonstration program to be executed is the one for [`thread-simple`](src/thread-simple.cpp) example.
