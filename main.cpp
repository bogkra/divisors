#include <iostream>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#include "divisors.hpp"


// (C) 2018 Boguslaw Krawczuk


using namespace std;

int main()
{
  Divisors d(0,0);

// 4  
  d.inM();  
  d.inN();  
// 1
  d.generateRandoms();
// 2 : sieve of Erastotenes
  d.sieve();
// 3
  d.map();

  return 0;
}

/*
Exercise 12B:
B. Divisors Finder
Requirements:
1. Generate N random values (int numbers from 0 to M)
2. Generate all prime numbers from 0 to M
3. Create a map Prime-> Values , where Prime is a divisor of Value. (eg . 3 -> [6,9]  where 6,9 are generated random numbers )
4. Input data: N, M (from cin )

Use as much STL as possible :smiley:
*/



