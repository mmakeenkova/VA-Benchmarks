# Makefile for microbenchmarks

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -O3
INCLUDES =-I/mnt/panzer/mmakeenkova/vm_project/sniper/include/

# Source files
SRCS = accumulate_random_elements.cpp accumulate_two_arrays.cpp copy_on_one.cpp copy_random_index.cpp filter_values.cpp
OBJS = $(SRCS:%.cpp=build/%.o)
BINS = $(SRCS:%.cpp=build/%)

# Targets
all: $(BINS) | build

build/%: build/%.o | build
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@ 

build/%.o: %.cpp | build
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build