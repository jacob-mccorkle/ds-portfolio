
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

all: contact_directory

contact_directory: main.cpp Contact.h ContactDirectory.h BST.h
	$(CXX) $(CXXFLAGS) main.cpp -o contact_directory

clean:
	rm -f contact_directory
