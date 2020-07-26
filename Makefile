#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a -Wall -g

HEADERS := $(wildcard *.h*)
STUDENT_SOURCES := $(filter-out $(wildcard Test*.cpp), $(wildcard *.cpp))
STUDENT_OBJECTS := $(subst .cpp,.o,$(STUDENT_SOURCES))

run: test
	./$^

#test: TestRunner.o Test.o Test_ariel.o Test_hila.o $(STUDENT_OBJECTS)
#	$(CXX) $(CXXFLAGS) $^ -o test

test: TestRunner.o Test.o Test_hila.cpp Test_ariel.o $(STUDENT_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o test
