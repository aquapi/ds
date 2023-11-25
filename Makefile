# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Ofast

# Directories
SRC_DIR = src
DIST_DIR = dist

# Find all C++ files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Get corresponding executable names for C++ files
EXECS = $(patsubst $(SRC_DIR)/%.cpp,$(DIST_DIR)/%,$(SRCS))

all: directories $(EXECS)

# Rule to compile C++ files into executables
$(DIST_DIR)/%: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Rule to create dist directory
directories: ${DIST_DIR}

${DIST_DIR}:
	mkdir -p ${DIST_DIR}

# Rule to clean dist directory
clean:
	rm -f $(DIST_DIR)/*


