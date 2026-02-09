CXX      := clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -pedantic
TARGET   := program
BUILD_NAME := Doubly Linked List

SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)

INPUTS := input_tests/input1.txt input_tests/input2.txt

all: info $(TARGET)

info:
	@echo "======================================"
	@echo "$(BUILD_NAME) build complete."
	@echo
	@echo "To run with own input:"
	@echo "  ./$(TARGET)"
	@echo
	@echo "To run tests, use one of:"
	@echo
	@for f in $(INPUTS); do echo "  ./$(TARGET) < $$f"; done
	@echo "======================================"

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean info
