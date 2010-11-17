CC = g++
CFLAGS = -Wall -pedantic
GLUTFLAGS = -lglut -lGL -lGLU -lX11 -lm

OBJECTS = joy.o stringEx.o fileUtils.o

.PHONY : all clean

all: joy

joy: main.cpp $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(GLUTFLAGS)

%.o: %.cpp %.h
	$(CC) -c -o $@ $< $(CFLAGS)
