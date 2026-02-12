CXX      := clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -pedantic
TARGET   := program
BUILD_NAME := Doubly Linked List

SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)  # convert .cpp file names to .o file names

INPUTS := input_tests/input1.txt input_tests/input2.txt

all: $(TARGET) info

info:
	@echo "======================================"
	@echo "$(BUILD_NAME) build complete."
	@echo "======================================"

# link .o files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# delete .o files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# mark commands
.PHONY: all clean info
