CXX = g++
CXXFLAGS = -g -std=c++11 -fprofile-arcs -ftest-coverage
TARGET = euler
OBJECTS = main.o # test.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) -lgcov

main.o: main.cpp Graph.hpp EulerCircuit.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test.o: test.cpp Graph.hpp EulerCircuit.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

clean:
	rm -f $(TARGET) $(OBJECTS) $(test.o) *.gcov *.gcda *.gcno
