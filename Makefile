# Makefile
# Build rules

# Compiler
CXX ?= g++ 

# Compiler flags
CXXFLAGS ?= --std=c++17 -Wall -Werror -pedantic -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
CXXFLAGS += -fsanitize=address -lncurses


main.exe: main.cpp board.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
