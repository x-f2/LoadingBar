APPNAMES := Run
EXTRAS :=

CXX := g++
CXXFLAGS := -std=c++11 -ggdb
WARNINGS := -Wall -Wextra -Wpedantic
LDFLAGS :=

RM := rm -f

all: $(APPNAMES)

Run: LoadingBar.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cc
	$(CXX) $(CXXFLAGS) $(WARNINGS) -c $< -o $@

LoadingBar.o: ../src/LoadingBar.cc ../src/LoadingBar.h
	$(CXX) $(CXXFLAGS) $(WARNINGS) -c $< -o $@

clean:
	$(RM) $(APPNAMES) $(EXTRAS) $(wildcard *.o)
