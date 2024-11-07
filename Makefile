# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Source directory
SRC_DIR = src
OUT_DIR = bin

# Find all .cpp files in the source directory
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Create a list of executables by replacing .cpp with nothing
EXECUTABLES = $(SOURCES:$(SRC_DIR)/%.cpp=%)

# Default target to build all executables
all: $(EXECUTABLES)

# Rule to build each executable from its corresponding .cpp file
%: $(SRC_DIR)/%.cpp
	mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $< -o $(OUT_DIR)/$@

# Clean up all executables
clean:
	rm -rf $(OUT_DIR)
	rm -f $(EXECUTABLES)

.PHONY: all clean

