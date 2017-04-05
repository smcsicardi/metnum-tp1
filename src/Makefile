CC=g++
CFLAGS=-Wall -Wpedantic -O2 -std=c++11
SOURCES=$(wildcard tp1/lib/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tp
TEST=test

all: $(SOURCES) $(EXECUTABLE) $(TEST)

rebuild: clean all

$(TEST):
	$(CC) $(CFLAGS) $(OBJECTS) tp1/tests.cpp -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) tp1/main.cpp -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm tp1/lib/*.o
	rm tp
	rm test
