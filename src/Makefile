CC=g++
CFLAGS=-Wall -Wpedantic -O2 -std=c++11
SOURCES=$(wildcard tp1/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tp

all: $(SOURCES) $(EXECUTABLE)

test:
	$(CC) $(CFLAGS) tp1/tests/tests.cpp -o test

rebuild: clean all

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm tp1/*.o
