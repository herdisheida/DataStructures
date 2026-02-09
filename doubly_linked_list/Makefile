CXX      := clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -pedantic
TARGET   := program

SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)

INPUTS := test_input/test1.txt test_input/test2.txt

all: info $(TARGET)

info:
	@echo "======================================"
	@echo "Build complete."
	@echo
	@echo "To run:"
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
