CC=g++
CFLAGS=-Wall -Wpedantic -O2 -std=c++11 -c
SOURCES=$(wildcard tp1/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tp

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@
