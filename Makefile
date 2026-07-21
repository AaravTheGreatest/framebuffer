CXX = g++
CXXFLAGS = -Iinclude
LDLIBS = -lX11

SRC = src/fb.cpp src/draw.cpp

all:
	$(CXX) -o build/main src/*.cpp $(CXXFLAGS) $(LDLIBS)

EXAMPLE ?= rect

example:
	$(CXX) -o build/$(EXAMPLE) examples/$(EXAMPLE).cpp $(SRC) $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf build/*

.PHONY: all example clean
