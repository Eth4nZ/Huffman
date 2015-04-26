CC = g++
CFLAGS = -c -Wall

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = hhh

all: $(SOURCES) $(EXECUTABLE)
	    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@




#all: hhh

#hhh: main.o
#	$(CC) main.o -o hhh

#main.o: main.cpp
#	$(CC) $(CFLAGS) main.cpp

#clean:
#	rm *o hhh


