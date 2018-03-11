CXX=g++
CFLAGS=--std=c++11  -Wall -Wextra -Wpedantic -Iincludes

divisors: *.cpp *.hpp
	$(CXX) main.cpp divisors.hpp divisors.cpp -o $@ $(CFLAGS)

clean:
	rm divisors
