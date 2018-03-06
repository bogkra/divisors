CXX=g++
CFLAGS=--std=c++11  -Wall -Wextra -Wpedantic -Iincludes

divisors: *.cpp 
	$(CXX) main.cpp  -o $@ $(CFLAGS)

clean:
	rm divisors
