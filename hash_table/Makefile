CXX      := clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -pedantic
TARGET   := program
BUILD_NAME := Hash Table

SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)

all: info $(TARGET)

info:
	@echo "======================================"
	@echo "$(BUILD_NAME) build complete."
	@echo
	@echo "To run with own input:"
	@echo "  ./$(TARGET)"
	@echo "======================================"

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean info
