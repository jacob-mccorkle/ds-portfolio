CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

all: scheduler word_frequency

scheduler: scheduler.cpp Task.h ../Portfolio3A/MinHeap.h
	$(CXX) $(CXXFLAGS) scheduler.cpp -o scheduler

word_frequency: word_frequency.cpp ../Portfolio3A/MinHeap.h ../Portfolio3A/HashTable.h
	$(CXX) $(CXXFLAGS) word_frequency.cpp -o word_frequency

run_scheduler: scheduler
	./scheduler

clean:
	rm -f scheduler word_frequency

.PHONY: all clean run_scheduler
