CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

TARGET = test_main
SOURCES = test_main.cpp
HEADERS = MinHeap.h HashTable.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
