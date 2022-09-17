# Complete Makefile separating the different application elements into directories:
# - bin: executables (programs)
# - build: binaries
# - doc: documentation (ideally generated in an automatic way)
# - src: source code files

# Special variables:
# - $@: target name
# - $^: list with all the pre-requisites without duplicates
# - $<: name of the first pre-requisite

# Operating system commands
RM=rm -rf		# Windows: cmd //C del
MKDIR=mkdir

# Compiler
CC=g++

# Directory variables
BIN_DIR=bin
BUILD_DIR=build
DOC_DIR=doc
SRC_DIR=src

# Program name
PROG=$(example)

# Compilation options
FLAGS=-W -Wall -pedantic -std=c++11

# Target for the complete compilation, removing generated object files at the end
all: $(PROG)

# Target to build the executable
# Linking object files (.o) defined as dependencies
$(PROG): $(BUILD_DIR)/$(PROG).o
	$(MKDIR) -p $(BIN_DIR)
	$(CC) $(FLAGS) -o $(BIN_DIR)/$@ $^
	@echo "> Executable '$@' created into '$(BIN_DIR)'"

# Target to build the object file
# Compilation of the source code files defined as dependencies
$(BUILD_DIR)/$(PROG).o: $(SRC_DIR)/$(PROG).cpp
	$(MKDIR) -p $(BUILD_DIR)
	$(CC) -c $(FLAGS) -o $@ $<

# Specific target for C programs using POSIX Threads
pthread:
	$(MKDIR) -p $(BIN_DIR)
	gcc -c $(SRC_DIR)/$(example).c -o $(BIN_DIR)/$(example)
	@echo "> Executable '$(example)' created into '$(BIN_DIR)'"

# Ensuring that targets of this list are not confused with files of the same name
.PHONY: all clean doxy debug doc

# Targets to automatically generate source code documentation with Doxygen
# Always remove the previous documentation (if it exists) and generates a new version
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g
doc:
	doxygen

# Target adding flags to debugging
debug: FLAGS += -g -O0
debug: $(PROG)

# Target to clean temporary (object) files generated during compilation and executables
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(BUILD_DIR)/*
